#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Node
{
	Node* next = nullptr;
	Node* prev = nullptr;
	string a;
};
struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;
};

void Menu();

bool Chek(List* list);

void push_buck(List* list);
void del_buck(List* list);

void push_front(List* list);
void del_front(List* list);

void PushK(List* list);
void DelK(List* list);

void DelList(List* list);
void CoutList(List* list);

int main()
{
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	List* list = new List;
	int i;
	bool F = 1;
	while (F)
	{
		Menu();
		cout << "������� ����� ��������" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			system("cls");
			push_front(list);
			break;
		}
		case 2:
		{
			system("cls");
			push_buck(list);
			break;
		}
		case 3:
		{
			system("cls");
			del_front(list);
			break;
		}
		case 4:
		{
			system("cls");
			del_buck(list);
			break;
		}
		case 5:
		{
			system("cls");
			PushK(list);
			break;
		}
		case 6:
		{
			system("cls");
			DelK(list);
			break;
		}
		case 7:
		{
			system("cls");
			CoutList(list);
			break;
		}
		case 8:
		{
			system("cls");
			DelList(list);
		}
		case 9:
			F = 0;
			break;
		default:
		{
			cout << "�������� ����� �������� ������� ���� � ����" << endl;
		}
		}
	}
}

void Menu()
{
	cout << "\t ����" << endl;
	cout << "1) �������� ������� � ����� ������" << endl;
	cout << "2) �������� ������� � ����� ������" << endl;
	cout << "3) ������� � ��������� �� ������ ������" << endl;
	cout << "4) ������� � ��������� �� ����� ������" << endl;
	cout << "5) �������� � ��������� � �������� ������" << endl;
	cout << "6) ������� � ��������� � �������� ������" << endl;
	cout << "7) ������� ������ �� �����" << endl;
	cout << "8) �������� ������" << endl;
	cout << "9) ���������� ������ �� �������" << endl;
}

void push_front(List* list)
{
	list->size++;
	Node* node = new Node;
	cout << "������� ������" << endl;
	getline(cin >> ws, node->a);
	if (Chek(list))
	{
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
	}
}
void del_front(List* list)
{
	int i, i1;
	CoutList(list);
	cout << "������� ������� ����� ������� ��������� �� ������ ������" << endl;
	cin >> i;
	i1 = i;
	if (Chek(list))
	{
		if (i < list->size)
		{
			while (i > 0)
			{
				Node* temp = list->head;
				list->head = list->head->next;
				list->head->prev = nullptr;
				delete temp;
				i--;
			}
			list->size = list->size - i1;
			cout << "�������� ������" << endl;
		}
		else
		{
			cout << "� ������ ���������� ��������� ������ ��� �����, ���������� ��������� ������� ���� �������, ������� ��������� ���� ������." << endl;
			DelList(list);
		}
	}
	else
	{
		cout << "������ ����" << endl;
	}
}

void push_buck(List* list)
{
	list->size++;
	Node* node = new Node;
	cout << "������� ������" << endl;
	getline(cin >> ws, node->a);
	if (Chek(list))
	{
		list->tail->next = node;
		node->prev = list -> tail;
		list->tail = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
	}
}
void del_buck(List* list)
{
	int i, i1;
	CoutList(list);
	cout << "������� ������� ��������� ����� ������� � ����� ������" << endl;
	cin >> i;
	i1 = i;
	if (Chek(list))
	{
		if (i < list->size)
		{
			while (i > 0)
			{
				Node* temp = list -> tail;
				list->tail = list->tail->prev;
				list->tail->next = nullptr;
				delete temp;
				i--;
			}
			list->size = list->size - i1;
			cout << "�������� �������" << endl;
		}
		else
		{
			cout << "� ������ ���������� ��������� ������ ��� �����, ���������� ��������� ������� ���� �������, ������� ��������� ���� ������." << endl;
			DelList(list);
		}
	}
	else
	{
		cout << "������ ����" << endl;
	}
}

void PushK(List* list)
{
	int n, i, i1;
	int k;
	CoutList(list);
	cout << "������� ������� � �������� ������� ���������� ��������� ������ ����������" << endl;
	cin >> n;
	cout << "������� ���������� �������� ���������" << endl;
	cin >> i;
	i1 = i;
	if (Chek(list))
	{
		if ((n <= list->size) && (n > 0))
		{
			if (n < (list->size) / 2)
			{
				k = 1;
				Node* temp = list->head;
				while (k < n)
				{
					temp = temp->next;
					k++;
				}
				Node* temp1;
				while (i > 0)
				{
					Node* node = new Node;
					getline(cin >> ws, node->a);
					temp1 = temp->next;
					node->next = temp1;
					temp->next = node;
					node->prev = temp;
					temp1->prev = node;
					temp = node;
					i--;
				}
			}
			else
			{
				k = list->size;
				Node* temp = list->tail;
				while (k > n)
				{
					temp = temp->prev;
					k--;
				}
				Node* temp1;
				while (i > 0)
				{
					Node* node = new Node;
					cout << "������� ������" << endl;
					getline(cin >> ws, node->a);
					temp1 = temp->next;
					node->next = temp1;
					temp->next = node;
					node->prev = temp;
					temp1->prev = node;
					temp = node;
					i--;
				}
			}
			list->size = list->size + i1;
		}
		else
		{
			cout << "������ �������� ��� � ������" << endl;
		}
	}
	else
	{
		cout << "������ ����" << endl;
	}
}
void DelK(List*list)
{
	int n, i, i1;
	int k;
	CoutList(list);
	cout << "������� ������� � �������� ������� �������� ���������" << endl;
	cin >> n;
	cout << "������� ���������� ��������� ���������" << endl;
	cin >> i;
	i1 = i;
	if (Chek(list))
	{
		if ((n <= list->size) && (n > 0))
		{
			if (n < (list->size) / 2)
			{
				k = 1;
				Node* temp = list->head;
				while (k < n)
				{
					temp = temp->next;
					k++;
				}
				i--;
				while (i > 0)
				{
					Node* temp1 = temp->next;
					temp1->prev = temp;
					temp->next = temp1->next;
					delete temp1;
					i--;
				}
				cout << "� ������ ���������� ��������� ������ ��� �����, ���������� ��������� ������� ���� �������, ������� ��������� ���� ������." << endl;
				list->size = list->size - i1;
			}
			else
			{
				k = list->size;
				Node* temp = list->tail;
				while (k > n)
				{
					temp = temp->prev;
					k--;
				}
				i--;
				while (i > 0)
				{
					Node* temp1 = temp->next;
					temp1->prev = temp;
					temp->next = temp1->next;
					delete temp1;
					i--;
				}
				cout << "�������� �������" << endl;
				list->size = list->size - i1;
			}
		}
		else
		{
			cout << "������ �������� ��� � ������" << endl;
		}
	}
	else
	{
		cout <<"������ ����" << endl;
	}
}

void DelList(List* list)
{
	Node* temp = list->head;
	while (temp != NULL)
	{
		Node* temp1 = temp;
		temp = temp->next;
		temp->prev = nullptr;
		delete temp1;
	}
	cout << "������ �����" << endl;
	list->size = 0;
}
bool Chek(List* list)
{
	if (list->head == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CoutList(List* list)
{
	Node* temp = list->head;
	int i = 1;
	while (temp != NULL)
	{
		cout << i << ") " << temp->a << endl;
		temp = temp->next;
		i++;
	}
}