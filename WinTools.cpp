#include "WinTools.h"

HWND CreateButton(LPCWSTR lpButtonText, int X, int Y, int width,
    int height, HWND hWndParent, int ButtonId, DWORD dwStyle) {
    return CreateWindowEx(
        WS_EX_CLIENTEDGE, _T("BUTTON"), lpButtonText, dwStyle,
        X, Y, width, height, hWndParent, (HMENU)ButtonId, NULL, NULL
    );
}

HWND CreateTextBox(LPCWSTR lpTextBoxText, int X, int Y, int width,
    int height, HWND hWndParent, int TextBoxId, DWORD dwStyle) {
    return CreateWindowEx(
        WS_EX_CLIENTEDGE, _T("Edit"), lpTextBoxText, dwStyle,
        X, Y, width, height, hWndParent, (HMENU)TextBoxId, NULL, NULL
    );
}

LPWSTR GetTextFromTextBox(HWND hTextBox) {
    LPWSTR pMem;
    int cTextLen = GetWindowTextLength(hTextBox);
    pMem = static_cast<LPWSTR>(VirtualAlloc(
        static_cast<LPVOID>(NULL),
        static_cast<DWORD>(cTextLen + 1),
        MEM_COMMIT, PAGE_READWRITE)
        );

    GetWindowText(hTextBox, pMem, cTextLen + 1);
    return pMem;
}

int ShowInfo(LPCWSTR lpText, LPCWSTR lpCaption, HWND hWnd, UINT uType) {
    return MessageBox(hWnd, lpText, lpCaption, uType);
}

int ShowError(LPCWSTR lpText, LPCWSTR lpCaption, HWND hWnd, UINT uType) {
    return MessageBox(hWnd, lpText, lpCaption, uType);
}

int ShowAsk(LPCWSTR lpText, LPCWSTR lpCaption, HWND hWnd) {
    return MessageBox(hWnd, lpText, lpCaption, MB_YESNO);
}