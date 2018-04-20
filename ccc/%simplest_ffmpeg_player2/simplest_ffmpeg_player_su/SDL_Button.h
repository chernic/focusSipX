#ifndef __SDL_BUTTON_H_
#define __SDL_BUTTON_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "global.h"

typedef enum BTUUON_CHECK_STATE{
  BTUUON_UNCHECKED=0,
  BTUUON_CHECKED=1,
}euBtnStste;

typedef struct BtnRect{
  SDL_Rect mouseover[2];
  SDL_Rect mouseout[2];
  SDL_Rect mousedown[2];
  SDL_Rect mouseup[2];
}BtnRect_t;

// SDL_Button ��    ��װ�˰�����λ�úʹ�С��Ϣ
// ����(Texture)    ĳ֡ʱĳ����ʾЧ��
// ��Ⱦ��(Renderer) �Կ��е�Ԫ����ĳ����ʾЧ�����ϣ�����Ƶ��ͼƬ��
class SDL_Button {
  private:
    SDL_BlendMode blendMode;        // ����ģʽ����
    euBtnStste    isChecked;
  public:
    BtnRect_t     btnRect;
    SDL_Rect      srcR1;            // Texture  ����(����) �߿�
    SDL_Rect      *srcR;            // Texture  ����(����) �߿�
    SDL_Rect      destR;            // Renderer ����(��Ⱦ��)�߿�

    //mTextureBtn=>mRenderer=>mWindow
    //SDL_Window    *mWindow;       // ��Ļ����
    //SDL_Renderer  *mRenderer;     // ��Ⱦ�� ���Surface
    SDL_Texture   *mTextureBtn;     // ����(��ť)

    ~SDL_Button();
    SDL_Button();
    /// ���Ƕ���ť��λ��
    void Init(SDL_Rect destr);
    void Init(int x, int y, int w, int h);

    /// setBtnRect ���Ƕ���ť����ͼƬ�ķָ�λ��
    void setBtnMouseoverRect  (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);
    void setBtnMouseoutRect   (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);
    void setBtnMousedownRect  (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);
    void setBtnMouseupRect    (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);

    /// ����button���¼���Ӧ����
    void  Handle_event(SDL_Renderer *renderer, SDL_Event event, int *done);
    int   Load(SDL_Renderer *renderer, const char *file);
    int   Show(SDL_Renderer *renderer);
};

#endif // __SDL_BUTTON_H_