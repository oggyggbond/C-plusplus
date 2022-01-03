#include <iostream>
using namespace std;

struct PHANSO
{
	int tuso;
	int mauso;
};

void Nhap_1_phan_so(PHANSO &x)
{
	cout << "\n\tNhap tu so: ";
	cin >> x.tuso;
	cout << "\n\tNhap mau so: ";
	cin >> x.mauso;
}

void Xuat_1_phan_so(PHANSO x)
{
	cout << "\n\t" << x.tuso << " / " << x.mauso;
}

void Nhap_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tNhap phan so thu " << i + 1;
		cout << endl;
		Nhap_1_phan_so(ps[i]);
	}
}

void Xuat_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tXuat phan so thu " << i + 1;
		cout << endl;
		Xuat_1_phan_so(ps[i]);
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
			b = b - a;
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

void Rut_Gon_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		ps[i] = Rut_gon_1_phan_so(ps[i]);
	}
}

PHANSO Tim_Phan_So_Lon_Nhat(PHANSO ps[100], int n)
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

PHANSO Cong_2_phan_so(PHANSO x, PHANSO y)
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
		sum = Cong_2_phan_so(sum, ps[i]);
	}
	return sum;
}

void Menu(PHANSO ps[], int n)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t======================== QUAN LY PHAN SO ========================";
		cout << "\n\t\t1. Nhap cac phan so";
		cout << "\n\t\t2. Xuat cac phan so";
		cout << "\n\t\t3. Rut gon cac phan so";
		cout << "\n\t\t4. Tim phan so lon nhat";
		cout << "\n\t\t5. Tong cac phan so";
		cout << "\n\t\t0. Ket thuc.";
		cout << "\n\n\t\t============================== END ===============================";
	
		cout << "\nNhap lua chon: " << endl;
		cin >> luachon;

		if (luachon == 1)
		{	
			cout << "\n\n\t\tNHAP CAC PHAN SO\n";
			Nhap_Cac_Phan_So(ps, n);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\tXUAT CAC PHAN SO\n";
			Xuat_Cac_Phan_So(ps, n);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\tRUT GON CAC PHAN SO\n";
			Rut_Gon_Cac_Phan_So(ps, n);
			cout << "\n\tCac phan so sau khi rut gon:\n";
			Xuat_Cac_Phan_So(ps, n);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\tTIM PHAN SO LON NHAT\n";
			PHANSO max = Tim_Phan_So_Lon_Nhat(ps, n);
			cout << "\n\tPhan so lon nhat la:\n";
			Xuat_1_phan_so(max);
			system("pause");
		}
		else if (luachon == 5)
		{

			cout << "\n\n\t\tCONG CAC PHAN SO\n";
			PHANSO sum = Cong_Cac_Phan_So(ps, n);
			cout << "\n\tTong la:\n";
			Xuat_1_phan_so(sum);
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
	PHANSO ps[100];
	int n;
	cout << "\nNhap so luong cac phan so: ";
	cin >> n;

	Menu(ps, n);
	
	return 0;
}