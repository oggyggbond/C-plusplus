#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct SACH
{
	string masach;
	string tensach;
	string loaisach;
};

void Nhap_Thong_Tin_Sach(SACH& s)
{
	while (getchar() != '\n');
	cout << "\nNhap ma sach: ";
	getline(cin, s.masach);
	cout << "\nNhap ten sach: ";
	getline(cin, s.tensach);
	cout << "\nNhap loai sach: ";
	getline(cin, s.loaisach);
}

void Xuat_Thong_Tin_Sach(SACH s)
{
	cout << "\nMa sach: " << s.masach;
	cout << "\nTen sach: " << s.tensach;
	cout << "\nLoai sach: " << s.loaisach;
}

struct NODE_SACH
{
	SACH data;
	NODE_SACH* pNext;
};

NODE_SACH* Khoi_Tao_Sach(SACH x)
{
	NODE_SACH* p = new NODE_SACH;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void Them_Cuoi(NODE_SACH*& pHead, NODE_SACH* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE_SACH* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

void Sua_Ten_Sach(NODE_SACH* pHead)
{
	string MS;
	while (getchar() != '\n');
	cout << "\nNhap ma sach: ";
	getline(cin, MS);

	for (NODE_SACH* k = pHead; k != NULL; k = k->pNext)
	{
		if (MS == k->data.masach)
		{
			cout << "\nNhap ten sach moi: ";
			getline(cin, k->data.tensach);
			break;
		}
	}
}

void Xoa_Dau(NODE_SACH*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else
	{
		NODE_SACH* k = pHead;
		pHead = pHead->pNext;
		delete k;
	}
}

void Xoa_Cuoi(NODE_SACH*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->pNext == NULL)
	{
		Xoa_Dau(pHead);
		return;
	}
	else
	{
		for (NODE_SACH* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext->pNext == NULL)
			{
				NODE_SACH* h = k->pNext->pNext;
				k->pNext = NULL;
				delete h;
				break;
			}
		}
	}
}

void Xoa_Sach_Co_Ma_So_Bat_Ky(NODE_SACH*& pHead)
{
	string ms;
	while (getchar() != '\n');
	cout << "\nNhap ma so cua sach muon xoa: ";
	getline(cin, ms);

	NODE_SACH* g = new NODE_SACH;
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->data.masach == ms)
	{
		Xoa_Dau(pHead);
	}
	else
	{
		for (NODE_SACH* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->data.masach == ms)
			{
				g->pNext = k->pNext;
				delete k;
				return;
			}
			g = k;
		}
	}
}

void Xuat_Tat_Ca_Sach_Cung_Loai(NODE_SACH* pHead)
{
	while (getchar() != '\n');
	string loai;
	cout << "\nNhap loai sach ban muon xem: ";
	getline(cin, loai);

	for (NODE_SACH* k = pHead; k != NULL; k = k->pNext)
	{
		if (loai == k->data.loaisach)
		{
			Xuat_Thong_Tin_Sach(k->data);
			cout << endl;
		}
	}

}

void Xuat_Danh_Sach(NODE_SACH* pHead)
{
	for (NODE_SACH* k = pHead; k != NULL; k = k->pNext)
	{
		Xuat_Thong_Tin_Sach(k->data);
		cout << endl;
	}
}

void Menu(NODE_SACH* pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =================== QUAN LY CAC LOAI SACH ======================";
		cout << "\n\t1. Them cuoi";
		cout << "\n\t2. Xoa dau";
		cout << "\n\t3. Xoa cuoi";
		cout << "\n\t4. Xoa sach co ma so bat ky";
		cout << "\n\t5. Xuat danh sach";
		cout << "\n\t6. Xuat tat ca cac cuon sach cung loai";
		cout << "\n\t7. Sua ten sach";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============================ END ================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			SACH x;
			cout << "\n\n\t\tNHAP THONG TIN SACH\n";
			Nhap_Thong_Tin_Sach(x);
			NODE_SACH* p = Khoi_Tao_Sach(x);
			Them_Cuoi(pHead, p);
		}
		else if (luachon == 2)
		{
			while (true)
			{
				system("cls");
				cout << "\n\t1. Yes";
				cout << "\n\t2. No";
				cout << "\n\t0. Quay tro lai";

				int chon;
				cout << "\nBan that su muon xoa?";
				cin >> chon;

				if (chon == 1)
				{
					Xoa_Dau(pHead);
				}
				else if (chon == 2)
				{
					break;
				}
				else
				{
					break;
				}
			}
		}
		else if (luachon == 3)
		{
			while (true)
			{
				system("cls");
				cout << "\n\t1. Yes";
				cout << "\n\t2. No";
				cout << "\n\t0. Quay tro lai";

				int chon;
				cout << "\nBan that su muon xoa?";
				cin >> chon;

				if (chon == 1)
				{
					Xoa_Cuoi(pHead);
				}
				else if (chon == 2)
				{
					break;
				}
				else
				{
					break;
				}
			}
		}
		else if (luachon == 4)
		{
			while (true)
			{
				system("cls");
				cout << "\n\t1. Yes";
				cout << "\n\t2. No";
				cout << "\n\t0. Quay tro lai";

				int chon;
				cout << "\nBan that su muon xoa?";
				cin >> chon;

				if (chon == 1)
				{
					Xoa_Sach_Co_Ma_So_Bat_Ky(pHead);
				}
				else if (chon == 2)
				{
					break;
				}
				else
				{
					break;
				}
			}
			system("pause");
		}
		else if (luachon == 5)
		{

			cout << "\n\n\t\t DANH SACH TAT CA CAC CUON SACH\n";
			Xuat_Danh_Sach(pHead);
			system("pause");
		}
		else if (luachon == 6)
		{
			Xuat_Tat_Ca_Sach_Cung_Loai(pHead);
			system("pause");
		}
		else if (luachon == 7)
		{
			while (true)
			{
				system("cls");
				cout << "\n\t1. Yes";
				cout << "\n\t2. No";
				cout << "\n\t0. Quay tro lai";

				int chon;
				cout << "\nBan chac chan muon sua Ten Sach? ";
				cin >> chon;

				if (chon == 1)
				{
					Sua_Ten_Sach(pHead);
				}
				else if (chon == 2)
				{
					break;
				}
				else
				{
					break;
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
	NODE_SACH* pHead = NULL;

	Menu(pHead);

	return 0;
}