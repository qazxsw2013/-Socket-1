#include "stdafx.h"
#include "ListenSocket.h"


CListenSocket::CListenSocket()
{
}


CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	CNewSocket *pSocket = new CNewSocket();
	if (Accept(*pSocket))
	{
		pSocket->AsyncSelect(FD_READ);						//����Read()����
		m_pSocket = pSocket;
	}
	else
	{
		delete pSocket;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}
