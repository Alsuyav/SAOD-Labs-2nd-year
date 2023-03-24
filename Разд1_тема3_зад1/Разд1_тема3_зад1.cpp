#include "Header.h"
using namespace std;

// элемент списка
struct Element
{
	int data;
	int next; // номер следующего элемента
};

class List_s
{
private:
	enum { MAX = 10 }; // макс. число элементов в списке
	Element list[MAX]; // сам список
	Element help_list[MAX]; // вспомогательный список (учёта своб. ячеек)
	int Start_free; // переменная для добавления элементов (учёта своб. ячеек)
	int count; // счётчик элементов в массиве, д.б. меньше МАХ-2
public:
	// констурктор
	List_s();

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
List_s::List_s() {
	for (int i = 0; i < MAX; i++) // заполение базового массива ссылками нулями
	{
		list[i].next = 0;
	}
	count = 0; // пока нет элементов
	for (int i = 1; i < MAX-1; i++) // заполение вспомогат. массива
	{
		help_list[i].next = i + 1;
	}
	help_list[MAX-1].next = 0;
	Start_free = 1; // первая свободная ячейка
}

// добавление элемента в список после заданного
void List_s::push_after()
{
	if (count < MAX-1)
	{
		int user_after;
		do
		{
			cout << "\nAfter what count element do you want to insert the new element? ";
			cin >> user_after;
			cin.get();
		} while (user_after < 0 || user_after > count);

		int newel;
		cout << "\nEnter new element: ";
		cin >> newel;
		cin.get();

		int real_num_after = 0; // реальный номер элемента после которого нужно вставить новый
								// ему присваивается номер элемента заголовка
		for (int i = 0; i < user_after; i++) // проход по массиву до нужного номера элемнта
		{
			real_num_after = list[real_num_after].next;
		}
		

		list[Start_free].next = list[real_num_after].next; // ссылка на след. после выбранного элемента помещается в новый элемент
		list[real_num_after].next = Start_free; // выбранный элемент теперь ссылается на новый 
		list[Start_free].data = newel; // запись данных в нов. элемент
		Start_free = help_list[Start_free].next; // переход к след. свободной ячейке
		cout << newel << " was added" << endl;
		count++;
	}
	else cout << "\nThe list is full!" << endl;
}

// добавление элемента в список перед заданным
void List_s::push_before()
{
	if (count != 0)
	{
		if (count < MAX - 1)
		{
			int user_before;
			do
			{
				cout << "\nBefore what count element do you want to insert the new element? ";
				cin >> user_before;
				cin.get();
			} while (user_before < 1 || user_before > count);

			int newel;
			cout << "\nEnter new element: ";
			cin >> newel;
			cin.get();

			int before_real_num = 0; // реальный номер элемента до      выбран.польз-лем элемента (перед кот. нужно вставить новый)
									// номер элемента заголовка
			for (int i = 0; i < user_before - 1; i++) // проход по массиву до нужного номера элемента
			{
				before_real_num = list[before_real_num].next;
			}


			list[Start_free].next = list[before_real_num].next; // ссылка на выбран.польз-лем элемент помещается в новый элемент
			list[before_real_num].next = Start_free; // элемент до выбран.польз-лем теперь ссылается на новый 
			list[Start_free].data = newel; // запись данных в нов. элемент
			Start_free = help_list[Start_free].next; // переход к след. свободной ячейке
			cout << newel << " was added" << endl;
			count++;
		}
		else cout << "\nThe list is full!" << endl;
	}
	else cout << "\nNot enough items!" << endl;
}

// удаление элемента списка
void List_s::pop()
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

		int before_del = 0; // реальный номер элемента до того, который нужно удалить
							// присваивается номер элемента заголовка
		for (int i = 0; i < user_del - 1; i++) // проход по массиву до нужного номера элемента
		{
			before_del = list[before_del].next;
		}

		int real_del = list[before_del].next;
		list[before_del].next = list[real_del].next; // элемент до удаляемого теперь ссылается на элемент после удаляемого
													// или 0, если удаляемый - последний элемент
		help_list[real_del].next = Start_free; // ячейка удаляемого элементв в вспомагательном массиве теперь
												// указывает на первую вакантную ячейку этого массива
		Start_free = real_del; // теперь это первая вакантная ячейка массива
		
		cout << user_del << " element was deleted" << endl;
		count--;
	}
	else
		cout << "\nThe list is empty!";
}

// вывод списка
void List_s::show_list()
{
	if (count > 0)
	{
		int current = list[0].next;
		cout << "\n\nYour list now:\n";
		while (current!=0)
		{
			cout << list[current].data << endl;
			current = list[current].next;
		}
	}
	else
		cout << "\nThe list is empty!";
}

// поиск элемента
void List_s::search()
{
	if (count > 0)
	{
		int search_elem;
		int current = list[0].next;
		cout << "\nEnter element you want to find: ";
		cin >> search_elem;
		cin.get();
		
		while (current != 0 && list[current].data != search_elem)
		{
			current = list[current].next;
		}
		
		if (current)
			cout << search_elem << " was found" << endl;
		else
			cout << search_elem << " wasn't found" << endl;
	}
	else
		cout << "\nThe list is empty!";
}

int main()
{
	List_s S;
	char ans;
	do
	{
		cout << "\nChoose the item:\n" <<
			"1 - show the line\n" <<
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
			case '2': S.push_after();  break;
			case '3': S.push_before(); break;
			case '4': S.search(); break;
			case '5': S.pop(); break;
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