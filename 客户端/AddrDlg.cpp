// AddrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ���.h"
#include "AddrDlg.h"
#include "afxdialogex.h"


// CAddrDlg �Ի���

IMPLEMENT_DYNAMIC(CAddrDlg, CDialogEx)

CAddrDlg::CAddrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddrDlg::IDD, pParent)
	, my_Addr(_T(""))
{

}

CAddrDlg::~CAddrDlg()
{
}

void CAddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, my_Addr);
}


BEGIN_MESSAGE_MAP(CAddrDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddrDlg ��Ϣ�������
