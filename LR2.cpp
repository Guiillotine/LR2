#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "LR2.h"
using namespace std;
void add_cow(struct cow *cow1, struct food food1[], int& num_cow, int num_food);
void add_food(struct food food1[], int& num_food);
void add_cowshed(struct cowshed cowshed1[], int& num_cowsheed);
void add_warehouse(struct warehouse warehouse1[], int& num_warehouse);
void add_worker(struct worker worker1[], int& num_worker);

int main()
{
	//struct cow *cow1 = new cow;
	//struct cow cow1[200] = {}; 
	struct cow *cow1; struct cow* cow2;
	struct food food1[200] = {};
	struct cowshed cowshed1[50] = {};
	struct warehouse warehouse1[50] = {};
	struct worker worker1[1000] = {};
	int num_cow = 0, num_food = 0, num_cowsheed = 0, num_warehouse = 0, num_worker = 0, *num_cow_p, num_cow2 = 3;
	cow1 = (cow*)malloc(3 * sizeof(cow)); cow2 = (cow*)malloc(3 * sizeof(cow));
	//num_cow_p = cow1;
	//food1 = (food*)malloc(20 * sizeof(food));
	num_food++;
	strcpy(food1[0].name, "Овёс");
	//add_worker(worker1, num_worker);
	//add_warehouse(warehouse1, num_warehouse);
	//add_cowshed(cowshed1, num_cowsheed);
	//add_food(food1, num_food);
	while (1)
	{
		add_cow(cow1, food1, num_cow, num_food);
		if (num_cow > num_cow2)
		{
			for (int i = 0; i < num_cow; i++)
			{
				cow2[i].id = cow1[i].id;
				strcpy(cow2[i].name, cow1[i].name);
				strcpy(cow2[i].breed, cow1[i].breed);
				strcpy(cow2[i].food, cow1[i].food);
				cow2[i].age = cow1[i].age;
				cow2[i].weight = cow1[i].weight;
				cow2[i].nadoi = cow1[i].nadoi;
			}
			cow1 = {};
			num_cow2 = num_cow + 10;
			cow1 = (cow*)malloc(num_cow2 * sizeof(cow));
			for (int i = 0; i < num_cow; i++)
			{
				cow1[i].id = cow2[i].id;
				strcpy(cow1[i].name, cow2[i].name);
				strcpy(cow1[i].breed, cow2[i].breed);
				strcpy(cow1[i].food, cow2[i].food);
				cow1[i].age = cow2[i].age;
				cow1[i].weight = cow2[i].weight;
				cow1[i].nadoi = cow2[i].nadoi;
			}
			cow2 = {};
			cow2 = (cow*)malloc(num_cow2 * sizeof(cow));
		}
			if (num_cow > 10) 
				for (int i = 0; i < num_cow; i++)
				{
					printf("\n № %d\n КЛИЧКА %s\n ПОРОДА %s\n КОРМ %s\n ВОЗРАСТ(лет) %d\n ВЕС(кг) %.3f\n НАДОЙ(л/сут) %d", cow1[i].id, cow1[i].name, cow1[i].breed, cow1[i].food, cow1[i].age, cow1[i].weight, cow1[i].nadoi);
				}
	}
	_getch();
}
