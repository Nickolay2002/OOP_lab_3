#include<iostream>

using namespace std;

class shape
{
public:
	shape()
	{
		cout << "Абстрактная фигура создалась" << endl;
	}
	~shape()
	{
		cout << "Фигура удалилась" << endl;
	}
	virtual void show_params()
	{
	}
};

class point :public shape
{
private:
	int x, y;
public:
	point()
	{
		cout << "Создалась точка" << endl;
		x = 0;
		y = 0;
	}
	~point()
	{
		cout << "Точка удалилась" << endl;
	}
	virtual void show_params()
	{
		cout << " Это точка" << endl;
		cout << " Координаты = " << x << " , " << y << endl;
	}
};

class Section :public shape
{
private:
	point* p1, * p2;
	int x1, x2, y1, y2;
public:
	Section()
	{
		p1 = new point();
		p2 = new point();
		x1 = x2 = y1 = y2 = 0;
		cout << "Отрезок создался" << endl;
	}
	~Section()
	{
		cout << "Отрезок удалился" << endl;
		delete p1;
		delete p2;
	}
	virtual void show_parametri()
	{
		cout << " Это отрезок " << endl;
	}
};

class MyStorage
{
private:
	shape** objects;
	int size;
public:
	MyStorage(int size)
	{
		this->size = size;
		objects = new shape * [size];
	}
	void SetObject(int index, shape* object)
	{
		objects[index] = object;
	}
	shape& GetObject(int index)
	{
		return *objects[index];
	}
	int getCount()
	{
		return;//TODO
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	MyStorage storage(10);
	for (int i = 0; i < storage.getCount(); i++) {
		storage.SetObject(i, new point());
	}
	for (int i = 0; i < storage.getCount(); i++) {
		storage.GetObject(i).show_params();
	}
	system("pause");
	return 0;

}