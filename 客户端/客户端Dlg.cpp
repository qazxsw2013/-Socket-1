
// �ͻ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ���.h"
#include "�ͻ���Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ͻ���Dlg �Ի���



C�ͻ���Dlg::C�ͻ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�ͻ���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ͻ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_MsgR);
	DDX_Control(pDX, IDC_EDIT1, m_MsgS);
}

BEGIN_MESSAGE_MAP(C�ͻ���Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &C�ͻ���Dlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_SEND, &C�ͻ���Dlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_CLOSE, &C�ͻ���Dlg::OnBnClickedClose)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C�ͻ���Dlg ��Ϣ�������

BOOL C�ͻ���Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ͻ���Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ͻ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�ͻ���Dlg::OnBnClickedConnect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_ClientSocket.ShutDown(2);
	m_ClientSocket.m_hSocket = INVALID_SOCKET;
	m_ClientSocket.my_bConnected = FALSE;
	CAddrDlg m_Dlg;
	my_szPort = 5088;
	if (m_Dlg.DoModal() == IDOK && !m_Dlg.my_Addr.IsEmpty())
	{
		memcpy(my_szServerAdr, m_Dlg.my_Addr, sizeof(my_szServerAdr));
		SetTimer(1, 1000, NULL);
		TryCount = 0;
	}
	GetDlgItem(IDC_CONNECT)->EnableWindow(false);
}


void C�ͻ���Dlg::OnBnClickedSend()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_ClientSocket.my_bConnected)
	{
		m_ClientSocket.my_nLength = m_MsgS.GetWindowTextLengthW();
		m_ClientSocket.AsyncSelect(FD_WRITE);
		m_MsgS.SetWindowTextW(L"");
	}
}


void C�ͻ���Dlg::OnBnClickedClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_ClientSocket.ShutDown(2);
	EndDialog(0);
}


void C�ͻ���Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_ClientSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_ClientSocket.Create(0, SOCK_STREAM, FD_CONNECT);
		if (!bFlag)
		{
			AfxMessageBox(L"Socket��������!");
			m_ClientSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	m_ClientSocket.Connect(LPCTSTR(my_szServerAdr), my_szPort);
	TryCount++;
	if (TryCount >= 10 || m_ClientSocket.my_bConnected)
	{
		KillTimer(1);
		if (TryCount >= 10)
		{
			AfxMessageBox(L"����ʧ��!");
			AfxMessageBox(LPCTSTR(my_szServerAdr));
			GetDlgItem(IDC_CONNECT)->EnableWindow(true);
		}
		return;
	}

	CDialogEx::OnTimer(nIDEvent);
}
