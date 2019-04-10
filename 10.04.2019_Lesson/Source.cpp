#include"Vector.h"

int main() {

	Vector v;
	ifstream in_file("in.txt");
	
	if (!in_file)
		cerr << "File open error" << endl;
	else {
		while (!in_file.eof()) {
			int tmp;
			in_file >> tmp;
			v.add(tmp);
		}
	}

	/*for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;*/
	//the same:
	cout << v << endl;

	Vector v1;
	v1.add(100);
	v1.add(500);

	//Vector res = v + v1; //только при объявлении можно без перегруженного оператора=, т.к. здесь вызывается конструктор
	Vector res;
	res = v + v1; // = здесь перегруженный оператор присваивания для сложного типа вектор. Без перегрузки бы он не сработал, только для простых типов int, double...
	cout << "plus " << res << endl;

	cout << "minus ";
	Vector res1;
	res1 = res - v;
	cout << res1 << endl;
	res1 << 0;
	cout << "erase " << res1 << endl;
	v1 >> 1000;
	cout << v1 << endl;
	cout << "tilda ";
	~v;
	cout << v << endl;

	system("pause");
	return 0;
}
