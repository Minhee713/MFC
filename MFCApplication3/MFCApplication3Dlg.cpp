
// MFCApplication3Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 대화 상자



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, m_edit_count(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HISTORY, m_lsit_history);
	DDX_Control(pDX, IDC_EDIT_NAME, m_edit_name);
	DDX_Control(pDX, IDC_EDIT_NUMBER, m_edit_number);
	DDX_Control(pDX, IDC_PICTURE, m_picture);
	DDX_Control(pDX, IDC_EDIT_ADD, m_edit_add);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btn_add);
	DDX_Control(pDX, IDC_SLIDER_COUNT, m_slider_count);
	//  DDX_Control(pDX, IDC_EDIT_COUNT, m_edit_count);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_edit_count);
	DDV_MinMaxInt(pDX, m_edit_count, 0, 100);
	DDX_Control(pDX, IDC_PROGRESS_COUNT, m_progress_count);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCApplication3Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_FILE, &CMFCApplication3Dlg::OnBnClickedButtonFile)
//	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_COUNT, &CMFCApplication3Dlg::OnTRBNThumbPosChangingSliderCount)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_COUNT, &CMFCApplication3Dlg::OnNMCustomdrawSliderCount)
//ON_BN_DOUBLECLICKED(IDC_BUTTON_ADD, &CMFCApplication3Dlg::OnBnDoubleclickedButtonAdd)
ON_LBN_DBLCLK(IDC_LIST_HISTORY, &CMFCApplication3Dlg::OnLbnDblclkListHistory)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 메시지 처리기

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	m_slider_count.SetRange(0, 100);
	m_edit_count = 0;

	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		//CDC* dc;
		//dc = m_picture.GetDC();

		// 전체 다이얼로그에 대한 
		CPaintDC dc(this);

		for(int i = 0; i <= 100; i++) 
			dc.SetPixel(10+i, 10, RGB(255, 0, 0));

		dc.MoveTo(10, 10);
		dc.LineTo(10, 100);

		dc.Rectangle(10, 100, 200, 200);
		dc.Ellipse(10, 100, 200, 200);

		dc.FillSolidRect(200, 100, 50, 50, RGB(0, 0, 255));

		// picture control에 대한 
		CDC* dc2;
		dc2 = m_picture.GetDC();

		for (int i = 0; i <= 100; i++)
			dc2->SetPixel(10 + i, 10, RGB(255, 0, 0));

		dc2->MoveTo(10, 10);
		dc2->LineTo(10, 100);

		dc2->Rectangle(10, 100, 200, 200);
		dc2->Ellipse(10, 100, 200, 200);

		dc2->FillSolidRect(200, 100, 50, 50, RGB(0, 0, 255));

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedButtonAdd()
{
	CString str;

	
	if (m_edit_add.GetWindowTextLengthW() != 0) { // edit control에 글자가 써졌을 때에만 
		m_edit_add.GetWindowTextW(str);
		m_lsit_history.AddString(str);
		m_edit_add.SetWindowTextW(_T(""));
	}
}


void CMFCApplication3Dlg::OnBnClickedButtonFile()
{
	// True면 읽어 오는 파일(열기), False면 저장 하는 파일(다른 이름으로 저장) 
	CFileDialog dlg(TRUE, _T(".jpg"), _T("image"), OFN_HIDEREADONLY, _T("이미지 파일(*.BMP, *.GIF, *.JPG) | *.bmp;*.jpg;*.gif | 모든파일(*.*)|*.*||"));

	if (dlg.DoModal() == IDOK) {
		CString str;
		CRect rect; // 영역에 대한 좌표 및 크기를 가져올 수 있는 클래스 
		CDC* dc; // 영역에 그림을 그리기 위한 클래스 
		CImage image; // 영역에 이미지 처리를 위한 클래스 

		str = dlg.GetPathName();
		m_picture.GetWindowRect(rect);

		dc = m_picture.GetDC();
			
		image.Load(str);

		image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
		ReleaseDC(dc);
	}
}


//void CMFCApplication3Dlg::OnTRBNThumbPosChangingSliderCount(NMHDR* pNMHDR, LRESULT* pResult)
//{
	// 이 기능을 사용하려면 Windows Vista 이상이 있어야 합니다.
	// _WIN32_WINNT 기호는 0x0600보다 크거나 같아야 합니다.
//	NMTRBTHUMBPOSCHANGING* pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING*>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	*pResult = 0;
//}


void CMFCApplication3Dlg::OnNMCustomdrawSliderCount(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	int pos = m_slider_count.GetPos();
	
	m_edit_count = pos;

	m_progress_count.SetPos(pos);

	UpdateData(FALSE);
	*pResult = 0;
}


void CMFCApplication3Dlg::OnLbnDblclkListHistory()
{
	CString str;

	m_lsit_history.GetText(m_lsit_history.GetCaretIndex(), str);
	m_edit_add.SetWindowTextW(str); 

}
