#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class NHANVIENSUAONGNUOC
{
public:
	void NhapThongTin();
	void XuatThongTin();
	float TinhTienLuong();

private:
	string hoten;
	int tuoi;
	string gioitinh;
	string sdt;
	string diachi;
	float chieucao;
	float cannang;
	float sogiosua;
};

void NHANVIENSUAONGNUOC::NhapThongTin()
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten nhan vien: ";
	getline(cin, hoten);
	cout << "\nNhap tuoi nhan vien: ";
	cin >> tuoi;
	while (getchar() != '\n');
	cout << "\nNhap gioi tinh nhan vien: ";
	getline(cin, gioitinh);
	cout << "\nNhap so dien thoai nhan vien: ";
	getline(cin, sdt);
	cout << "\nNhap dia chi nhan vien: ";
	getline(cin, diachi);
	cout << "\nNhap chieu cao nhan vien: ";
	cin >> chieucao;
	cout << "\nNhap can nang nhan vien: ";
	cin >> cannang;
	cout << "\nNhap so gio sua cua nhan vien: ";
	cin >> sogiosua;
}

void NHANVIENSUAONGNUOC::XuatThongTin()
{
	cout << "\nHo ten nhan vien: " << hoten;
	cout << "\nTuoi nhan vien: " << tuoi;
	cout << "\nGioi tinh nhan vien: " << gioitinh;
	cout << "\nSo dien thoai nhan vien: " << sdt;
	cout << "\nDia chi nhan vien: " << diachi;
	cout << "\nNhap chieu cao nhan vien: " << chieucao;
	cout << "\nNhap can nang nhan vien: " << cannang;
	cout << "\nSo gio sua cua nhan vien: " << sogiosua;
}

float NHANVIENSUAONGNUOC::TinhTienLuong()
{
	return sogiosua * 50000;
}

void Xuat_Danh_Sach_NV_SUAONGNUOC(NHANVIENSUAONGNUOC ds_nvsuaongnuoc[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t THONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1 << endl;
		ds_nvsuaongnuoc[i].XuatThongTin();
	}
}

float Tinh_Tong_Tien_Luong_NV_SUAONGNUOC(NHANVIENSUAONGNUOC ds_nvsuaongnuoc[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + ds_nvsuaongnuoc[i].TinhTienLuong();
	}
	return s;
}

void Hoan_vi(NHANVIENSUAONGNUOC& a, NHANVIENSUAONGNUOC& b)
{
	NHANVIENSUAONGNUOC tmp = a;
	a = b;
	b = tmp;
}

void Sap_xep_danh_sach_NV_SUAONGNUOC(NHANVIENSUAONGNUOC ds_nvsuaongnuoc[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((ds_nvsuaongnuoc[i].TinhTienLuong()) < (ds_nvsuaongnuoc[j].TinhTienLuong()))
			{
				Hoan_vi(ds_nvsuaongnuoc[i], ds_nvsuaongnuoc[j]);
			}
		}
	}
}

class NHANVIENGIAOHANG
{
public:
	void NhapThongTin();
	void XuatThongTin();
	float TinhTienLuong();

private:
	string hoten;
	int tuoi;
	string gioitinh;
	string sdt;
	string diachi;
	float chieucao;
	float cannang;
	int sohanggiao;
};

void NHANVIENGIAOHANG::NhapThongTin()
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten nhan vien: ";
	getline(cin, hoten);
	cout << "\nNhap tuoi nhan vien: ";
	cin >> tuoi;
	while (getchar() != '\n');
	cout << "\nNhap gioi tinh nhan vien: ";
	getline(cin, gioitinh);
	cout << "\nNhap so dien thoai nhan vien: ";
	getline(cin, sdt);
	cout << "\nNhap dia chi nhan vien: ";
	getline(cin, diachi);
	cout << "\nNhap chieu cao nhan vien: ";
	cin >> chieucao;
	cout << "\nNhap can nang nhan vien: ";
	cin >> cannang;
	cout << "\nNhap so hang giao cua nhan vien: ";
	cin >> sohanggiao;
}

void NHANVIENGIAOHANG::XuatThongTin()
{
	cout << "\nHo ten nhan vien: " << hoten;
	cout << "\nTuoi nhan vien: " << tuoi;
	cout << "\nGioi tinh nhan vien: " << gioitinh;
	cout << "\nSo dien thoai nhan vien: " << sdt;
	cout << "\nDia chi nhan vien: " << diachi;
	cout << "\nNhap chieu cao nhan vien: " << chieucao;
	cout << "\nNhap can nang nhan vien: " << cannang;
	cout << "\nSo hang giao cua nhan vien: " << sohanggiao;
}

float NHANVIENGIAOHANG::TinhTienLuong()
{
	return sohanggiao * 33500;
}

