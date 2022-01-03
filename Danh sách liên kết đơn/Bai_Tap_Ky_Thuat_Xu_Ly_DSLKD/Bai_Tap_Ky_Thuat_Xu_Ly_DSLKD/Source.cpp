#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

NODE* Khoi_tao_node(int x)
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

void Them_dau(NODE*& pHead, NODE* p)
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

void Them_node_vao_sau_node(NODE*& pHead, NODE* p)
{
	int x;
	cout << "\nNhap data node q: ";
	cin >> x;
	NODE* q = Khoi_tao_node(x);
	if (q->data == pHead->data && pHead->pNext == NULL)
	{
		Them_Cuoi(pHead, p);
	}
	else
	{
		for (NODE* k = pHead; k != NULL; k = k->pNext)
		{
			if (q->data == k->data)
			{
				NODE* h = Khoi_tao_node(p->data);
				h->pNext = k->pNext;
				k->pNext = h;
				k = k->pNext;
			}
		}
	}
}

void Them_node_vao_truoc_node(NODE*& pHead, NODE *p)
{
	int x;
	cout << "\nNhap data node q: ";
	cin >> x;
	NODE* q = Khoi_tao_node(x);
	NODE* g = NULL;
	if (q->data == pHead->data && pHead->pNext == NULL)
	{
		Them_dau(pHead, p);
	}
	else
	{
		for (NODE* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->data == q->data)
			{
				NODE* h = Khoi_tao_node(p->data);
				h->pNext = k;
				g->pNext = h;
			}
			g = k;
		}
	}
}

void Xoa_node_bat_ky(NODE*& pHead)
{
	NODE* g = new NODE;
	int x;
	cout << "\nNhap node co data can xoa: ";
	cin >> x;

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

void Xuat_Danh_Sach(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

void Giai_phong_DSLKD(NODE*& pHead)
{
	NODE* k = pHead;
	while (pHead != NULL)
	{
		pHead = pHead->pNext;
		delete k;
		k = pHead;
	}
}

void Menu(NODE* pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= KY THUAT XU LY DSLKD =========================";
		cout << "\n\t1. Them phan tu vao cuoi danh sach";
		cout << "\n\t2. Xuat danh sach";
		cout << "\n\t3. Them node p vao sau node q";
		cout << "\n\t4. Them node p vao truoc node q";
		cout << "\n\t5. Xoa node co data bat ky";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================== END ==================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu: ";
			cin >> x;
			NODE* p = Khoi_tao_node(x);
			Them_Cuoi(pHead, p);
		}
		else if (luachon == 2)
		{
			Xuat_Danh_Sach(pHead);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE* p = Khoi_tao_node(x);
			Them_node_vao_sau_node(pHead, p);
		}
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE* p = Khoi_tao_node(x);
			Them_node_vao_truoc_node(pHead, p);
		}
		else if (luachon == 5)
		{
			Xoa_node_bat_ky(pHead);
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
	
	Giai_phong_DSLKD(pHead);
	return 0;
}