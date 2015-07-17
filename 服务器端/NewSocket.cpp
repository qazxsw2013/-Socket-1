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
	my_nLength = Receive(my_szBuffer, sizeof(my_szBuffer), 0);		//������Ϣ//my_nLength����4096
	
	
	if (my_szBuffer[0] != '\0') {
		AsyncSelect(FD_WRITE);										//����OnSend()����,(ת�����յ�����Ϣ)
	}
	

	CAsyncSocket::OnReceive(nErrorCode);
}


void CNewSocket::OnSend(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	char my_SendBuffer[4096];
	//memset(my_SendBuffer, 0, sizeof(my_SendBuffer));
	memcpy(my_SendBuffer, "������ת��:", 24);
	strncat_s(my_SendBuffer, my_szBuffer, my_nLength);				//���Ƹ�ֵ
	int i = 0;
	while (my_SendBuffer[i] != '\0')
	{ 
		i++; 
	}
	//Send(my_SendBuffer, sizeof(my_SendBuffer));						//��������
	Send(my_SendBuffer, i);						//��������
	AsyncSelect(FD_READ);											//����OnReceive()����

	CAsyncSocket::OnSend(nErrorCode);
}