void Xuat_Danh_Sach_NV_GIAOHANG(NHANVIENGIAOHANG ds_nvgiaohang[], int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "\n\n\t THONG TIN NHAN VIEN GIAO HANG THU " << i + 1 << endl;
		ds_nvgiaohang[i].XuatThongTin();
	}
}

float Tinh_Tong_Tien_Luong_NV_GIAOHANG(NHANVIENGIAOHANG ds_nvgiaohang[], int m)
{
	float s = 0;
	for (int i = 0; i < m; i++)
	{
		s = s + ds_nvgiaohang[i].TinhTienLuong();
	}
	return s;
}

void Hoan_vi(NHANVIENGIAOHANG& a, NHANVIENGIAOHANG& b)
{
	NHANVIENGIAOHANG tmp = a;
	a = b;
	b = tmp;
}

void Sap_xep_danh_sach_NV_GIAOHANG(NHANVIENGIAOHANG ds_nvgiaohang[], int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if ((ds_nvgiaohang[i].TinhTienLuong()) < (ds_nvgiaohang[j].TinhTienLuong()))
			{
				Hoan_vi(ds_nvgiaohang[i], ds_nvgiaohang[j]);
			}
		}
	}
}

class NHANVIENXEOM
{
public:
	void NhapThongTin();
	void XuatThongTin();
	float TinhTienLuong();

private:
	string hoten;
	int tuoi;
	string gioitinh;
	string sdt;
	string diachi;
	float chieucao;
	float cannang;
	float so_km;
};

void NHANVIENXEOM::NhapThongTin()
{
	while (getchar() != '\n');
	cout << "\nNhap ho ten nhan vien: ";
	getline(cin, hoten);
	cout << "\nNhap tuoi nhan vien: ";
	cin >> tuoi;
	while (getchar() != '\n');
	cout << "\nNhap gioi tinh nhan vien: ";
	getline(cin, gioitinh);
	cout << "\nNhap so dien thoai nhan vien: ";
	getline(cin, sdt);
	cout << "\nNhap dia chi nhan vien: ";
	getline(cin, diachi);
	cout << "\nNhap chieu cao nhan vien: ";
	cin >> chieucao;
	cout << "\nNhap can nang nhan vien: ";
	cin >> cannang;
	cout << "\nNhap so km di duoc cua nhan vien: ";
	cin >> so_km;
}

void NHANVIENXEOM::XuatThongTin()
{
	cout << "\nHo ten nhan vien: " << hoten;
	cout << "\nTuoi nhan vien: " << tuoi;
	cout << "\nGioi tinh nhan vien: " << gioitinh;
	cout << "\nSo dien thoai nhan vien: " << sdt;
	cout << "\nDia chi nhan vien: " << diachi;
	cout << "\nNhap chieu cao nhan vien: " << chieucao;
	cout << "\nNhap can nang nhan vien: " << cannang;
	cout << "\nSo km di duoc cua nhan vien: " << so_km;
}

float NHANVIENXEOM::TinhTienLuong()
{
	return so_km * 10000;
}

void Xuat_Danh_Sach_NV_XEOM(NHANVIENXEOM ds_nvxeom[], int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << "\n\n\t THONG TIN NHAN VIEN XE OM THU " << i + 1 << endl;
		ds_nvxeom[i].XuatThongTin();
	}
}

float Tinh_Tong_Tien_Luong_NV_XEOM(NHANVIENXEOM ds_nvxeom[], int k)
{
	float s = 0;
	for (int i = 0; i < k; i++)
	{
		s = s + ds_nvxeom[i].TinhTienLuong();
	}
	return s;
}

void Hoan_vi(NHANVIENXEOM& a, NHANVIENXEOM& b)
{
	NHANVIENXEOM tmp = a;
	a = b;
	b = tmp;
}

void Sap_xep_danh_sach_NV_XEOM(NHANVIENXEOM ds_nvxeom[], int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if ((ds_nvxeom[i].TinhTienLuong()) < (ds_nvxeom[j].TinhTienLuong()))
			{
				Hoan_vi(ds_nvxeom[i], ds_nvxeom[j]);
			}
		}
	}
}

