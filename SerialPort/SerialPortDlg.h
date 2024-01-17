
// SerialPortDlg.h: 헤더 파일
//

#include "comm.h"

#pragma once


// CSerialPortDlg 대화 상자
class CSerialPortDlg : public CDialogEx
{
// 생성입니다.
public:
	CSerialPortDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERIALPORT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnReceiveMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_receive;
	CEdit m_edit_send;

	CCommThread cComThread;

	afx_msg void OnBnClickedButtonSend();

	afx_msg LRESULT OnReceive(WPARAM wParam, LPARAM IParam);
	CComboBox m_combo_port;
	afx_msg void OnBnClickedButtonOpen();
};
