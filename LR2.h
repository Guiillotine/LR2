#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct cow
{
	int id;
	char name[50];
	char breed[100]; //порода
	char food[50];
	int age;
	double weight;
	int nadoi; //Надой
};

struct food
{
	int id;
	char name[50];
	char company[70]; //фирма
	double price;
};

struct cowshed //Коровник
{
	int id;
	int S; //Площадь
	int kol_cows; // Сколько помещается коров
	double price; //Стоимость коровника
	double exp; //Ежемесячные затраты на обслуживание
};

struct warehouse //склад
{
	int id;
	int S; //Площадь
	int kol_bags; //Вместимость (в мешках)
	double price; //Стоимость скалада
	double exp; //Ежемесячные затраты на обслуживание
};

struct worker
{
	int id;
	char fio[100];
	int year; //Год рождения
	char prof[100]; //Профессия
	char stat[10]; //в норме/ болеет/ в отпуске
	double pay;
};


void add_cow(struct cow *cow1, struct food *food1, int& num_cow, int num_food)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int a; 
	//system("cls");
	printf("\n Добавление новой коровы\n ");
	for (int i = 0; i < 23; i++) printf("-");
	printf("\n");
	cow1[num_cow].id = num_cow + 1;

	printf("\n Введите кличку коровы: ");
	gets_s(cow1[num_cow].name);

	printf("\n Введите породу коровы: ");
	gets_s(cow1[num_cow].breed); //gets_s для ввода с пробелами

	printf("\n Выберите корм для коровы: ");
	for (int i = 0; i < num_food; i++) 
		printf("\n %d->%s", i+1, food1[i].name);
	printf("\n ");
	std::cin >> a;
	while (getchar() != '\n');
	for (int i = 0; i < num_food; i++)
		if (a == (i + 1)) strcpy(cow1[num_cow].food, food1[i].name);

	printf("\n Введите возраст коровы (лет): ");
	std::cin >> cow1[num_cow].age;

	printf("\n Введите вес коровы (кг): ");
	std::cin >> cow1[num_cow].weight;

	printf("\n Введите надой коровы (л/сут): ");
	std::cin >> cow1[num_cow].nadoi;

	printf("\n № %d\n КЛИЧКА %s\n ПОРОДА %s\n КОРМ %s\n ВОЗРАСТ(лет) %d\n ВЕС(кг) %.3f\n НАДОЙ(л/сут) %d", cow1[num_cow].id, cow1[num_cow].name, cow1[num_cow].breed, cow1[num_cow].food, cow1[num_cow].age, cow1[num_cow].weight, cow1[num_cow].nadoi);
	num_cow++;
	while (getchar() != '\n');
}


void add_food(struct food *food1, int& num_food)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	printf("\n Добавление нового корма\n ");
	for (int i = 0; i < 23; i++) printf("-");
	printf("\n");
	food1[num_food].id = num_food + 1;

	printf("\n Введите название корма: ");
	std::cin >> food1[num_food].name;

	printf("\n Введите фирму-производителя корма: ");
	std::cin >> food1[num_food].company;

	printf("\n Введите цену корма (в рублях): ");
	std::cin >> food1[num_food].price;

	printf("\n № %d\n НАЗВАНИЕ %s\n ФИРМА %s\n ЦЕНА(в рублях) %.3f\n\n", food1[num_food].id, food1[num_food].name, food1[num_food].company, food1[num_food].price);
	num_food++;
}


