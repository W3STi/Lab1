#include "Mechanics.h"
#include "Graphics.h"
#include "Menu.h"

//Функция пользовательского меню
void menu() {
	int p = 1, c = 0;
	int x11 = 760, x22 = 780, y11 = 215, y22 = 235;
	int height, width;
	char name[LEN];
	system("cls");
	FILE *file;
	bool stopwatch = 0;//Проверка на то, нужен ли секундомер и ввод никнейма
	graphicsofmenu();
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	//Правая граница
	brush = CreateSolidBrush(RGB(20, 10, 100)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты
	while (TRUE) //навигация по меню
	{
		int prov = 0;
		c = _getch();
		switch (c)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			p = c - '0';
		case KEY_ENTER:
			switch (p)
			{
			case 1:
				Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
				DeleteObject(brush); //Очищаем память от созданной кисти
				while (prov == 0) {
					system("cls");
					Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
					printf("Условия для размеров лабиринта:                              \n");
					printf("1)Длина равна Ширине.                                        \n");
					printf("2)Длина/ширина - нечётные величины на отрезке от 11 до 33    \n");
					printf("Введите длину лабиринта -                                    \n");
					scanf_s("%d", &height);
					printf("Введите ширину лабиринта -                                   \n");
					scanf_s("%d", &width);
					//Проверка значений
					__asm {
						mov eax, height;
						mov ebx, width;
						mov edi, 2;
						cmp eax, 34;
						jge end1;
						cmp eax, 10;
						jle end1;
						mov ecx, eax;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end1;
						cmp ecx, ebx;
						jne end1;

						cmp ebx, 34;
						jge end1;
						cmp ebx, 10;
						jle end1;
						mov eax, ebx;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end1;
						jmp endgood;
					end1:
						mov prov, 0;
						jmp finaly;
					endgood:
						mov prov, 1;
						jmp finaly;
					finaly:;
					}
				}
				DeleteObject(brush); //Очищаем память от созданной кисти
				ReleaseDC(hwnd, dc);
				mazegame(height, width, stopwatch, 0, 0);
				break;
			case 2:
				Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
				DeleteObject(brush); //Очищаем память от созданной кисти
				char name[LEN];
				while (prov == 0) {
					system("cls");
					Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
					printf("Условия для размеров лабиринта:                              \n");
					printf("1)Длина равна Ширине.                                        \n");
					printf("2)Длина/ширина - нечётные величины на отрезке от 11 до 33    \n");
					printf("Введите длину лабиринта -                                    \n");
					scanf_s("%d", &height);
					printf("Введите ширину лабиринта -                                   \n");
					scanf_s("%d", &width);
					__asm {
						mov eax, height;
						mov ebx, width;
						mov edi, 2;
						cmp eax, 34;
						jge end2;
						cmp eax, 10;
						jle end2;
						mov ecx, eax;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end2;
						cmp ecx, ebx;
						jne end2;

						cmp ebx, 34;
						jge end2;
						cmp ebx, 10;
						jle end2;
						mov eax, ebx;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end2;
						jmp endgood2;
					end2:
						mov prov, 0;
						jmp finaly2;
					endgood2:
						mov prov, 1;
						jmp finaly2;
					finaly2:;
					}
				}
				printf("Введите ваше имя (< 15 символов)                             \n");
				scanf("%" STRLEN(LEN) "s", name);
				file = fopen("Результаты.txt", "a");
				fprintf(file, "************************************\n");
				setlocale(LC_ALL, "Rus");
				fprintf(file, "Имя/никнейм - %s \n", name);
				fclose(file);
				DeleteObject(brush); //Очищаем память от созданной кисти
				ReleaseDC(hwnd, dc);
				stopwatch = 1;
				mazegame(height, width, stopwatch, 0, 0);
				break;
			case 3:
				char name1[LEN];
				int lvl;
				while (prov == 0) {
					system("cls");
					Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
					printf("Условия для размеров лабиринта:                              \n");
					printf("1)Длина равна Ширине.                                        \n");
					printf("2)Длина/ширина - нечётные величины на отрезке от 11 до 21    \n");
					printf("Введите длину лабиринта -                                    \n");
					scanf_s("%d", &height);
					printf("Введите ширину лабиринта -                                   \n");
					scanf_s("%d", &width);
					printf("Введите сложность лабиринта лабиринта - '1'. '2' или '3'     \n");
					scanf_s("%d", &lvl);
					__asm {
						mov eax, height;
						mov ebx, width;
						mov edi, 2;
						cmp eax, 22;
						jge end22;
						cmp eax, 10;
						jle end22;
						mov ecx, eax;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end22;
						cmp ecx, ebx;
						jne end22;

						cmp ebx, 22;
						jge end22;
						cmp ebx, 10;
						jle end22;
						mov eax, ebx;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end22;
						jmp egd2;
					end22:
						mov prov, 0;
						jmp fnl2;
					egd2:
						mov prov, 1;
						jmp fnl2;
					fnl2:;
					}
					if (lvl > 3 || lvl < 1) {
						prov = 0;
					}
				}
				printf("Введите ваше имя (< 15 символов)                             \n");
				scanf("%" STRLEN(LEN) "s", name1);
				file = fopen("Результаты.txt", "a");
				fprintf(file, "************************************\n");
				setlocale(LC_ALL, "Rus");
				fprintf(file, "Имя/никнейм - %s \n", name1);
				fclose(file);
				DeleteObject(brush); //Очищаем память от созданной кисти
				ReleaseDC(hwnd, dc);
				stopwatch = 1;
				mazegame(height, width, stopwatch, 1, lvl);
				__asm {
					mov eax, y11;
					mov ebx, y22;
					cmp eax, 215;
					jle endwarning;
					sub eax, 140;
					cmp ebx, 235;
					jle endwarning;
					sub ebx, 140;
					mov y11, eax;
					mov y22, ebx;
				endwarning:;
				}
				break;
			case 4:
				system("cls");
				rules();
				_getch();
				if (_kbhit()) _getch();
				__asm {
					mov eax, y11;
					mov ebx, y22;
					cmp eax, 215;
					jle endw;
					sub eax, 210;
					cmp ebx, 235;
					jle endw;
					sub ebx, 210;
					mov y11, eax;
					mov y22, ebx;
				endw:;
				}
				break;
			case 5:
				system("cls");
				exit(0);
			}
			system("cls");
			graphicsofmenu();
			p = 1;
			break;
		case KEY_UP:
			if (p > 1) {
				brush = CreateSolidBrush(RGB(20, 100, 200)); // Не выбранный элемент
				SelectObject(dc, brush); //Выбираем кисть
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //Очищаем память от созданной кисти
				p--;
				y11 -= 70;
				y22 -= 70;
				brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
				SelectObject(dc, brush); //Выбираем кисть
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //Очищаем память от созданной кисти
			}
			break;
		case KEY_DOWN:
			if (p < 5) {
				brush = CreateSolidBrush(RGB(20, 100, 200)); // Не выбранный элемент
				SelectObject(dc, brush); //Выбираем кисть
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //Очищаем память от созданной кисти
				p++;
				y11 += 70;
				y22 += 70;
				brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
				SelectObject(dc, brush); //Выбираем кисть
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //Очищаем память от созданной кисти
			}
			break;
		}
	}
}