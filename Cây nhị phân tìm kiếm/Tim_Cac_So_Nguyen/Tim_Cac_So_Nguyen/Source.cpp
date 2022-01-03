#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;

void ThemNode(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x > t->data)
		{
			ThemNode(t->pRight, x);
		}
		else if (x < t->data)
		{
			ThemNode(t->pLeft, x);
		}
	}
}

void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

bool Kiem_tra_so_doi_xung(int n)
{
	int tmp = n, y = 0;
	while (tmp > 0)
	{
		int x = tmp % 10;
		y = y * 10 + x;
		tmp = tmp / 10;
	}
	if (y == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Xuat_So_Doi_Xung(TREE t)
{
	if (t != NULL)
	{
		if (Kiem_tra_so_doi_xung(t->data) == true)
		{
			cout << t->data << " ";
		}
		Xuat_So_Doi_Xung(t->pLeft);
		Xuat_So_Doi_Xung(t->pRight);
	}
}

bool Kiem_tra_so_chinh_phuong(int n)
{
	if ((sqrt((float)n)) == (((int)sqrt((float)n))))
	{
		return true;
	}
	return false;
}

void Xuat_So_Chinh_Phuong(TREE t)
{
	if (t != NULL)
	{
		if (Kiem_tra_so_chinh_phuong(t->data) == true)
		{
			cout << t->data << " ";
		}
		Xuat_So_Chinh_Phuong(t->pLeft);
		Xuat_So_Chinh_Phuong(t->pRight);
	}
}

bool Kiem_tra_so_hoan_thien(int n)
{
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			s = s + i;
		}
	}
	if (s == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tinh_Tong_Cac_So_Hoan_Thien(TREE t, int &s)
{
	if (t != NULL)
	{
		if (Kiem_tra_so_hoan_thien(t->data) == true)
		{
			s = s + t->data;
		}
		Tinh_Tong_Cac_So_Hoan_Thien(t->pLeft, s);
		Tinh_Tong_Cac_So_Hoan_Thien(t->pRight, s);
	}
}

int Tim_So_Lon_Nhat(TREE t)
{
	if (t->pRight == NULL)
	{
		return t->data;
	}
	return Tim_So_Lon_Nhat(t->pRight);
}

int Tim_So_Nho_Nhat(TREE t)
{
	if (t->pLeft == NULL)
	{
		return t->data;
	}
	return Tim_So_Nho_Nhat(t->pLeft);
}

void Menu(TREE t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= BINARY SEARCH TREE =========================";
		cout << "\n\t1. Nhap phan tu";
		cout << "\n\t2. Duyet cay";
		cout << "\n\t3. Xuat cac so doi xung";
		cout << "\n\t4. Xuat cac so chinh phuong";
		cout << "\n\t5. Tinh tong cac so hoan thien";
		cout << "\n\t6. Tim so lon nhat trong cay";
		cout << "\n\t7. Tim so nho nhat trong cay";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================ END ================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			ThemNode(t, x);
		}
		else if (luachon == 2)
		{
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t CAC SO DOI XUNG: ";
			Xuat_So_Doi_Xung(t);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t CAC SO CHINH PHUONG: ";
			Xuat_So_Chinh_Phuong(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\n\t TONG CAC SO HOAN THIEN LA: ";
			int s = 0;
			Tinh_Tong_Cac_So_Hoan_Thien(t, s);
			cout << s;
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\n\t SO LON NHAT LA: ";
			cout << Tim_So_Lon_Nhat(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			cout << "\n\n\t SO NHO NHAT LA: ";
			cout << Tim_So_Nho_Nhat(t);
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
	TREE t;
	t = NULL;
	Menu(t);
	
	return 0;
}