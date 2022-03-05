#pragma once
#ifndef TITLE_H
#define TITLE_H

int text_cbnu[19][66];

void show_title();
void t_start();
void t_restart();
void t_exit();
void t_rexit();
void print_t();
void print_t_restart();
void retitle_execute(int* y);
void retitle_move(char key, int* x, int* y);
void title_move(char key, int* x, int* y);
void title_execute(int* x);
void textcolor(int foreground, int background);
void print_sulmung();
void print_sulmung2();
#endif // !TITLE_H