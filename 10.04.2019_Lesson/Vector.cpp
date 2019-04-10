#include "Vector.h"

Vector::Vector()
{
	els = 0;
	buf_size = 0;
	cur_size = 0;
}

Vector::Vector(int buf_size)
{
	cur_size = 0;
	this->buf_size = buf_size;
	els = new int[buf_size];
}

Vector::Vector(const Vector & obj)
{
	cur_size = buf_size = obj.cur_size;
	els = new int[buf_size];
	for (int i = 0; i < buf_size; i++)
		els[i] = obj.els[i];
}

Vector::~Vector()
{
	//cout << "DESTRUCTION" << endl;
	delete[] els;
}

int Vector::size()
{
	return cur_size;
}

int Vector::operator[](int index)
{
	return els[index];
}

Vector Vector::operator+(const Vector & obj)
{
	Vector tmp;
	for (int i = 0; i < cur_size; i++)
		tmp.add(els[i]);
	for (int i = 0; i < obj.cur_size; i++)
		tmp.add(obj.els[i]);

	return tmp;
}
//через сортировку выделение необщих элементов - убирает из первого строго по количеству повторений встречающихся во втором векторе
//Vector Vector::operator-(const Vector & obj)
//{
//	Vector tmp;
//	int k = 0;
//	for (int i = 0; i < obj.cur_size; i++)
//	{
//		for (int j = k; j < cur_size; j++)
//		{
//			if (els[i] != els[j])
//			{
//				swap(els[j], els[k]);
//				k++;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < k; i++)
//		tmp.add(obj.els[i]);
//
//	return tmp;
//}


//написать как в классе opeator- 
//(но он будет убирать все повторящиеся элменты, т.е. если во втором векторе есть 2, то уберет все 2 из первого вектора)
Vector Vector::operator-(const Vector &obj)
{
	Vector tmp;
	bool f = true;
	for (int i = 0; i < cur_size; i++)
	{
		f = true;
		for (int j = 0; j < obj.cur_size; j++)
		{
			if (els[i] == obj.els[j])
				f = false;
		}
		if (f == true)
			tmp.add(els[i]);
	}
	return tmp;
}

void Vector::operator>>(int el)
{
	add(el);
}

Vector Vector::operator<<(int index)
{
	for (int i = index; i < cur_size; i++)
		els[i] = els[i + 1];
	cur_size--;
	return *this;
}

void Vector::operator~()
{
	for (int i = 0; i < cur_size; i++)
	{
		for (int j = i+1; j < cur_size; j++)//!
		{
			if (els[i] == els[j])
			{
				for (int k = j; k < cur_size-1; k++)//!
					els[k] = els[k + 1];
				j--;
				cur_size--;
			}
		}
	}
	
}

bool Vector::operator==(const Vector & obj)
{
	if (cur_size != obj.cur_size)
		return false;
	else {
		for (int i = 0; i < cur_size;)
			if (els[i] != obj.els[i])
				return false;
		return true;
	}
}

Vector Vector::operator!=(const Vector & obj)
{
	if (cur_size != obj.cur_size)
		return true;
	else {
		for (int i = 0; i < cur_size;)
			if (els[i] != obj.els[i])
				return true;
		return false;
	}
}

Vector Vector::operator=(const Vector & obj)
{
	buf_size = cur_size = obj.cur_size;
	els = new int[buf_size];
	for (int i = 0; i < cur_size; i++)
		els[i] = obj.els[i];

	return *this;
}

void Vector::add(int el)
{
	if (buf_size == 0) {
		buf_size = 4;
		els = new int[buf_size];
	}
	else {
		if (cur_size == buf_size) {
			buf_size *= 2;
			int *tmp = new int[buf_size];
			for (int i = 0; i < cur_size; i++)
				tmp[i] = els[i];
			delete[] els;
			els = tmp;
		}
	}
	els[cur_size++] = el;
}

ostream & operator<<(ostream & os, Vector v)
{
	for (int i = 0; i < v.size(); i++)
		os << v[i] << " ";
	return os;
}

