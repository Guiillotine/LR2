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
	string fio;
	int age;
	string prof; //Профессия
	string stat; //в норме/ болеет/ уволен
	int exp; //Ежемесячные затраты на обслуживание
};


void add_cow(struct cow cow1[], struct food food1[], int& num_cow, int num_food)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int a; 
	//system("cls");
	printf("\n Добавление новой коровы");
	cow1[num_cow].id = num_cow + 1;

	printf("\n Введите кличку коровы: ");
	std::cin >> cow1[num_cow].name; while (getchar() != '\n');

	printf("\n Введите породу коровы: ");
	gets_s(cow1[num_cow].breed); //gets_s тобы вводить с пробелами


	printf("\n Выберите корм для коровы: ");
	for (int i = 0; i < num_food; i++) printf("\n %d->%s", i+1, food1[i].name);
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
}


void add_food(struct food food1[], int& num_food)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int a;
	//system("cls");
	printf("\n Добавление нового корма");
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


void add_cowshed (struct cowshed cowshed1[], int& num_cowsheed)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int a;
	//system("cls");
	printf("\n Добавление нового коровника");
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

void add_warehouse(struct warehouse warehouse1[], int& num_warehouse)
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int a;
	system("cls");
	printf("\n Добавление нового склада");
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
