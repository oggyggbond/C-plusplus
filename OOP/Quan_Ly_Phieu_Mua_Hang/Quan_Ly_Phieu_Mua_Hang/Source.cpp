#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class KHACHHANG
{
protected:

	string makhachhang;
	string hoten;
	string diachi;
	string sdt;
	string email;
	string ngaysinh;
	int namhientai;

public:

	virtual void Nhap_Thong_Tin()
	{
		while (getchar() != '\n');
		cout << "\nNhap ma khach hang: ";
		getline(cin, makhachhang);
		cout << "\nNhap ho ten khach hang: ";
		getline(cin, hoten);
		cout << "\nNhap dia chi khach hang: ";
		getline(cin, diachi);
		cout << "\nNhap so dien thoai khach hang: ";
		getline(cin, sdt);
		cout << "\nNhap Email khach hang: ";
		getline(cin, email);
		cout << "\nNhap ngay sinh: ";
		getline(cin, ngaysinh);
		cout << "\nNhap nam hien tai: ";
		cin >> namhientai;
	}

	virtual void Xuat_Thong_Tin()
	{
		cout << "\nMa khach hang: " << makhachhang;
		cout << "\nHo ten: " << hoten;
		cout << "\nDia chi: " << diachi;
		cout << "\nSo dien thoai: " << sdt;
		cout << "\nEmail: " << email;
		cout << "\nNgay sinh: " << ngaysinh;
		cout << "\nNam hien tai: " << namhientai;
	}

	virtual float Tinh_Diem() = 0;
};

class KH_THUONGXUYEN : public  KHACHHANG
{
private:

	int namthamgia;

public:

	void Nhap_Thong_Tin()
	{
		KHACHHANG::Nhap_Thong_Tin();
		cout << "\nNhap ngay tham gia: ";
		cin >> namthamgia;
	}

	void Xuat_Thong_Tin()
	{
		KHACHHANG::Xuat_Thong_Tin();
		cout << "\nNgay tham gia: " << namthamgia;
	}

	float Tinh_Diem()
	{
		return (namhientai - namthamgia) * 10;
	}
};

class KH_VIP : public KHACHHANG
{
private:

	float sotienmuahang;

public:

	void Nhap_Thong_Tin()
	{
		KHACHHANG::Nhap_Thong_Tin();
		cout << "\nNhap so tien mua hang: ";
		cin >> sotienmuahang;
	}

	void Xuat_Thong_Tin()
	{
		KHACHHANG::Xuat_Thong_Tin();
		cout << "\nSo tien mua hang: " << (size_t)sotienmuahang;
	}

	float Tinh_Diem()
	{
		return sotienmuahang / 100000;
	}
};

class PHIEUMUAHANG
{
private:

	string maphieu;
	string ngayhethan;
	float giatri;
	KHACHHANG* DS_KH;
	int loaiphieu; //1.phieu chuan, 2.phieu bac, 3.phieu vang

public:

	void Nhap_Thong_Tin_PMH()
	{
		while (getchar() != '\n');
		cout << "\nNhap ma phieu: ";
		getline(cin, maphieu);
		cout << "\nNhap ngay het han: ";
		getline(cin, ngayhethan);
		cout << "\n\tNhap loai phieu(1 || 2 || 3): " << endl;
		cout << "\n1. Phieu chuan";
		cout << "\n2. Phieu bac";
		cout << "\n3. Phieu vang";
		cout << endl;
		cin >> loaiphieu;
		cout << "\n\n\t\tNHAP THONG TIN KHACH HANG\n";
		cout << "\n\t1. Khach hang thuong xuyen";
		cout << "\n\t2. Khach hang VIP";
		cout << "\n\nNhap loai khach hang(1 || 2): ";
		int n;
		cin >> n;
		if (n == 1)
		{
			KHACHHANG* KH_TX = new KH_THUONGXUYEN;
			KH_TX->Nhap_Thong_Tin();
			if (loaiphieu == 1)
			{
				giatri = KH_TX->Tinh_Diem() * 10000;
			}
			else if (loaiphieu == 2)
			{
				giatri = KH_TX->Tinh_Diem() * 15000;
			}
			else
			{
				if (KH_TX->Tinh_Diem() < 200)
				{
					giatri = KH_TX->Tinh_Diem() * 25000;
				}
				else
				{
					giatri = KH_TX->Tinh_Diem() * 40000;
				}
			}
			DS_KH = KH_TX;
		}
		else
		{
			KHACHHANG* kh_vip = new KH_VIP;
			kh_vip->Nhap_Thong_Tin();
			if (loaiphieu == 1)
			{
				giatri = kh_vip->Tinh_Diem() * 10000;
			}
			else if (loaiphieu == 2)
			{
				giatri = kh_vip->Tinh_Diem() * 15000;
			}
			else
			{
				if (kh_vip->Tinh_Diem() < 200)
				{
					giatri = kh_vip->Tinh_Diem() * 25000;
				}
				else
				{
					giatri = kh_vip->Tinh_Diem() * 40000;
 				}
			}
			DS_KH = kh_vip;
		}
	}

