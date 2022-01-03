#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class NHANVIEN
{
protected:
	string hoten;
	string maso;
	string diachi;
	string sdt;
	string email;
	int namsinh;
	int namvaolam;
	int namhientai;

public:
	void Nhap_Thong_Tin();
	void Xuat_Thong_Tin();
};

void NHANVIEN::Nhap_Thong_Tin()
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten nhan vien: ";
	getline(cin, hoten);
	cout << "\nNhap ma so nhan vien: ";
	getline(cin, maso);
	cout << "\nNhap dia chi nhan vien: ";
	getline(cin, diachi);
	cout << "\nNhap so dien thoai nhan vien: ";
	getline(cin, sdt);
	cout << "\nNhap Email nhan vien: ";
	getline(cin, email);
	cout << "\nNhap nam sinh nhan vien: ";
	cin >> namsinh;
	cout << "\nNhap nam vao lam: ";
	cin >> namvaolam;
	cout << "\nNhap nam hien tai: ";
	cin >> namhientai;
}

void NHANVIEN::Xuat_Thong_Tin()
{
	cout << "\nHo ten nhan vien: " << hoten;
	cout << "\nMa so nhan vien: " << maso;
	cout << "\nDia chi nhan vien: " << diachi;
	cout << "\nSo dien thoai: " << sdt;
	cout << "\nEmail: " << email;
	cout << "\nNam sinh: " << namsinh;
	cout << "\nNam vao lam: " << namvaolam;
	cout << "\nNam hien tai: " << namhientai;
}

class NHANVIENSANXUAT : NHANVIEN
{
private:
	float sanpham;
	int songaynghi;
	int tuoi;

public:
	void Nhap_Thong_Tin();
	void Xuat_Thong_Tin();
	float Tinh_Tien_Luong();

	int Getter_tuoi()
	{
		return tuoi;
	}

	string Getter_maso()
	{
		return maso;
	}

	string Getter_Layten()
	{
		return hoten;
	}

	string Getter_Sdt()
	{
		return sdt;
	}
};

void NHANVIENSANXUAT::Nhap_Thong_Tin()
{
	NHANVIEN::Nhap_Thong_Tin();
	tuoi = namhientai - namsinh;
	cout << "\nNhap so san pham: ";
	cin >> sanpham;
	cout << "\nNhap so ngay nghi: ";
	cin >> songaynghi;
}

void NHANVIENSANXUAT::Xuat_Thong_Tin()
{
	NHANVIEN::Xuat_Thong_Tin();
	cout << "\nSo san pham: " << sanpham;
	cout << "\nSo ngay nghi: " << songaynghi;
	cout << "\nTuoi: " << tuoi;
}

float NHANVIENSANXUAT::Tinh_Tien_Luong()
{
	return (sanpham * 10000) - (songaynghi * 10000) + (100000 + ((namhientai - namvaolam) * 20000));
}

class NHANVIENVANPHONG : NHANVIEN
{
private:
	float mucluong;
	int songaynghi;
	int tuoi;

public:
	void Nhap_Thong_Tin();
	void Xuat_Thong_Tin();
	float Tinh_Tien_Luong();


	int Getter_tuoi()
	{
		return tuoi;
	}

	string Getter_maso()
	{
		return maso;
	}

	string Getter_Layten()
	{
		return hoten;
	}

	string Getter_Sdt()
	{
		return sdt;
	}
};

void NHANVIENVANPHONG::Nhap_Thong_Tin()
{
	NHANVIEN::Nhap_Thong_Tin();
	tuoi = namhientai - namsinh;
	cout << "\nNhap muc luong: ";
	cin >> mucluong;
	cout << "\nNhap so ngay nghi: ";
	cin >> songaynghi;
}

void NHANVIENVANPHONG::Xuat_Thong_Tin()
{
	NHANVIEN::Xuat_Thong_Tin();
	cout << "\nMuc luong: " << (size_t)mucluong;
	cout << "\nSo ngay nghi: " << songaynghi;
	cout << "\nTuoi: " << tuoi;
}

float NHANVIENVANPHONG::Tinh_Tien_Luong()
{
	return (mucluong - (songaynghi * 10000)) + (100000 + ((namhientai - namvaolam) * 20000));
}

class NHANVIENCONGNHAT : NHANVIEN
{
private:
	float luongcung;
	float songaydilam;
	float songaynghi;
	float songaycong;
	int tuoi;

public:
	void Nhap_Thong_Tin();
	void Xuat_Thong_Tin();
	float Tinh_Tien_Luong();

	int Getter_tuoi()
	{
		return tuoi;
	}

	string Getter_maso()
	{
		return maso;
	}

	string Getter_Layten()
	{
		return hoten;
	}

	string Getter_Sdt()
	{
		return sdt;
	}
};

