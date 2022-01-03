#include <iostream>
#include <string>
using namespace std;

struct PHANSO
{
	int tuso;
	int mauso;
};

void Nhap_1_Phan_So(PHANSO& x)
{
	cout << "\n\tNhap tu so: ";
	cin >> x.tuso;
	cout << "\n\tNhap mau so: ";
	cin >> x.mauso;
}

void Xuat_1_Phan_So(PHANSO x)
{
	cout << "\n\t" << x.tuso << " / " << x.mauso;
}

void Nhap_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tNhap phan so thu " << i + 1 << endl;
		Nhap_1_Phan_So(ps[i]);
	}
}

void Xuat_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tPhan so thu " << i + 1 << endl;
		Xuat_1_Phan_So(ps[i]);
	}
}

int UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}

PHANSO Rut_Gon_1_Phan_So(PHANSO ps)
{
	 int x = UCLN(ps.tuso, ps.mauso);
	ps.tuso = ps.tuso / x;
	ps.mauso = ps.mauso / x;
	return ps;
}

void Rut_Gon_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		ps[i] = Rut_Gon_1_Phan_So(ps[i]);
	}
}

PHANSO Tim_Phan_So_Max(PHANSO ps[100], int n)
{
	float max = (float)ps[0].tuso / ps[0].mauso;
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		float x = (float)ps[i].tuso / ps[i].mauso;
		if (max < x)
		{
			max = x;
			k = i;
		}
	}
	return ps[k];
}

PHANSO Cong_2_Phan_So(PHANSO x, PHANSO y)
{
	PHANSO k;
	k.tuso = (x.tuso * y.mauso) + (x.mauso * y.tuso);
	k.mauso = (x.mauso * y.mauso);
	return k;
}

PHANSO Cong_Cac_Phan_So(PHANSO ps[100], int n)
{
	PHANSO sum = ps[0];
	for (int i = 1; i < n; i++)
	{
		sum = Cong_2_Phan_So(sum, ps[i]);
	}
	return sum;
}

int main()
{
	PHANSO ps[100];
	int n;
	cout << " Nhap so luong cac phan so: ";
	cin >> n;

	cout << "\n\n\t\tNhap phan so: ";
	Nhap_Cac_Phan_So(ps, n);

	cout << "\n\n\t\tXuat phan so: ";
	Xuat_Cac_Phan_So(ps, n);

	cout << "\n\n\t\tRut gon phan so: ";
	Rut_Gon_Cac_Phan_So(ps, n);
	Xuat_Cac_Phan_So(ps, n);

	PHANSO max = Tim_Phan_So_Max(ps, n);
	cout << "\n\n\t\tPhan so lon nhat la: ";
	Xuat_1_Phan_So(max);

	cout << "\n\n\t\tTong cac phan so: ";
	PHANSO sum = Cong_Cac_Phan_So(ps, n);
	Xuat_1_Phan_So(sum);

	return 0;
}