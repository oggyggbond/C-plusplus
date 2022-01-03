#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct KHOA
{
	string tenkhoa;
	string makhoa;
};

void Nhap_Thong_Tin_Khoa(KHOA& k)
{
	while (getchar() != '\n');
	cout << "\nNhap ten khoa: ";
	getline(cin, k.tenkhoa);
	cout << "\nNhap ma khoa: ";
	getline(cin, k.makhoa);
}

void Xuat_Thong_Tin_Khoa(KHOA k)
{
	cout << "\nTen khoa: " << k.tenkhoa;
	cout << "\nMa khoa: " << k.makhoa;
}

struct NODE_KHOA
{
	KHOA data;
	NODE_KHOA* pNext;
};

NODE_KHOA* Khoi_Tao_Khoa(KHOA x)
{
	NODE_KHOA* p = new NODE_KHOA;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void Them_Khoa_Vao_Cuoi(NODE_KHOA*& pHead, NODE_KHOA* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE_KHOA* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

void Xuat_DS_Khoa(NODE_KHOA* pHead)
{
	for (NODE_KHOA* k = pHead; k != NULL; k = k->pNext)
	{
		Xuat_Thong_Tin_Khoa(k->data);
		cout << endl;
	}
}

struct SV
{
	string masv;
	string hotensv;
	string MK;
};

void Nhap_Thong_Tin_SV(SV& sv)
{
	cout << "\nNhap ma so sinh vien: ";
	cin >> sv.masv;

	for (int i = 0; i < sv.masv.length(); i++)
	{
		while (sv.masv[i] < 48 || sv.masv[i] > 57)
		{
			cout << "\n\nMSSV phai la so. Nhap lai!";
			cin >> sv.masv;
		}
	}

	while (getchar() != '\n');
	cout << "\nNhap ho ten sinh vien: ";
	getline(cin, sv.hotensv);

	cout << "\nNhap ma khoa sinh vien: ";
	getline(cin, sv.MK);
}

bool KT_MK(NODE_KHOA* pHead)
{
	for (NODE_KHOA* k = pHead; k != NULL; k = k->pNext)
	{
		for (NODE_KHOA* m = k->pNext; m != NULL; m = m->pNext)
		{
			if (k->data.makhoa == m->data.makhoa)
			{
				return true;
			}
		}
	}
}

void Xuat_Thong_Tin_SV(SV sv)
{
	cout << "\nMa so sinh vien: " << sv.masv;
	cout << "\nHo ten sinh vien: " << sv.hotensv;
	cout << "\nMa khoa cua sinh vien: " << sv.MK;
}

struct NODE_SV
{
	SV data;
	NODE_SV* pNext;
};

NODE_SV* Khoi_Tao_SV(SV sv)
{
	NODE_SV* p = new NODE_SV;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!";
		return  NULL;
	}
	p->data = sv;
	p->pNext = NULL;
	return p;
}

void Them_SV_Vao_Cuoi(NODE_SV*& phead, NODE_SV* p)
{
	if (phead == NULL)
	{
		phead = p;
	}
	else
	{
		for (NODE_SV* k = phead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

bool KT_MSV(NODE_SV* phead)
{
	for (NODE_SV* k = phead; k != NULL; k = k->pNext)
	{
		for (NODE_SV* m = k->pNext; m != NULL; m = m->pNext)
		{
			if (k->data.masv == m->data.masv)
			{
				return true;
			}
		}
	}
}

void Xuat_DS_SV(NODE_SV* phead)
{
	for (NODE_SV* k = phead; k != NULL; k = k->pNext)
	{
		Xuat_Thong_Tin_SV(k->data);
		cout << endl;
	}
}

void Hoan_Vi(SV& x, SV& y)
{
	SV tam = x;
	x = y;
	y = tam;
}

void Sap_Xep(NODE_SV* phead)
{
	for (NODE_SV* k = phead; k != NULL; k = k->pNext)
	{
		for (NODE_SV* l = k->pNext; l != NULL; l = l->pNext)
		{
			if (strcmp(k->data.hotensv.c_str(), l->data.hotensv.c_str()) > 0)
			{
				Hoan_Vi(k->data, l->data);
			}
		}
	}
}

void Tim_Kiem_SV_Trong_Khoa(NODE_KHOA* pHead, NODE_SV* phead)
{
	while (getchar() != '\n');
	string tenKhoa;
	cout << "\nNhap ten khoa can tim: ";
	getline(cin, tenKhoa);

	string mk;
	for (NODE_KHOA* k = pHead; k != NULL; k = k->pNext)
	{
		if (tenKhoa == k->data.tenkhoa)
		{
			mk = k->data.makhoa;
		}
	}
	for (NODE_SV* k = phead; k != NULL; k = k->pNext)
	{
		if (mk == k->data.MK)
		{
			Xuat_Thong_Tin_SV(k->data);
			cout << endl;
		}
	}
}

void Menu(NODE_KHOA* pHead, NODE_SV* phead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ===================== CAC SINH VIEN TRONG KHOA ======================";
		cout << "\n\t1. Nhap thong tin khoa";
		cout << "\n\t2. Xuat thong tin khoa";
		cout << "\n\t3. Nhap thong tin sinh vien";
		cout << "\n\t4. Xuat thong tin sinh vien";
		cout << "\n\t5. Tim sinh vien trong khoa";
		cout << "\n\t6. Sap xep sinh vien theo ten";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ================================ END =================================";

		int chon;
		cout << "\nNhap lua chon: ";
		cin >> chon;

		if (chon == 1)
		{
			KHOA x;
			cout << "\n\n\t\tNHAP THONG TIN KHOA\n";
			Nhap_Thong_Tin_Khoa(x);
			NODE_KHOA* p = Khoi_Tao_Khoa(x);
			Them_Khoa_Vao_Cuoi(pHead, p);
			while (KT_MK(pHead) == true)
			{
				cout << "\nMa khoa da ton tai!";
				for (NODE_KHOA* k = pHead; k != NULL; k = k->pNext)
				{
					if (k->pNext->pNext == NULL)
					{
						NODE_KHOA* h = k->pNext->pNext;
						k->pNext = NULL;
						delete h;
						break;
					}
				}
				break;
			}
			system("pause");
		}
		else if (chon == 2)
		{
			cout << "\n\n\t\tDANH SACH CAC KHOA\n";
			Xuat_DS_Khoa(pHead);
			system("pause");
		}
		else if (chon == 3)
		{
			SV sv;
			cout << "\n\n\t\tNHAP THONG TIN SINH VIEN\n";
			Nhap_Thong_Tin_SV(sv);
			NODE_SV* p = Khoi_Tao_SV(sv);
			Them_SV_Vao_Cuoi(phead, p);
			for (NODE_KHOA* k = pHead; k != NULL; k = k->pNext)
			{
				while (sv.MK != k->data.makhoa)
				{
					cout << "\nKhong ton tai ma khoa!";
					break;
				}
			}
			while (KT_MSV(phead) == true)
			{
				cout << "\nMa sinh vien da ton tai!";
				for (NODE_SV* k = phead; k != NULL; k = k->pNext)
				{
					if (k->pNext->pNext == NULL)
					{
						NODE_SV* h = k->pNext->pNext;
						k->pNext = NULL;
						delete h;
						break;
					}
				}
				break;
			}
			system("pause");
		}
		else if (chon == 4)
		{
			cout << "\n\n\t\tDANH SACH SINH VIEN\n";
			Xuat_DS_SV(phead);
			system("pause");
		}
		else if (chon == 5)
		{
			Tim_Kiem_SV_Trong_Khoa(pHead, phead);
			system("pause");
		}
		else if (chon == 6)
		{
			Sap_Xep(phead);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	NODE_KHOA* pHead = NULL;
	NODE_SV* phead = NULL;

	Menu(pHead, phead);

	return 0;
}