#include <iostream>
#include <string>
#include <fstream>

using namespace std;

float s = 0;
struct KH
{
	string tenkh;
	string cmnd;
	string gaden;
	float giatien;
};

void Doc_Thong_Tin_1_KH(ifstream &filein, KH &kh)
{
	getline(filein, kh.tenkh, ',');
	filein.seekg(1, 1);
	getline(filein, kh.cmnd, ',');
	filein.seekg(1, 1);
	getline(filein, kh.gaden, ',');
	filein.seekg(1, 1);
	filein >> kh.giatien;

	string tam;
	getline(filein, tam);
}

void Xuat_Thong_Tin_KH(KH kh)
{
	cout << "\nHo ten khach hang: " << kh.tenkh;
	cout << "\nCMND khach hang: " << kh.cmnd;
	cout << "\nGa den: " << kh.gaden;
	cout << "\nGia tien: " << kh.giatien;
}

struct NODE_KH
{
	KH data;
	NODE_KH* pNext;
	NODE_KH* pre;
};

NODE_KH* Khoi_Tao_KH(KH x)
{
	NODE_KH* p = new NODE_KH;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	p->pre = NULL;
	return p;
}

void Them_Cuoi(NODE_KH*& pHead, NODE_KH* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE_KH* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p; 
				p->pre = k;
				k = p;
				break;
			}
		}
	}
}

void Doc_DS_KH(ifstream& filein, NODE_KH*& pHead)
{
	while (filein.eof() == false)
	{
		KH kh;
		Doc_Thong_Tin_1_KH(filein, kh);
		NODE_KH* p = Khoi_Tao_KH(kh);
		Them_Cuoi(pHead, p);
	}
}

void Xuat_DS_KH(NODE_KH* pHead)
{
	int dem = 1;
	for (NODE_KH* k = pHead; k != NULL; k = k->pNext)
	{
		cout << "\n\n\t\tKHACH HANG THU " << dem++ << endl;
		Xuat_Thong_Tin_KH(k->data);
		cout << endl;
	}
}

void Ghi_Thong_Tin_KH(ofstream& fileout, KH kh)
{
	fileout << kh.tenkh << " , ";
	fileout << kh.cmnd << " , ";
	fileout << kh.gaden << " , ";
	fileout << kh.giatien;
}

void Ghi_DS_KH(NODE_KH* pHead)
{
	ofstream fileout;
	fileout.open("DSKH.txt", ios::out);

	for (NODE_KH* k = pHead; k != NULL; k = k->pNext)
	{
		Ghi_Thong_Tin_KH(fileout, k->data);
		fileout << endl;
	}
	fileout.close();
}

void Xoa_Dau(NODE_KH*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->pNext == NULL)
	{
		NODE_KH* k = pHead;
		pHead = NULL;
		delete k;
		return;
	}
	else
	{
		NODE_KH* k = pHead;
		pHead = pHead->pNext;
		pHead->pre = NULL;
		delete k;
	}
}

void Xoa_KH_Khong_Mua_Ve_Nua(NODE_KH*& pHead, string x)
{
	NODE_KH* g = new NODE_KH;

	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->data.cmnd == x)
	{
		Xoa_Dau(pHead);
	}
	else
	{
		for (NODE_KH* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->data.cmnd == x)
			{
				g->pNext = k->pNext;
				delete k;
				return;
			}
			k->pre = g;
			g = k;
		}
	}
}

KH Ban_Ve(NODE_KH*& pHead)
{
	if (pHead->pNext == NULL)
	{
		NODE_KH* k = pHead;
		KH x;
		x = k->data;
		pHead = NULL;
		delete k;
		return x;
	}
	else if (pHead ->pNext != NULL)
	{
		NODE_KH* k = pHead;
		KH x;
		x = k->data;
		pHead = pHead->pNext;
		pHead->pre = NULL;
		delete k;
		return x;
	}
}

void Thong_Ke_Ban_Ve(NODE_KH* pHead)
{
	cout << "\nSo khach cho nhan ve: ";
	Xuat_DS_KH(pHead);
	cout << "\nSo khach da nhan ve: ";
	ifstream filein;
	filein.open("BanVeChoKH.txt", ios::in);
	while (filein.eof() == false)
	{
		KH kh;
		Doc_Thong_Tin_1_KH(filein, kh);
		NODE_KH* p = Khoi_Tao_KH(kh);
		Them_Cuoi(pHead, p);
	}
	cout << "\nTong so tien ban ve: " << (size_t)s;
	filein.close();
}