void NHANVIENCONGNHAT::Nhap_Thong_Tin()
{
	NHANVIEN::Nhap_Thong_Tin();
	tuoi = namhientai - namsinh;
	cout << "\nLuong cung: ";
	cin >> luongcung;
	cout << "\nNhap so ngay di lam: ";
	cin >> songaydilam;
	cout << "\nNhap so ngay nghi: ";
	cin >> songaynghi;
	songaycong = songaydilam - songaynghi;
}

void NHANVIENCONGNHAT::Xuat_Thong_Tin()
{
	NHANVIEN::Xuat_Thong_Tin();
	cout << "\nLuong cung: " << (size_t)luongcung;
	cout << "\nSo ngay di lam: " << songaydilam;
	cout << "\nSo ngay nghi: " << songaynghi;
	cout << "\nSo ngay cong: " << songaycong;
	cout << "\nTuoi: " << tuoi;
}

float NHANVIENCONGNHAT::Tinh_Tien_Luong()
{
	return ((songaycong * 100000) + luongcung - (songaynghi * 10000)) + (100000 + ((namhientai - namvaolam) * 20000));
}

void Xuat_Thong_Tin_Tung_Loai_Nhan_Vien(NHANVIENSANXUAT* ds_nvsanxuat[], int n, NHANVIENVANPHONG* ds_nvvanphong[], int m, NHANVIENCONGNHAT* ds_nvcongnhat[], int k)
{
	cout << "\n\n\t\t\t THONG TIN NHAN VIEN\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\t THONG TIN NHAN VIEN SAN XUAT THU " << i + 1 << endl;
		ds_nvsanxuat[i]->Xuat_Thong_Tin();
		cout << "\nTien luong: " << (size_t)ds_nvsanxuat[i]->Tinh_Tien_Luong();
	}

	for (int i = 0; i < m; i++)
	{
		cout << "\n\n\t\t THONG TIN NHAN VIEN VAN PHONG THU " << i + 1 << endl;
		ds_nvvanphong[i]->Xuat_Thong_Tin();
		cout << "\nTien luong: " << (size_t)ds_nvvanphong[i]->Tinh_Tien_Luong();
	}

	for (int i = 0; i < k; i++)
	{
		cout << "\n\n\t\t THONG TIN NHAN VIEN CONG NHAT THU " << i + 1 << endl;
		ds_nvcongnhat[i]->Xuat_Thong_Tin();
		cout << "\nTien luong: " << (size_t)ds_nvcongnhat[i]->Tinh_Tien_Luong();
	}
}

float Tong_So_Tien_Cong_Ty_Tra_Cho_Nhan_Vien(NHANVIENSANXUAT* ds_nvsanxuat[], int n, NHANVIENVANPHONG* ds_nvvanphong[], int m, NHANVIENCONGNHAT* ds_nvcongnhat[], int k)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + ds_nvsanxuat[i]->Tinh_Tien_Luong();
	}
	for (int i = 0; i < m; i++)
	{
		s = s + ds_nvvanphong[i]->Tinh_Tien_Luong();
	}
	for (int i = 0; i < k; i++)
	{
		s = s + ds_nvcongnhat[i]->Tinh_Tien_Luong();
	}
	return s;
}

void Xuat_Danh_Sach_Thong_Tin_Nhan_Vien_Tuoi_Hon_50(NHANVIENSANXUAT* ds_nvsanxuat[], int n, NHANVIENVANPHONG* ds_nvvanphong[], int m, NHANVIENCONGNHAT* ds_nvcongnhat[], int k)
{
	for (int i = 0; i < n; i++)
	{
		if (ds_nvsanxuat[i]->Getter_tuoi() > 50)
		{
			cout << "\n\n\t\t THONG TIN NHAN VIEN SAN XUAT THU " << i + 1 << endl;
			ds_nvsanxuat[i]->Xuat_Thong_Tin();
		}		
	}

	for (int i = 0; i < m; i++)
	{
		if (ds_nvvanphong[i]->Getter_tuoi() > 50)
		{
			cout << "\n\n\t\t THONG TIN NHAN VIEN VAN PHONG THU " << i + 1 << endl;
			ds_nvvanphong[i]->Xuat_Thong_Tin();
		}
	}

	for (int i = 0; i < k; i++)
	{
		if (ds_nvcongnhat[i]->Getter_tuoi() > 50)
		{
			cout << "\n\n\t\t THONG TIN NHAN VIEN CONG NHAT THU " << i + 1 << endl;
			ds_nvcongnhat[i]->Xuat_Thong_Tin();
		}
	}
}

void Xoa(NHANVIENSANXUAT* ds_nvsanxuat[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		ds_nvsanxuat[i - 1] = ds_nvsanxuat[i];
	}
	n--;
}

