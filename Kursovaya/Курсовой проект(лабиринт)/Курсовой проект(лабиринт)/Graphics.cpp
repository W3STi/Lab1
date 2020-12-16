#include "Graphics.h"
#include "Mechanics.h"
#include "Menu.h"

void rules() {
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	brush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	RECT WinCoord = {}; //������ ��������� ���� 
	GetWindowRect(hwnd, &WinCoord); //����� ����������
	Rectangle(dc, 0, 15, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
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
	TextOut(dc, 490, 50, L"������� ���� ��������:", 23);
	TextOut(dc, 180, 100, L"�� ������ �� ���������� � ����� ������� ����, ���� ���� - ��������� �� ������(������� ������� ����)", 100);
	TextOut(dc, 220, 150, L"���������� �������� �������������� ��� ������ ������: a-�����, s-���� , d-������, w-�����", 90);
	TextOut(dc, 170, 200, L"1.��� ������ ���� � ������� ������, ��� ���������� ������ ������� ��������� ��� ����������� ����������", 103);
	TextOut(dc, 30, 250, L"2.��� ������ ���� � ������ '�� ��������', ��� ���������� ������ ������ ���������, ���� ��� ��� ������ ������ ����������", 120);
	TextOut(dc, 180, 300, L"����� ����� ������� ������� Enter ���������� ������. ���� - ������ �������� �� ���������� ���-�� �������", 105);
	TextOut(dc, 40, 350, L"����� � ����� ������� ����� �������� �������, ������� � ������ '�� ��������' ��������������� ������ �� ������ ������", 117);
	TextOut(dc, 365, 400, L"��� ������ ������� �����, ��� ���������� ���������", 51);
	TextOut(dc, 300, 450, L"���� � ������������ (����������.txt) ����� ����� � ����� � �����", 65);
	TextOut(dc, 25, 500, L"3.��� ������ ���� � ������ ���� � �����, ��� ���������� ������ ������� ��������� � ������� ��������� �����������", 113);
	TextOut(dc, 20, 550, L"����� ����� ��������� ��������� � CAPSLOCK, ���� �������� ������� ���������� ������ � �������� ��������� ���� ������", 117);
	TextOut(dc, 370, 600, L"������� ����� ������� ��� ����������� � ����...", 48);
	ReleaseDC(hwnd, dc);
	DeleteObject(brush);
	ReleaseDC(hwnd, dc); 
}

void graphicsofmenu() {
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������	
	brush = CreateSolidBrush(RGB(20, 100, 200)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	RECT WinCoord = {}; //������ ��������� ���� 
	GetWindowRect(hwnd, &WinCoord); //����� ����������
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //������ ����� �������������, ������� ����� �����
	DeleteObject(brush); //������� ������ �� ���������, �� ��� �������� �����
	brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
	SelectObject(dc, brush); //�������� �����
	Ellipse(dc, 760, 215, 780, 235);
	DeleteObject(brush); //������� ������ �� ��������� �����
	brush = CreateSolidBrush(RGB(20, 100, 200)); // �� ��������� �������
	SelectObject(dc, brush); //�������� �����
	Ellipse(dc, 760, 285, 780, 305);
	Ellipse(dc, 760, 355, 780, 375);
	Ellipse(dc, 760, 425, 780, 445);
	Ellipse(dc, 760, 495, 780, 515);
	DeleteObject(brush); //������� ������ �� ��������� �����

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
	TextOut(dc, 530, 200, L"������� ����", strlen("������� ����"));
	TextOut(dc, 527, 270, L"���� �� �����", strlen("���� �� �����"));
	TextOut(dc, 530, 340, L"���� c �����", strlen("���� c �����"));
	TextOut(dc, 570, 410, L"�������", strlen("�������"));
	TextOut(dc, 587, 480, L"�����", strlen("�����"));
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
	TextOut(dc, 360, 50, L"���� ��������", strlen("���� ��������"));
	//����
	brush = CreateSolidBrush(RGB(255, 189, 187));
	SelectObject(dc, brush); 
	Rectangle(dc, 310, 50, 330, 70);
	Rectangle(dc, 945, 50, 965, 70); 
	DeleteObject(brush); 
	//������
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); 
	Rectangle(dc, 330, 50, 350, 70); 
	Rectangle(dc, 925, 50, 945, 70); 
	DeleteObject(brush); 
	//�����
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); 
	Rectangle(dc, 310, 70, 330, 90);
	Rectangle(dc, 945, 70, 965, 90); 
	DeleteObject(brush); 
	//�����
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
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	//������ �������
	brush = CreateSolidBrush(RGB(255, 189, 187)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	RECT WinCoord = {}; //������ ��������� ���� 
	GetWindowRect(hwnd, &WinCoord); //����� ����������
	Rectangle(dc, 400, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
	//����� �������
	brush = CreateSolidBrush(RGB(0, 178, 228));
	SelectObject(dc, brush); 
	Rectangle(dc, 10, 0, 402, WinCoord.bottom); 
	DeleteObject(brush); 
	//������ ����
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush); 
	Rectangle(dc, 90, 70, 270, 130); 
	DeleteObject(brush); 
	//������ ����
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush); 
	Rectangle(dc, 40, 200, 330, 270); 
	DeleteObject(brush); 
	//������ ����
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush); 
	Rectangle(dc, 30, 580, 370, 650); 
	DeleteObject(brush); 
	//����
	brush = CreateSolidBrush(RGB(255, 189, 187));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 420, 70, 440); 
	DeleteObject(brush); 
	//������
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 460, 70, 480); 
	DeleteObject(brush); 
	//�����
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 500, 70, 520); 
	DeleteObject(brush); 
	//�����
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); 
	Rectangle(dc, 50, 540, 70, 560);
	DeleteObject(brush);
	//�������
	brush = CreateSolidBrush(RGB(20, 100, 200)); // �� ��������� �������
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
	TextOut(dc, 93, 30, L"��������� ����", strlen("��������� ����"));
	TextOut(dc, 80, 160, L"��������� �������", strlen("��������� �������"));
	TextOut(dc, 80, 300, L"��������� �������", strlen("��������� �������"));
	DeleteObject(hFont); //�������� �� ������ ������ ������

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
	TextOut(dc, 105, 90, L"�����������...", strlen("�����������..."));
	if (stopwatch == 0) {
		TextOut(dc, 115, 225, L"��� �������", strlen("��� �������"));
	}
	else TextOut(dc, 90, 225, L"������ �������!", strlen("������ �������!"));
	TextOut(dc, 80, 421, L"- ���� ", strlen("- ���� "));
	TextOut(dc, 80, 461, L"- ������ ", strlen("- ������ "));
	TextOut(dc, 80, 501, L"- ����� ", strlen("- ����� "));
	TextOut(dc, 80, 541, L"- ����� ", strlen("- ����� "));
	TextOut(dc, 100, 595, L"������� '������'", strlen("������� '������'"));
	TextOut(dc, 75, 615, L"����� ��������� � ����", strlen("����� ��������� � ����"));
	DeleteObject(hFont1); //�������� �� ������ ������ ������
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			switch (maze[i][j]) {
			case wall:
				brush = CreateSolidBrush(RGB(105, 105, 105));
				SelectObject(dc, brush); //�������� �����
				Rectangle(dc, x1, y1, x2, y2); //���������� �������������, ����������� ����� ������
				DeleteObject(brush); //������� ������ �� ��������� �����
				x1 += 20;
				x2 += 20;
				break;
			case pass:
				x1 += 20;
				x2 += 20;
				break;
			case coin:
				brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
				SelectObject(dc, brush); //�������� �����
				Ellipse(dc, x1, y1, x2, y2);
				DeleteObject(brush); //������� ������ �� ��������� �����
				x1 += 20;
				x2 += 20;
			}
		}
		x1 -= (width) * 20;
		x2 -= (width) * 20;
		y1 += 20;
		y2 += 20;
	}
	//������
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 430, 50, 450, 70); //���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
	//���������
	RECT r;
	r.left = 450 + (width - 1) * 20;
	r.top = 30;
	r.right = 470 + (width - 1) * 20;
	r.bottom = 50;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	//���������
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 430, 30, 450, 50); //���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
	//�����
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 430 + (width - 1) * 20, 30 + (height - 2) * 20, 450 + (width - 1) * 20, 50 + (height - 2) * 20); //���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
	ReleaseDC(hwnd, dc);
}

