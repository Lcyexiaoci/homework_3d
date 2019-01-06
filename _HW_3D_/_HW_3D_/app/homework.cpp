#include "../app.h"

namespace {
	constexpr int default_width = 800;
	constexpr int default_height = 600;
	constexpr bool full_screen = false;
	constexpr LPCSTR window_title = "homework";

	//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
}

_HW_3D_OPEN_HW_NAMESPACE_

class Homework : public Application {
public:
	Homework();

	~Homework();
	
	Homework(const Homework&) = delete;
	Homework& operator=(const Homework&) = delete;

private:
	_HW_3D_STD_ pair<int, int> initial_window();

private:
	HINSTANCE _hinstance;
	HWND _hwnd;

};

// _HW_3D_REGISTER_DEMO_(Homework, "homework");

_HW_3D_STD_ pair<int, int> Homework::initial_window() {
	_HW_3D_STD_ pair<int, int> res;

	auto&[width, height] = res; 

	_hinstance = GetModuleHandle(NULL);

	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = _hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = window_title;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&wc);


	width = default_width;
	height = default_height;
	int pos_x, pos_y;
	if (full_screen)
	{
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);

		DEVMODE dev_mode;
		memset(&dev_mode, 0, sizeof(dev_mode));
		dev_mode.dmSize = sizeof(dev_mode);
		dev_mode.dmPelsWidth = (unsigned long)width;
		dev_mode.dmPelsHeight = (unsigned long)height;
		dev_mode.dmBitsPerPel = 32;
		dev_mode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dev_mode, CDS_FULLSCREEN);

		pos_x = pos_y = 0;
	}
	else
	{
		pos_x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
		pos_y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	}

	_hwnd = CreateWindowEx(WS_EX_APPWINDOW, window_title, window_title,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		pos_x, pos_y, width, height, NULL, NULL, _hinstance, NULL);

	ShowWindow(_hwnd, SW_SHOW);
	SetForegroundWindow(_hwnd);
	SetFocus(_hwnd);

	return res;
}


_HW_3D_CLOSE_HW_NAMESPACE_