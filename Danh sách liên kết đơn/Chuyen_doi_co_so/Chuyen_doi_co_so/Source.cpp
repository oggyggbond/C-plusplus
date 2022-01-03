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
		cout << "\nKhong du bo nho de cap phat";
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

void Chuyen_doi_co_so(NODE*& pHead, int thapphan, int coso)
{
	while (thapphan != 0)
	{
		int x = thapphan % coso;
		NODE* p = Khoi_tao_node(x);
		Them_dau(pHead, p);
		thapphan = thapphan / coso;
	}
}

void Ket_Qua(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		if (k->data >= 0 && k->data <= 9)
		{
			cout << k->data;
		}
		else
		{
			if (k->data == 10)
			{
				cout << "A";
			}
			else if (k->data == 11)
			{
				cout << "B";
			}
			else if (k->data == 12)
			{
				cout << "C";
			}
			else if (k->data == 13)
			{
				cout << "D";
			}
			else if (k->data == 14)
			{
				cout << "E";
			}
			else
			{
				cout << "F";
			}
		}
	}
}

void Xuat_danh_sach(NODE* pHead)
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

int main()
{
	NODE* pHead = NULL;
	int n;
	cout << "\nNhap so thap phan: ";
	cin >> n;
	int coso;
	cout << "\nNhap co so can chuyen doi(2, 8, 16): ";
	cin >> coso;
	Chuyen_doi_co_so(pHead, n, coso);
	Ket_Qua(pHead);

	Giai_phong_DSLKD(pHead);
	return 0;
}