void Xoa(NHANVIENVANPHONG* ds_nvvanphong[], int& m, int vt)
{
	for (int i = vt + 1; i < m; i++)
	{
		ds_nvvanphong[i - 1] = ds_nvvanphong[i];
	}
	m--;
}

void Xoa(NHANVIENCONGNHAT* ds_nvcongnhat[], int& k, int vt)
{
	for (int i = vt + 1; i < k; i++)
	{
		ds_nvcongnhat[i - 1] = ds_nvcongnhat[i];
	}
	k--;
}

void Xoa_Nhan_Vien_Co_Ma_So_Bat_Ky(NHANVIENSANXUAT* ds_nvsanxuat[], int& n, NHANVIENVANPHONG* ds_nvvanphong[], int& m, NHANVIENCONGNHAT* ds_nvcongnhat[], int& k)
{
	while (getchar() != '\n');
	string MASO;
	cout << "\nNhap ma so cua nhan vien muon xoa: ";
	getline(cin, MASO);
	for (int i = 0; i < n; i++)
	{
		if (ds_nvsanxuat[i]->Getter_maso() == MASO)
		{
			Xoa(ds_nvsanxuat, n, i);
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		if (ds_nvvanphong[i]->Getter_maso() == MASO)
		{
			Xoa(ds_nvvanphong, m, i);
		}
	}

	for (int i = 0; i < k; i++)
	{
		if (ds_nvcongnhat[i]->Getter_maso() == MASO)
		{
			Xoa(ds_nvcongnhat, k, i);
		}
	}
}

void Xuat_Thong_Tin_Nhan_Vien_Co_Chu_Cai_Trong_Ten_Trung_Voi_Sau_x_Can_Tim(NHANVIENSANXUAT* ds_nvsanxuat[], int n, NHANVIENVANPHONG* ds_nvvanphong[], int m, NHANVIENCONGNHAT* ds_nvcongnhat[], int k)
{
	while (getchar() != '\n');
	string chucai;
	cout << "\nNhap chu cai: ";
	getline(cin, chucai);
	int x = chucai.length();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < ds_nvsanxuat[i]->Getter_Layten().length(); j++)
		{
			if (ds_nvsanxuat[i]->Getter_Layten().substr(j, x) == chucai)
			{
				cout << "\n\n\t\t NHAN VIEN SAN XUAT THU " << i + 1 << endl;
				ds_nvsanxuat[i]->Xuat_Thong_Tin();
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < ds_nvvanphong[i]->Getter_Layten().length(); j++)
		{
			if (ds_nvvanphong[i]->Getter_Layten().substr(j, x) == chucai)
			{
				cout << "\n\n\t\t NHAN VIEN VAN PHONG THU " << i + 1 << endl;
				ds_nvvanphong[i]->Xuat_Thong_Tin();
			}
		}
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < ds_nvcongnhat[i]->Getter_Layten().length(); j++)
		{
			if (ds_nvcongnhat[i]->Getter_Layten().substr(j, x) == chucai)
			{
				cout << "\n\n\t\t NHAN VIEN CONG NHAT THU " << i + 1 << endl;
				ds_nvcongnhat[i]->Xuat_Thong_Tin();
			}
		}
	}
}

