#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "render.h"
#pragma warning (disable : 4996)
#ifndef CHARACTER_H
#define CHARACTER_H


typedef struct character {
	int x;
	int y;
	char** dot;

}Character;

Character Hero;

void character_init();
void character_move(char key);
void character_attack();
#endif // !CHARACTER_H