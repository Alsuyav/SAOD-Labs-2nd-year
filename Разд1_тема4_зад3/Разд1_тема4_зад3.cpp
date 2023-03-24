//#include "Header.h"
//using namespace std;
//
//struct Element_sub
//{
//	int data;
//	Element_sub* next;
//};
//
//class Sub_list
//{
//private:
//	Element_sub* first_sub;
//	int count_sub; // счётчик элементов в побочном списке
//
//public:
//	// конструктор
//	Sub_list();
//};
//
//// конструктор
//Sub_list::Sub_list()
//{
//	Element_sub* pHead = new Element_sub; // создание места для нового элемента
//	pHead->next = pHead;
//	first_sub = pHead;
//	count_sub = 0; // пока базовых списков
//}
//
//
//
//
//
//struct Element_main
//{
//	Element_sub* first_sub; // информативная часть
//	Element_main* next;
//};
//
//class Main_list
//{
//private:
//	Element_main* first_main;
//	int count_main; // счётчик элементов в базовом списке
//public:
//	// констурктор
//	Main_list();
//	void Add_to_main();
//};
//
//// констурктор
//Main_list::Main_list()
//{
//	// добавление фиктивного элемента-заголовка
//	Element_main* pHead = new Element_main; // создание места для нового элемента
//	pHead->next = pHead;
//	first_main = pHead;
//	count_main = 0; // пока базовых списков
//}
//
//void Main_list::Add_to_main()
//{
//	Element_main* temp = new Element_main;
//	Sub_list nov;
//
//
//
//}
///////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////////
/*int main()
{
	List_m M;
	char ans;
	do
	{
		cout << "\nChoose the item:\n" << "1 - show the line (next)\n" <<
			"2 - show the line (left)\n" <<
			"3 - add new element after certain element\n" <<
			"4 - add new element before certain element\n" <<
			"5 - search the element (next)\n" <<
			"6 - delete certain element\n" <<
			"7 - search the element (left)\n" <<
			"0 - exit\n";
		ans = _getche();
		if ((ans >= '0') && (ans <= '7'))
		{
			switch (ans)
			{
			case '1': S.show_list_next(); break;
			case '2': S.show_list_left(); break;
			case '3': S.push_after(); S.show_list_next(); break;
			case '4': S.push_before(); S.show_list_next(); break;
			case '5': S.search_next(); break;
			case '6': S.pop();  S.show_list_next(); break;
			case '0': return 0;
			case '7': S.search_left(); break;
			default: break;
			}

		}
		if ((ans >= '0') && (ans <= '7'))
		{
			cout << "\nPress ENTER\n";
			cin.get();
		}
	} while (ans != '0');
	return 0;
}*/



// Программа, выполняющая стандартный набор операций с кольцевой очередью на основе массива:
//	проверку пустоты очереди
//	проверку заполненности очереди
//	добавление элемента в конец очереди
//	удаление элемента из начала очереди
//	вывод текущего состояния очереди на экран
//Требования к программе:
//	все действия должны быть оформлены как процедуры или функции
//	добавлению/удалению должна предшествовать проверка возможности выполнения этих операций
//	главная программа реализует следующий набор действий:
//	инициализация пустой очереди
//	организация диалогового цикла с пользователем

#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

#define MAX 5

// функция для добавления элемента
void push(int a[], int** b, int& c) // передается массив, указатель на последний эл-т и счётчик элементов
{
	if (c < MAX) // если не макс. число элементов
	{
		int var;
		cout << "\nEnter new element: ";
		cin >> var;
		cin.get(); // для Enter после числа
		*b = &var; // добавление значение

		if (*b == a + MAX) // если указывает на посл. место в массиве
			*b = a; // указывать на первое место в массиве
		else
			b++; // указывать на след. элемент по порядку
		cout << var << " was added\n";
		c++; // увеличение числа элементов
	}
	else cout << "\nLine is full!\n";
}

// функция для удаления элемента
void pop(int a[], int** b, int& c) // передается массив, указатель на 1-й эл-т и счётчик элементов
{
	if (c > 0)
	{
		if (*b == a + MAX) // если указывает на посл. место в массиве
			*b = a; // указывать на первое место в массиве
		else
			b++; // указывать на след. элемент по порядку

		cout << "\nThe first element was deleted\n";
		c--; // уменьшение числа элементов
	}
	else cout << "\nLine is empty!\n";
}

// функция для вывода очереди
void show_line(int a[], int* b, int* d, int c) // передается массив, указатель на 1-й эл-т, указатель на последний эл-т и счётчик элементов
{
	if (c > 0)
	{
		cout << "\n\nYour line now:\n";
		int* to_show_line; // временный указатель для вывода очереди
		to_show_line = b;
		int i = 1; // счетчик номера в очереди
		while (to_show_line != d) // пока не последний эл-т - происходит поэлементный вывод
		{
			cout << i << " element is " << *to_show_line << endl;
			i++;
			to_show_line++;
		}
		cout << endl;
	}
	else cout << "\nLine is empty!\n";
}

int main()
{
	int ring_line[MAX]; // сама кольцевая очередь - массив
	int* first = NULL, // указатель на 1-й элемент
		* last = NULL; // указатель на последний элемент
	int counter = 0; // счетчик числа элементов в очереди
	char answer; // ответ пользователя

	do
	{
		cout << "\nChoose the item:\n" << "1 - show line\n2 - add element\n3 - delete the first element\n0 - exit\n";
		answer = _getche();
		if ((answer >= '0') && (answer <= '3'))
		{
			switch (answer)
			{
			case '1': show_line(ring_line, first, last, counter); break;
			case '2': push(ring_line, &last, counter); break;
			case '3': pop(ring_line, &first, counter); break;
			case '0': return 0;
			default: break;
			}
		}

		if ((answer >= '0') && (answer <= '3'))
		{
			cout << "\nPress ENTER\n";
			cin.get();
		}
	} while (answer != '0');
	return 0;
}
