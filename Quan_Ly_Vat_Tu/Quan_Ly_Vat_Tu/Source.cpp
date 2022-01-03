#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct CT_HOADON
{
	string mavt;
	int soluong;
	float dongia;
	float vat;
};

struct DANHSACH_CT_HOADON
{
	CT_HOADON ds_ct_hoadon[20];
	int n;
};

struct NGAY
{
	int d, m, y;
};

struct HOADON
{
	string sohoadon;
	NGAY ngaythanglap;
	char loai;
	DANHSACH_CT_HOADON dscthd;
};

void Nhap_Ngay(NGAY& ng)
{
	cout << "\nNhap ngay: ";
	cin >> ng.d;
	cout << "\nNhap thang: ";
	cin >> ng.m;
	cout << "\nNhap nam: ";
	cin >> ng.y;
}

void Xuat_Ngay(NGAY ng)
{
	cout << ng.d << "/" << ng.m << "/" << ng.y;
}

void Nhap_Thong_Tin_Hoa_Don(HOADON& hd)
{
	while (getchar() != '\n');
	cout << "\nNhap so hoa don: ";
	getline(cin, hd.sohoadon);
	cout << "\nNhap ngay thang lap: ";
	Nhap_Ngay(hd.ngaythanglap);
	cout << "\nNhap loai: ";
	cin >> hd.loai;
}

void Xuat_Thong_Tin_Hoa_Don(HOADON hd)
{
	cout << "\nSo hoa don: " << hd.sohoadon;
	cout << "\nNgay thang lap: ";
	Xuat_Ngay(hd.ngaythanglap);
	cout << "\nLoai hoa don: " << hd.loai;
}

struct NODE_HOADON
{
	HOADON data;
	NODE_HOADON* pNext;
};

NODE_HOADON* Khoi_tao_node_hd(HOADON x)
{
	NODE_HOADON* p = new NODE_HOADON;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void Them_Cuoi(NODE_HOADON*& pHead, NODE_HOADON* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE_HOADON* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

struct NHANVIEN
{
	int manv;
	string ho;
	string ten;
	string phai;
	NODE_HOADON* pHead;
};

void Nhap_Thong_Tin_Nhan_Vien(NHANVIEN& nv)
{
	cout << "\nNhap ma nhan vien: ";
	cin >> nv.manv;
	while (getchar() != '\n');
	cout << "\nNhap ho nhan vien: ";
	getline(cin, nv.ho);
	cout << "\nNhap ten nhan vien: ";
	getline(cin, nv.ten);
	cout << "\nNhap phai nhan vien: ";
	getline(cin, nv.phai);
	nv.pHead = NULL;
}

void Xuat_Thong_Tin_Nhan_Vien(NHANVIEN nv)
{
	cout << "\nMa nhan vien: " << nv.manv;
	cout << "\nHo nhan vien: " << nv.ho;
	cout << "\nTen nhan vien: " << nv.ten;
	cout << "\nPhai: " << nv.phai;
}

struct NODE_NHANVIEN
{
	NHANVIEN data;
	NODE_NHANVIEN* pLeft;
	NODE_NHANVIEN* pRight;
};
typedef NODE_NHANVIEN* TREE;

void ThemNhanVien(TREE& t, NHANVIEN nv)
{
	if (t == NULL)
	{
		NODE_NHANVIEN* p = new NODE_NHANVIEN;
		p->data = nv;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (nv.manv > t->data.manv)
		{
			ThemNhanVien(t->pRight, nv);
		}
		else if (nv.manv < t->data.manv)
		{
			ThemNhanVien(t->pLeft, nv);
		}
	}
}

void DuyetNhanVien(TREE t)
{
	if (t != NULL)
	{
		Xuat_Thong_Tin_Nhan_Vien(t->data);
		cout << "\n\n";
		DuyetNhanVien(t->pLeft);
		DuyetNhanVien(t->pRight);
	}
}

struct VATTU
{
	string mavt;
	string tenvt;
	string dvt;
	int soluongton;
};

struct DANHSACHVATTU
{
	VATTU* ds_vt[100];
	int n;
};

void Nhap_Thong_Tin_Vat_Tu(VATTU& vt)
{
	while (getchar() != '\n');
	cout << "\nNhap ten vat tu: ";
	getline(cin, vt.tenvt);
	cout << "\nNhap ma vat tu: ";
	getline(cin, vt.mavt);
	cout << "\nNhap don vi tinh: ";
	getline(cin, vt.dvt);
	cout << "\nNhap so luong ton: ";
	cin >> vt.soluongton;
}

void Xuat_Thong_Tin_Vat_Tu(VATTU vt)
{
	cout << "\nTen vat tu: " << vt.tenvt;
	cout << "\nMa vat tu: " << vt.mavt;
	cout << "\nDon vi tinh: " << vt.dvt;
	cout << "\nSo luong ton: " << vt.soluongton;
}

void Menu_QuanLyVatTu(DANHSACHVATTU& ds)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================== QUAN LY VAT TU ==========================";
		cout << "\n\t1. Nhap thong tin vat tu moi";
		cout << "\n\t2. Xuat danh sach vat tu";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t =============================== END ===============================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			VATTU vt;
			cout << "\n\tNHAP THONG TIN VAT TU\n";
			Nhap_Thong_Tin_Vat_Tu(vt);
			ds.ds_vt[ds.n] = new VATTU;
			*ds.ds_vt[ds.n] = vt;
			ds.n = ds.n + 1;
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\tXUAT DANH SACH VAT TU\n";
			for (int i = 0; i < ds.n; i++)
			{
				cout << "\n\tVAT TU THU " << i + 1 << endl;
				Xuat_Thong_Tin_Vat_Tu(*(ds.ds_vt[i]));
			}
			system("pause");
		}
		else
		{
			break;
		}
	}
}

