#include <iostream>
#include <fstream>
using namespace std;

struct PHANSO
{
	int tuso;
	int mauso;
};

void Doc_1_phan_so(PHANSO& ps, ifstream& filein)
{
	filein >> ps.tuso;
	char x;
	filein >> x;
	filein >> ps.mauso;
}

void Doc_Cac_Phan_So(PHANSO ps[100], int n, ifstream& filein)
{
	for (int i = 0; i < n; i++)
	{
		Doc_1_phan_so(ps[i], filein);
	}
}

void Xuat_Cac_Phan_So(PHANSO ps[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ps[i].tuso << "/" << ps[i].mauso << endl;
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

void Rut_Gon_Cac_Phan_So(PHANSO ps[100], int n, ofstream& fileout)
{
	for (int i = 0; i < n; i++)
	{
		ps[i] = Rut_gon_1_phan_so(ps[i]);
	}
	fileout.open("RUTGONPHANSO.TXT", ios_base::out);
	fileout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fileout << ps[i].tuso << "/" << ps[i].mauso << endl;
	}
	fileout.close();
}

void Tim_Phan_So_Lon_Nhat(PHANSO ps[100], int n, ofstream& fileout)
{
	fileout.open("OUTPUT.TXT", ios_base::out);
	float max = (float)ps[0].tuso / ps[0].mauso;
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		float x = (float)ps[i].tuso / ps[i].mauso;
		if (x > max)
		{
			max = x;
			k = i;
		}
	}
	fileout << ps[k].tuso << "/" << ps[k].mauso;
	fileout.close();
}

int main()
{
	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong hop le! Xin kiem tra lai";
		system("pause");
		return 0;
	}
	PHANSO ps[100];
	int n;
	filein >> n;
	Doc_Cac_Phan_So(ps, n, filein);
	Xuat_Cac_Phan_So(ps, n);
	ofstream fileout;
	Rut_Gon_Cac_Phan_So(ps, n, fileout);
	Tim_Phan_So_Lon_Nhat(ps, n, fileout);

	filein.close();
	
	return 0;
}