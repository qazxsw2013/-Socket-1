
// �ͻ���Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C�ͻ���Dlg �Ի���
class C�ͻ���Dlg : public CDialogEx
{
// ����
public:
	C�ͻ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_MsgR;
	CEdit m_MsgS;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedClose();
};