void Menu_QuanLyHoaDon(NODE_HOADON*& pHead)
{
	HOADON hd;
	cout << "\n\n\t\tNHAP THONG TIN HOA DON\n";
	Nhap_Thong_Tin_Hoa_Don(hd);
	hd.dscthd.n = 0;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= BAN MUON MUA GI - TOI CO DO =========================";
		cout << "\n\t1. Nhap thong tin chi tiet hoa don";
		cout << "\n\t2. Thoat";
		cout << "\n\n\t\t ===================================== END =====================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			CT_HOADON x;
			while (getchar() != '\n');
			cout << "\nNhap ma vat tu: ";
			getline(cin, x.mavt);
			cout << "\nNhap so luong: ";
			cin >> x.soluong;
			cout << "\nNhap don gia: ";
			cin >> x.dongia;
			cout << "\nNhap VAT: ";
			cin >> x.vat;
			hd.dscthd.ds_ct_hoadon[hd.dscthd.n] = x;
			hd.dscthd.n++;
		}
		else
		{
			break;
		}
	}
}

void Menu_QuanLyNhanVien(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========================= QUAN LY NHAN VIEN =========================";
		cout << "\n\t1. Nhap nhan vien";
		cout << "\n\t2. Xuat danh sach nhan vien";
		cout << "\n\t3. Nhap hoa don";
		cout << "\n\t4. Xuat tat ca hoa don cua nhan vien";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t ================================ END ================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			NHANVIEN nv;
			cout << "\n\n\t\tNHAP THONG TIN NHAN VIEN\n";
			Nhap_Thong_Tin_Nhan_Vien(nv);
			ThemNhanVien(t, nv);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\tDANH SACH NHAN VIEN\n";
			DuyetNhanVien(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			Menu_QuanLyHoaDon(t->data.pHead);
		}
		else if (luachon == 4)
		{
			for (NODE_HOADON* k = t->data.pHead; k != NULL; k = k->pNext)
			{
				Xuat_Thong_Tin_Hoa_Don(k->data);
				cout << endl << endl;
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
	DANHSACHVATTU ds;
	ds.n = 0;
	Menu_QuanLyVatTu(ds);

	NODE_HOADON* pHead;
	pHead = NULL;
	Menu_QuanLyHoaDon(pHead);

	TREE t;
	t = NULL;
	Menu_QuanLyNhanVien(t);

	for (int i = 0; i < ds.n; i++)
	{
		delete ds.ds_vt[i];
	}
	return 0;
}