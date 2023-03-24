#include "Header.h"

using namespace std;

// элемент стека
struct Element
{
	int data;
	Element* next; // указатель на следующий элемент
};

class Stack_d // стек на основе динам. распред. памяти
{
private:
	Element* first; // указатель на последний добавленный (первый на удаление) элемент стека
public:				// добавление идёт всегда в начало стека
// конструктор
	Stack_d() { first = NULL; }

// добавление элемента в стек
	void push() 
	{
		int var;
		cout << "\nEnter new element: ";
		cin >> var;
		cin.get(); // Enter
		Element* newelem = new Element; // создание места для нового элемента, newelem - указатель
		newelem->data = var; // запись в нов. элемент
		newelem->next = first; // этот элемент укажет на первый
		first = newelem; // теперь он в начале
		cout << var << " was added\n";
	}

// удаление элемента из стека
	void pop() 
	{
		if (first) // если указатель не NULL
		{
			first = first->next; // переход к следующему элементу
			cout << "\nLast added element was deleted\n";
		}
		else cout << "\nStack is empty!\n";
	}

// вывод всего стека
	void show_stack()
	{
		if (first) // если указатель не NULL
		{
			Element* elem = first; // новый указатель на первый элемент
			cout << "\nYour stack now:\n";
			while (elem) // пока указатель не NULL
			{
				cout << elem->data << endl; // вывод данных
				elem = elem->next; // переход к следующему
			}
		}
		else cout << "\nStack is empty!\n";
	}

// заполнить стек
	void fill_stack()
	{
		unsigned int num; // кол-во ранд. элементов стека
		int var;
		cout << "\nHow many elements do you want to add?\n";
		cin >> num;
		cin.get(); // Enter
		for(unsigned int i = 0; i < num; i++)
		{
			var = rand();
			Element* newelem = new Element; // создание места для нового элемента
			newelem->data = var; // запись в нов. элемент
			newelem->next = first; // этот элемент укажет на первый
			first = newelem; // теперь он в начале
		}
		cout << num << " elements were added\n";
	}
};

int main()
{
	Stack_d S;
	char ans;
	do
	{
		cout << "\nChoose the item:\n" << "1 - show stack\n2 - add element\n3 - delete last element\n4 - fill stack\n0 - exit\n";
		ans = _getche();
		if ((ans >= '0') && (ans <= '4'))
		{
			switch (ans)
			{
			case '1': S.show_stack(); break;
			case '2': S.push(); break;
			case '3': S.pop(); break;
			case '4': S.fill_stack(); break;
			case '0': return 0;
			default: break;
			}

		}
		if ((ans >= '0') && (ans <= '4'))
		{
			cout << "\nPress ENTER\n";
			cin.get();
		}
	} while (ans != '0');
	return 0;
}