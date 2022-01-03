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

int Tim_UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}

PHANSO Rut_gon_1_phan_so(PHANSO ps)
{
	int x = Tim_UCLN(ps.tuso, ps.mauso);
	ps.tuso = ps.tuso / x;
	ps.mauso = ps.mauso / x;
	return ps;
}

void Rut_gon_cac_phan_so(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		 k->data = Rut_gon_1_phan_so(k->data);
	}
}


PHANSO Cong_2_Phan_So(PHANSO x, PHANSO y)
{
	PHANSO k;
	k.tuso = (x.tuso * y.mauso) + (x.mauso * y.tuso);
	k.mauso = (x.mauso * y.mauso);
	return k;
}

PHANSO Cong_Cac_Phan_So(NODE* pHead)
{
	PHANSO sum = pHead->data;
	for (NODE* k = pHead->pNext; k != NULL; k = k->pNext)
	{
		sum = Cong_2_Phan_So(sum, k->data);
	}
	return sum;
}

PHANSO Tim_phan_so_max(NODE* pHead)
{
	float max = (float)pHead->data.tuso / pHead->data.mauso;
	PHANSO h;
	for (NODE* k = pHead->pNext; k != NULL; k = k->pNext)
	{
		float x = (float)k->data.tuso / k->data.mauso;
		if (max < x)
		{
			max = x;
			h = k->data;
		}
	}
	return h;
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
		cout << "\n\n\t\t ========================== THAO TAC VOI PHAN SO ==========================";
		cout << "\n\t1. Nhap phan so";
		cout << "\n\t2. Rut gon";
		cout << "\n\t3. Tinh tong";
		cout << "\n\t4. Tim phan so lon nhat";
		cout << "\n\t5. Xuat danh sach phan so";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================== END ==================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHANSO ps;
			Nhap_phan_so(ps);
			NODE* p = Khoi_tao_node(ps);
			Them_cuoi(pHead, p);
		}
		else if (luachon == 2)
		{
			Rut_gon_cac_phan_so(pHead);
			Xuat_danh_sach_cac_phan_so(pHead);
			system("pause");
		}
		else if (luachon == 3)
		{
			PHANSO ps = Cong_Cac_Phan_So(pHead);
			ps = Rut_gon_1_phan_so(ps);
			if (ps.mauso == 1)
			{
				cout << ps.tuso;
			}
			else
			{
				Xuat_phan_so(ps);
			}
			system("pause");
		}
		else if (luachon == 4)
		{
			PHANSO max = Tim_phan_so_max(pHead);
			Xuat_phan_so(max);
			system("pause");
		}
		else if (luachon == 5)
		{
			Xuat_danh_sach_cac_phan_so(pHead);
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