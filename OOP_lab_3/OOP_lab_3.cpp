#include<iostream>

using namespace std;

class object
{
public:
	object()
	{
		cout << "Конструктор абстрактного класса object" << endl;
	}
	~object()
	{
		cout << "Деструктор абстрактного класса object" << endl;
	}
	virtual void show_params()
	{
		cout << "Абстрактный объект" << endl;
	}
};

class shape :public object
{
public:
	shape()
	{
		cout << "Конструктор класса shape" << endl;
	}
	~shape()
	{
		cout << "Деструктор класса shape" << endl;
	}
	virtual void show_params()
	{
		cout << "Фигура" << endl;
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
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
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

class section :public shape
{
private:
	point* p1, * p2;
	float length;
public:
	section()
	{
		p1 = new point(0,0);
		p2 = new point(5,5);
		length = 5;
		cout << "Отрезок создался" << endl;
	}
	~section()
	{
		cout << "Отрезок удалился" << endl;
		delete p1;
		delete p2;
	}
	virtual void show_params()
	{
		cout << " Это отрезок " << endl;
		cout << " Начало отрезка с координатами:" << endl;//TODO
	}
};

class aircraft :public object
{
public:
	aircraft()
	{
		cout << "Конструктор класса aircraft" << endl;
	}
	~aircraft()
	{
		cout << "Деструктор класса aircraft" << endl;
	}
	virtual void show_params()
	{
	}
};

class plane :public aircraft
{
private:
	int size_of_wing;
public:
	plane()
	{
		size_of_wing = 50;
		cout << "Конструктор класса plane" << endl;
	}
	~plane()
	{
		cout << "Деструктор класса plane" << endl;
	}
	virtual void show_params()
	{
	}
};

class helicopter : public aircraft
{
private:
	int size_of_blades;
public:
	helicopter()
	{
		size_of_blades = 100;
		cout << "Конструктор класса helicopter" << endl;
	}
	~helicopter()
	{
		cout << "Деструктор класса helicopter" << endl;
	}
	virtual void show_params()
	{
	}
};

class MyStorage
{
private:
	object** objects;
	int size;
public:
	MyStorage(int size)
	{
		this->size = size;
		objects = new object * [size];
	}
	void SetObject(int index, object* object)
	{
		objects[index] = object;
	}
	object& GetObject(int index)
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