# Tic tac toe - game with artificial intelligence (AI)

### Language: C++ (WinAPI)
### IDLE: Visual studio 2019

## AI logic
TicTacToeAI, RandomAI, GreadyAI, MinimaxAI - different AI strategies:
1) RandomAI - every move is random
2) GreadyAI - gready logic - choose the first available move from the following list:
* Win: If the player has two in a row, they can place a third to get three in a row.
* Block: If the opponent has two in a row, the player must play the third themselves to block the opponent.
* Fork: Create an opportunity where the player has two ways to win (two non-blocked lines of 2).
* Blocking an opponent's fork: If there is only one possible fork for the opponent, the player should block it. 
	 Otherwise, the player should block all forks in any way that simultaneously allows them to create 
	 two in a row. 
* Center: A player marks the center. (If it is the first move of the game, playing a corner move gives the second player more opportunities to make a mistake and may therefore be the better choice; however, it makes no difference between perfect players.)
* Opposite corner: If the opponent is in the corner, the player plays the opposite corner.
* Empty corner: The player plays in a corner square.
* Random empty cell
3) MinimaxAI - full bruteforce (work only for 3x3 field). Build the decision tree with using recursion. Every list got the value: 1 - AI win, 0 - tie, -1 - the player win. For other nodes: if the player's turn then choose min value from children nodes else choose max value. 

## Other files:
* Main - the main window
* Game - the main class for game that stores the game-field and implements main logic
* GameBasic - static class that implements check of the end of the game
* Tools - generate random numbers
* WinTools - helper methods for creating windows

Demo-video: https://www.youtube.com/watch?v=QwJ37IXjeg4

# Программная реализация игры "Крестики-нолики"

### Язык: C++ (WinAPI)
### IDLE: Visual studio 2019

## Логика ИИ
TicTacToeAI, RandomAI, GreadyAI, MinimaxAI - классы, реализующие различные стратегии ИИ:
1) RandomAI - каждый ход случайный
2) GreadyAI - жадная стратегия, в которой следующий ход компьютера выбирается как первый подходящий ход в свободную клетку из следующего списка:
* ход, которым можно победить (win)
* ход, которым может победить игрок (block)
* ход, которым можно сделать "вилку" (fork)
* ход блокирующий возможность (если она есть) игроку сделать "вилку" (block fork)
* ход в свободную клетку в центре поля
* ход в угол, напротив клетки, занятой игроком
* ход в свободный угол
* ход в свободную клетку (случайную)
3) MinimaxAI - полный перебор методом минимакса (работает только для поля размера 3x3). Строим дерево решений с помощью рекурсивного перебора. Каждому листу дерева назначаем одно из чисел (1 - победа ИИ, 0 - ничья, -1 - победа игрока). Заполняем узлы дерева: если сейчас ход компьютера, то выбираем максимальное из уже посчитаных потомков, если ход игрока, то выбираем минимальное значение.

## Другие файлы
* Main.cpp - главное окно программы
* Game - класс, реализующий основные методы игры и хранящий состояние игрового поля
* GameBasic - статический класс, реализующий методы проверки того, что игра окончена
* Tools - содержит методы для генерации случайных чисел
* WinTools - методы для генерации объектов на форме и получения значений

Демо-видео: https://www.youtube.com/watch?v=QwJ37IXjeg4
