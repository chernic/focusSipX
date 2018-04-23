#pragma once

#include "define.h"
#include "settings.h"

/////////////////////// 屏幕布局
// 左上
#define IN_NAVBAR_L     1
// 右上
#define IN_NAVBAR_R     2
// 左下
#define IN_FOOTER_L     3
// 右下
#define IN_FOOTER_R     4
///////////////////////
#define IN_MENU_T       5
#define IN_MENU_B       6
#define IN_SIDEBAR_T    7
#define IN_SIDEBAR_B    8

// 左上
#define NAVBAR_L        9
// 右上
#define NAVBAR_R        10
// 左下
#define FOOTER_L        11
// 右下
#define FOOTER_R        12
///////////////////////
#define MENU_T          13
#define MENU_B          14
#define SIDEBAR_T       15
#define SIDEBAR_B       16

#define DEFAULT_MODE    IN_NAVBAR_L

typedef double SCT;

typedef struct Layout{
    pjmedia_coord       pos;
    pjmedia_rect_size   siz;
}Layout_t;

struct Overlay{
    int sIsInit;
    int sMode;
    SCT sScale;
    int sWs; // Screen
    int sHs; // Screen
    int sWt; // Thumbnail
    int sHt; // Thumbnail

    pj_bool_t IsStreamShow;
    pj_bool_t IsComplexShow;

    Layout_t Stream;
    Layout_t Complex;
    Layout_t Background;
    Layout_t Foreground;
    Layout_t Button;

    //
    static void update(Layout_t *pLayout, int x, int y, int w, int h){
        pLayout->pos.x=x;
        pLayout->pos.y=y;
        pLayout->siz.w=w;
        pLayout->siz.h=h;
    }

	Overlay();
private:
	void Init();
	void setTwoWinShow(void);
	void setDefaultMode(void);

	void updateThumbnailSize(void);
	void setDefaultShow(void);
	void setDefaultScreen(void);

public:
	pj_status_t setScreen(int w, int h, double s);
	//  默认
    void switchMode(int mode);
    void switch2NavbarL(void);
    void switch2NavbarR(void);
    void switch2FooterL(void);
    void switch2FooterR(void);

    void switchInNavbarL(void);
    void switchInNavbarR(void);
    void switchInFooterL(void);
    void switchInFooterR(void);
};

extern Overlay gOverlay;
