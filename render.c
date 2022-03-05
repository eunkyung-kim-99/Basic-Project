#include <stdio.h>
#include "render.h"
#pragma warning(disable:4996)

//X,Y 좌표로 커서 이동하는 함수
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//커서를 안보이게 하는 함수
void cursor(int n) // 커서 보이기 & 숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//밑에 세개 묶어서 폰트 크기 조절하는데 쓰이는 함수
int GetFontSize(HANDLE windowHandle, COORD* size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	*size = font.dwFontSize;

	return 1;
}
int SetFontSize(HANDLE windowHandle, COORD size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	font.dwFontSize = size;

	if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	return 1;
}
void changeFsize() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;

	if (GetFontSize(h, &size))
	{
		size.X -= (SHORT)(size.X * .8);
		size.Y -= (SHORT)(size.Y * .8);
		SetFontSize(h, size);
	}
}
void getbackFsize() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;

	if (GetFontSize(h, &size))
	{
		size.X += (SHORT)(size.X * 4.0);
		size.Y += (SHORT)(size.Y * 4.0);
		SetFontSize(h, size);
	}
}
void printDot( int check, int x, int y) {

	switch (check) {
	case 0:
		for (int i = 0;i<14;i++) {
			printf("%s",Hero.dot[i]);
		}
		break;
	case 1:
		for (int i = 0; i < 14; i++) {
			gotoxy(x, y + i);
			printf("%s", Hero.dot[i]);
		}
		break;
	case 2:
		for (int i = 0; i < 14; i++) {
			gotoxy(x, y + i);
			printf("                    ");
		}
		break;
	case 3:
		for (int i = 0; i < 9; i++) {
			gotoxy(x, y + i);
			printf("%s", monster.dot[i]);
		}
	}
}