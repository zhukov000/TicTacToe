
#include "framework.h"

// Global Variables:
HINSTANCE hInst;											// current instance
WCHAR szTitle[MAX_LOADSTRING] = _T("Tic Tac Toe");			// the title bar text
WCHAR szWindowClass[MAX_LOADSTRING] = _T("TICTACTOE");      // the main window class name

HWND hCreateButton;                                         // handle for CreateButton
HWND hSizeTextBox;                                          // handle for SizeTextBox
HWND** ahGameButton;                                        // handles for game buttons
TTTGame::Game* objGame;                                     // game object

size_t fieldSize;
bool playerFirst;

// Registers the window class
ATOM                MyRegisterClass(HINSTANCE hInstance);
// Saves instance handle and creates main window
BOOL                InitInstance(HINSTANCE, int);
// Processes messages for the main window
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//
LRESULT CALLBACK    onCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
// Processes WM_PAINT message
LRESULT CALLBACK    onPaint(HDC hdc, PAINTSTRUCT &ps);
// Processes WM_CREATE
LRESULT CALLBACK    onInit(HWND hWnd);
// Processes WM_CREATE
LRESULT CALLBACK    onDestroy(HWND hWnd);
// create game buttons
void GameStart(size_t size, HWND hWnd);
// free memory for ahGameButton array
void FreeGameButtons();

// Entry point
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowEx(
        WS_EX_CLIENTEDGE, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, NULL, NULL, hInstance, NULL
    );

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT res = 0;
    switch (message)
    {
    case WM_CREATE: // process the create window
    {
        res = onInit(hWnd);
    }   
    break;
    case WM_COMMAND: //  process the command
    {
        res = onCommand(hWnd, message, wParam, lParam);
    }
    break;
    case WM_PAINT: // process paint the main window
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        res = onPaint(hdc, ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY: // process destroy
        res = onDestroy(hWnd);
        PostQuitMessage(0);
        break;
    default:
        res = DefWindowProc(hWnd, message, wParam, lParam);
    }
    return res;
}

LRESULT CALLBACK onPaint(HDC hdc, PAINTSTRUCT& ps) {

    TextOut(hdc, GREETING_LABEL_POSX, GREETING_LABEL_POSY, _T(GREETING_LABEL_TEXT), GREETING_LABEL_LEN);
    
    return 0;
}

LRESULT CALLBACK onInit(HWND hWnd) {
    hCreateButton = CreateButton(
        _T(CREATE_BUTTON_TEXT), 
        CREATE_BUTTON_POSX, 
        CREATE_BUTTON_POSY, 
        CREATE_BUTTON_WIDTH, 
        CREATE_BUTTON_HEIGHT, 
        hWnd, 
        CREATE_BUTTON_ID,
        CREATE_BUTTON_STYLE
    );

    hSizeTextBox = CreateTextBox(
        _T(SIZE_TEXTBOX_TEXT),
        SIZE_TEXTBOX_POSX, 
        SIZE_TEXTBOX_POSY,
        SIZE_TEXTBOX_WIDTH,
        SIZE_TEXTBOX_HEIGHT,
        hWnd,
        SIZE_TEXTBOX_ID
    );

    fieldSize = 0;
    playerFirst = false;
    ahGameButton = nullptr;
    objGame = nullptr;

    return 0;
}

LRESULT CALLBACK onDestroy(HWND hWnd) {
    FreeGameButtons();
    if (objGame) {
        delete objGame;
    }
    return 0;
}

LRESULT CALLBACK onCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmId = LOWORD(wParam);
    switch (wmId)
    {
    case CREATE_BUTTON_ID: // Create new game
    {
        LPWSTR pMem = GetTextFromTextBox(hSizeTextBox);
        size_t size = _wtoi(pMem);
        VirtualFree(pMem, 0, MEM_RELEASE);

        if (size < 3 || size > 7) {
            ShowError(_T(INVALID_FIELD_SIZE), _T(ERROR_TITLE), hWnd);
        }
        else {
            // Ask who first
            int resultAsk = ShowAsk(_T(ASK_WHO_FIRST), _T(ASK_TITLE), hWnd);
            if (resultAsk == IDYES) {
                // ShowInfo(_T(YOU_FIRST_MOVE), _T(START_TITLE), hWnd);
                playerFirst = true;
            }
            else {
                // ShowInfo(_T(YOU_SECOND_MOVE), _T(START_TITLE), hWnd);
                playerFirst = false;
            }
            GameStart(size, hWnd);
        }
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void GameStart(size_t size, HWND hWnd) {
    FreeGameButtons();
    ahGameButton = new HWND* [size];
    for (size_t i = 0; i < size; ++i) {
        ahGameButton[i] = new HWND[size];
        for (size_t j = 0; j < size; ++j) {
            ahGameButton[i][j] = CreateButton(
                _T(" "),
                GAME_BUTTONS_FIRST_X + j * (GAME_BUTTONS_WIDTH + GAME_BUTTONS_PADDING),
                GAME_BUTTONS_FIRST_Y + i * (GAME_BUTTONS_HEIGHT + GAME_BUTTONS_PADDING),
                GAME_BUTTONS_WIDTH,
                GAME_BUTTONS_HEIGHT,
                hWnd,
                GAME_BUTTONS_FIRST_ID + i * size + j
            );
        }
    }
    fieldSize = size;
}

void FreeGameButtons() {
    if (ahGameButton) {
        for (size_t i = 0; i < fieldSize; ++i) {
            for (size_t j = 0; j < fieldSize; ++j) {
                // destroy control
                DestroyWindow(ahGameButton[i][j]);
            }
            delete[] ahGameButton[i];
        }
        delete[] ahGameButton;
    }
}