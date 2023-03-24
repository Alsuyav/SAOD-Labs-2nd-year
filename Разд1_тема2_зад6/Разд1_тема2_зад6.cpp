#include "Header.h"
using namespace std;

// элемент очереди
struct Element
{
	int data;
	Element* next; // указатель на следующий элемент
};


class R_line_d
{
private:
	Element* first, // указатель на 1-й элемент
		* last; // указатель на последний элемент
public:
	// констурктор
	R_line_d();

	// добавление элемента в очередь
	void push();

	// удаление элемента из очереди
	void pop();

	// вывод всей очереди
	void show_line();
};

// конструктор
R_line_d::R_line_d()
{
	// добавление фиктивного элемента-заголовка
	Element* fake = new Element; // создание места для нового элемента, fake - указатель
	fake->next = NULL;
	first = fake;
	last = fake;
}

// добавление элемента в очередь
void R_line_d::push()
{
	int var;
	cout << "\nEnter new element: ";
	cin >> var;
	cin.get(); // Enter
	Element* ptr = new Element; // создание места для нового элемента
	ptr->data = var; // запись в нов. элемент
	last->next = ptr; // теперь посл. элемент указывает на новый
	last = ptr; // теперь новый - это посл. элемент
	last->next = NULL;
	cout << var << " was added\n";
}

// удаление элемента из очереди
void R_line_d::pop()
{
	if (first->next) // если указатель не NULL
	{
		Element* ptr;
		ptr = first->next; // указатель на удаляемый элемент
		first->next = ptr->next;
		if (!first->next) last = first;
		cout << "\nLast added element was deleted\n";
	}
	else cout << "\nLine is empty!\n";
}


// вывод всей очереди
void R_line_d::show_line()
{
	if (first->next) // если указатель не NULL
	{
		Element* ptr = first->next; // новый указатель на первый элемент
		cout << "\nYour line now:\n";
		while (ptr)
		{
			cout << ptr->data << endl; // вывод данных
			ptr = ptr->next; // переход к следующему
		}
	}
	else cout << "\nLine is empty!\n";
}


int main()
{
	R_line_d Rl;
	char ans;
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
