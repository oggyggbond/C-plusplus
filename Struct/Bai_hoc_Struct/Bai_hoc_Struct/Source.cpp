#include <iostream>
#include<string>
#include <conio.h>
using namespace std;

struct SINHVIEN
{
	string hoten;
	string maso;
	int namsinh;
	float diemtb;
};

void Nhap_Thong_Tin_1_SV(SINHVIEN &x)
{
	while (getchar() != '\n');
	cout << "\n\tNhap ho ten sinh vien: ";
	getline(cin, x.hoten);
	cout << "\n\tNhap ma so sinh vien: ";
	getline(cin, x.maso);
	cout << "\n\tNhap nam sinh: ";
	cin >> x.namsinh;
	cout << "\n\tNhap diem trung binh: ";
	cin >> x.diemtb;
}

void Xuat_Thong_Tin_1_SV(SINHVIEN x)
{
	cout << "\n\tHo ten: " << x.hoten << endl;
	cout << "\n\tMa so: " << x.maso << endl;
	cout << "\n\tNam sinh: " << x.namsinh << endl;
	cout << "\n\tDiem trung binh: " << x.diemtb << endl;
}

void Nhap_Danh_Sach_SV(SINHVIEN ds[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\tNhap thong tin sinh vien thu " << i + 1;
		cout << endl;
		Nhap_Thong_Tin_1_SV(ds[i]);
	}
}

void Xuat_Danh_Sach_SV(SINHVIEN ds[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\tThong tin sinh vien thu " << i + 1;
		cout << endl;
		Xuat_Thong_Tin_1_SV(ds[i]);
	}
}

void Hoan_vi(SINHVIEN& x, SINHVIEN& y)
{
	SINHVIEN tmp = x;
	x = y;
	y = tmp;
}

void Sap_Xep_SV_Tang_Dan_Theo_DiemTB(SINHVIEN ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ds[i].diemtb > ds[j].diemtb)
			{
				Hoan_vi(ds[i], ds[j]);
			}
		}
	}
}

void Xoa(SINHVIEN ds[], int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		ds[i - 1] = ds[i];
	}
	n--;
}

void Xoa_SV_Co_Ma_So_Bat_Ky(SINHVIEN ds[], int& n)
{
	while (getchar() != '\n');
	string ms;
	cout << "\n\tNhap ma so sinh vien muon xoa: ";
	getline(cin, ms);
	for (int i = 0; i < n; i++)
	{
		if (ds[i].maso == ms)
		{
			Xoa(ds,n,i);
		}
	}
}

void Them_SV(SINHVIEN ds[], int& n, int vt, SINHVIEN x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		ds[i + 1] = ds[i];
	}
	ds[vt] = x;
	n++;
}

void Tim_Kiem_Thong_Tin_SV_Co_Ma_So_Bat_Ky(SINHVIEN ds[], int n)
{
	while (getchar() != '\n');
	string ms;
	cout << "\n\tNhap ma so sinh vien muon tim: ";
	getline(cin, ms);
	for (int i = 0; i < n; i++)
	{
		if (ds[i].maso == ms)
		{
			Xuat_Thong_Tin_1_SV(ds[i]);
		}
	}
}

int main()
{
	SINHVIEN ds[100];
	int n;
	cout << " Nhap so luong sinh vien: ";
	cin >> n;

	Nhap_Danh_Sach_SV(ds, n);
	cout << "\n\n";

	Xuat_Danh_Sach_SV(ds, n);
	cout << "\n\n";

	cout << " Sap xep danh sach sinh vien tang dan theo diem trung binh: " << endl;
	Sap_Xep_SV_Tang_Dan_Theo_DiemTB(ds, n);
	Xuat_Danh_Sach_SV(ds, n);
	cout << "\n\n";

	cout << " Xoa sinh vien co ma so bat ky: " << endl;
	Xoa_SV_Co_Ma_So_Bat_Ky(ds, n);
	Xuat_Danh_Sach_SV(ds, n);
	cout << "\n\n";

	int vt;
	SINHVIEN x;
	cout << " Nhap vi tri can them: ";
	cin >> vt;
	cout << "\n\n\t\tNhap thong tin sinh vien can them: " << endl;
	Nhap_Thong_Tin_1_SV(x);
	Them_SV(ds, n, vt, x);
	cout << "\n\n\t\tDanh sach sinh vien sau khi them: " << endl;
	Xuat_Danh_Sach_SV(ds, n);
	cout << "\n\n";
	
	cout << " Tim kiem thong tin sinh vien co ma so bat ky: " << endl;
	Tim_Kiem_Thong_Tin_SV_Co_Ma_So_Bat_Ky(ds, n);

	return 0;
}