#include <iostream>
using namespace std;

struct PHANSO
{
	int tuso;
	int mauso;
};

void Nhap_phan_so(PHANSO& ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuso;
	cout << "\nNhap mau so: ";
	cin >> ps.mauso;
}

void Xuat_phan_so(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

struct NODE
{
	PHANSO data;
	NODE* pNext;
};

NODE* Khoi_tao_node(PHANSO ps)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat";
		return NULL;
	}
	p->data = ps;
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

void Xoa_dau(NODE*& pHead)
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

void Xoa_cuoi(NODE*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->pNext == NULL)
	{
		Xoa_dau(pHead);
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

void Xuat_danh_sach_cac_phan_so(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		Xuat_phan_so(k->data);
		cout << endl;
	}
}

void Menu(NODE* pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ====================== QUAN LY DANH SACH PHAN SO ======================";
		cout << "\n\t1. Them phan so vao dau danh sach";
		cout << "\n\t2. Them phan so vao cuoi danh sach";
		cout << "\n\t3. Xuat phan so";
		cout << "\n\t4. Xoa phan so dau danh sach";
		cout << "\n\t5. Xoa phan so cuoi danh sach";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================ END =================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHANSO ps;
			cout << "\n\n\t\tNHAP PHAN SO\n";
			Nhap_phan_so(ps);
			cout << "\n\n\t\tTHEM PHAN SO VAO DAU DANH SACH\n";
			NODE* p = Khoi_tao_node(ps);
			Them_dau(pHead, p);
		}
		else if (luachon == 2)
		{
			PHANSO ps;
			cout << "\n\n\t\tNHAP PHAN SO\n";
			Nhap_phan_so(ps);
			cout << "\n\n\t\tTHEM PHAN SO VAO CUOI DANH SACH\n";
			NODE* p = Khoi_tao_node(ps);
			Them_cuoi(pHead, p);
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\tDANH SACH PHAN SO\n";
			Xuat_danh_sach_cac_phan_so(pHead);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\tXOA PHAN SO DAU DANH SACH\n";
			Xoa_dau(pHead);
		}
		else if (luachon == 5)
		{
			cout << "\n\n\t\tXOA PHAN SO CUOI DANH SACH\n";
			Xoa_cuoi(pHead);
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