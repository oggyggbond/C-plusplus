#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

struct QUEUE
{
	NODE* pTop;
};

NODE* Khoi_tao_node(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool IsEmpty(QUEUE q)
{
	if (q.pTop == NULL)
	{
		return true;
	}
	return false;
}

bool Push(QUEUE& q, NODE *p)
{
	if (IsEmpty(q) == true)
	{
		q.pTop = p;
	}
	else
	{
		for (NODE* k = q.pTop; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
	return true;
}

bool Pop(QUEUE& q, int& x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE* k = q.pTop;
		x = q.pTop->data;
		q.pTop = q.pTop->pNext;
		delete k;
	}
	return true;
}

bool Top(QUEUE q, int& x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pTop->data;
	return true;
}

void Giai_phong_QUEUE(QUEUE& q)
{
	NODE* k = q.pTop;
	while (q.pTop != NULL)
	{
		q.pTop = q.pTop->pNext;
		delete k;
		k = q.pTop;
	}
}

void Menu(QUEUE q)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ==================== QUAN LY QUEUE ====================";
		cout << "\n\t1. Push phan tu vao queue";
		cout << "\n\t2. Pop phan tu khoi queue - xuat queue";
		cout << "\n\t3. Xem phan tu o dau queue";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ========================= END =========================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu: ";
			cin >> x;
			NODE* p = Khoi_tao_node(x);
			Push(q, p);
		}
		else if (luachon == 2)
		{
			while (IsEmpty(q) == false)
			{
				int x;
				Pop(q, x);
				cout << x << " ";
			}
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(q, x);
			cout << x;
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	QUEUE q;
	q.pTop = NULL;
	Menu(q);

	Giai_phong_QUEUE(q);
	return 0;
}