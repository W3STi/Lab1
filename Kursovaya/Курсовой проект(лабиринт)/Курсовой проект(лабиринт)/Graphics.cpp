#include "Graphics.h"
#include "Mechanics.h"
#include "Menu.h"

void rules() {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	brush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты
	Rectangle(dc, 0, 15, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
	dc = GetDC(hwnd);
	static LOGFONT lf;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	lf.lfHeight = 20;
	lf.lfWidth = 10;
	lf.lfItalic = 0;

	lf.lfUnderline = 1;
	lf.lfEscapement = 0;

	HFONT hFont = CreateFontIndirect(&lf);
	SelectObject(dc, hFont);
	SetTextColor(dc, RGB(0, 0, 128));
	SetBkColor(dc, RGB(0, 204, 255));
	TextOut(dc, 490, 50, L"Правила игры лабиринт:", 23);
	TextOut(dc, 180, 100, L"На старте вы находитесь в левом верхнем углу, ваша цель - добраться до финиша(правого нижнего угла)", 100);
	TextOut(dc, 220, 150, L"Управление объектом осуществляется при помощи клавиш: a-влево, s-вниз , d-вправо, w-вверх", 90);
	TextOut(dc, 170, 200, L"1.При старте игры в обычном режиме, вам необходимо ввести размеры лабиринта для дальнейшего прохожения", 103);
	TextOut(dc, 30, 250, L"2.При старте игры в режиме 'со временем', вам необходимо ввести размер лабиринта, ваше имя для записи вашего результата", 120);
	TextOut(dc, 180, 300, L"Сразу после нажатия клавиши Enter запустится таймер. Цель - пройти лабиринт за наименьшее кол-во времени", 105);
	TextOut(dc, 40, 350, L"Также в обоих режимах можно собирать монетки, монетки в режиме 'со временем' непосредственно влияют на рекорд игрока", 117);
	TextOut(dc, 365, 400, L"Чем больше собрано монет, тем престижнее результат", 51);
	TextOut(dc, 300, 450, L"Файл с результатами (Результаты.txt) можно найти в папке с игрой", 65);
	TextOut(dc, 25, 500, L"3.При старте игры в режиме игры с ботом, вам необходимо ввести размеры лабиринта и выбрать сложность прохождения", 113);
	TextOut(dc, 20, 550, L"Также важно проверять раскладку и CAPSLOCK, ведь движение объекта происходит только с нажатием указанных выше клавиш", 117);
	TextOut(dc, 370, 600, L"Нажмите любую клавишу для возвращения в меню...", 48);
	ReleaseDC(hwnd, dc);
	DeleteObject(brush);
	ReleaseDC(hwnd, dc); 
}

void graphicsofmenu() {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания	
	brush = CreateSolidBrush(RGB(20, 100, 200)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //Рисуем новый прямоугольник, который будет небом
	DeleteObject(brush); //Очищаем память от созданной, но уже ненужной кисти
	brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
	SelectObject(dc, brush); //Выбираем кисть
	Ellipse(dc, 760, 215, 780, 235);
	DeleteObject(brush); //Очищаем память от созданной кисти
	brush = CreateSolidBrush(RGB(20, 100, 200)); // Не выбранный элемент
	SelectObject(dc, brush); //Выбираем кисть
	Ellipse(dc, 760, 285, 780, 305);
	Ellipse(dc, 760, 355, 780, 375);
	Ellipse(dc, 760, 425, 780, 445);
	Ellipse(dc, 760, 495, 780, 515);
	DeleteObject(brush); //Очищаем память от созданной кисти

	static LOGFONT lf1;
	lf1.lfCharSet = DEFAULT_CHARSET;
	lf1.lfPitchAndFamily = DEFAULT_PITCH;
	lf1.lfHeight = 50;
	lf1.lfWidth = 15;
	lf1.lfItalic = 1;
	lf1.lfUnderline = 0;
	lf1.lfEscapement = 0;
	HFONT hFont1 = CreateFontIndirect(&lf1);
	SelectObject(dc, hFont1);
	SetTextColor(dc, RGB(0, 0, 70));
	SetBkColor(dc, RGB(0, 204, 255));
	TextOut(dc, 530, 200, L"Обычная игра", strlen("Обычная игра"));
	TextOut(dc, 527, 270, L"Игра на время", strlen("Игра на время"));
	TextOut(dc, 530, 340, L"Игра c ботом", strlen("Игра c ботом"));
	TextOut(dc, 570, 410, L"Правила", strlen("Правила"));
	TextOut(dc, 587, 480, L"Выход", strlen("Выход"));
	DeleteObject(hFont1);

	static LOGFONT lf;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	lf.lfHeight = 70;
	lf.lfWidth = 30;
	lf.lfItalic = 0;
	lf.lfUnderline = 1;
	lf.lfEscapement = 0;
	HFONT hFont = CreateFontIndirect(&lf);
	SelectObject(dc, hFont);
	SetTextColor(dc, RGB(128, 0, 0));
	SetBkColor(dc, RGB(0, 204, 255));
	TextOut(dc, 360, 50, L"ИГРА ЛАБИРИНТ", strlen("Игра ЛАБИРИНТ"));
	//Путь
	brush = CreateSolidBrush(RGB(255, 189, 187));
	SelectObject(dc, brush); 
	Rectangle(dc, 310, 50, 330, 70);
	Rectangle(dc, 945, 50, 965, 70); 
	DeleteObject(brush); 
	//Объект
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); 
	Rectangle(dc, 330, 50, 350, 70); 
	Rectangle(dc, 925, 50, 945, 70); 
	DeleteObject(brush); 
	//Стена
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); 
	Rectangle(dc, 310, 70, 330, 90);
	Rectangle(dc, 945, 70, 965, 90); 
	DeleteObject(brush); 
	//Финиш
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); 
	Rectangle(dc, 330, 70, 350, 90); 
	Rectangle(dc, 925, 70, 945, 90); 
	DeleteObject(brush); 
	DeleteObject(hFont);
	ReleaseDC(hwnd, dc); 
}

