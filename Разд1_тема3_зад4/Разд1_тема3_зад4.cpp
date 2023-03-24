#include "Header.h"
using namespace std;

// элемент списка
struct Element 
{
	int data;
	Element* next; // номер следующего элемента
};

class List_d
{
private:
	Element* first; // сам список
	int count; // счётчик элементов в массиве, д.б. меньше МАХ-2
public:
	// констурктор
	List_d();

	// добавление элемента в список после заданного
	void push_after();

	// добавление элемента в список перед заданным
	void push_before();

	// удаление элемента из списка
	void pop();

	// вывод всей очереди
	void show_list();

	// поиск элемента в списке
	void search();
};

// констурктор
List_d::List_d()
{
	// добавление фиктивного элемента-заголовка
	Element* pHead = new Element; // создание места для нового элемента, fake - указатель
	pHead->next = NULL;
	first = pHead;
	count = 0; // пока нет элементов
}

// добавление элемента в список после заданного
void List_d::push_after()
{
	int user_after;
	do
	{
		cout << "\nAfter what count element do you want to insert the new element? ";
		cin >> user_after;
		cin.get();
	} while (user_after < 0 || user_after > count);

	int var;
	cout << "\nEnter new element: ";
	cin >> var;
	cin.get(); // Enter

	Element* after_this_insert = first;
	for (int i = 0; i < user_after; i++)
	{
		after_this_insert = after_this_insert->next; // переход к след.
	}

	Element* ptr = new Element; // создание места для нового элемента
	ptr->data = var; // запись в нов. элемент
	ptr->next = after_this_insert->next; // новый элемент указывает туда, куда указывал выбранный
	after_this_insert->next = ptr; // выбранный элемент указывает на новый
	
	cout << var << " was added\n";
	count++;
}

// добавление элемента в список перед заданным
void List_d::push_before()
{
	if (count != 0)
	{

		int user_before;
		do
		{
			cout << "\nBefore what count element do you want to insert the new element? ";
			cin >> user_before;
			cin.get();
		} while (user_before < 1 || user_before > count);

		int var;
		cout << "\nEnter new element: ";
		cin >> var;
		cin.get(); // Enter

		Element* before_this = first;
		for (int i = 0; i < user_before-1; i++)
		{
			before_this = before_this->next; // переход к след.
		}

		Element* ptr = new Element; // создание места для нового элемента
		ptr->data = var; // запись в нов. элемент
		ptr->next = before_this->next;
		before_this->next = ptr;
		cout << var << " was added\n";
		count++;
	}
	else cout << "\nNot enough elements!" << endl;
}

// удаление элемента списка
void List_d::pop()
{
	if (first->next)
	{
		int user_del;
		do
		{
			cout << "\nWhat count element do you want to delete? ";
			cin >> user_del;
			cin.get();
		} while (user_del < 1 || user_del > count);

		Element* before_del = first;
		for (int i = 0; i < user_del-1; i++)
		{
			before_del = before_del->next; // переход к след.
		}
		Element* real_del = before_del->next;
		before_del->next = real_del->next;
		cout << user_del << " element was deleted" << endl;
		count--;
	}
	else
		cout << "\nThe list is empty!";
}

// вывод списка
void List_d::show_list()
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
	else cout << "\nThe list is empty!\n";
}

// поиск элемента
void List_d::search()
{
	if (count > 0)
	{
		int search_elem;
		cout << "\nEnter element you want to find: ";
		cin >> search_elem;
		cin.get();

		Element* ptr = first->next; // новый указатель на первый элемент
		int found = 0;

		while (ptr != 0 && ptr->data != search_elem)
		{
			ptr = ptr->next;
		}

		if (ptr)
			cout << search_elem << " was found" << endl;
		else
			cout << search_elem << " wasn't found" << endl;
	}
	else
		cout << "\nThe list is empty!";
}

int main()
{
	List_d S;
	char ans;
	do
	{
		cout << "\nChoose the item:\n" << "1 - show the line\n" <<
			"2 - add new element after certain element\n" <<
			"3 - add new element before certain element\n" <<
			"4 - search the element\n" <<
			"5 - delete certain element\n" <<
			"0 - exit\n";
		ans = _getche();
		if ((ans >= '0') && (ans <= '5'))
		{
			switch (ans)
			{
			case '1': S.show_list(); break;
			case '2': S.push_after(); S.show_list(); break;
			case '3': S.push_before(); S.show_list(); break;
			case '4': S.search(); break;
			case '5': S.pop();  S.show_list(); break;
			case '0': return 0;
			default: break;
			}

		}
		if ((ans >= '0') && (ans <= '5'))
		{
			cout << "\nPress ENTER\n";
			cin.get();
		}
	} while (ans != '0');
	return 0;
}