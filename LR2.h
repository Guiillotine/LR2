﻿#define _CRT_SECURE_NO_WARNINGS
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
	char breed[50]; //порода
	char food[50];
	char sex;
	int age;
	int weight;
};

struct food
{
	int id;
	char name[50];
	string company; //фирма
	double price;
};

struct cowshed //Коровник
{
	int id;
	int S; //Площадь
	int kol_cows; // Сколько помещается коров
	int price; //Стоимость коровника
	int exp; //Ежемесячные затраты на обслуживание
};

struct warehouse //склад
{
	int id;
	int S; //Площадь
	int capacity; //Вместимость (в мешках)
	int price; //Стоимость скалада
	int exp; //Ежемесячные затраты на обслуживание
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
	system("cls");
	printf("\n Добавление новой коровы");
	cow1[num_cow].id = num_cow + 1;

	printf("\n Введите кличку коровы: ");
	gets_s(cow1[num_cow].name);

	printf("\n Введите породу коровы: ");
	gets_s(cow1[num_cow].breed);

	printf("\n Выберите корм для коровы: ");
	for (int i = 0; i < num_food; i++) printf("\n %d->%s", i+1, food1[i].name);
	printf("\n ");
	scanf("%d", &a);
	while (getchar() != '\n');
	for (int i = 0; i < num_food; i++)
		if (a == (i + 1)) strcpy(cow1[num_cow].food, food1[i].name);

	printf("\n Выберите пол коровы (М/Ж): ");
	scanf("%c", &cow1[num_cow].sex);
	while (getchar() != '\n');

	printf("\n Введите возраст коровы (лет): ");
	scanf("%d", &cow1[num_cow].age);
	while (getchar() != '\n');

	printf("\n Введите вес коровы (кг): ");
	scanf("%d", &cow1[num_cow].weight);
	while (getchar() != '\n');
	num_cow++;
}