void dynamic_array_print(int** maze, int height, int width, bool stopwatch) {
	system("cls");
	int x1 = 450, y1 = 30, x2 = 470, y2 = 50;
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	//Правая граница
	brush = CreateSolidBrush(RGB(255, 189, 187)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты
	Rectangle(dc, 400, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	//Левая граница
	brush = CreateSolidBrush(RGB(0, 178, 228));
	SelectObject(dc, brush); 
	Rectangle(dc, 10, 0, 402, WinCoord.bottom); 
	DeleteObject(brush); 
	//Первое поле
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush); 
	Rectangle(dc, 90, 70, 270, 130); 
	DeleteObject(brush); 
	//Второе поле
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush); 
	Rectangle(dc, 40, 200, 330, 270); 
	DeleteObject(brush); 
	//Третье поле
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush); 
	Rectangle(dc, 30, 580, 370, 650); 
	DeleteObject(brush); 
	//Путь
	brush = CreateSolidBrush(RGB(255, 189, 187));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 420, 70, 440); 
	DeleteObject(brush); 
	//Объект
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 460, 70, 480); 
	DeleteObject(brush); 
	//Стена
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 500, 70, 520); 
	DeleteObject(brush); 
	//Финиш
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 540, 70, 560);
	DeleteObject(brush);
	//Монетки
	brush = CreateSolidBrush(RGB(20, 100, 200)); // Не выбранный элемент
	SelectObject(dc, brush); 
	Ellipse(dc, 130, 360, 150, 380);
	Ellipse(dc, 170, 360, 190, 380);
	Ellipse(dc, 210, 360, 230, 380);
	DeleteObject(brush); 

	static LOGFONT lf;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	lf.lfHeight = 30;
	lf.lfWidth = 10;
	lf.lfItalic = 1;
	lf.lfUnderline = 0;
	lf.lfEscapement = 0;
	HFONT hFont = CreateFontIndirect(&lf);
	SelectObject(dc, hFont);
	SetTextColor(dc, RGB(0, 0, 255));
	SetBkColor(dc, RGB(59, 255, 251));
	TextOut(dc, 93, 30, L"Состояние игры", strlen("Состояние игры"));
	TextOut(dc, 80, 160, L"Состояние таймера", strlen("Состояние таймера"));
	TextOut(dc, 80, 300, L"Собранные монетки", strlen("Собранные монетки"));
	DeleteObject(hFont); //выгрузим из памяти объект шрифта

	static LOGFONT lf1;
	lf1.lfCharSet = DEFAULT_CHARSET;
	lf1.lfPitchAndFamily = DEFAULT_PITCH;
	lf1.lfHeight = 20;
	lf1.lfWidth = 10;
	lf1.lfItalic = 0;
	HFONT hFont1 = CreateFontIndirect(&lf1);
	SelectObject(dc, hFont1);
	SetTextColor(dc, RGB(0, 0, 0));
	SetBkColor(dc, RGB(59, 255, 251));
	TextOut(dc, 105, 90, L"Прохождение...", strlen("Прохождение..."));
	if (stopwatch == 0) {
		TextOut(dc, 115, 225, L"Без таймера", strlen("Без таймера"));
	}
	else TextOut(dc, 90, 225, L"Таймер запущен!", strlen("Таймер запущен!"));
	TextOut(dc, 80, 421, L"- Путь ", strlen("- Путь "));
	TextOut(dc, 80, 461, L"- Объект ", strlen("- Объект "));
	TextOut(dc, 80, 501, L"- Стена ", strlen("- Стена "));
	TextOut(dc, 80, 541, L"- Финиш ", strlen("- Финиш "));
	TextOut(dc, 100, 595, L"Нажмите 'Пробел'", strlen("Нажмите 'Пробел'"));
	TextOut(dc, 75, 615, L"Чтобы вернуться в меню", strlen("Чтобы вернуться в меню"));
	DeleteObject(hFont1); //выгрузим из памяти объект шрифта
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			switch (maze[i][j]) {
			case wall:
				brush = CreateSolidBrush(RGB(105, 105, 105));
				SelectObject(dc, brush); //Выбираем кисть
				Rectangle(dc, x1, y1, x2, y2); //Нарисовали прямоугольник, закрашенный неким стилем
				DeleteObject(brush); //Очищаем память от созданной кисти
				x1 += 20;
				x2 += 20;
				break;
			case pass:
				x1 += 20;
				x2 += 20;
				break;
			case coin:
				brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
				SelectObject(dc, brush); //Выбираем кисть
				Ellipse(dc, x1, y1, x2, y2);
				DeleteObject(brush); //Очищаем память от созданной кисти
				x1 += 20;
				x2 += 20;
			}
		}
		x1 -= (width) * 20;
		x2 -= (width) * 20;
		y1 += 20;
		y2 += 20;
	}
	//Объект
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 430, 50, 450, 70); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	//Дорисовка
	RECT r;
	r.left = 450 + (width - 1) * 20;
	r.top = 30;
	r.right = 470 + (width - 1) * 20;
	r.bottom = 50;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	//Дорисовка
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 430, 30, 450, 50); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	//Финиш
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 430 + (width - 1) * 20, 30 + (height - 2) * 20, 450 + (width - 1) * 20, 50 + (height - 2) * 20); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	ReleaseDC(hwnd, dc);
}

