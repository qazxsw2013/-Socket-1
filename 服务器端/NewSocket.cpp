#include "stdafx.h"
#include "NewSocket.h"


CNewSocket::CNewSocket()
{
	my_nLength = 0;
	memset(my_szBuffer, 0, sizeof(my_szBuffer));
}


CNewSocket::~CNewSocket()
{
	if (m_hSocket != INVALID_SOCKET) Close();
}


void CNewSocket::OnReceive(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	my_nLength = Receive(my_szBuffer, sizeof(my_szBuffer), 0);		//������Ϣ
	AsyncSelect(FD_WRITE);											//����OnSend()����,(ת�����յ�����Ϣ)

	CAsyncSocket::OnReceive(nErrorCode);
}


void CNewSocket::OnSend(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	char my_SendBuffer[4096];
	memcpy(my_SendBuffer, "������ת��:", 24);
	strncat(my_SendBuffer, my_szBuffer, my_nLength);				//���Ƹ�ֵ
	Send(my_SendBuffer, sizeof(my_SendBuffer));						//��������
	AsyncSelect(FD_READ);											//����OnReceive()����

	CAsyncSocket::OnSend(nErrorCode);
}
