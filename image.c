#include <stdio.h>
#include <math.h>
#include <Windows.h>

void images(int x, int y, int num)
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	HWND myconsole = GetConsoleWindow();
	HBITMAP hImage, hOldBitmap;

	HDC hdc = GetDC(myconsole);
	HDC hMemDC = CreateCompatibleDC(hdc);

	system("mode con cols=125 lines=55");
	// 이미지 로드
	hImage = NULL;
	hImage = (HBITMAP)LoadImage(NULL, TEXT("0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	hImage = (HBITMAP)LoadImage(NULL, TEXT("0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	num = getch();
	hImage = (HBITMAP)LoadImage(NULL, TEXT("1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	num = getch();
	hImage = (HBITMAP)LoadImage(NULL, TEXT("2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	num = getch();
	hImage = (HBITMAP)LoadImage(NULL, TEXT("3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	num = getch();
	hImage = (HBITMAP)LoadImage(NULL, TEXT("4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	num = getch();
	hImage = (HBITMAP)LoadImage(NULL, TEXT("5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hdc, x, y, 1200, 900, hMemDC, 0, 0, SRCCOPY);
	num = getch();

	return;
}