void Menu(NHANVIENSUAONGNUOC ds_nvsuaongnuoc[],NHANVIENGIAOHANG ds_nvgiaohang[],NHANVIENXEOM ds_nvxeom[], int n, int m, int k)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= QUAN LY NHAN VIEN =========================";
		cout << "\n\t1. Nhap thong tin nhan vien sua ong nuoc";
		cout << "\n\t2. Nhap thong tin nhan vien giao hang";
		cout << "\n\t3. Nhap thong tin nhan vien xe om";
		cout << "\n\t4. Xuat danh sach nhan vien sua ong nuoc";
		cout << "\n\t5. Xuat danh sach nhan vien giao hang";
		cout << "\n\t6. Xuat danh sach nhan vien xe om";
		cout << "\n\t7. Tinh tong tien luong danh sach nhan vien sua ong nuoc";
		cout << "\n\t8. Tinh tong tien luong danh sach nhan vien giao hang";
		cout << "\n\t9. Tinh tong tien luong danh sach nhan vien xe om";
		cout << "\n\t10. Sap xep danh sach cac nhan vien giam dan theo luong";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================ END ================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			NHANVIENSUAONGNUOC x;
			cout << "\n\n\t\t NHAP THONG TIN\n";
			x.NhapThongTin();
			ds_nvsuaongnuoc[n] = x;
			n++;
		}
		else if (luachon == 2)
		{
			NHANVIENGIAOHANG y;
			cout << "\n\n\t\t NHAP THONG TIN\n";
			y.NhapThongTin();
			ds_nvgiaohang[m] = y;
			m++;
		}
		else if (luachon == 3)
		{
			NHANVIENXEOM z;
			cout << "\n\n\t\t NHAP THONG TIN\n";
			z.NhapThongTin();
			ds_nvxeom[k] = z;
			k++;
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC\n";
			Xuat_Danh_Sach_NV_SUAONGNUOC(ds_nvsuaongnuoc, n);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\n\t\t DANH SACH NHAN VIEN GIAO HANG\n";
			Xuat_Danh_Sach_NV_GIAOHANG(ds_nvgiaohang, m);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\n\t\t DANH SACH NHAN VIEN XE OM\n";
			Xuat_Danh_Sach_NV_XEOM(ds_nvxeom, k);
			system("pause");
		}
		else if (luachon == 7)
		{
			cout << "\n\n\t\t TONG TIEN LUONG DANH SACH NHAN VIEN SUA ONG NUOC: " << (size_t)Tinh_Tong_Tien_Luong_NV_SUAONGNUOC(ds_nvsuaongnuoc, n);
			system("pause");
		}
		else if (luachon == 8)
		{
			cout << "\n\n\t\t TONG TIEN LUONG DANH SACH NHAN VIEN GIAO HANG: " << (size_t)Tinh_Tong_Tien_Luong_NV_GIAOHANG(ds_nvgiaohang, m);
			system("pause");
		}
		else if (luachon == 9)
		{
			cout << "\n\n\t\t TONG TIEN LUONG DANH SACH NHAN VIEN XE OM: " << (size_t)Tinh_Tong_Tien_Luong_NV_XEOM(ds_nvxeom, k);
			system("pause");
		}
		else if (luachon == 10)
		{
			while (true)
			{
				system("cls");
				cout << "\n\n\t\t ========================= DANH SACH NHAN VIEN GIAM DAN THEO LUONG =========================";
				cout << "\n\t1. Danh sach nhan vien sua ong nuoc";
				cout << "\n\t2. Danh sach nhan vien giao hang";
				cout << "\n\t3. Danh sach nhan vien xe om";
				cout << "\n\t0. Ket thuc";
				cout << "\n\n\t\t =========================================== END ===========================================";

				int luachon;
				cout << "\nNhap danh sach nhan vien ban muon xem: ";
				cin >> luachon;

				if (luachon == 1)
				{
					Sap_xep_danh_sach_NV_SUAONGNUOC(ds_nvsuaongnuoc, n);
					cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC GIAM DAN THEO LUONG\n";
					Xuat_Danh_Sach_NV_SUAONGNUOC(ds_nvsuaongnuoc, n);
					system("pause");
				}
				else if (luachon == 2)
				{
					Sap_xep_danh_sach_NV_GIAOHANG(ds_nvgiaohang, m);
					cout << "\n\n\t\t DANH SACH NHAN VIEN GIAO HANG GIAM DAN THEO LUONG\n";
					Xuat_Danh_Sach_NV_GIAOHANG(ds_nvgiaohang, m);
					system("pause");
				}
				else if (luachon == 3)
				{

					Sap_xep_danh_sach_NV_XEOM(ds_nvxeom, k);
					cout << "\n\n\t\t DANH SACH NHAN VIEN XE OM GIAM DAN THEO LUONG\n";
					Xuat_Danh_Sach_NV_XEOM(ds_nvxeom, k);
					system("pause");
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	NHANVIENSUAONGNUOC ds_nvsuaongnuoc[100];
	NHANVIENGIAOHANG ds_nvgiaohang[100];
	NHANVIENXEOM ds_nvxeom[100];
	int n = 0;
	int m = 0;
	int k = 0;
	Menu(ds_nvsuaongnuoc, ds_nvgiaohang, ds_nvxeom, n, m, k);

	return 0;
}