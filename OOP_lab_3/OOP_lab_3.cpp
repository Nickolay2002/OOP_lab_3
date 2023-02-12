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
		cout << "Абстрактный объект\n" << endl;
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
		cout << "Фигура\n" << endl;
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
		cout << "Создалась точка через конструктор с параметрами" << endl;
		this->x = x;
		this->y = y;
	}
	~point()
	{
		cout << "Точка удалилась" << endl;
	}
	virtual void show_params()
	{
		cout << " Это точка\n" << endl;
		cout << " Координаты = " << x << " , " << y << "\n" << endl;
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
		p1 = new point(0, 0);
		p2 = new point(5, 5);
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
		cout << " Это отрезок\n" << endl;
		cout << "Начало отрезка с координатами:" << p1 << "Длина:" << length << endl;
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
		cout << "Это воздушное судно\n" << endl;
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
		cout << " Это самолет\n" << endl;
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
		cout << " Это вертолет\n" << endl;
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
		cout << "Конструктор хранилища\n" << endl;
		this->size = size;
		objects = new object * [size];
		for (int i = 0; i < size; i++)
			objects[i] = nullptr;
	}

	~MyStorage()
	{
		for (int i = 0; i < size; i++)
			if (objects[i] != nullptr)
				delete (objects[i]);
		delete[] objects;
		cout << "Хранилище удалено" << endl;
	}

	void IncreaseMyStorage(object** PrevObjects, int size, int newSize)
	{
		object** newObjects = new object * [newSize];
		for (int i = 0; i < newSize; i++)
		{
			if (i < size)
			{
				newObjects[i] = PrevObjects[i];
			}
			else
			{
				newObjects[i] = nullptr;
			}
		}
		this->size = newSize;
		this->objects = newObjects;
		delete[] PrevObjects;
	}

	bool CheckObject(int index)
	{
		if (index >= size)
		{
			return false;
		}
		else
		{
			if (objects[index] == nullptr)
			{
				return false;
			}
			else return true;
		}
	}

	void AddObject(object* object)
	{
		bool position = false;
		for (int i = 0; i < size; i++)
		{
			if (objects[i] == nullptr)
			{
				position = true;
				objects[i] = object;
				cout << "Объект добавлен в позицию с номером " << i << endl;
			}
		}
		if (position == false)
		{
			SetObject(size, object);
			cout << "Объект добавлен в позицию с номером " << size << endl;
		}

	}

	void SetObject(int index, object* object)
	{
		if (index < this->size)
		{
			if (CheckObject(index) == false)
			{
				objects[index] = object;
			}
			else
			{
				AddObject(object);
			}
		}
		else
		{
			IncreaseMyStorage(objects, size, index + 1);
			objects[index] = object;
		}
		objects[index] = object;
	}

	object* GetObject(int index)
	{
		if (CheckObject(index))
		{
			return objects[index];
		}
		else
		{
			return nullptr;
		}
	}

	void DeleteObject(int index)
	{
		if (CheckObject(index))
			objects[index] = nullptr;
		else return;
	}

	int CountObjects()
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (CheckObject(i))
				count += 1;
		}
		return count;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	//создание хранилища на 10 объектов
	MyStorage storage(10);
	//создание объектов
	object* object0 = new point(7, 10);
	object* object1 = new section();
	object* object2 = new plane();
	object* object3 = new helicopter();
	object* object4 = new point(2, 1);
	object* object5 = new helicopter();
	object* object6 = new plane();
	object* object7 = new section();
	object* object8 = new point();
	object* object9 = new plane();
	object* object10 = new plane();
	cout << "____________________________________________________________________" << endl;
	//добавление объектов
	storage.SetObject(0, object0);
	storage.SetObject(1, object1);
	storage.SetObject(2, object2);
	storage.SetObject(3, object3);
	storage.SetObject(4, object4);
	storage.SetObject(5, object5);
	storage.SetObject(6, object6);
	storage.SetObject(7, object7);
	storage.SetObject(8, object8);
	storage.SetObject(9, object9);
	cout << endl;
	//опрос объектов
	object* any_object0 = storage.GetObject(4);
	(*any_object0).show_params();
	object* any_object1 = storage.GetObject(2);
	(*any_object1).show_params();
	object* any_object2 = storage.GetObject(0);
	(*any_object2).show_params();
	object* any_object3 = storage.GetObject(5);
	(*any_object3).show_params();
	object* any_object4 = storage.GetObject(8);
	(*any_object4).show_params();
	cout << "____________________________________________________________________" << endl;
	//добавление объекта в заполненое храилище
	storage.AddObject(object10);
	int newSize = storage.CountObjects();
	cout << "Теперь размер хранилища " << newSize << endl;
	system("pause");
	return 0;
}