#include <iostream>
#include <stdio.h>
#include <windows.h>
extern "C" void _fastcall asm_func(const char* lpText);

void Scrglitch() {
    HMONITOR monitor = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTONEAREST);
    MONITORINFO info;
    info.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitor, &info);
    for (int i = 0; i < 1000; i++) {
        int w = info.rcMonitor.right - info.rcMonitor.left;
        int h = info.rcMonitor.bottom - info.rcMonitor.top;
        int x1 = rand() % (w - 400);
        int y1 = rand() % (h - 400);
        int x2 = rand() % (w - 400);
        int y2 = rand() % (h - 400);
        int width = rand() % 400;
        int height = rand() % 400;
        HDC hdc = GetDC(NULL);

        BitBlt(hdc, x1, y1, width, height, hdc, x2, y2, SRCCOPY);
    }
}
void BRUH() {
    for (int i = 0; i < 100000000; i++) {

        GetDC(NULL);
        HMONITOR monitor = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTONEAREST);
        MONITORINFO info;
        info.cbSize = sizeof(MONITORINFO);
        GetMonitorInfo(monitor, &info);
        int w = info.rcMonitor.right - info.rcMonitor.left;
        int h = info.rcMonitor.bottom - info.rcMonitor.top;
        HDC hdc = GetDC(NULL);
        StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);









    }
}
void what() {
    for (int i = 0; i < 1000000; i++) {
        HDC hdc = GetDC(NULL);
        POINT point;
        GetCursorPos(&point);
        int ix = GetSystemMetrics(SM_CXICON) / 2;
        int iy = GetSystemMetrics(SM_CYICON) / 2;

        DrawIcon(hdc, point.x - ix, point.y - iy, LoadIcon(NULL, IDI_ERROR));
    }
}
    int main() {
    
    asm_func("ENEMIES");
    BRUH();
    what();
    
}




extern "C" UINT GetMessageBoxType() {
	return MB_YESNO | MB_ICONERROR;
}