void Giai_Phong_Vung_Nho(NODE_KH*& pHead)
{
	while (pHead != NULL)
	{
		if (pHead->pNext == NULL)
		{
			NODE_KH* p = pHead;
			pHead = NULL;
			delete p;
			return;
		}
		else
		{
			NODE_KH* p = pHead;
			pHead = pHead->pNext;
			pHead->pre = NULL;
			delete p;
		}
	}
}

void Menu(ifstream& filein, NODE_KH*& pHead)
{
	while (true)
	{
		system("cls");

		cout << "\n\n\t\t =============================== QUAN LY KHACH HANG CUA NHA GA ===============================";
		cout << "\n\t1. Doc danh sach khach hang tu file";
		cout << "\n\t2. Them mot khach hang moi vao hang doi mua ve";
		cout << "\n\t3. Ban mot ve cho khach hang (chi ban cho nguoi dang ki truoc)";
		cout << "\n\t4. Hien thi danh sach khach hang";
		cout << "\n\t5. Huy mot khach hang ra khoi danh sach";
		cout << "\n\t6. Thong ke tinh hinh ban ve";
		cout << "\n\t7. Luu danh sach vao file";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============================================ END ============================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			while (filein.eof() == false)
			{
				KH kh;
				Doc_Thong_Tin_1_KH(filein, kh);
				NODE_KH* p = Khoi_Tao_KH(kh);
				Them_Cuoi(pHead, p);
			}
		}
		else if (luachon == 2)
		{
			KH kh;
			while (getchar() != '\n');
			cout << "\n\n\t\tNHAP THONG TIN KHACH HANG CAN THEM\n";
			cout << "\nNhap ho ten khach hang: ";
			getline(cin, kh.tenkh);
			cout << "\nNhap cmnd khach hang: ";
			getline(cin, kh.cmnd);
			cout << "\nNhap ga den: ";
			getline(cin, kh.gaden);
			cout << "Nhap gia tien: ";
			cin >> kh.giatien;

			NODE_KH* p = Khoi_Tao_KH(kh);
			Them_Cuoi(pHead, p);

			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\tBAN VE CHO KHACH HANG\n";

			while (true)
			{
				cout << endl;
				cout << "\n\t1. Yes";
				cout << "\n\t2. No";
				cout << "\n\t0. Quay lai";
				cout << endl;

				int chon;
				cout << "\nBan co chac chan muon ban ve cho khach hang?";
				cin >> chon;

				if (chon == 1)
				{
					KH x = Ban_Ve(pHead);
					s = s + x.giatien;
					ofstream fileout;
					fileout.open("BanVeChoKH.txt", ios::out);
					Ghi_Thong_Tin_KH(fileout, x);
					fileout.close();
				}
				else
				{
					break;
				}
			}
			
			system("pause");
		}
		else if (luachon == 4)
		{
			Xuat_DS_KH(pHead);

			system("pause");
		}
		else if (luachon == 5)
		{
			string x;
			while (getchar() != '\n');
			cout << "\nNhap cmnd cua khach hang khong mua ve nua: ";
			getline(cin, x);

			while (true)
			{
				system("cls");
				cout << "\n\t1. Yes";
				cout << "\n\t2. No";
				cout << "\n\t0. Quay lai";

				int chon;
				cout << "\nBan co chac chan muon xoa?";
				cin >> chon;

				if (chon == 1)
				{
					Xoa_KH_Khong_Mua_Ve_Nua(pHead, x);
				}
				else
				{
					break;
				}
			}
			system("pause");
		}
		else if (luachon == 6)
		{
			Thong_Ke_Ban_Ve(pHead);
			system("pause");
		}
		else if (luachon == 7)
		{
			Ghi_DS_KH(pHead);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	NODE_KH* pHead = NULL;
	ifstream filein;
	filein.open("KHACHHANG.txt", ios::in);
	
	Menu(filein, pHead);

	Giai_Phong_Vung_Nho(pHead);
	filein.close();
	
	return 0;
}