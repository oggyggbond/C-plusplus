#include <iostream>
#include <string.h>
using namespace std;

struct NODE
{
	char data;
	NODE* pNext;
};

NODE* Khoi_tao_node(char x)
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

void Them_cuoi(NODE*& pHead, NODE* p)
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

void Sap_xep_giam_dan(NODE*& pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		for (NODE* l = k->pNext; l != NULL; l = l->pNext)
		{
			if (k->data < l->data)
			{
				char c = k->data;
				k->data = l->data;
				l->data = c;
			}
		}
	}
}

void Xuat_danh_sach_cac_ky_tu(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

int main()
{
	NODE* pHead = NULL;
	int n;
	cout << "\nNhap so luong ky tu can them: ";
	cin >> n;
	char x;
	for (int i = 1; i <= n; i++)
	{
		cout << "\nNhap ky tu can them thu " << i << " : ";
		cin >> x;
		NODE* p = Khoi_tao_node(x);
		Them_cuoi(pHead, p);
	}
	Sap_xep_giam_dan(pHead);
	Xuat_danh_sach_cac_ky_tu(pHead);

	return 0;
}