void dynamic_array_bot(int** maze, int height, int width, bool stopwatch){
	system("cls");
	int x1 = 400, y1 = 30, x2 = 420, y2 = 50;
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	//������ �������
	brush = CreateSolidBrush(RGB(255, 189, 187)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	RECT WinCoord = {}; //������ ��������� ���� 
	GetWindowRect(hwnd, &WinCoord); //����� ����������
	Rectangle(dc, 828, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
	//������� �������
	brush = CreateSolidBrush(RGB(255, 189, 187)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 348, 0, 830, WinCoord.bottom);
	DeleteObject(brush); //������� ������ �� ��������� �����
	//������ �������
	brush = CreateSolidBrush(RGB(0, 178, 228));
	SelectObject(dc, brush);
	Rectangle(dc, 348, 500, WinCoord.right, WinCoord.bottom);
	DeleteObject(brush);
	//����� �������
	brush = CreateSolidBrush(RGB(0, 178, 228));
	SelectObject(dc, brush);
	Rectangle(dc, 10, 0, 350, WinCoord.bottom);
	DeleteObject(brush);
	//������ ����
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush);
	Rectangle(dc, 90, 70, 270, 130);
	DeleteObject(brush);
	//������ ����
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush);
	Rectangle(dc, 40, 200, 330, 270);
	DeleteObject(brush);
	//������ ����
	brush = CreateSolidBrush(RGB(59, 255, 251));
	SelectObject(dc, brush);
	Rectangle(dc, 40, 295, 330, 365);
	DeleteObject(brush);
	//����
	brush = CreateSolidBrush(RGB(255, 189, 187));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 380, 70, 400);
	DeleteObject(brush);
	//���
	brush = CreateSolidBrush(RGB(3, 0, 189));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 420, 70, 440);
	DeleteObject(brush);
	//������
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 460, 70, 480);
	DeleteObject(brush);
	//�����
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush);
	Rectangle(dc, 50, 500, 70, 520);
	DeleteObject(brush);
	//�����
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
	TextOut(dc, 93, 30, L"��������� ����", strlen("��������� ����"));
	TextOut(dc, 80, 160, L"��������� �������", strlen("��������� �������"));
	DeleteObject(hFont); //�������� �� ������ ������ ������

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
	TextOut(dc, 105, 90, L"�����������...", strlen("�����������..."));
	if (stopwatch == 0) {
		TextOut(dc, 115, 225, L"��� �������", strlen("��� �������"));
	}
	else TextOut(dc, 90, 225, L"������ �������!", strlen("������ �������!"));
	TextOut(dc, 80, 381, L"- ���� ", strlen("- ���� "));
	TextOut(dc, 80, 421, L"- ��� ", strlen("- ��� "));
	TextOut(dc, 80, 461, L"- ������ ", strlen("- ������ "));
	TextOut(dc, 80, 501, L"- ����� ", strlen("- ����� "));
	TextOut(dc, 80, 541, L"- ����� ", strlen("- ����� "));
	TextOut(dc, 90, 310, L"������� '������'", strlen("������� '������'"));
	TextOut(dc, 60, 330, L"����� ��������� � ����", strlen("����� ��������� � ����"));
	DeleteObject(hFont1); //�������� �� ������ ������ ������
	for (int k = 0; k < height; k++) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				switch (maze[i][j]) {
				case wall:
					brush = CreateSolidBrush(RGB(105, 105, 105));
					SelectObject(dc, brush); //�������� �����
					Rectangle(dc, x1, y1, x2, y2); //���������� �������������, ����������� ����� ������
					DeleteObject(brush); //������� ������ �� ��������� �����
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
	//������
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 380, 50, 400, 70); //���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
	//���������
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
	//���������
	brush = CreateSolidBrush(RGB(105, 105, 105));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 380, 30, 400, 50);
	Rectangle(dc, 880, 30, 900, 50);//���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
	//�����
	brush = CreateSolidBrush(RGB(50, 205, 50));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 380 + (width - 1) * 20, 30 + (height - 2) * 20, 400 + (width - 1) * 20, 50 + (height - 2) * 20); //���������� �������������, ����������� ����� ������
	Rectangle(dc, 880 + (width - 1) * 20, 30 + (height - 2) * 20, 900 + (width - 1) * 20, 50 + (height - 2) * 20);
	DeleteObject(brush); //������� ������ �� ��������� �����
	ReleaseDC(hwnd, dc);
}