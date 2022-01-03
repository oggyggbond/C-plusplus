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
		cout << t->data << " ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

void Node_La(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << " ";
		}
		Node_La(t->pLeft);
		Node_La(t->pRight);
	}
}

void Node_co_1_con(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pRight != NULL && t->pLeft == NULL))
		{
			cout << t->data << " ";
		}
		Node_co_1_con(t->pLeft);
		Node_co_1_con(t->pRight);
	}
}

void Node_co_2_con(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
		{
			cout << t->data << " ";
		}
		Node_co_2_con(t->pLeft);
		Node_co_2_con(t->pRight);
	}
}

int Tinh_Chieu_Cao_Cay(TREE t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		int Cay_Con_Trai = Tinh_Chieu_Cao_Cay(t->pLeft);
		int Cay_Con_Phai = Tinh_Chieu_Cao_Cay(t->pRight);
		if (Cay_Con_Trai > Cay_Con_Phai)
		{
			return (Cay_Con_Trai + 1);
		}
		else
		{
			return (Cay_Con_Phai + 1);
		}
	}
}

void DiTimNodeThayThe(TREE& k, TREE& j)
{
	if (j->pLeft != NULL)
	{
		DiTimNodeThayThe(k, j->pLeft);
	}
	else
	{
		k->data = j->data;
		k = j;
		j = j->pRight;
	}
}

void XoaNode(TREE& t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (x < t->data)
		{
			XoaNode(t->pLeft, x);
		}
		else if (x > t->data)
		{
			XoaNode(t->pRight, x);
		}
		else
		{
			NODE* k = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else
			{
				DiTimNodeThayThe(k, t->pRight);
			}
			delete k;
		}
	}
}

void Menu(TREE t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======================== BINARY SEARCH TREE ========================";
		cout << "\n\t1. Nhap phan tu";
		cout << "\n\t2. Xuat phan tu";
		cout << "\n\t3. Xuat cac node la";
		cout << "\n\t4. Xuat cac node co 1 con";
		cout << "\n\t5. Xuat cac node co 2 con";
		cout << "\n\t6. Tinh chieu cao cay";
		cout << "\n\t7. Xoa node co data bat ky";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t =============================== END ===============================";

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
			cout << "\n\n\tNLR: ";
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\tCAC NODE LA: ";
			Node_La(t);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\tCAC NODE CO 1 CON: ";
			Node_co_1_con(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\n\tCAC NODE CO 2 CON: ";
			Node_co_2_con(t);
			system("pause");

		}
		else if (luachon == 6)
		{
			cout << "\n\n\tCHIEU CAO CAY LA: ";
			cout << Tinh_Chieu_Cao_Cay(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			int x;
			cout << "\nNhap data node can xoa: ";
			cin >> x;
			XoaNode(t, x);
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