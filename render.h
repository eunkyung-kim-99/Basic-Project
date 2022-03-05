#pragma once
#include <Windows.h>
#include "character.h"
#include "ch1.h"
#pragma warning (disable : 4996)
#ifndef RENDER_H
#define RENDER_H
void gotoxy(int x, int y);
void cursor(int n);
int GetFontSize(HANDLE windowHandle, COORD* size);
int SetFontSize(HANDLE windowHandle, COORD size);
void changeFsize();
void getbackFsize();
void printDot(int check, int x, int y);
void textcolor(int foreground, int background);
#endif // !RENDER_H

