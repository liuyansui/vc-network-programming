// ClientSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ClientSocket.h"
#include "ChatClientDlg.h"

// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��Ա����


void CClientSocket::OnConnect(int nErrorCode)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (nErrorCode)
	{
		AfxMessageBox(_T("����ʧ�ܣ��������ԣ�"));
		return;
	}
	((CChatClientDlg*)(AfxGetApp()->m_pMainWnd))->m_ListWords.AddString(_T("���ӷ������ɹ���"));
	((CChatClientDlg*)(AfxGetApp()->m_pMainWnd))->m_ListWords.SetTopIndex(
		((CChatClientDlg*)(AfxGetApp()->m_pMainWnd))->m_ListWords.GetCount() - 1);
	CAsyncSocket::OnConnect(nErrorCode);
}
