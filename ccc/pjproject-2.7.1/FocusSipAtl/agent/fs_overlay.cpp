#include "stdafx.h"
#include "fs_overlay.h"


void Overlay::setDefaultMode(void){
    sMode= DEFAULT_MODE;
}
void Overlay::setDefaultShow(void){
    IsStreamShow  = PJ_FALSE;
    IsComplexShow = PJ_TRUE;
}
void Overlay::setTwoWinShow(void){
    IsStreamShow  = PJ_TRUE;
    IsComplexShow = PJ_TRUE;
}
//// + ERROR RETURN

void Overlay::updateThumbnailSize(void){
    if( sWs==0 || sHs==0 || sScale==0 )
        setDefaultScreen();
    sWt = sWs*sScale;
    sHt = sHs*sScale;
}
void Overlay::setDefaultScreen(void){
    sWs    = GetSystemMetrics(SM_CXSCREEN)/2;
    sHs    = GetSystemMetrics(SM_CYSCREEN)/2;
    sScale = 0.33;
	updateThumbnailSize();
}

pj_status_t Overlay::setScreen(int w, int h,  double s){
	if( w==0 || h==0 || s==0 )
	{
        setDefaultScreen();
	}else{
		sWs    = w;
		sHs    = h;
		sScale = s;
	}
	
	updateThumbnailSize();

	switchMode(0);

    return PJ_SUCCESS;
}
//  默认
void Overlay::switchMode(int mode){
    if( PJ_SUCCESS != sIsInit)
	{
        Init();
    }
	// 假如修改模式, 0为不修改模式
	if(mode!=0)
	{
        sMode = mode;
	}
    switch(sMode){
        case IN_FOOTER_R:{
            //update(&Button  ,    0,    0,  sWt/4,  sHt/4);
            update(&Background,    0,    0,    sWs,    sHs);
            update(&Foreground,sWs-sWt,sHs-sHt,sWt,    sHt);
            update(&Complex   ,    0,    0,    sWs,    sHs);
            update(&Stream    ,    0,    0,    sWs,    sHs);
        }break;
        case IN_FOOTER_L:{
            //update(&Button  ,    0,    0,  sWt/4,  sHt/4);
            update(&Background,    0,    0,    sWs,    sHs);
            update(&Foreground,    0,sHs-sHt,  sWt,    sHt);
            update(&Complex   ,    0,    0,    sWs,    sHs);
            update(&Stream    ,    0,    0,    sWs,    sHs);
        }break;
        case IN_NAVBAR_R:{
            //update(&Button  ,    0,    0,  sWt/4,  sHt/4);
            update(&Background,    0,    0,    sWs,    sHs);
            update(&Foreground,sWs-sWt,  0,    sWt,    sHt);
            update(&Complex   ,    0,    0,    sWs,    sHs);
            update(&Stream    ,    0,    0,    sWs,    sHs);
        }break;
        case IN_NAVBAR_L:
		default:{
            //update(&Button  ,    0,    0,  sWt/4,  sHt/4);
            update(&Background,    0,    0,    sWs,    sHs);
            update(&Foreground,    0,    0,    sWt,    sHt);
            update(&Complex   ,    0,    0,    sWs,    sHs);
            update(&Stream    ,    0,    0,    sWs,    sHs);
        }break;
    }
}

///// 两个窗口 /////
void Overlay::switch2NavbarL(void){ // 上左
    sMode = NAVBAR_L;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0,  sWt/4,  sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,    0,    0,    sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}
void Overlay::switch2NavbarR(void){ // 上右
    sMode = NAVBAR_R;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0, sWt/4,   sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,sWs-sWt,  0,    sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}
void Overlay::switch2FooterL(void){ // 下左
    sMode = FOOTER_L;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0,  sWt/4,  sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,    0,sHs-sHt,  sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}
void Overlay::switch2FooterR(void){ // 下左
    sMode = FOOTER_R;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0,  sWt/4,  sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,sWs-sWt,sHs-sHt,sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}


///// 单个窗口 /////
void Overlay::switchInNavbarL(void){ // 上左
    switchMode(IN_NAVBAR_L);
}
void Overlay::switchInNavbarR(void){ // 单窗口上右
    switchMode(IN_NAVBAR_R);
}
void Overlay::switchInFooterL(void){ // 单窗口下左
    switchMode(IN_FOOTER_L);
}
void Overlay::switchInFooterR(void){ // 单窗口下右
    switchMode(IN_FOOTER_R);
}
// 

void Overlay::Init(void){
	sIsInit = -1; 

	setDefaultMode();
	setDefaultShow();
	setDefaultScreen();

	sIsInit = PJ_SUCCESS; 
}
Overlay::Overlay(){
    Init();
}

Overlay gOverlay;