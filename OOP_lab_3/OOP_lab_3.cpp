#include<iostream>
#include<time.h>
#include<stddef.h>

using namespace std;
bool debug = false;

class object
{
public:
	object()
	{
		if(debug)
			cout << "Конструктор абстрактного класса object" << endl;
	}
	~object()
	{
		if (debug)
			cout << "Деструктор абстрактного класса object" << endl;
	}
	virtual void name()
	{
		if (debug)
			cout << "Абстрактный объект\n" << endl;
	}
	virtual void showParams()
	{
		if (debug)
			cout << "Нет параметров\n" << endl;
	}
};

class shape :public object
{
public:
	shape()
	{
		if (debug)
			cout << "Конструктор класса shape" << endl;
	}
	~shape()
	{
		if (debug)
			cout << "Деструктор класса shape" << endl;
	}
	virtual void name()
	{
		if (debug)
			cout << "Фигура\n" << endl;
	}
	virtual void showParams()
	{
		if (debug)
			cout << "Нет параметров\n" << endl;
	}
};

class point :public shape
{
private:
	int x, y;
public:
	point()
	{
		if (debug)
			cout << "Создалась точка" << endl;
		x = 0;
		y = 0;
	}
	point(int x, int y)
	{
		if (debug)
			cout << "Создалась точка через конструктор с параметрами" << endl;
		this->x = x;
		this->y = y;
	}
	~point()
	{
		if (debug)
			cout << "Точка удалилась" << endl;
	}
	void name()
	{
		if (debug)
			cout << " Это точка\n" << endl;
	}
	void showParams()
	{
		if (debug)
			cout << " Координаты точки = " << x << " , " << y << "\n" << endl;
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
		if (debug)
			cout << "Отрезок создался" << endl;
	}
	section(float length)
	{
		p1 = new point(0, 0);
		p2 = new point(5, 5);
		this->length = length;
		if (debug)
			cout << "Отрезок создался с помощью констркутора с параметрами" << endl;
	}
	~section()
	{
		if (debug)
			cout << "Отрезок удалился" << endl;
		delete p1;
		delete p2;
	}
	void name()
	{
		if (debug)
			cout << " Это отрезок\n" << endl;
	}
	void showParams()
	{
		if (debug)
			cout << " Начало отрезка с координатами: 0,0" << " Длина:" << length << "\n" << endl;
	}
};

class aircraft :public object
{
public:
	aircraft()
	{
		if (debug)
			cout << "Конструктор класса aircraft" << endl;
	}
	~aircraft()
	{
		if (debug)
			cout << "Деструктор класса aircraft" << endl;
	}
	virtual void name()
	{
		if (debug)
			cout << "Это воздушное судно\n" << endl;
	}
	virtual void showParams()
	{
		if (debug)
			cout << "Нет параметров\n" << endl;
	}
};

class plane :public aircraft
{
private:
	int sizeOfWings;
public:
	plane()
	{
		sizeOfWings = 150;
		if (debug)
			cout << "Конструктор класса plane" << endl;
	}
	plane(int sizeOfWings)
	{
		this->sizeOfWings = sizeOfWings;
	}
	~plane()
	{
		if (debug)
			cout << "Деструктор класса plane" << endl;
	}
	virtual void name()
	{
		if (debug)
			cout << " Это самолет\n" << endl;
	}
	virtual void showParams()
	{
		if (debug)
			cout << " Длина крыла:" << sizeOfWings << "\n" << endl;
	}
	void fly()
	{
		if (debug)
			cout << " Самолет летит\n" << endl;
	}
};

class helicopter : public aircraft
{
private:
	int sizeOfBlades;
public:
	helicopter()
	{
		sizeOfBlades = 100;
		if (debug)
			cout << "Конструктор класса helicopter" << endl;
	}
	helicopter(int sizeOfBlades)
	{
		this->sizeOfBlades = sizeOfBlades;
	}
	~helicopter()
	{
		if (debug)
			cout << "Деструктор класса helicopter" << endl;
	}
	virtual void name()
	{
		if (debug)
			cout << " Это вертолет\n" << endl;
	}
	virtual void showParams()
	{
		if (debug)
			cout << " Длина лопастей:" << sizeOfBlades << "\n" << endl;
	}
	void levitate()
	{
		if (debug)
			cout << " Вертолет поднимается в воздух\n" << endl;
	}
};

