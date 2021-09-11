#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "LR2.h"
using namespace std;
void add_cow(struct cow *cow1, struct food *food1, int& num_cow, int num_food);
void add_food(struct food *food1, int& num_food);
void add_cowshed(struct cowshed *cowshed1, int& num_cowsheed);
void add_warehouse(struct warehouse *warehouse1, int& num_warehouse);
void add_worker(struct worker *worker1, int& num_worker);

int main()
{
	struct cow* cow1; struct cow* cow2;
	struct food *food1; struct food* food2;
	struct cowshed *cowshed1; struct cowshed *cowshed2;
	struct warehouse *warehouse1; struct warehouse *warehouse2;
	struct worker *worker1; struct worker *worker2;
	int num_cow = 0, num_food = 0, num_cowshed = 0, num_warehouse = 0, num_worker = 0;
	int num_cow2 = 5, num_food2 = 5, num_cowshed2 = 5, num_warehouse2 = 5, num_worker2 = 5;
	cow1 = (cow*)malloc(num_cow2 * sizeof(cow)); cow2 = (cow*)malloc(num_cow2 * sizeof(cow));
	food1 = (food*)malloc(num_food2 * sizeof(food)); food2 = (food*)malloc(num_food2 * sizeof(food));
	cowshed1 = (cowshed*)malloc(num_cowshed2 * sizeof(cowshed)); cowshed2 = (cowshed*)malloc(num_cowshed2 * sizeof(cowshed));
	warehouse1 = (warehouse*)malloc(num_warehouse2 * sizeof(warehouse)); warehouse2 = (warehouse*)malloc(num_warehouse2 * sizeof(warehouse));
	worker1 = (worker*)malloc(num_worker2 * sizeof(worker)); worker2 = (worker*)malloc(num_worker2 * sizeof(worker));

	num_food++;
	strcpy(food1[0].name, "Овёс");

	while (1)
	{
		add_worker(worker1, num_worker);
		if (num_worker >= num_worker2)
		{
			for (int i = 0; i < num_worker; i++)
			{
				worker2[i].id = worker1[i].id;
				strcpy(worker2[i].fio, worker1[i].fio);
				worker2[i].age = worker1[i].age;
				strcpy(worker2[i].prof, worker1[i].prof);
				strcpy(worker2[i].stat, worker1[i].stat);
				worker2[i].pay = worker1[i].pay;
			}
			worker1 = {};
			num_worker2 = num_worker + 10;
			worker1 = (worker*)malloc(num_worker2 * sizeof(worker));
			for (int i = 0; i < num_worker; i++)
			{
				worker1[i].id = worker2[i].id;
				strcpy(worker1[i].fio, worker2[i].fio);
				worker1[i].age = worker2[i].age;
				strcpy(worker1[i].prof, worker2[i].prof);
				strcpy(worker1[i].stat, worker2[i].stat);
				worker1[i].pay = worker2[i].pay;
			}
			worker2 = {};
			worker2 = (worker*)malloc(num_worker2 * sizeof(worker));
		}
		if (num_worker > 10)
			for (int i = 0; i < num_worker; i++)
			{
				printf("\n № %d\n ФИО сотрудника %s\n ВОЗРАСТ СОТРУДНИКА(лет)  %d\n ДОЛЖНОСТЬ %s\n ОКЛАД (в рублях) %.3f\n\n", worker1[i].id, worker1[i].fio, worker1[i].age, worker1[i].prof, worker1[i].pay);
			}
	}

	while (1)
	{
		add_warehouse(warehouse1, num_warehouse);
		if (num_warehouse >= num_warehouse2)
		{
			for (int i = 0; i < num_warehouse; i++)
			{
				warehouse2[i].id = warehouse1[i].id;
				warehouse2[i].S = warehouse1[i].S;
				warehouse2[i].kol_bags = warehouse1[i].kol_bags;
				warehouse2[i].exp = warehouse1[i].exp;
				warehouse2[i].price = warehouse1[i].price;
			}
			warehouse1 = {};
			num_warehouse2 = num_warehouse + 10;
			warehouse1 = (warehouse*)malloc(num_warehouse2 * sizeof(warehouse));
			for (int i = 0; i < num_warehouse; i++)
			{
				warehouse1[i].id = warehouse2[i].id;
				warehouse1[i].S = warehouse2[i].S;
				warehouse1[i].kol_bags = warehouse2[i].kol_bags;
				warehouse1[i].exp = warehouse2[i].exp;
				warehouse1[i].price = warehouse2[i].price;
			}
			warehouse2 = {};
			warehouse2 = (warehouse*)malloc(num_warehouse2 * sizeof(warehouse));
		}
		if (num_warehouse > 10)
			for (int i = 0; i < num_warehouse; i++)
			{
				printf("\n № %d\n ПЛОЩАДЬ СКЛАДА(м^2) %d\n ВМЕСТИМОСТЬ СКЛАДА(количество мешков) %d\n СТОИМОСТЬ склада(в рублях) %.3f\n ЕЖЕМЕСЯЧНЫЕ ЗАТРАТЫ НА ОБСЛУЖИВАНИЕ(в рублях) %.3f\n\n", warehouse1[i].id, warehouse1[i].S, warehouse1[i].kol_bags, warehouse1[i].price, warehouse1[i].exp);
			}
	}

	while (1)
	{
		add_cowshed(cowshed1, num_cowshed);
		if (num_cowshed >= num_cowshed2)
		{
			for (int i = 0; i < num_cowshed; i++)
			{
				cowshed2[i].id = cowshed1[i].id;
				cowshed2[i].S = cowshed1[i].S;
				cowshed2[i].kol_cows = cowshed1[i].kol_cows;
				cowshed2[i].exp = cowshed1[i].exp;
				cowshed2[i].price = cowshed1[i].price;
			}
			cowshed1 = {};
			num_cowshed2 = num_cowshed + 10;
			cowshed1 = (cowshed*)malloc(num_cowshed2 * sizeof(cowshed));
			for (int i = 0; i < num_cowshed; i++)
			{
				cowshed1[i].id = cowshed2[i].id;
				cowshed1[i].S = cowshed2[i].S;
				cowshed1[i].kol_cows = cowshed2[i].kol_cows;
				cowshed1[i].exp = cowshed2[i].exp;
				cowshed1[i].price = cowshed2[i].price;
			}
			cowshed2 = {};
			cowshed2 = (cowshed*)malloc(num_cowshed2 * sizeof(cowshed));
		}
		if (num_cowshed > 10)
			for (int i = 0; i < num_cowshed; i++)
			{
				printf("\n № %d\n ПЛОЩАДЬ КОРОВНИКА(м^2) %d\n ВМЕСТИМОСТЬ КОРОВНИКА(количество животных) %d\n СТОИМОСТЬ КОРОВНИКА(в рублях) %.3f\n ЕЖЕМЕСЯЧНЫЕ ЗАТРАТЫ НА ОБСЛУЖИВАНИЕ(в рублях) %.3f\n\n", cowshed1[i].id, cowshed1[i].S, cowshed1[i].kol_cows, cowshed1[i].price, cowshed1[i].exp);
			}
	}

	while (1)
	{
	add_food(food1, num_food);
	if (num_food >= num_food2)
	{
		for (int i = 0; i < num_food; i++)
		{
			food2[i].id = food1[i].id;
			strcpy(food2[i].name, food1[i].name);
			strcpy(food2[i].company, food1[i].company);
			food2[i].price = food1[i].price;
		}
		food1 = {};
		num_food2 = num_food + 10;
		food1 = (food*)malloc(num_food2 * sizeof(food));
		for (int i = 0; i < num_food; i++)
		{
			food1[i].id = food2[i].id;
			strcpy(food1[i].name, food2[i].name);
			strcpy(food1[i].company, food2[i].company);
			food1[i].price = food2[i].price;
		}
		food2 = {};
		food2 = (food*)malloc(num_food2 * sizeof(food));
	}
	if (num_food > 10)
		for (int i = 0; i < num_food; i++)
		{
			printf("\n № %d\n НАЗВАНИЕ %s\n ФИРМА %s\n ЦЕНА(в рублях) %.3f\n\n", food1[i].id, food1[i].name, food1[i].company, food1[i].price);
		}
}
	while (1)
	{
		add_cow(cow1, food1, num_cow, num_food);
		if (num_cow >= num_cow2)
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
