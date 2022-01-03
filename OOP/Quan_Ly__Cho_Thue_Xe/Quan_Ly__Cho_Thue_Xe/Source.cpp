#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class XEDAP
{
public:
	void Nhap_Thong_Tin();
	void Xuat_Thong_Tin();
	float Tinh_Tien_Thue();

private:
	string hotennguoithue;
	float sogiothue;
};

void XEDAP::Nhap_Thong_Tin()
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten nguoi thue: ";
	getline(cin, hotennguoithue);
	cout << "\nNhap so gio thue: ";
	cin >> sogiothue;
}

void XEDAP::Xuat_Thong_Tin()
{
	cout << "\nHo ten nguoi thue: " << hotennguoithue;
	cout << "\nSo gio thue: " << sogiothue;
}

float XEDAP::Tinh_Tien_Thue()
{
	return 10000 + (8000 * (sogiothue - 1));
}

class XEMAY
{
public:
	void Nhap_Thong_Tin();
	void Xuat_Thong_Tin();
	float Tinh_Tien_Thue();

	int Getter_loaixe()
	{
		return loaixe;
	}
	void Setter_loaixe(int Loaixe)
	{
		loaixe = Loaixe;
	}

private:
	string hotennguoithue;
	float sogiothue;
	int loaixe;
	string bienso;
};

void XEMAY::Nhap_Thong_Tin()
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten nguoi thue: ";
	getline(cin, hotennguoithue);
	cout << "\nNhap so gio thue: ";
	cin >> sogiothue;
	cout << "\nNhap loai xe: ";
	cin >> loaixe;
	while (getchar() != '\n');
	cout << "\nNhap bien so: ";
	getline(cin, bienso);
}

void XEMAY::Xuat_Thong_Tin()
{
	cout << "\nHo ten nguoi thue: " << hotennguoithue;
	cout << "\nSo gio thue: " << sogiothue;
	cout << "\nLoai xe: " << loaixe;
	cout << "\Bien so: " << bienso;
}

float XEMAY::Tinh_Tien_Thue()
{
	float s = 0;
	if (loaixe == 100)
	{
		s = 150000;
	}
	else
	{
		s = 200000;
	}
	return s + (100000 * (sogiothue - 1));
}

void Xuat_Tat_Ca_Thong_Tin_Thue_Xe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tTHONG TIN THUE XE DAP THU " << i + 1 << endl;
		ds_xedap[i].Xuat_Thong_Tin();
		cout << "\nTien thue: " << (size_t)ds_xedap[i].Tinh_Tien_Thue();
	}
	cout << "\n\n\t\t DANH SACH THUE XE MAY\n";
	for (int i = 0; i < m; i++)
	{
		cout << "\n\tTHONG TIN THUE XE MAY THU " << i + 1 << endl;
		ds_xemay[i].Xuat_Thong_Tin();
		cout << "\nTien thue: " << (size_t)ds_xemay[i].Tinh_Tien_Thue();
	}
}

float Tinh_Tong_Tien_Cho_Thue_Xe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + ds_xedap[i].Tinh_Tien_Thue();
	}
	for (int i = 0; i < m; i++)
	{
		s = s + ds_xemay[i].Tinh_Tien_Thue();
	}
	return s;
}

float Tinh_Tong_Tien_Cho_Thue_XEMAY_Loai_250_Phan_Khoi(XEMAY ds_xemay[], int m)
{
	float s = 0;
	for (int i = 0; i < m; i++)
	{
		if (ds_xemay[i].Getter_loaixe() == 250)
		{
			s = s + ds_xemay[i].Tinh_Tien_Thue();
		}
	}
	return s;
}

void Menu(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t========================== QUAN LY THUE XE ==========================";
		cout << "\n\t1. Nhap danh sach thue xe dap va xe may";
		cout << "\n\t2. Xuat tat ca thong tin thue xe";
		cout << "\n\t3. Tinh tong so tien cho thue xe dap va xe may";
		cout << "\n\t4. Tinh tong so tien cho thue xe may loai 250 phan khoi";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t================================ END ================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			while (true)
			{
				system("cls");
				cout << "\n\t1. Thue xe dap";
				cout << "\n\t2. Thue xe may";
				cout << "\n\t0. Ket thuc";

				int chon;
				cout << "\nChon xe muon thue: ";
				cin >> chon;

				if (chon == 1)
				{
					XEDAP x;
					cout << "\n\n\t\t NHAP THONG TIN CHO THUE XE DAP\n";
					x.Nhap_Thong_Tin();
					ds_xedap[n] = x;
					n++;
				}
				else if (chon == 2)
				{
					XEMAY x;
					cout << "\n\n\t\t NHAP THONG TIN CHO THUE XE MAY\n";
					x.Nhap_Thong_Tin();
					ds_xemay[m] = x;
					m++;
				}
				else
				{
					break;
				}
			}
		}
		else if (luachon == 2)
		{
			Xuat_Tat_Ca_Thong_Tin_Thue_Xe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\t Tong tien cho thue xe: " << (size_t)Tinh_Tong_Tien_Cho_Thue_Xe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\tTong tien cho thue xe may loai 250 phan khoi: " << (size_t)Tinh_Tong_Tien_Cho_Thue_XEMAY_Loai_250_Phan_Khoi(ds_xemay, m);
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
	XEDAP ds_xedap[100];
	int n = 0;
	XEMAY ds_xemay[100];
	int m = 0;
	Menu(ds_xedap, n, ds_xemay, m);
	
	return 0;
}