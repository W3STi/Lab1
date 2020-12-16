#include "Graphics.h"
#include "Mechanics.h"
#include "Menu.h"
//Нейтрализация мигания
void Blinking(int off = 99) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = off;
	cci.bVisible = false;
	SetConsoleCursorInfo(hCon, &cci);
}
//Выставления цвета и размеров консоли
void sizecolor() {
	system("color 9F");
	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, 1370, 740, TRUE);
	HMENU hm;
	hm = GetSystemMenu(hwnd, FALSE);
	RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hwnd);
}
//main функция
int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	sizecolor();
	Blinking();
	printf("Навигацию по меню осуществляется с помощью стрелок на клавиатуре, нажав Enter, или цифр: 1,2,3,4. Нажмите любую клавишу для перехода в меню...\n");
	_getch();
	menu();
	return 0;
}