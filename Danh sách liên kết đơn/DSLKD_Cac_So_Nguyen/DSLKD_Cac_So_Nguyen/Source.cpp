#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

NODE* Khoi_Tao_Node(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void Them_Dau(NODE*& pHead, NODE* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead;
		pHead = p;
	}
}

void Them_Cuoi(NODE*& pHead, NODE* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

void Xoa_Dau(NODE*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else
	{
		NODE* k = pHead;
		pHead = pHead->pNext;
		delete k;
	}
}

void Xoa_Cuoi(NODE*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->pNext == NULL)
	{
		Xoa_Dau(pHead);
		return;
	}
	else
	{
		for (NODE* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext->pNext == NULL)
			{
				NODE* h = k->pNext->pNext;
				k->pNext = NULL;
				delete h;
				break;
			}
		}
	}
}

void Xuat_Danh_Sach(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

void Menu(NODE* pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= DANH SACH LIEN KET DON =========================";
		cout << "\n\t1. Them phan tu vao dau danh sach";
		cout << "\n\t2. Them phan tu vao cuoi danh sach";
		cout << "\n\t3. Xoa phan tu dau danh sach";
		cout << "\n\t4. Xoa phan tu cuoi danh sach";
		cout << "\n\t5. Xuat danh sach";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================== END ===================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu: ";
			cin >> x;
			NODE* p = Khoi_Tao_Node(x);
			Them_Dau(pHead, p);
		}
		else if (luachon == 2)
		{
			int x;
			cout << "\nNhap phan tu: ";
			cin >> x;
			NODE* p = Khoi_Tao_Node(x);
			Them_Cuoi(pHead, p);
		}
		else if (luachon == 3)
		{
			Xoa_Dau(pHead);
		}
		else if (luachon == 4)
		{
			Xoa_Cuoi(pHead);
		}
		else if (luachon == 5)
		{
			cout << "\n\n\t\tDANH SACH LIEN KET DON\n";
			Xuat_Danh_Sach(pHead);
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
	NODE* pHead = NULL;
	Menu(pHead);

	return 0;
}