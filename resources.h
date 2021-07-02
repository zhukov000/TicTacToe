#pragma once

/////////////////////////////////////////////////////////////
// Main window
/////////////////////////////////////////////////////////////
#define MAIN_WINDOW_WIDTH		500
#define MAIN_WINDOW_HEIGHT		400

/////////////////////////////////////////////////////////////
// CreateButton 
/////////////////////////////////////////////////////////////
#define CREATE_BUTTON_ID		101
#define CREATE_BUTTON_TEXT		"Создать"
#define CREATE_BUTTON_POSX		350
#define CREATE_BUTTON_POSY		17
#define CREATE_BUTTON_WIDTH		100
#define CREATE_BUTTON_HEIGHT	25
#define CREATE_BUTTON_STYLE		(WS_VISIBLE | WS_CHILD)

/////////////////////////////////////////////////////////////
// SizeTextBox
/////////////////////////////////////////////////////////////
#define SIZE_TEXTBOX_ID			102
#define SIZE_TEXTBOX_TEXT		"3"
#define SIZE_TEXTBOX_POSX		300
#define SIZE_TEXTBOX_POSY		17
#define SIZE_TEXTBOX_WIDTH		25
#define SIZE_TEXTBOX_HEIGHT		25

/////////////////////////////////////////////////////////////
// GreetingLabel
/////////////////////////////////////////////////////////////
#define GREETING_LABEL_TEXT		"Введите размер игрового поля [3, 7]:"
#define GREETING_LABEL_LEN		36
#define GREETING_LABEL_POSX		10		
#define GREETING_LABEL_POSY		20

/////////////////////////////////////////////////////////////
// Game buttons
/////////////////////////////////////////////////////////////
#define GAME_BUTTONS_FIRST_ID	200
#define GAME_BUTTONS_FIRST_X	20
#define GAME_BUTTONS_FIRST_Y	60
#define GAME_BUTTONS_WIDTH		25
#define GAME_BUTTONS_HEIGHT		25
#define GAME_BUTTONS_PADDING	10

/////////////////////////////////////////////////////////////
// Common
/////////////////////////////////////////////////////////////
#define MAX_LOADSTRING			100
#define ERROR_TITLE				"Произошла ошибка"
#define INVALID_FIELD_SIZE		"Недопустимый размер игорового поля"
#define ASK_WHO_FIRST			"Вы согласны ходить первым?"
#define ASK_TITLE				"Вопрос"
#define START_TITLE				"Начало игры"
#define	YOU_FIRST_MOVE			"Ваш ход первый"
#define	YOU_SECOND_MOVE			"Вы ходите вторым"
