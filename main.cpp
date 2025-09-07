#include <windows.h>
#include <cwchar>
#include "SourceFile.h"
#include "Project.h"
#include <iostream>

Project project = Project("Projekt_1");



int counter;
void drawTitle(HDC hdc, HWND hwnd, const wchar_t* _text) {
	RECT rect;
	GetClientRect(hwnd, &rect);

	SIZE sz;
	GetTextExtentPoint(hdc, _text, wcslen(_text), &sz);

	int x = (rect.right - sz.cx) / 2;
	int y = (rect.bottom - sz.cy) / 2;


	TextOut(hdc, x, y, _text, wcslen(_text));
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SIZE:
		InvalidateRect(hwnd, nullptr, TRUE);
		break;
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		counter++;

		wchar_t title[64];
		std::swprintf(title, 64, L"WM_PAINT Counter: %d", counter);
		SetWindowTextW(hwnd, title);

		drawTitle(hdc, hwnd, L"Hallo");


		EndPaint(hwnd, &ps);
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
	counter = 0;

	project.printProjectData();

	WNDCLASSEX wc = { };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WinProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"mainWindowClass";
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClassEx(&wc)) {
		MessageBox(nullptr, L"Fensterklasse konnte nicht registriert werden!", L"Fehler", MB_ICONERROR);
		return 0;
	}
	/*else {
		MessageBox(nullptr, L"Fensterklasse ist registriert worden!", L"Info", MB_ICONINFORMATION);
	}*/

	HWND hwnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		L"Hauptmenu",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800,600,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (!hwnd) {
		DWORD err = GetLastError();
		wchar_t buf[256];
		wsprintf(buf, L"Fenster konnte nicht erstellt werden! Fehlercode: %lu", err);
		MessageBox(nullptr, buf, L"Fehler", MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}