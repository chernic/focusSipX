// Preview.h : CComplex ������
// ATL3.0�еĴ�����-�ͻ���ʹ��ATL����DUI��ܵ����
// http://blog.csdn.net/klarclm/article/details/7160982

#pragma once

#include "resource.h"       // ������

//#include <Windows.h>  
#include <string>
// #include <atlhost.h>
// #include "atlapp.h"
// #include "atlmisc.h"
// #include "atlframe.h"
#include "dh_window_bg_brush_helper.h"

// CComplex
class CComplex : 
    public CAxDialogImpl<CComplex>
{
  public:
    CComplex()
    {
    }

    ~CComplex()
    {
    }

    enum { IDD = IDD_COMPLEX };

	DhWindowBgBrushHelper brush_helper_;  

BEGIN_MSG_MAP(CComplex) // ���ú�ʵ��ProcessWindowMessage���������Էַ���Ϣ 
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  //MESSAGE_HANDLER(WM_PAINT,OnPaint)
  CHAIN_MSG_MAP(CAxDialogImpl<CComplex>)
END_MSG_MAP()

// �������ԭ��:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
  LRESULT OnInitDialog  (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  void SetComplexWindow(RECT rcC);
  void DestroyWindow(void);
};

extern CComplex *pComplex;

