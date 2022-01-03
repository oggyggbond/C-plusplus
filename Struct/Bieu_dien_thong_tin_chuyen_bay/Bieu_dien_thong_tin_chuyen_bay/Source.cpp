#include <iostream>
#include <string>
using namespace std;

struct Ngay
{
	int dd, mm, yy;
};

struct Gio
{
	int h, m, s;
};

struct CHUYENBAY
{
	char machuyenbay[5];
	Ngay ngaybay;
	Gio giobay;
	char noidi[20];
	char noiden[20];
	char hotenhanhkhach[30];
};

void Nhap_Gio(Gio& g)
{
	cout << "\n\tNhap gio: ";
	cin >> g.h;
	cout << "\n\tNhap phut: ";
	cin >> g.m;
	cout << "\n\tNhap giay: ";
	cin >> g.s;
}

void Xuat_Gio(Gio g)
{
	cout << g.h << " : " << g.m << " : " << g.s;
}

void Nhap_Ngay(Ngay& ng)
{
	cout << "\n\tNhap ngay: ";
	cin >> ng.dd;
	cout << "\n\tNhap thang: ";
	cin >> ng.mm;
	cout << "\n\tNhap nam: ";
	cin >> ng.yy;
}

void Xuat_Ngay(Ngay ng)
{
	cout << ng.dd << " / " << ng.mm << " / " << ng.yy;
}

void Nhap_Chuyen_Bay(CHUYENBAY& cb)
{
	while (getchar() != '\n');
	cout << "\n\tNhap ten hanh khach: ";
	gets_s(cb.hotenhanhkhach);
	cout << "\n\tNhap ma chuyen bay: ";
	gets_s(cb.machuyenbay);
	cout << "\n\tNhap ngay bay: " << endl;
	Nhap_Ngay(cb.ngaybay);
	cout << "\n\tNhap gio bay: " << endl;
	Nhap_Gio(cb.giobay);
	while (getchar() != '\n');
	cout << "\n\tNhap noi di: ";
	gets_s(cb.noidi);
	cout << "\n\tNhap noi den: ";
	gets_s(cb.noiden);
}

void Xuat_Chuyen_Bay(CHUYENBAY cb)
{
	cout << "\n\tTen hanh khach: " << cb.hotenhanhkhach << endl;
	cout << "\n\tMa chuyen bay: " << cb.machuyenbay << endl;
	cout << "\n\tNgay bay: ";
	Xuat_Ngay(cb.ngaybay);
	cout << endl;
	cout << "\n\tGio bay: ";
	Xuat_Gio(cb.giobay);
	cout << endl;
	cout << "\n\tNoi di: " << cb.noidi << endl;
	cout << "\n\tNoi den " << cb.noiden << endl;
}

void Nhap_Cac_Chuyen_Bay(CHUYENBAY cb[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\tNhap chuyen bay thu " << i + 1 << endl;
		Nhap_Chuyen_Bay(cb[i]);
	}
}

void Xuat_Cac_Chuyen_Bay(CHUYENBAY cb[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\tThong tin chuyen bay thu " << i + 1 << endl;
		Xuat_Chuyen_Bay(cb[i]);
	}
}

void Them_Chuyen_Bay(CHUYENBAY cb[], int &n, int vt, CHUYENBAY x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		cb[i + 1] = cb[i];
	}
	cb[vt] = x;
	n++;
}

void Xoa(CHUYENBAY cb[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		cb[i - 1] = cb[i];
	}
	n--;
}

void Xoa_Chuyen_Bay_Co_Ma_Bat_Ky(CHUYENBAY cb[], int& n)
{
	string maso;
	cout << "\n\tNhap ma so chuyen bay muon xoa: ";
	getline(cin, maso);
	for (int i = 0; i < n; i++)
	{
		if (cb[i].machuyenbay == maso)
		{
			Xoa(cb,n,i);
		}
	}
}

int main()
{
	CHUYENBAY cb[100];
	int n;
	cout << " Nhap so luong chuyen bay: ";
	cin >> n;

	cout << "\n\n\t\tNHAP THONG TIN CHUYEN BAY\n";
	Nhap_Cac_Chuyen_Bay(cb, n);

	cout << "\n\n\t\tXUAT THONG TIN CHUYEN BAY\n";
	Xuat_Cac_Chuyen_Bay(cb, n);
	cout << "\n\n";

	CHUYENBAY x;
	int vt;
	cout << " Nhap vi tri can them: ";
	cin >> vt;
	cout << "\n\n\t\tNHAP THONG TIN CHUYEN BAY CAN THEM\n";
	Nhap_Chuyen_Bay(x);
	Them_Chuyen_Bay(cb, n, vt, x);
	cout << "\n\n\t\tDANH SACH CAC CHUYEN BAY SAU KHI THEM\n";
	Xuat_Cac_Chuyen_Bay(cb, n);

	cout << "\n\n\t\tXOA CHUYEN BAY CO MA SO BAT KY\n";
	Xoa_Chuyen_Bay_Co_Ma_Bat_Ky(cb, n);
	Xuat_Cac_Chuyen_Bay(cb, n);

	return 0;
}
