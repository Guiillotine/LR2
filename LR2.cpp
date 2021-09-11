#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "LR2.h"
using namespace std;
void add_cow(struct cow *cow1, struct food *food1, int& num_cow, int num_food); //Добавление коровы в список
void add_food(struct food *food1, int& num_food); //Добавление корма в список
void add_cowshed(struct cowshed *cowshed1, int& num_cowsheed); //Добавление коровника в список
void add_warehouse(struct warehouse *warehouse1, int& num_warehouse); //Добавление склада в список
void add_worker(struct worker *worker1, int& num_worker); //Добавление работника в список
void stat_worker(struct worker* worker1, int num_worker); //Изменение статуса работника
void del_worker(struct worker* worker1, int& num_worker); //Увольнение сотрудника
void sell_warehouse(struct warehouse* warehouse1, int& num_warehouse); //Продажа склада


int main()
{
	struct cow* cow1; struct cow* cow2;
	struct food *food1; struct food* food2;
	struct cowshed *cowshed1; struct cowshed *cowshed2;
	struct warehouse *warehouse1; struct warehouse* warehouse2;
	struct worker *worker1; struct worker *worker2;
	int num_cow = 0, num_food = 0, num_cowshed = 0, num_warehouse = 0, num_worker = 0;
	int num_cow2 = 5, num_food2 = 5, num_cowshed2 = 5, num_warehouse2 = 5, num_worker2 = 5;
	cow1 = (cow*)malloc(num_cow2 * sizeof(cow)); cow2 = (cow*)malloc(num_cow2 * sizeof(cow));
	food1 = (food*)malloc(num_food2 * sizeof(food)); food2 = (food*)malloc(num_food2 * sizeof(food));
	cowshed1 = (cowshed*)malloc(num_cowshed2 * sizeof(cowshed)); cowshed2 = (cowshed*)malloc(num_cowshed2 * sizeof(cowshed));
	warehouse1 = (warehouse*)malloc(num_warehouse2 * sizeof(warehouse)); warehouse2 = (warehouse*)malloc(num_warehouse2 * sizeof(warehouse));
	worker1 = (worker*)malloc(num_worker2 * sizeof(worker)); worker2 = (worker*)malloc(num_worker2 * sizeof(worker));

	// Пример: заполнена структура с кормами (заполнение - функцией add_food)
	num_food++;
	food1[0].id = 1;
	strcpy(food1[0].name, "Овёс");
	strcpy(food1[0].company, "Зеленщик");
	food1[0].price = 50.99;

	//Структура с коровами имеет связь со структурой с кормами: при заполнении массива структур cow корм для коровы выбирается из имеющихся в массиве структур с кормами.
	do			//Изменение размера динамичекого массива cow1
	{
		add_cow(cow1, food1, num_cow, num_food); //Добавление в список новой коровы
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
		printf("\n Нажмите esc, чтобы закончить ввод"); 
	}while (_getch() != 27);

	//Аналогичным образом заполняются данные обо всех других элементах фермы: при помощи функций вида add_...

	do			//Изменение размера динамичекого массива warehouse1
	{
		add_worker(worker1, num_worker);
		if (num_worker >= num_worker2)
		{
			for (int i = 0; i < num_worker; i++)
			{
				worker2[i].id = worker1[i].id;
				strcpy(worker2[i].fio, worker1[i].fio);
				worker2[i].year = worker1[i].year;
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
				worker1[i].year = worker2[i].year;
				strcpy(worker1[i].prof, worker2[i].prof);
				strcpy(worker1[i].stat, worker2[i].stat);
				worker1[i].pay = worker2[i].pay;
			}
			worker2 = {};
			worker2 = (worker*)malloc(num_worker2 * sizeof(worker));
		}
		printf("\n Нажмите esc, чтобы закончить ввод");
	} while (_getch() != 27);

	while (1) del_worker(worker1, num_worker);     // После занесения данных о сотрудниках фермы, можно использовать функции вида ..._worker для управления персоналом
	while (1) stat_worker(worker1, num_worker);



	do			//Изменение размера динамичекого массива warehouse1
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
		printf("\n Нажмите esc, чтобы закончить ввод");
	} while (_getch() != 27);

	sell_warehouse(warehouse1, num_warehouse); // После занесения данных о складах фермы, можно использовать функции вида ..._warehouse для управления численностью складов на ферме

	do			//Изменение размера динамического массива cowshed1
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
	printf("\n Нажмите esc, чтобы закончить ввод");
	} while (_getch() != 27);


	do			//Изменение размера динамического массива food1
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
	printf("\n Нажмите esc, чтобы закончить ввод");
	} while (_getch() != 27);


	_getch();
}








