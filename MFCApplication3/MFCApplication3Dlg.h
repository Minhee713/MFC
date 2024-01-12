
// MFCApplication3Dlg.h: 헤더 파일
//

#pragma once


// CMFCApplication3Dlg 대화 상자
class CMFCApplication3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
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
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lsit_history;
	CEdit m_edit_name;
	CEdit m_edit_number;
	CStatic m_picture;
	CEdit m_edit_add;
	CButton m_btn_add;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonFile();
	CSliderCtrl m_slider_count;
//	CEdit m_edit_count;

//	afx_msg void OnTRBNThumbPosChangingSliderCount(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSliderCount(NMHDR* pNMHDR, LRESULT* pResult);
	int m_edit_count;
	CProgressCtrl m_progress_count;
//	afx_msg void OnBnDoubleclickedButtonAdd();
	afx_msg void OnLbnDblclkListHistory();
};
