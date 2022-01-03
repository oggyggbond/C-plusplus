#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

struct STACK
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

bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}

bool Push(STACK& s, NODE* p)
{
	if (IsEmpty(s) == true)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}

bool Pop(STACK& s, int& x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE* k = s.pTop;
		x = s.pTop->data;
		s.pTop = s.pTop->pNext;
		delete k;
	}
	return true;
}

bool Top(STACK s, int& x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

void Giai_phong_STACK(STACK& s)
{
	NODE* k = s.pTop;
	while (s.pTop != NULL)
	{
		s.pTop = s.pTop->pNext;
		delete k;
		k = s.pTop;
	}
}

void Menu(STACK s)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======================= QUAN LY STACK =======================";
		cout << "\n\t1. Push phan tu vao stack";
		cout << "\n\t2. Pop phan tu ra khoi stack - xuat stack";
		cout << "\n\t3. Xem phan tu dau stack";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============================ END ============================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu: ";
			cin >> x;
			NODE* p = Khoi_tao_node(x);
			Push(s, p);
		}
		else if (luachon == 2)
		{
			while (IsEmpty(s) == false)
			{
				int x;
				Pop(s, x);
				cout << x << " ";
			}
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(s, x);
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
	STACK s;
	s.pTop = NULL;
	Menu(s);

	Giai_phong_STACK(s);
	return 0;
}