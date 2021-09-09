#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "LR2.h"
using namespace std;
void add_cow(struct cow cow1[], struct food food1[], int *num_cow, int num_food);
void add_food(struct food food1[], int *num_food);
void add_cowshed(struct cowshed cowshed1[], int *num_cowsheed);
void add_warehouse(struct warehouse warehouse1[], int *num_warehouse);
void add_worker(struct worker worker1[], int *num_worker);

int main()
{
	struct cow cow1[200] = {};
	struct food food1[200] = {};
	struct cowshed cowshed1[50] = {};
	struct warehouse warehouse1[50] = {};
	struct worker worker1[1000] = {};
	int *num_cow, *num_food, *num_cowsheed, *num_warehouse, *num_worker;
	//cow1 = (cow*)malloc(20 * sizeof(cow));
	//food1 = (food*)malloc(20 * sizeof(food));
	num_cow = (int*)malloc(sizeof(int));
	num_food = (int*)malloc(sizeof(int));
	num_cowsheed = (int*)malloc(sizeof(int));
	num_warehouse = (int*)malloc(sizeof(int));
	num_worker = (int*)malloc(sizeof(int));
	*num_cow = 0;
	*num_food = 0;
	*num_cowsheed = 0;
	*num_warehouse = 0;
	*num_worker = 0;
	(*num_food)++;
	strcpy(food1[0].name, "Овёс");
	add_worker(worker1, num_worker);
	add_warehouse(warehouse1, num_warehouse);
	add_cowshed(cowshed1, num_cowsheed);
	add_food(food1, num_food);
	add_cow(cow1, food1, num_cow, *num_food);
	_getch();
}
