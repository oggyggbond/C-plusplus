#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;

void ThemNode(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x > t->data)
		{
			ThemNode(t->pRight, x);
		}
		else if (x < t->data)
		{

			ThemNode(t->pLeft, x);
		}
	}
}

void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << "   ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

void NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << "   ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

void LNR(TREE t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->data << "   ";
		LNR(t->pRight);
	}
}

void RNL(TREE t)
{
	if (t != NULL)
	{
		RNL(t->pRight);
		cout << t->data << "   ";
		RNL(t->pLeft);
	}
}

void LRN(TREE t)
{
	if (t != NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << t->data << "   ";
	}
}

void RLN(TREE t)
{
	if (t != NULL)
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->data << "   ";
	}
}

bool Kiem_Tra_So_Nguyen_to(int n)
{
	if (n < 2)
	{
		return false;
	}
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void Xuat_Cac_SNT(TREE t)
{
	if (t != NULL)
	{
		if (Kiem_Tra_So_Nguyen_to(t->data) == true)
		{
			cout << t->data << "  ";
		}
		Xuat_Cac_SNT(t->pLeft);
		Xuat_Cac_SNT(t->pRight);
	}
}

int SoMAX(TREE t)
{
	if (t->pRight == NULL)
	{
		return t->data;
	}
	return SoMAX(t->pRight);
}

void Menu(TREE t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============================== BINARY SEARCH TREE ==============================";
		cout << "\n\t1. Nhap phan tu";
		cout << "\n\t2. 6 cach duyet cay";
		cout << "\n\t3. Xuat cac so nguyen to";
		cout << "\n\t4. Tim so lon nhat";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ===================================== END =====================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			ThemNode(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\nNLR: ";
			NLR(t);
			cout << "\nNRL: ";
			NRL(t);
			cout << "\nLNR: ";
			LNR(t);
			cout << "\nRNL: ";
			RNL(t);
			cout << "\nLRN: ";
			LRN(t);
			cout << "\nRLN: ";
			RLN(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t CAC SO NGUYEN TO: ";
			Xuat_Cac_SNT(t);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t SO LON NHAT LA: ";
			cout << SoMAX(t);
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
	TREE t;
	t = NULL;
	Menu(t);

	return 0;
}