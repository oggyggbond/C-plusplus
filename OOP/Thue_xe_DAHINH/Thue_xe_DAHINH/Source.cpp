#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class XE
{
protected:
	string hotennguoithue;
	float sogiothue;
	bool KT;
	int KT_loaixe;

public:
	virtual void Nhap_Thong_Tin()
	{
		while (getchar() != '\n');
		cout << "\nNhap ho ten nguoi thue: ";
		getline(cin, hotennguoithue);
		cout << "\nNhap so gio thue: ";
		cin >> sogiothue;
	}
	virtual void Xuat_Thong_Tin()
	{
		cout << "\nHo ten: " << hotennguoithue;
		cout << "\nSo gio thue: " << sogiothue;
	}

	virtual float Tinh_Tien_Thue() = 0;

	bool Getter_KT()
	{
		return KT;
	}

	void Setter_KT(bool kt)
	{
		KT = kt;
	}

	int Getter_KT_loaixe()
	{
		return KT_loaixe;
	}

	void Setter_KT_loaixe(int KT_Loaixe)
	{
		KT_loaixe = KT_Loaixe;
	}
};

class XEDAP : public XE
{
public:
	float Tinh_Tien_Thue()
	{
		return 10000 + (8000 * (sogiothue - 1));
	}
};

class XEMAY : public XE
{
private:
	int loaixe;
	string bienso;
public:
	void Nhap_Thong_Tin()
	{
		XE::Nhap_Thong_Tin();
		cout << "\nNhap loai xe: ";
		cin >> loaixe;
		while (getchar() != '\n');
		cout << "\nNhap bien so: ";
		getline(cin, bienso);
	}
	void Xuat_Thong_Tin()
	{
		XE::Xuat_Thong_Tin();
		cout << "\nLoai xe: " << loaixe;
		cout << "\nBien so: " << bienso;
	}

	float Tinh_Tien_Thue()
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
};

void Xuat_Tat_Ca_Thong_Tin_Thue_Xe(XE* ds[], int n)
{
	cout << "\n\n\t\t DANH SACH THUE XE\n";
	for (int i = 0; i < n; i++)
	{
		if (ds[i]->Getter_KT() == true)
		{
			cout << "\n\n\tTHONG TIN THUE XE DAP THU " << i + 1 << endl;
			ds[i]->Xuat_Thong_Tin();
			cout << "\nTien thue: " << (size_t)ds[i]->Tinh_Tien_Thue();
		}
		else
		{
			cout << "\n\n\tTHONG TIN THUE XE MAY THU " << i + 1 << endl;
			ds[i]->Xuat_Thong_Tin();
			cout << "\nTien thue: " << (size_t)ds[i]->Tinh_Tien_Thue();
		}
	}
}

float Tinh_Tong_Tien_Cho_Thue_Xe(XE *ds[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + ds[i]->Tinh_Tien_Thue();
	}
	return s;
}

float Tinh_Tong_So_Tien_Cho_Thue_Xe_May_Loai_250_Phan_Khoi(XE* ds[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{	
			if (ds[i]->Getter_KT_loaixe() == 250)
			{
				s = s + ds[i]->Tinh_Tien_Thue();
			}	
	}
	return s;
}

void Menu(XE* ds[], int &n)
{
	XE* x = NULL;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======================= QUAN LY THUE XE =======================";
		cout << "\n\t1. Nhap thong tin cho thue xe dap va xe may";
		cout << "\n\t2. Xuat tat ca thong tin thue xe";
		cout << "\n\t3. Tinh tong so tien cho thue xe dap va xe may";
		cout << "\n\t4. Xuat tat ca thong tin cho thue xe dap";
		cout << "\n\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============================= END =============================";

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
				cout << "\nNhap loai xe muon thue: ";
				cin >> chon;

				if (chon == 1)
				{
					x = new XEDAP;
					cout << "\n\n\t\t NHAP THONG TIN THUE XE DAP\n";
					x->Nhap_Thong_Tin();
					x->Setter_KT(true);
					ds[n] = x;
					n++;
				}
				else if (chon == 2)
				{
					x = new XEMAY;
					cout << "\n\n\t\t NHAP THONG TIN THUE XE MAY\n";
					x->Nhap_Thong_Tin();
					x->Setter_KT(false);
					ds[n] = x;
					n++;
				}
				else
				{
					break;
				}
			}
		}
		else if (luachon == 2)
		{
			Xuat_Tat_Ca_Thong_Tin_Thue_Xe(ds, n);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\nTong tien thue xe la: " << (size_t)Tinh_Tong_Tien_Cho_Thue_Xe(ds, n);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
			for (int i = 0; i < n; i++)
			{
				if (ds[i]->Getter_KT() == true)
				{
					cout << "\n\n\t THONG TIN THUE XE DAP THU " << i + 1 << endl;
					ds[i]->Xuat_Thong_Tin();
					cout << "\nTien thue: " << (size_t)ds[i]->Tinh_Tien_Thue();
				}
			}
			system("pause");
		}
		else if (luachon == 5)
		{
			x->Setter_KT_loaixe(250);
			cout << "\n\n\t\t Tong so tien thue xe may loai 250 phan khoi: " << (size_t)Tinh_Tong_So_Tien_Cho_Thue_Xe_May_Loai_250_Phan_Khoi(ds, n);
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
	XE* ds[100];
	int n = 0;
	Menu(ds, n);

	for (int i = 0; i < n; i++)
	{
		delete ds[i];
	}

	return 0;
}