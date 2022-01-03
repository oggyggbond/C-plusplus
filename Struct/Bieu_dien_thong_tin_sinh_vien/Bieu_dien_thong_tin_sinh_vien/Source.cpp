#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct SV
{
	string hoten;
	string maso;
	float diemKTLT, diemTRR, diemCTDLGT, diemTB;
};

void Nhap_DS_thong_tin_SV(SV &x)
{
	while (getchar() != '\n');
	cout << "\n\tNhap ho ten sinh vien: ";
	getline(cin, x.hoten);
	cout << "\n\tNhap ma so sinh vien: ";
	getline(cin, x.maso);
	cout << "\n\tNhap diem ki thuat lap trinh: ";
	cin >> x.diemKTLT;
	cout << "\n\tNhap diem toan roi rac: ";
	cin >> x.diemTRR;
	cout << "\n\tNhap diem cau truc du lieu va giai thuat: ";
	cin >> x.diemCTDLGT;
	x.diemTB = ((x.diemKTLT) + (x.diemTRR) + (x.diemCTDLGT)) / 3;
}

void Xuat_DS_thong_tin_SV(SV x)
{
	cout << "\n\n\tHo ten: " << x.hoten;
	cout << "\n\n\tMa so: " << x.maso;
	cout << "\n\n\tDiem ki thuat lap trinh: " << x.diemKTLT;
	cout << "\n\n\tDiem toan roi rac: " << x.diemTRR;
	cout << "\n\n\tDiem cau truc du lieu va giai thuat: " << x.diemCTDLGT;
	cout << "\n\n\tDiem trung binh la: " << x.diemTB;
}

void Nhap_DS_thong_tin_nhieu_SV(SV ds[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\t\tNhap thong tin sinh vien thu " << i + 1 << endl;
		Nhap_DS_thong_tin_SV(ds[i]);
	}
}

void Xuat_DS_thong_tin_nhieu_SV(SV ds[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\t\tXuat thong tin sinh vien thu " << i + 1 << endl;
		Xuat_DS_thong_tin_SV(ds[i]);
	}
}

void Xep_Loai_SV(SV x)
{
	float diemTB = ((x.diemKTLT) + (x.diemTRR) + (x.diemCTDLGT)) / 3;
	if (diemTB < 4)
	{
		cout << " Yeu " << endl;
	}
	else if (diemTB > 4 && diemTB < 6.5)
	{
		cout << " Trung binh " << endl;
	}
	else if (diemTB > 6.5 && diemTB < 8)
	{
		cout << " Kha " << endl;
	}
	else if (diemTB >= 8 && diemTB < 9.8)
	{
		cout << " Gioi " << endl;
	}
	else
		cout << " Xuat sac " << endl;
}

void Xep_loai_nhieu_SV(SV ds[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tSinh vien thu " << i + 1;
		Xep_Loai_SV(ds[i]);
	}
}

void Hoan_vi(SV& x, SV& y)
{
	SV tam = x;
	x = y;
	y = tam;
}

void Sap_Xep_SV_Tang_Dan_Theo_DTB(SV ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ds[i].diemTB > ds[j].diemTB)
			{
				Hoan_vi(ds[i], ds[j]);
			}
		}
	}
}

void Sap_Xep_SV_Giam_Dan_Theo_Ten(SV ds[], int n)
{

}

int main()
{
	SV ds[100];
	int n;
	cout << " Nhap so luong sinh vien: ";
	cin >> n;
	cout << "\n\n\t\tNhap danh sach thong tin sinh vien: " << endl;
	Nhap_DS_thong_tin_nhieu_SV(ds,n);
	cout << "\n\n\t\tXuat danh sach thong tin sinh vien: " << endl;
	Xuat_DS_thong_tin_nhieu_SV(ds,n);
	cout << "\n\n\t\tXep loai: " << endl;
	Xep_loai_nhieu_SV(ds,n);
	Sap_Xep_SV_Tang_Dan_Theo_DTB(ds, n);
	Xuat_DS_thong_tin_nhieu_SV(ds, n);



	return 0;
}