	void Xuat_Thong_Tin_PMH()
	{
		cout << "\nMa phieu: " << maphieu;
		cout << "\nNgay het han: " << ngayhethan;
		cout << "\n\n\tTHONG TIN KHACH HANG\n";
		DS_KH->Xuat_Thong_Tin();
		cout << "\nGia tri: " << (size_t)giatri;
	}

	float Getter_Gia_Tri_PMH()
	{
		return giatri;
	}
	~PHIEUMUAHANG()
	{
		delete DS_KH;
	}
};

void Hoan_Vi(PHIEUMUAHANG*& x, PHIEUMUAHANG*& y)
{
	PHIEUMUAHANG* tmp = x;
	x = y;
	y = tmp;
}

void Menu(PHIEUMUAHANG* DS_PMH[], int n)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ===================== QUAN LY PHIEU MUA HANG =====================";
		cout << "\n\t1. Nhap danh sach phieu mua hang";
		cout << "\n\t2. Xuat thong tin danh sach phieu mua hang";
		cout << "\n\t3. In danh sach theo thu tu giam dan cua gia tri phieu mua hang";
		cout << "\n\t4. Tim va in ra man hinh cac phieu mua hang co gia tri nam trong khoang cho truoc";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============================== END =================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHIEUMUAHANG* PMH = new PHIEUMUAHANG;
			cout << "\n\n\t\t NHAP THONG TIN PHIEU MUA HANG\n";
			PMH->Nhap_Thong_Tin_PMH();
			DS_PMH[n] = PMH;
			n++;
		}
		else if (luachon == 2)
		{
			cout << "\n\n\n\t\t DANH SACH PHIEU MUA HANG\n";
			for (int i = 0; i < n; i++)
			{
				cout << "\n\n\t Phieu mua hang thu " << i + 1 << endl;
				DS_PMH[i]->Xuat_Thong_Tin_PMH();
			}
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\t\t THU TU GIAM DAN THEO GIA TRI CUA PHIEU MUA HANG\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (DS_PMH[i]->Getter_Gia_Tri_PMH() < DS_PMH[j]->Getter_Gia_Tri_PMH())
					{
						Hoan_Vi(DS_PMH[i], DS_PMH[j]);
					}
				}
			}
			cout << "\n\n\t\t DANH SACH PHIEU MUA HANG\n";
			for (int i = 0; i < n; i++)
			{
				cout << "\n\n\t Phieu mua hang thu " << i + 1 << endl;
				DS_PMH[i]->Xuat_Thong_Tin_PMH();
			}
			system("pause");
		}
		else if (luachon == 4)
		{
			int khoangbe, khoanglon;
			cout << "\nNhap khoang be, khoang lon: ";
			cin >> khoangbe >> khoanglon;
			for (int i = 0; i < n; i++)
			{
				if (khoangbe < DS_PMH[i]->Getter_Gia_Tri_PMH() && DS_PMH[i]->Getter_Gia_Tri_PMH() < khoanglon)
				{
					DS_PMH[i]->Xuat_Thong_Tin_PMH();
				}
			}
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
	PHIEUMUAHANG* DS_PMH[100];
	int n = 0;
	Menu(DS_PMH, n);

	return 0;
}