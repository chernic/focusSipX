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
//  Ĭ��
void Overlay::switchMode(int mode){
    if( PJ_SUCCESS != sIsInit)
	{
        Init();
    }
	// �����޸�ģʽ, 0Ϊ���޸�ģʽ
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

///// �������� /////
void Overlay::switch2NavbarL(void){ // ����
    sMode = NAVBAR_L;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0,  sWt/4,  sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,    0,    0,    sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}
void Overlay::switch2NavbarR(void){ // ����
    sMode = NAVBAR_R;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0, sWt/4,   sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,sWs-sWt,  0,    sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}
void Overlay::switch2FooterL(void){ // ����
    sMode = FOOTER_L;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0,  sWt/4,  sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,    0,sHs-sHt,  sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}
void Overlay::switch2FooterR(void){ // ����
    sMode = FOOTER_R;
    setTwoWinShow();
    setDefaultScreen();

  //update(&Button    ,    0,    0,  sWt/4,  sHt/4);
    update(&Background,    0,    0,     0,       0);
    update(&Foreground,    0,    0,    sWt,    sHt);
    update(&Complex   ,sWs-sWt,sHs-sHt,sWt,    sHt);
    update(&Stream    ,    0,    0,    sWs,    sHs);
}


///// �������� /////
void Overlay::switchInNavbarL(void){ // ����
    switchMode(IN_NAVBAR_L);
}
void Overlay::switchInNavbarR(void){ // ����������
    switchMode(IN_NAVBAR_R);
}
void Overlay::switchInFooterL(void){ // ����������
    switchMode(IN_FOOTER_L);
}
void Overlay::switchInFooterR(void){ // ����������
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