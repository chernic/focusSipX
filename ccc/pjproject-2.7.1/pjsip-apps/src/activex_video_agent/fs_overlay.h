#pragma once

/////////////////////// ��Ļ����
// ����
#define IN_NAVBAR_L     1
// ����
#define IN_NAVBAR_R     2
// ����
#define IN_FOOTER_L     3
// ����
#define IN_FOOTER_R     4
///////////////////////
#define IN_MENU_T       5
#define IN_MENU_B       6
#define IN_SIDEBAR_T    7
#define IN_SIDEBAR_B    8

// ����
#define NAVBAR_L        9
// ����
#define NAVBAR_R        10
// ����
#define FOOTER_L        11
// ����
#define FOOTER_R        12
///////////////////////
#define MENU_T          13
#define MENU_B          14
#define SIDEBAR_T       15
#define SIDEBAR_B       16






typedef struct Layout{
    pjmedia_coord       pos;
    pjmedia_rect_size   siz;
}Layout_t;

typedef struct Overlay{
    int mode;
    int wS; // Screen
    int hS; // Screen
    unsigned Scale;
    int wT; // Thumbnail
    int hT; // Thumbnail

    pj_bool_t IsStreamShow;
    pj_bool_t IsComplexShow;

    Layout_t Stream;
    Layout_t Complex;
    Layout_t Background;
    Layout_t Foreground;
    Layout_t Button;

    int setScale(unsigned s){
        if(s==0){
            s = 1;
            return -1;
        }
        Scale = s; 
        return 0;
    }
    int setThumbnailSize(void){
        if(wS==0||hS==0) return -1;
        wT = wS/Scale;
        hT = hS/Scale;
        return 0;
    }
    int setScreen(int w, int h){
        wS=w;
        hS=h;
        setThumbnailSize();
        return 0;
    }
    void update(Layout_t *pLayout, int x, int y, int w, int h){
        pLayout->pos.x=x;
        pLayout->pos.y=y;
        pLayout->siz.w=w;
        pLayout->siz.h=h;
    }

    // ��������
    void switch2NavbarL(int w, int h){ // ����
        mode = NAVBAR_L;
        IsStreamShow  = PJ_TRUE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,     0,     0);
        update(&Foreground,    0,    0,    wT,    hT);
        update(&Complex   ,    0,    0,    wT,    hT);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    void switch2NavbarR(int w, int h){ // ����
        mode = NAVBAR_R;
        IsStreamShow  = PJ_TRUE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,     0,     0);
        update(&Foreground,    0,    0,    wT,    hT);
        update(&Complex   ,wS-wT,    0,    wT,    hT);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    void switch2FooterL(int w, int h){ // ����
        mode = FOOTER_L;
        IsStreamShow  = PJ_TRUE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,     0,     0);
        update(&Foreground,    0,    0,    wT,    hT);
        update(&Complex   ,    0,hS-hT,    wT,    hT);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    void switch2FooterR(int w, int h){ // ����
        mode = FOOTER_R;
        IsStreamShow  = PJ_TRUE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,     0,     0);
        update(&Foreground,    0,    0,    wT,    hT);
        update(&Complex   ,wS-wT,hS-hT,    wT,    hT);
        update(&Stream    ,    0,    0,    wS,    hS);
    }

    // ��������
    void switchInNavbarL(int w, int h){ // ����
        mode = IN_NAVBAR_L;
        IsStreamShow  = PJ_FALSE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,    wS,    hS);
        update(&Foreground,    0,    0,    wT,    hT);
        update(&Complex   ,    0,    0,    wS,    hS);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    void switchInNavbarR(int w, int h){ // ����������
        mode = IN_NAVBAR_L;
        IsStreamShow  = PJ_FALSE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,    wS,    hS);
        update(&Foreground,wS-wT,    0,    wT,    hT);
        update(&Complex   ,    0,    0,    wS,    hS);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    void switchInFooterL(int w, int h){ // ����������
        mode = IN_FOOTER_L;
        IsStreamShow  = PJ_FALSE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,    wS,    hS);
        update(&Foreground,    0,hS-hT,    wT,    hT);
        update(&Complex   ,    0,    0,    wS,    hS);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    void switchInFooterR(int w, int h){ // ����������
        mode = IN_FOOTER_R;
        IsStreamShow  = PJ_FALSE;
        IsComplexShow = PJ_TRUE;
        setScale(3);
        setScreen(w,h);
        setThumbnailSize();

      //update(&Button    ,    0,    0,  wT/4,  hT/4);
        update(&Background,    0,    0,    wS,    hS);
        update(&Foreground,wS-wT,hS-hT,    wT,    hT);
        update(&Complex   ,    0,    0,    wS,    hS);
        update(&Stream    ,    0,    0,    wS,    hS);
    }
    // 
}Overlay_t;
