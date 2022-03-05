#pragma once
#ifndef CH1_H
#define CH1_H

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include "character.h"
#include "render.h"
#define MON 6 // 몬스터의 최대 개수
int kill_count;

typedef struct xy {
	double x;
	int y;
	char** dot;
};

struct xy monster;

struct xy mon[MON];
void ch1_init();
void ch1_start(double monster_speed,int i);
void print_mon(double monster_speed);
void all_clear();
#endif // !CH1_H