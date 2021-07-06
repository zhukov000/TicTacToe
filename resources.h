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
// ComboBox 
/////////////////////////////////////////////////////////////
#define AI_SELECT_ID			103
#define AI_SELECT_X				300
#define AI_SELECT_Y				60
#define AI_SELECT_WIDTH			150
#define AI_SELECT_HEIGHT		200

#define AI_RANDOM_ID			0
#define AI_RANDOM_STR			"Случайный"
#define AI_GREADY_ID			1
#define AI_GREADY_STR			"Жадный"
#define AI_MINIMAX_ID			2
#define AI_MINIMAX_STR			"Минимакс"


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
// Game results
/////////////////////////////////////////////////////////////
#define GAME_RESAULT_TITLE		"Результаты игры"
#define GAME_RESAULT_WIN		"Поздравляем! Вы победили!"
#define GAME_RESAULT_LOST		"Компьютер победил. Возможно, в следующий раз вам повезет"
#define GAME_RESAULT_TIE		"Игра окончена. Ничья"

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

#define ATTENTION_TITLE			"Предупреждение"
#define ATTENTION_MINIMAX		"Метод минимакса можно использовать только для игры 3x3. Для большей размерности используйте другие алгоритмы"

#define RANDOM_ID				0
#define GREADY_ID				1
#define MINIMAX_ID				2

#define MIN_FIELD_SIZE			3
#define MAX_FIELD_SIZE_MM		3
#define MAX_FIELD_SIZE			7