void Xac_Thuc_SDT_Cac_Nhan_Vien_Co_Dinh_Dang_Chua(NHANVIENSANXUAT* ds_nvsanxuat[], int n, NHANVIENVANPHONG* ds_nvvanphong[], int m, NHANVIENCONGNHAT* ds_nvcongnhat[], int k)
{
	for (int i = 0; i < n; i++)
	{
		if ((ds_nvsanxuat[i]->Getter_Sdt().length() == 10) && (ds_nvsanxuat[i]->Getter_Sdt()[0] == '0'))
		{
			cout << "\nSo dien thoai nhan vien san xuat thu " << i + 1 << " dung dinh dang";
		}
		else
		{
			cout << "\nSo dien thoai nhan vien san xuat thu " << i + 1 << " chua dung dinh dang";
		}
	}

	for (int i = 0; i < m; i++)
	{
		if ((ds_nvvanphong[i]->Getter_Sdt().length() == 10) && (ds_nvvanphong[i]->Getter_Sdt()[0] == '0'))
		{
			cout << "\nSo dien thoai nhan vien van phong thu " << i + 1 << " dung dinh dang";
		}
		else
		{
			cout << "\nSo dien thoai nhan vien van phong thu " << i + 1 << " chua dung dinh dang";
		}
	}

	for (int i = 0; i < k; i++)
	{
		if ((ds_nvcongnhat[i]->Getter_Sdt().length() == 10) && (ds_nvcongnhat[i]->Getter_Sdt()[0] == '0'))
		{
			cout << "\nSo dien thoai nhan vien cong nhat thu " << i + 1 << " dung dinh dang";
		}
		else
		{
			cout << "\nSo dien thoai nhan vien cong nhat thu " << i + 1 << " chua dung dinh dang";
		}
	}
}

	
void Menu(NHANVIENSANXUAT* ds_nvsanxuat[], int &n, NHANVIENVANPHONG* ds_nvvanphong[], int &m, NHANVIENCONGNHAT* ds_nvcongnhat[], int &k)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======================= QUAN LY NHAN VIEN =======================";
		cout << "\n\t1. Nhap danh sach nhan vien cong ty";
		cout << "\n\t2. Xuat thong tin tung loai nhan vien";
		cout << "\n\t3. Tinh tong so tien cong ty phai tra cho nhan vien moi thang";
		cout << "\n\t4. Xuat danh sach thong tin nhan vien cong nhat va so ngay cong tuong ung";
		cout << "\n\t5. In ra danh sach thong tin nhan vien hon 50 tuoi";
		cout << "\n\t6. Xoa nhan vien co ma so bat ky";
		cout << "\n\t7. Liet ke het tat ca thong tin nhan vien co chu cai trong ten trung voi sau x can tim kiem";
		cout << "\n\t8. Xac thuc so dien thoai cua cac nhan vien co dung dinh dang hay chua";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============================== END ==============================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			while (true)
			{
				system("cls");
				cout << "\n\t1. Nhap danh sach nhan vien san xuat";
				cout << "\n\t2. Nhap danh sach nhan vien van phong";
				cout << "\n\t3. Nhap danh sach nhan vien cong nhat";
				cout << "\n\t0. Ket thuc";

				int luachon;
				cout << "\nNhap lua chon: ";
				cin >> luachon;

				if (luachon == 1)
				{
					cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN SAN XUAT\n";
					NHANVIENSANXUAT* x = new NHANVIENSANXUAT;
					x->Nhap_Thong_Tin();
					ds_nvsanxuat[n] = x;
					n++;
				}
				else if (luachon == 2)
				{
					cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN VAN PHONG\n";
					NHANVIENVANPHONG* x = new NHANVIENVANPHONG;
					x->Nhap_Thong_Tin();
					ds_nvvanphong[m] = x;
					m++;

				}
				else if (luachon == 3)
				{
					cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN CONG NHAT\n";
					NHANVIENCONGNHAT* x = new NHANVIENCONGNHAT;
					x->Nhap_Thong_Tin();
					ds_nvcongnhat[k] = x;
					k++;
				}
				else
				{
					break;
				}
			}
		}
		else if (luachon == 2)
		{
			Xuat_Thong_Tin_Tung_Loai_Nhan_Vien(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\t So tien cong ty phai tra cho nhan vien moi thang la: " << (size_t)Tong_So_Tien_Cong_Ty_Tra_Cho_Nhan_Vien(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\t\t DANH SACH THONG TIN NHAN VIEN CONG NHAT VA SO NGAY CONG TUONG UNG\n";
			for (int i = 0; i < k; i++)
			{
				cout << "\n\n\t\t THONG TIN NHAN VIEN CONG NHAT THU "  << i + 1 << endl;
				ds_nvcongnhat[i]->Xuat_Thong_Tin();
			}
			system("pause");
		}
		else if (luachon == 5)
		{
			Xuat_Danh_Sach_Thong_Tin_Nhan_Vien_Tuoi_Hon_50(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);
			system("pause");
		}
		else if (luachon == 6)
		{
			Xoa_Nhan_Vien_Co_Ma_So_Bat_Ky(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);
			system("pause");
		}
		else if (luachon == 7)
		{
			Xuat_Thong_Tin_Nhan_Vien_Co_Chu_Cai_Trong_Ten_Trung_Voi_Sau_x_Can_Tim(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);
			system("pause");
		}
		else if (luachon == 8)
		{
			Xac_Thuc_SDT_Cac_Nhan_Vien_Co_Dinh_Dang_Chua(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);
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
	NHANVIENSANXUAT* ds_nvsanxuat[100];
	int n = 0;
	NHANVIENVANPHONG* ds_nvvanphong[100];
	int m = 0;
	NHANVIENCONGNHAT* ds_nvcongnhat[100];
	int k = 0;
	Menu(ds_nvsanxuat, n, ds_nvvanphong, m, ds_nvcongnhat, k);

	for (int i = 0; i < n; i++)
	{
		delete ds_nvsanxuat[i];
	}
	for (int i = 0; i < m; i++)
	{
		delete ds_nvvanphong[i];
	}
	for (int i = 0; i < k; i++)
	{
		delete ds_nvcongnhat[i];
	}

	return 0;
}
