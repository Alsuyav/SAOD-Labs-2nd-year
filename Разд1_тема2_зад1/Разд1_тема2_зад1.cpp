#include "Header.h"

using namespace std;

class Stack_m // Стек на основе массива
{
private:
	enum { MAX = 3 };
	int num[MAX];
	int top; // номер последнего элемента

public:
// конструктор
	Stack_m() { num[0] = 0; top = -1; }

// добавление элемента в стек
	void push() 
	{
		if (top < MAX - 1)
		{
			int var;
			cout << "\nEnter new element: ";
			cin >> var;
			cin.get(); // для Enter после числа
			num[++top] = var;
			cout << var << " was added\n";
		}
		else cout << "\nStack is full!\n";
	}

// удаление элемента из стека
	void pop() 
	{
		if (top >= 0)
		{
			top--; // уменьшение индекса последнего элемента
			cout << "\nLast element was deleted\n";
		}
		else cout << "\nStack is empty!\n";
	}

// вывод всего стека
	void show_stack()
	{
		if (top >= 0)
		{
			cout << "\n\nYour stack now:\n";
			for (int i = 0; i <= top; i++)
			{
				cout << i + 1 << " element is " << num[i] << endl;
			}
			cout << endl;
		}
		else cout << "\nStack is empty!\n";
	}
};

int main()
{
	Stack_m S;
	char ans;
	do
	{
		cout << "\nChoose the item:\n" << "1 - show stack\n2 - add element\n3 - delete last element\n0 - exit\n";
		ans = _getche();
		if ((ans >= '0') && (ans <= '3'))
		{
			switch (ans)
			{
			case '1': S.show_stack(); break;
			case '2': S.push(); break;
			case '3': S.pop(); break;
			case '0': return 0;
			default: break;
			}

		}
		if ((ans >= '0') && (ans <= '3'))
		{
			cout << "\nPress ENTER\n";
			cin.get();
		}
	} while (ans != '0');
	return 0;
}