void add_cowshed (struct cowshed *cowshed1, int& num_cowsheed)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	printf("\n Добавление нового коровника\n ");
	for (int i = 0; i < 27; i++) printf("-");
	printf("\n");
	cowshed1[num_cowsheed].id = num_cowsheed + 1;

	printf("\n Укажите площадь коровника(м^2): ");
	std::cin >> cowshed1[num_cowsheed].S;

	printf("\n Укажите вместимость коровника (количество животных): ");
	std::cin >> cowshed1[num_cowsheed].kol_cows;

	printf("\n Укажите стоимость коровника (в рублях): ");
	std::cin >> cowshed1[num_cowsheed].price;

	printf("\n Укажите ежемесячные затраты на обслуживание (в рублях): ");
	std::cin >> cowshed1[num_cowsheed].exp;

	printf("\n № %d\n ПЛОЩАДЬ КОРОВНИКА(м^2) %d\n ВМЕСТИМОСТЬ КОРОВНИКА(количество животных) %d\n СТОИМОСТЬ КОРОВНИКА(в рублях) %.3f\n ЕЖЕМЕСЯЧНЫЕ ЗАТРАТЫ НА ОБСЛУЖИВАНИЕ(в рублях) %.3f\n\n", cowshed1[num_cowsheed].id, cowshed1[num_cowsheed].S, cowshed1[num_cowsheed].kol_cows, cowshed1[num_cowsheed].price, cowshed1[num_cowsheed].exp);
	num_cowsheed++;
}

void add_warehouse(struct warehouse *warehouse1, int& num_warehouse)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	printf("\n Добавление нового склада\n ");
	for (int i = 0; i < 24; i++) printf("-");
	printf("\n");
	warehouse1[num_warehouse].id = num_warehouse + 1;

	printf("\n Укажите площадь склада(м^2): ");
	std::cin >> warehouse1[num_warehouse].S;

	printf("\n Укажите вместимость склада (количество мешков): ");
	std::cin >> warehouse1[num_warehouse].kol_bags;

	printf("\n Укажите стоимость склада (в рублях): ");
	std::cin >>warehouse1[num_warehouse].price;

	printf("\n Укажите ежемесячные затраты на обслуживание (в рублях): ");
	std::cin >> warehouse1[num_warehouse].exp;

	printf("\n № %d\n ПЛОЩАДЬ СКЛАДА(м^2) %d\n ВМЕСТИМОСТЬ СКЛАДА(количество мешков) %d\n СТОИМОСТЬ склада(в рублях) %.3f\n ЕЖЕМЕСЯЧНЫЕ ЗАТРАТЫ НА ОБСЛУЖИВАНИЕ(в рублях) %.3f\n\n", warehouse1[num_warehouse].id, warehouse1[num_warehouse].S, warehouse1[num_warehouse].kol_bags, warehouse1[num_warehouse].price, warehouse1[num_warehouse].exp);
	num_warehouse++;
}

void add_worker(struct worker *worker1, int& num_worker)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	printf("\n Добавление нового сотрудника\n ");
	for (int i = 0; i < 28; i++) printf("-");
	printf("\n");
	worker1[num_worker].id = num_worker + 1;

	printf("\n Укажите ФИО сотрудника: ");
	gets_s(worker1[num_worker].fio);

	printf("\n Укажите год рождения сотрудника: ");
	std::cin >> worker1[num_worker].year; while (getchar() != '\n');

	printf("\n Укажите должность сотрудника: ");
	gets_s(worker1[num_worker].prof);

	printf("\n Укажите оклад сотрудника(в рублях): ");
	std::cin >> worker1[num_worker].pay;

	strcpy(worker1[num_worker].stat, "В норме");

	printf("\n № %d\n ФИО СОТРУДНИКА %s\n ГОД РОЖДЕНИЯ СОТРУДНИКА %d\n ДОЛЖНОСТЬ %s\n ОКЛАД (в рублях) %.3f\n\n", worker1[num_worker].id, worker1[num_worker].fio, worker1[num_worker].year, worker1[num_worker].prof, worker1[num_worker].pay);
	num_worker++;
	while (getchar() != '\n');
}