class MyStorage
{
private:
	bool debug = false;
	object** objects;
	int size;
public:
	MyStorage(int size)
	{
		if (debug)
			cout << "Конструктор хранилища\n" << endl;
		this->size = size;
		objects = new object * [size];
		for (int i = 0; i < size; i++)
			objects[i] = nullptr;
	}

	~MyStorage()
	{
		delete[] objects;
		cout << "\nХранилище удалено" << endl;
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
				if (debug)
					cout << "Объект добавлен в позицию с номером " << i << endl;
			}
		}
		if (position == false)
		{
			SetObject(size, object);
			if (debug)
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
	debug = true;
	//создание объектов
	object* object0 = new point(7, 10);
	object* object1 = new section();
	object* object2 = new plane();
	object* object3 = new helicopter(123);
	object* object4 = new point(2, 1);
	object* object5 = new helicopter();
	object* object6 = new plane(200);
	object* object7 = new section(50);
	object* object8 = new point();
	object* object9 = new plane();
	object* object10 = new plane(300);
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
	object* any_object0 = storage.GetObject(1);
	(*any_object0).showParams();
	object* any_object1 = storage.GetObject(2);
	(*any_object1).showParams();
	object* any_object2 = storage.GetObject(0);
	(*any_object2).name();
	object* any_object3 = storage.GetObject(6);
	(*any_object3).showParams();
	object* any_object4 = storage.GetObject(8);
	(*any_object4).name();
	cout << "____________________________________________________________________" << endl;
	//добавление объекта в заполненое храилище
	storage.AddObject(object10);
	int newSize = storage.CountObjects();
	cout << "Теперь размер хранилища " << newSize << endl;
	cout << "____________________________________________________________________" << endl;
	debug = false;
	//циклы из 100,1000 и 10000 случайных действий
	clock_t start , end;
	//100
	start = clock() * 1000 / CLOCKS_PER_SEC;
	for (int i = 0; i < 100; i++)
	{
		int random = rand() % 100 + 1;
		if (random % 2 == 0)
		{
			object* newObjectPoint = new point;
			storage.SetObject(i, newObjectPoint);
			//cout << "Добавлена точка\n" << endl;
		}
		if (random % 3 == 0)
		{
			storage.DeleteObject(i);
			//cout << "Объект удален\n" << endl;
		}
		if (random % 5 == 0)
		{
			object* newObject = storage.GetObject(i);
			//if (newObject == nullptr)
				//cout << "Нет объекта";
			//else
				//newObject->showParams();
		}
	}
	end = clock() * 1000 / CLOCKS_PER_SEC;
	cout << "100 итераций за " ;
	cout << difftime(end, start);
	cout << "мс" << endl;
	//1000
	start = clock() * 1000 / CLOCKS_PER_SEC;
	for (int i = 0; i < 1000; i++)
	{
		int random = rand() % 1000 + 1;
		if (random % 2 == 0)
		{
			object* newObjectPoint = new point;
			storage.SetObject(i, newObjectPoint);
			//cout << "Добавлена точка\n" << endl;
		}
		if (random % 3 == 0)
		{
			storage.DeleteObject(i);
			//cout << "Объект удален\n" << endl;
		}
		if (random % 5 == 0)
		{
			object* newObject = storage.GetObject(i);
			//if (newObject == nullptr)
				//cout << "Нет объекта";
			//else
				//newObject->showParams();
		}
	}
	end = clock() * 1000 / CLOCKS_PER_SEC;
	cout << "1000 итераций за ";
	cout << difftime(end, start);
	cout << "мс" << endl;
	//10000
	start = clock() * 1000 / CLOCKS_PER_SEC;
	for (int i = 0; i < 10000; i++)
	{
		int random = rand() % 10000 + 1;
		if (random % 2 == 0)
		{
			object* newObjectPoint = new point;
			storage.SetObject(i, newObjectPoint);
			//cout << "Добавлена точка\n" << endl;
		}
		if (random % 3 == 0)
		{
			storage.DeleteObject(i);
			//cout << "Объект удален\n" << endl;
		}
		if (random % 5 == 0)
		{
			object* newObject = storage.GetObject(i);
			//if (newObject == nullptr)
				//cout << "Нет объекта";
			//else
				//newObject->showParams();
		}
	}
	end = clock() * 1000 / CLOCKS_PER_SEC;
	cout << "10000 итераций за ";
	cout << difftime(end, start);
	cout << "мс" << endl;
	return 0;
}