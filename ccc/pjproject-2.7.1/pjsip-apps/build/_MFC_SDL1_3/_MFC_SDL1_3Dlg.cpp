
// _MFC_SDL1_3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "_MFC_SDL1_3.h"
#include "_MFC_SDL1_3Dlg.h"
#include <SDL.h>  

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_MFC_SDL1_3Dlg 对话框




C_MFC_SDL1_3Dlg::C_MFC_SDL1_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C_MFC_SDL1_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C_MFC_SDL1_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C_MFC_SDL1_3Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &C_MFC_SDL1_3Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C_MFC_SDL1_3Dlg 消息处理程序

BOOL C_MFC_SDL1_3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C_MFC_SDL1_3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C_MFC_SDL1_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C_MFC_SDL1_3Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;

	//首先初始化
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return ;
	}
	//创建窗口
	gWindow=SDL_CreateWindowFrom( (void *)( GetDlgItem(IDC_STATIC)->GetSafeHwnd() ) );
	if(gWindow==NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return ;
	}
	//Use this function to get the SDL surface associated with the window.
	//获取窗口对应的surface
	gScreenSurface=SDL_GetWindowSurface(gWindow);

	//加载图片
	gHelloWorld = SDL_LoadBMP("Hello_World.bmp");//加载图片
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "Hello_World.bmp", SDL_GetError() );
		return ;
	}
	//Use this function to perform a fast surface copy to a destination surface.  
	//surface的快速复制
	//              SDL_Surface* src ,const SDL_Rect* srcrect , SDL_Surface* dst ,  SDL_Rect* dstrect
	SDL_BlitSurface( gHelloWorld ,     NULL ,                     gScreenSurface ,          NULL);
	SDL_UpdateWindowSurface(gWindow);//更新显示copy the window surface to the screen
}
