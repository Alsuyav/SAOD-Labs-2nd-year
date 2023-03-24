#include "Header.h"
using namespace std;

// элемент очереди
struct Element
{
	int data;
	Element* right; // указатель на следующий элемент
	Element* left;
};

  
class List_d
{
private:
	Element* first; // первый элемент-заголовок
	int count; // счётчик элементов в массиве, д.б. меньше МАХ-2
	Element* pHead;
public:
	// констурктор
	List_d();

	// добавление элемента в список после заданного
	void push_after();

	// добавление элемента в список перед заданным
	void push_before();

	// удаление элемента из списка
	void pop();

	// вывод списка в прямом направлении
	void show_list_right();

	// вывод списка в обратном направлении
	void show_list_left();

	// поиск элемента в списке
	void search_right();

	// поиск элемента в списке
	void search_left();
};

// констурктор
List_d::List_d()
{
	// добавление фиктивного элемента-заголовка
	Element* pHead = new Element; // создание места для нового элемента, fake - указатель
	pHead->right = pHead;
	pHead->left = pHead;
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
		after_this_insert = after_this_insert->right; // переход к след.
	}

	Element* ptr = new Element; // создание места для нового элемента
	ptr->data = var; // запись в нов. элемент
	ptr->right = after_this_insert->right;
	ptr->left = after_this_insert;
	(after_this_insert->right)->left = ptr;
	after_this_insert->right = ptr; // выбранный элемент указывает на новый
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
		for (int i = 0; i < user_before - 1; i++)
		{
			before_this = before_this->right; // переход к след.
		}

		Element* ptr = new Element; // создание места для нового элемента
		ptr->data = var; // запись в нов. элемент
		ptr->right = before_this->right;
		ptr->left = before_this;
		(before_this->right)->left = ptr;
		before_this->right = ptr; // выбранный элемент указывает на новый
		cout << var << " was added\n";
		count++;
	}
	else cout << "\nNot enough elements!" << endl;
}

// удаление элемента списка
void List_d::pop()
{
	if (count > 0)
	{
		int user_del;
		do
		{
			cout << "\nWhat count element do you want to delete? ";
			cin >> user_del;
			cin.get();
		} while (user_del < 1 || user_del > count);

		Element* del = first;
		for (int i = 0; i < user_del; i++)
		{
			del = del->right; // переход к след.
		}

		(del->left)->right = del->right;
		(del->right)->left = del->left;
		cout << user_del << " element was deleted" << endl;
		count--;
	}
	else
		cout << "\nThe list is empty!";
}

// вывод списка в прямом направлении
void List_d::show_list_right()
{
	if (count > 0) // если указатель не NULL
	{
		Element* ptr = first->right; // новый указатель на первый элемент
		cout << "\nYour line now:\n";
		while (ptr!=first)
		{
			cout << ptr->data << endl; // вывод данных
			ptr = ptr->right; // переход к следующему
		}
	}
	else cout << "\nThe list is empty!\n";
}

// вывод списка в обратном направлении
void List_d::show_list_left()
{
	if (count > 0) // если указатель не NULL
	{
		Element* ptr = first->left; // новый указатель на первый элемент
		cout << "\nYour line now:\n";
		while (ptr != first)
		{
			cout << ptr->data << endl; // вывод данных
			ptr = ptr->left; // переход к следующему
		}
	}
	else cout << "\nThe list is empty!\n";
}

// поиск элемента
void List_d::search_right()
{
	if (count > 0)
	{
		int search_elem;
		cout << "\nEnter element you want to find: ";
		cin >> search_elem;
		cin.get();

		Element* ptr = first->right; 
		
		while (ptr!=first&& ptr->data != search_elem)
		{
			ptr = ptr->right; // переход к следующему
		}

		if (ptr!=first)
			cout << search_elem << " was found" << endl;
		else
			cout << search_elem << " wasn't found" << endl;
	}
	else
		cout << "\nThe list is empty!";
}

void List_d::search_left()
{
	if (count > 0)
	{
		int search_elem;
		cout << "\nEnter element you want to find: ";
		cin >> search_elem;
		cin.get();

		Element* ptr = first->left;

		while (ptr != first && ptr->data != search_elem)
		{
			ptr = ptr->left; // переход к следующему
		}

		if (ptr != first)
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
		cout << "\nChoose the item:\n" << "1 - show the line (right)\n" <<
			"2 - show the line (left)\n" <<
			"3 - add new element after certain element\n" <<
			"4 - add new element before certain element\n" <<
			"5 - search the element (right)\n" <<
			"6 - delete certain element\n" <<
			"7 - search the element (left)\n" <<
			"0 - exit\n";
		ans = _getche();
		if ((ans >= '0') && (ans <= '7'))
		{
			switch (ans)
			{
			case '1': S.show_list_right(); break;
			case '2': S.show_list_left(); break;
			case '3': S.push_after(); S.show_list_right(); break;
			case '4': S.push_before(); S.show_list_right(); break;
			case '5': S.search_right(); break;
			case '6': S.pop();  S.show_list_right(); break;
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
}