void dynamic_array_bot(int** maze, int height, int width, bool stopwatch){
	system("cls");
	int x1 = 400, y1 = 30, x2 = 420, y2 = 50;
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	//Правая граница
	brush = CreateSolidBrush(RGB(255, 189, 187)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты
	Rectangle(dc, 828, 0, WinCoord.right, WinCoord.bottom); //Нарисовали прямоугольник, закрашенный неким стилем
	//Средняя граница
	brush = CreateSolidBrush(RGB(255, 189, 187)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 348, 0, 830, WinCoord.bottom);
	DeleteObject(brush); //Очищаем память от созданной кисти
	//Нижняя граница
	brush = CreateSolidBrush(RGB(0, 178, 228));
	SelectObject(dc, brush);
	Rectangle(dc, 348, 500, WinCoord.right, WinCoord.bottom);
	DeleteObject(brush);
	//Левая граница
	brush = CreateSolidBrush(RGB(0, 178, 228));
	SelectObject(dc, brush);
	Rectangle(dc, 10, 0, 350, WinCoord.bottom);
	DeleteObject(brush);
	//Первое поле
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush);
	Rectangle(dc, 90, 70, 270, 130);
	DeleteObject(brush);
	//Второе поле
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush);
	Rectangle(dc, 40, 200, 330, 270);
	DeleteObject(brush);
	//Третье поле
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush);
	Rectangle(dc, 40, 295, 330, 365);
	DeleteObject(brush);
	//Путь
	brush = CreateSolidBrush(RGB(255, 189, 187));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 380, 70, 400);
	DeleteObject(brush);
	//Бот
	brush = CreateSolidBrush(RGB(3, 0, 189));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 420, 70, 440);
	DeleteObject(brush);
	//Объект
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 460, 70, 480);
	DeleteObject(brush);
	//Стена
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 500, 70, 520);
	DeleteObject(brush);
	//Финиш
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 540, 70, 560);
	DeleteObject(brush);

	static LOGFONT lf;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	lf.lfHeight = 30;
	lf.lfWidth = 10;
	lf.lfItalic = 1;
	lf.lfUnderline = 0;
	lf.lfEscapement = 0;
	HFONT hFont = CreateFontIndirect(&lf);
	SelectObject(dc, hFont);
	SetTextColor(dc, RGB(0, 0, 255));
	SetBkColor(dc, RGB(59, 255, 251));
	TextOut(dc, 93, 30, L"Состояние игры", strlen("Состояние игры"));
	TextOut(dc, 80, 160, L"Состояние таймера", strlen("Состояние таймера"));
	DeleteObject(hFont); //выгрузим из памяти объект шрифта

	static LOGFONT lf1;
	lf1.lfCharSet = DEFAULT_CHARSET;
	lf1.lfPitchAndFamily = DEFAULT_PITCH;
	lf1.lfHeight = 20;
	lf1.lfWidth = 10;
	lf1.lfItalic = 0;
	HFONT hFont1 = CreateFontIndirect(&lf1);
	SelectObject(dc, hFont1);
	SetTextColor(dc, RGB(0, 0, 0));
	SetBkColor(dc, RGB(59, 255, 251));
	TextOut(dc, 105, 90, L"Прохождение...", strlen("Прохождение..."));
	if (stopwatch == 0) {
		TextOut(dc, 115, 225, L"Без таймера", strlen("Без таймера"));
	}
	else TextOut(dc, 90, 225, L"Таймер запущен!", strlen("Таймер запущен!"));
	TextOut(dc, 80, 381, L"- Путь ", strlen("- Путь "));
	TextOut(dc, 80, 421, L"- Бот ", strlen("- Бот "));
	TextOut(dc, 80, 461, L"- Объект ", strlen("- Объект "));
	TextOut(dc, 80, 501, L"- Стена ", strlen("- Стена "));
	TextOut(dc, 80, 541, L"- Финиш ", strlen("- Финиш "));
	TextOut(dc, 90, 310, L"Нажмите 'Пробел'", strlen("Нажмите 'Пробел'"));
	TextOut(dc, 60, 330, L"Чтобы вернуться в меню", strlen("Чтобы вернуться в меню"));
	DeleteObject(hFont1); //выгрузим из памяти объект шрифта
	for (int k = 0; k < height; k++) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				switch (maze[i][j]) {
				case wall:
					brush = CreateSolidBrush(RGB(105, 105, 105));
					SelectObject(dc, brush); //Выбираем кисть
					Rectangle(dc, x1, y1, x2, y2); //Нарисовали прямоугольник, закрашенный неким стилем
					DeleteObject(brush); //Очищаем память от созданной кисти
					x1 += 20;
					x2 += 20;
					break;
				case pass:
					x1 += 20;
					x2 += 20;
					break;
				}
			}
			x1 -= (width) * 20;
			x2 -= (width) * 20;
			y1 += 20;
			y2 += 20;
		}
		x1 = 900;
		y1 = 30;
		x2 = 920;
		y2 = 50;
	}
	//Объект
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 380, 50, 400, 70); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	//Дорисовка
	RECT r;
	r.left = 400 + (width - 1) * 20;
	r.top = 30;
	r.right = 420 + (width - 1) * 20;
	r.bottom = 50;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	RECT r1;
	r1.left = 900 + (width - 1) * 20;
	r1.top = 30;
	r1.right = 920 + (width - 1) * 20;
	r1.bottom = 50;
	FillRect(dc, &r1, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	r1.left = 880;
	r1.top = 30;
	r1.right = 900;
	r1.bottom = 50;
	FillRect(dc, &r1, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	//Дорисовка
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 380, 30, 400, 50);
	Rectangle(dc, 880, 30, 900, 50);//Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	//Финиш
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 380 + (width - 1) * 20, 30 + (height - 2) * 20, 400 + (width - 1) * 20, 50 + (height - 2) * 20); //Нарисовали прямоугольник, закрашенный неким стилем
	Rectangle(dc, 880 + (width - 1) * 20, 30 + (height - 2) * 20, 900 + (width - 1) * 20, 50 + (height - 2) * 20);
	DeleteObject(brush); //Очищаем память от созданной кисти
	ReleaseDC(hwnd, dc);
}