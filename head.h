#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*ÆäËû¸¨Öúº¯Êý*/
int num(int n);
void difficult_game();
int bili(int g,int *x,int (*a)[4]);
int UP(int (*a)[4]);
int DOWN(int (*a)[4]);
int LEFT(int (*a)[4]);
int RIGHT(int (*a)[4]);

#endif  //HEAD_H
