#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>
#pragma warning(disable: 4996) 
using namespace std;

struct SINHVIEN
{
	string hoten;
	string maso;
	float diemtb;
};

void Nhap_Thong_Tin_SV(SINHVIEN& x)
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten sinh vien: ";
	getline(cin, x.hoten);
	cout << "\nNhap ma so sinh vien: ";
	getline(cin, x.maso);
	cout << "\nNhap diem trung binh cua sinh vien: ";
	cin >> x.diemtb;
}

void Xuat_Thong_Tin_SV(SINHVIEN x)
{
	cout << "\nHo ten: " << x.hoten;
	cout << "\nMa so: " << x.maso;
	cout << "\nDiem trung binh: " << x.diemtb;
}

struct NODE
{
	SINHVIEN data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;

void ThemNode(TREE& t, SINHVIEN x)
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
		if (stricmp(x.maso.c_str(), t->data.maso.c_str()) > 0)
		{
			ThemNode(t->pRight, x);
		}
		else if (stricmp(x.maso.c_str(), t->data.maso.c_str()) < 0)
		{
			ThemNode(t->pLeft, x);
		}
	}
}

void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << "\n\n\t\t THONG TIN SINH VIEN\n";
		Xuat_Thong_Tin_SV(t->data);
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

void Xuat_thong_tin_sv_co_ma_so_bat_ky(TREE t, string ms)
{
	if (t != NULL)
	{	
		if (ms == t->data.maso)
		{
			cout << "\n\n\t\t THONG TIN SINH VIEN\n";
			Xuat_Thong_Tin_SV(t->data);
		}
		Xuat_thong_tin_sv_co_ma_so_bat_ky(t->pLeft, ms);
		Xuat_thong_tin_sv_co_ma_so_bat_ky(t->pRight, ms);
	}
}

void Tim_node_the_mang(TREE& k, TREE& j)
{
	if (j->pLeft != NULL)
	{
		Tim_node_the_mang(k, j->pLeft);
	}
	else
	{
		k->data = j->data;
		k = j;
		j = j->pRight;
	}
}

void Xoa_Sv_Co_Ma_So_Bat_Ky(TREE& t, string ms)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (stricmp(ms.c_str(), t->data.maso.c_str()) > 0)
		{
			Xoa_Sv_Co_Ma_So_Bat_Ky(t->pRight, ms);
		}
		else if (stricmp(ms.c_str(), t->data.maso.c_str()) < 0)
		{
			Xoa_Sv_Co_Ma_So_Bat_Ky(t->pLeft, ms);
		}
		else
		{
			NODE* k = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else
			{
				Tim_node_the_mang(k, t->pRight);
			}
			delete k;
		}
	}
}

void Menu(TREE t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= CAY NHI PHAN TIM KIEM SINH VIEN =========================";
		cout << "\n\t1. Nhap thong tin sinh vien";
		cout << "\n\t2. Xuat danh sach sinh vien";
		cout << "\n\t3. Xuat thong tin sinh vien co ma so bat ky";
		cout << "\n\t4. Xoa sinh vien co ma so bat ky";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ======================================= END =======================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			SINHVIEN x;
			cout << "\n\n\t\t NHAP THONG TIN SINH VIEN\n";
			Nhap_Thong_Tin_SV(x);
			ThemNode(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH SINH VIEN\n";
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			while (getchar() != '\n');
			string ms;
			cout << "\nNhap ma so sinh vien: ";
			getline(cin, ms);
			Xuat_thong_tin_sv_co_ma_so_bat_ky(t, ms);
			system("pause");
		}
		else if (luachon == 4)
		{
			while (getchar() != '\n');
			string ms;
			cout << "\nNhap ma so sinh vien muon xoa: ";
			getline(cin, ms);
			Xoa_Sv_Co_Ma_So_Bat_Ky(t, ms);
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