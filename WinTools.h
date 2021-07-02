#pragma once

#include <windows.h>
#include <tchar.h>

HWND CreateButton(LPCWSTR lpButtonText, int X, int Y, int width, int height,
    HWND hWndParent = NULL,
    int ButtonId = NULL,
    DWORD dwStyle = WS_VISIBLE | WS_CHILD | BS_FLAT);

HWND CreateTextBox(LPCWSTR lpTextBoxText, int X, int Y, int width, int height,
    HWND hWndParent = NULL,
    int TextBoxId = NULL,
    DWORD dwStyle = WS_VISIBLE | WS_CHILD);
// ES_MULTILINE | WS_VSCROLL | WS_HSCROLL

LPWSTR GetTextFromTextBox(HWND);

int ShowInfo(LPCWSTR, LPCWSTR, HWND hWnd = NULL, UINT uType = MB_OK | MB_ICONINFORMATION);

int ShowError(LPCWSTR, LPCWSTR, HWND hWnd = NULL, UINT uType = MB_OK | MB_ICONERROR);

int ShowAsk(LPCWSTR, LPCWSTR, HWND hWnd = NULL);