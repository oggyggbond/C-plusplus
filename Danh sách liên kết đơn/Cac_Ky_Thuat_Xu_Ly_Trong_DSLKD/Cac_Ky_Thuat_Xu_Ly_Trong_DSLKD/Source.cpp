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

void Them_Sau(NODE*& pHead, NODE* p, NODE* q)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE* h = Khoi_Tao_Node(p->data);
			h->pNext = k->pNext;
			k->pNext = h;
			k = k->pNext;
		}
	}
}

void Them_Truoc(NODE*& pHead, NODE* p, NODE* q)
{
	NODE* g = NULL;

	if (q->data == pHead->data && pHead->pNext == NULL)
	{
		Them_Dau(pHead, p);
	}
	else
	{
		for (NODE* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->data == q->data)
			{
				NODE* h = Khoi_Tao_Node(p->data);
				h->pNext = k;
				g->pNext = h;
			}
			g = k;
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

void Xoa_Node_Bat_Ky(NODE*& pHead)
{
	NODE* g = new NODE;
	int x;
	cout << "\nNhap data node can xoa: ";
	cin >> x;

	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->data == x)
	{
		Xoa_Dau(pHead);
	}
	else
	{
		for (NODE* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->data == x)
			{
				g->pNext = k->pNext;
				delete k;
				break;
			}
			g = k;
		}
	}
}

void Reverse(NODE*& pHead)
{
	NODE* prev = NULL;
	NODE* current = pHead;
	NODE* pNext;
	while (current != NULL)
	{
		pNext = current->pNext;
		current->pNext = prev;
		prev = current;
		current = pNext;
	}
	pHead = prev;
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
		cout << "\n\n\t\t =================== DSLKD ======================";
		cout << "\n\t1. Them dau";
		cout << "\n\t2. Them cuoi";
		cout << "\n\t3. Them node p vao sau node q";
		cout << "\n\t4. Them node p vao truoc node q";
		cout << "\n\t5. Xoa dau";
		cout << "\n\t6. Xoa cuoi";
		cout << "\n\t7. Xoa node co data bat ky";
		cout << "\n\t8. Xuat danh sach";
		cout << "\n\t9. Dao nguoc danh sach";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ==================== END =======================";

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
			int x;
			cout << "\nNhap data node q: ";
			cin >> x;
			NODE* q = Khoi_Tao_Node(x);
			int y;
			cout << "\nNhap phan tu can them: ";
			cin >> y;
			NODE* p = Khoi_Tao_Node(y);
			Them_Sau(pHead, p, q);
		}
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap data node q: ";
			cin >> x;
			NODE* q = Khoi_Tao_Node(x);
			int y;
			cout << "\nNhap phan tu can them: ";
			cin >> y;
			NODE* p = Khoi_Tao_Node(y);
			Them_Truoc(pHead, p, q);
		}
		else if (luachon == 5)
		{
			Xoa_Dau(pHead);
		}
		else if (luachon == 6)
		{
			Xoa_Cuoi(pHead);
		}
		else if (luachon == 7)
		{
			Xoa_Node_Bat_Ky(pHead);
		}
		else if (luachon == 8)
		{
			cout << "\n\n\t\t DANH SACH LIEN KET DON\n";
			Xuat_Danh_Sach(pHead);
			system("pause");
		}
		else if (luachon == 9)
		{
			Reverse(pHead);
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