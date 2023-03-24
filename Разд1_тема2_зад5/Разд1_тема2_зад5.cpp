#include "Header.h"

using namespace std;

class R_line
{
private:
	enum { MAX = 5 }; // макс. число элементов в очереди
	int ring_line[MAX]; // сама кольцевая очередь
	int* first, // указатель на 1-й элемент
		* last; // указатель на последний элемент
	int counter; // счетчик числа элементов в очереди
public:
	// констурктор
	R_line();

	// добавление элемента в очередь
	void push();

	// удаление элемента из очереди
	void pop();

	// вывод всей очереди
	void show_line();
};

// конструктор
R_line::R_line() { first = ring_line; last = ring_line; counter = 0; }

// добавление элемента в очередь
void R_line::push()
{
	if (counter < MAX) // если не макс. число элементов
	{
		int var;
		cout << "\nEnter new element: ";
		cin >> var;
		cin.get(); // для Enter после числа
		*last = var;
		if (last == ring_line + MAX) // если указывает на посл. место в массиве
			last = ring_line; // указывать на первое место в массиве
		else
			last++; // указывать на след. элемент по порядку
		cout << var << " was added\n";
		counter++;
	} 
	else cout << "\nLine is full!\n";
}

// удаление элемента из очереди
void R_line::pop()
{
	if (counter > 0)
	{
		if (first == ring_line + MAX) // если указывает на посл. место в массиве
			first = ring_line; // указывать на первое место в массиве
		else
			first++; // указывать на след. элемент по порядку
		counter--; // уменьшение числа элементов
		cout << "\nThe first element was deleted\n";
	}
	else cout << "\nLine is empty!\n";
}

// вывод всей очереди
void R_line::show_line()
{
	if (counter > 0)
	{
		cout << "\n\nYour line now:\n";
		int* to_show_line; // указатель для вывода очереди
		to_show_line = first;
		int i = 1; // счетчик номера в очереди
		while (to_show_line!=last) // пока не последний элемент - происходит поэлементный вывод
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
	R_line Rl;
	char ans;
	int newel;
	do
	{
		cout << "\nChoose the item:\n" << "1 - show line\n2 - add element\n3 - delete the first element\n0 - exit\n";
		ans = _getche();
		if ((ans >= '0') && (ans <= '3'))
		{
			switch (ans)
			{
			case '1': Rl.show_line(); break;
			case '2': Rl.push(); break;
			case '3': Rl.pop(); break;
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