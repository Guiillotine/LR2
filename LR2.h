#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
//#include <stdlib.h.>
//#include <windows.h>
using namespace std;

void add_cow(cow *cow1);

struct cow
{
	int id;
	string name;
	string breed; //порода
	string food[5];
	int age;
	int weight;
};

struct food
{
	int id;
	char name[20];
	char company[50]; //фирма
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

int main()
{

}

void add_cow(cow *cow1);