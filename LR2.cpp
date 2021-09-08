#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "LR2.h"
using namespace std;
void add_cow(struct cow cow1[], struct food food1[], int& num_cow, int num_food);
void add_food(struct food food1[], int& num_food);

int main()
{
	struct cow cow1[200] = {};
	struct food food1[200] = {};
	int num_cow, num_food;
	num_cow = 0;
	num_food = 0;
	//cow1 = (cow*)malloc(20 * sizeof(cow));
	//food1 = (food*)malloc(20 * sizeof(food));
	num_food++;
	strcpy(food1[0].name, "Овёс");
	add_food(food1, num_food);
	add_cow(cow1, food1, num_cow, num_food);
	_getch();
}
