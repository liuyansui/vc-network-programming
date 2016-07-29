// ClientSocket.cpp : 实现文件
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


// CClientSocket 成员函数


void CClientSocket::OnConnect(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (nErrorCode)
	{
		AfxMessageBox(_T("连接失败，请你重试！"));
		return;
	}
	((CChatClientDlg*)(AfxGetApp()->m_pMainWnd))->m_ListWords.AddString(_T("连接服务器成功！"));
	((CChatClientDlg*)(AfxGetApp()->m_pMainWnd))->m_ListWords.SetTopIndex(
		((CChatClientDlg*)(AfxGetApp()->m_pMainWnd))->m_ListWords.GetCount() - 1);
	CAsyncSocket::OnConnect(nErrorCode);
}
