
// _MFC_SDLDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "_MFC_SDL.h"
#include "_MFC_SDLDlg.h"
#include <SDL.h>  

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_MFC_SDLDlg �Ի���
C_MFC_SDLDlg::C_MFC_SDLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(C_MFC_SDLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C_MFC_SDLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C_MFC_SDLDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &C_MFC_SDLDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C_MFC_SDLDlg ��Ϣ�������

BOOL C_MFC_SDLDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C_MFC_SDLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C_MFC_SDLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C_MFC_SDLDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;

	//���ȳ�ʼ��
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return ;
	}
	//��������
	gWindow=SDL_CreateWindowFrom( (void *)( GetDlgItem(IDC_STATIC)->GetSafeHwnd() ) );
	if(gWindow==NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return ;
	}
	//Use this function to get the SDL surface associated with the window.
	//��ȡ���ڶ�Ӧ��surface
	gScreenSurface=SDL_GetWindowSurface(gWindow);

	//����ͼƬ
	gHelloWorld = SDL_LoadBMP("Hello_World.bmp");//����ͼƬ
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "Hello_World.bmp", SDL_GetError() );
		return ;
	}
	//Use this function to perform a fast surface copy to a destination surface.  
	//surface�Ŀ��ٸ���
	//              SDL_Surface* src ,const SDL_Rect* srcrect , SDL_Surface* dst ,  SDL_Rect* dstrect
	SDL_BlitSurface( gHelloWorld ,     NULL ,                     gScreenSurface ,          NULL);
	SDL_UpdateWindowSurface(gWindow);//������ʾcopy the window surface to the screen
}
