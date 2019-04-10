#pragma once
#include<iostream>
#include <iomanip>
#include<Windows.h>
#include<ctime>
#include<cstring>
#include<fstream>
using namespace std;

//1.	В ранее созданный класс вектор добавьте перегрузку следующих операторов :
//[], +, -, << , >> , == , != , ~
//Оператор + складывает два вектора.Оператор – удаляет из первого вектора значения, которые есть во втором векторе.
//Оператор << удаляет из вектора элемент с индексом указанным в качестве второго операнда и возвращает удаленное значение, например :

//	Vector	V;
//V.Add(10);
//V.Add(11);
//V.Add(12);
//int a = V << 1;
//cout << a << “\n”;			// Выведет 11
//for (int i = 0; i < V.Size(); i++)
//{
//	cout << V[i] << “\n”;		// Выведет 10, 12
//}

//Оператор >> добавляет новое значение в конец вектора(Аналог функции Add).
//Унарный оператор ~ удаляет из вектора повторяющиеся значения.

//Так же в виде дружественных функций выполните перегрузку вывода в поток :
//Vector	V;
//V >> 10;
//V >> 11;
//V >> 12;
//cout << V << “\n”;			// выведет [0] = 10, [1] = 11 и т.д.


class Vector {
private:
	int *els;
	int buf_size;
	int cur_size;
public:
	Vector();
	Vector(int buf_size);
	Vector(const Vector&obj);
	~Vector();
	int size();
	// перегруженные операторы принимают только 1 аргумент, т.к. по обе стороны от знака + - = и тд могут стоять только по одному значению
	int operator[](int index);
	Vector operator+(const Vector &obj);
	//Vector operator-(const Vector &obj);
	Vector operator-(const Vector &obj);
	void operator>>(int el);
	Vector operator<<(int index);
	void operator~(); //все унарные операторы ставятся впереди
	bool operator==(const Vector &obj);
	Vector operator!=(const Vector &obj);
	Vector operator=(const Vector&obj);
	
	void add(int el);
	//friend ostream& operator<<(ostream &os, Vector v);
};

//два аругмента можно передавать, если метод реализовывать как внешний для класса!
ostream &operator<<(ostream& os, Vector v);//тип ostream возвращает поток вывода
// в данном случае os означает cout (поток вывода), а вектор - тот который распечатать хотим "<<(cout, v)", в source этот метод перегруженного оператора выглядит так: cout << v;