void stat_worker(struct worker *worker1, int num_worker)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	int a, num = 0;
	char stat2[8] = {};
	for (int i = 0; i < num_worker; i++)
		printf("\n №%d\n %s\n %d г.р.\n %s\n <%s>\n", worker1[i].id, worker1[i].fio, worker1[i].year, worker1[i].prof, worker1[i].stat);
	do
	{
		printf("\n Изменение статуса сотрудника\n Введите номер сотрудника, статус которого следует изменить: ");
		std::cin >> num;
	} while ((num < 1) || (num > num_worker));
	strcpy(stat2, worker1[num-1].stat);
	do
	{
	printf("\n\n 1->В норме\n 2->Болеет\n 3->В отпуске\n\n Введите номер нового статуса: ");
		std::cin >> a;
		switch (a)
		{
		case 1:
			strcpy(worker1[num - 1].stat, "В норме");
			break;
		case 2:
			strcpy(worker1[num - 1].stat, "Болеет");
			break;
		case 3:
			strcpy(worker1[num - 1].stat, "В отпуске");
			break;
		}
	} while ((a < 1) || (a > 3));
	printf("\n Статус сотрудника %s изменен с <%s> на <%s>\n", worker1[num-1].fio, stat2, worker1[num-1].stat);
}

void del_worker(struct worker* worker1, int& num_worker)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	int num = 0;
	for (int i = 0; i < num_worker; i++)
		printf("\n № %d\n ФИО СОТРУДНИКА %s\n ГОД РОЖДЕНИЯ СОТРУДНИКА %d\n ДОЛЖНОСТЬ %s\n ОКЛАД (в рублях) %.3f\n СТАТУС %s\n\n", worker1[i].id, worker1[i].fio, worker1[i].year, worker1[i].prof, worker1[i].pay, worker1[i].stat);
	{
		printf("\n Увольнение сотрудника \n Введите номер сотрудника в списке, чтобы уволить его: ");
		std::cin >> num;
	} while ((num < 1) || (num > num_worker));
	printf("\n Сотрудник %s уволен", worker1[num-1].fio);

	for (int i = num - 1; i < num_worker-1; i++)
	{
		strcpy(worker1[i].fio, worker1[i+1].fio);
		worker1[i].year = worker1[i+1].year;
		strcpy(worker1[i].prof, worker1[i+1].prof);
		strcpy(worker1[i].stat, worker1[i+1].stat);
		worker1[i].pay = worker1[i+1].pay;
	}
	worker1[num_worker - 1].id = 0;
	strcpy(worker1[num_worker - 1].fio, "");
	worker1[num_worker - 1].year = 0;
	strcpy(worker1[num_worker - 1].prof, "");
	strcpy(worker1[num_worker - 1].stat, "");
	worker1[num_worker - 1].pay = 0;
	num_worker--;
}

void sell_warehouse(struct warehouse* warehouse1, int& num_warehouse)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	//system("cls");
	int num = 0;
	for (int i = 0; i < num_warehouse; i++)
		printf("\n № %d\n ПЛОЩАДЬ СКЛАДА(м^2) %d\n ВМЕСТИМОСТЬ СКЛАДА(количество мешков) %d\n СТОИМОСТЬ склада(в рублях) %.3f\n ЕЖЕМЕСЯЧНЫЕ ЗАТРАТЫ НА ОБСЛУЖИВАНИЕ(в рублях) %.3f\n\n", warehouse1[i].id, warehouse1[i].S, warehouse1[i].kol_bags, warehouse1[i].price, warehouse1[i].exp);
	do
	{
		printf("\n Продажа склада\n Введите номер склада, чтобы продать его: ");
		std::cin >> num;
	} while ((num < 1) || (num > num_warehouse));
	printf("\n Склад №%d продан\n", num);

	for (int i = num - 1; i < num_warehouse - 1; i++)
	{
		warehouse1[i].S = warehouse1[i+1].S;
		warehouse1[i].kol_bags = warehouse1[i+1].kol_bags;
		warehouse1[i].exp = warehouse1[i+1].exp;
		warehouse1[i].price = warehouse1[i+1].price;
	}
	warehouse1[num_warehouse - 1].id = 0;
	warehouse1[num_warehouse - 1].S = 0;
	warehouse1[num_warehouse - 1].kol_bags = 0;
	warehouse1[num_warehouse - 1].exp = 0;
	warehouse1[num_warehouse - 1].price = 0;
	num_warehouse--;
}
