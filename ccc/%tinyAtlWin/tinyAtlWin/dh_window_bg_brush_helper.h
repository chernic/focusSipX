#ifndef __DH_WINDOW_BG_BRUSH_HELPER
#define __DH_WINDOW_BG_BRUSH_HELPER

#include <Windows.h>
#include <map>

class DhWindowBgBrushHelper
{
	public:
		DhWindowBgBrushHelper();
		~DhWindowBgBrushHelper();

		void AddSubWindow(HWND hwnd,HBITMAP parent_background);
		HBRUSH GetHBRUSH(HWND hwnd);
	private:
		std::map<HWND,HBRUSH> hbrush;
};

#endif