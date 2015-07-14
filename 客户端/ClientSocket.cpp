#include "stdafx.h"
#include "ClientSocket.h"

#include "�ͻ���Dlg.h"
#include "�ͻ���.h"


CClientSocket::CClientSocket()
{
	my_nLength = 0;
	memset(my_szBuffer, 0, sizeof(my_szBuffer));
	my_bConnected = FALSE;
}


CClientSocket::~CClientSocket()
{
	if (m_hSocket != INVALID_SOCKET) Close();
}


void CClientSocket::OnConnect(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (nErrorCode == 0)
	{
		my_bConnected = TRUE;
		C�ͻ���App *pApp = (C�ͻ���App*)AfxGetApp();
		C�ͻ���Dlg *pDlg = (C�ͻ���Dlg*)pApp->m_pMainWnd;
		memcpy(my_szBuffer, "���ӵ�:", 13);
		strncat(my_szBuffer, pDlg->my_szServerAdr, sizeof(pDlg->my_szServerAdr));
		pDlg->m_MsgR.InsertString(0, LPCTSTR(my_szBuffer));
		pDlg->GetDlgItem(IDC_SEND)->EnableWindow(true);
		AsyncSelect(FD_READ);
	}

	CAsyncSocket::OnConnect(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	my_nLength = Receive(my_szBuffer, sizeof(my_szBuffer));
	C�ͻ���App *pApp = (C�ͻ���App*)AfxGetApp();
	C�ͻ���Dlg *pDlg = (C�ͻ���Dlg*)pApp->m_pMainWnd;
	pDlg->m_MsgR.InsertString(0, LPCTSTR(my_szBuffer));
	memset(my_szBuffer, 0, sizeof(my_szBuffer));

	CAsyncSocket::OnReceive(nErrorCode);
}


void CClientSocket::OnSend(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	Send(my_szBuffer, my_nLength, 0);
	my_nLength = 0;
	memset(my_szBuffer, 0, sizeof(my_szBuffer));
	AsyncSelect(FD_READ);

	CAsyncSocket::OnSend(nErrorCode);
}
