#include <iostream>

using namespace std;

struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;

void ThemNode(TREE&, int);
void LRN(TREE);
void RLN(TREE);
void LNR(TREE);
void RNL(TREE);
void NLR(TREE);
void NRL(TREE);
void Node_La(TREE);
void Node_Co_1_con(TREE);
void Node_Co_2_con(TREE);
bool TimNode(TREE, int);
int TimChieuCao(TREE);
int DemNode(TREE);
void Kiem_Tra_Can_Bang(TREE, bool);
void DiTimNodeTheMang(TREE&, TREE&);
void XoaNode(TREE&, int);
void Xoa_Toan_Bo_Cay(TREE&);
void LeftRotate(TREE&);
void RightRotate(TREE&);
void Left_RightRotate(TREE&);
void Right_LeftRotate(TREE&);
void AVL(TREE&, bool&);
void CB(TREE&);
void Menu(TREE);

int main()
{
	TREE t = NULL;
	Menu(t);

	return 0;
}

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
		else
		{
			cout << "\n\tDa ton tai gia tri " << x << " trong cay!";
			system("pause");
			return;
		}
	}
}

void LRN(TREE t)
{
	if (t != NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << t->data << " ";
	}
	else
		return;
}

void RLN(TREE t)
{
	if (t != NULL)
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->data << " ";
	}
}

void LNR(TREE t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->data << " ";
		LNR(t->pRight);
	}
}

void RNL(TREE t)
{
	if (t != NULL)
	{
		RNL(t->pRight);
		cout << t->data << "  ";
		RNL(t->pLeft);
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

void NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

void Node_La(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft == NULL) && (t->pRight == NULL))
		{
			cout << t->data << " ";
		}
		Node_La(t->pLeft);
		Node_La(t->pRight);
	}
}

void Node_Co_1_con(TREE t)
{
	if (t != NULL)
	{
		if (((t->pLeft == NULL) && (t->pRight != NULL)) || ((t->pLeft != NULL) && (t->pRight == NULL)))
		{
			cout << t->data << " ";
		}
		Node_Co_1_con(t->pLeft);
		Node_Co_1_con(t->pRight);
	}
}

void Node_Co_2_con(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft != NULL) && (t->pRight != NULL))
		{
			cout << t->data << " ";
		}
		Node_Co_2_con(t->pLeft);
		Node_Co_2_con(t->pRight);
	}
}

bool TimNode(TREE t, int x)
{
	if (t == NULL)
	{
		return false;
	}

	if (t->data == x)
	{
		return true;
	}
	else if (t->data > x)
	{
		return TimNode(t->pLeft, x);
	}
	else if (t->data < x)
	{
		return TimNode(t->pRight, x);
	}
}

int TimChieuCao(TREE t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		int hLeft = TimChieuCao(t->pLeft);
		int hRight = TimChieuCao(t->pRight);
		if (hLeft > hRight)
		{
			return hLeft + 1;
		}
		else
		{
			return hRight + 1;
		}
	}
}

int DemNode(TREE t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + DemNode(t->pLeft) + DemNode(t->pRight);
	}
}

void Kiem_Tra_Can_Bang(TREE t, bool check)
{
	if (t != NULL)
	{
		while (!((TimChieuCao(t->pLeft) == TimChieuCao(t->pRight)) || ((TimChieuCao(t->pLeft) - TimChieuCao(t->pRight) == 1) || (TimChieuCao(t->pRight) - TimChieuCao(t->pLeft) == 1))))
		{
			if ((TimChieuCao(t->pLeft) > TimChieuCao(t->pRight)) && (TimChieuCao(t->pLeft) - TimChieuCao(t->pRight)) > 1)
			{
				if (TimChieuCao(t->pLeft->pLeft) >= TimChieuCao(t->pLeft->pRight))
				{
					cout << "\nCay bi lech trai trai.";
					break;
				}
				else
				{
					if (TimChieuCao(t->pLeft->pLeft) < TimChieuCao(t->pLeft->pRight))
					{
						cout << "\nCay bi lech trai phai.";
						break;
					}
				}
				check = true;
			}
			else
			{
				if ((TimChieuCao(t->pLeft) < TimChieuCao(t->pRight)) && (TimChieuCao(t->pRight) - TimChieuCao(t->pLeft)) > 1)
				{
					if (TimChieuCao(t->pRight->pLeft) <= TimChieuCao(t->pRight->pRight))
					{
						cout << "\nCay bi lech phai phai.";
						break;
					}
					else
					{
						if (TimChieuCao(t->pRight->pLeft) > TimChieuCao(t->pRight->pRight))
						{
							cout << "\nCay bi lech phai trai.";
							break;
						}
					}
					check = true;
				}
			}
		}

		if (check == false)
		{
			Kiem_Tra_Can_Bang(t->pLeft, check);
			Kiem_Tra_Can_Bang(t->pRight, check);
		}
	}
}

void DiTimNodeTheMang(TREE& k, TREE& j)
{
	if (j->pLeft != NULL)
	{
		DiTimNodeTheMang(k, j->pLeft);
	}
	else
	{
		k->data = j->data;
		k = j;
		j = j->pRight;
	}

	/*if (j->pRight != NULL)
	{
		DiTimNodeTheMang(k, j->pRight);
	}
	else
	{
		k->data = j->data;
		k = j;
		j = j->pLeft;
	}*/
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
				DiTimNodeTheMang(k, t->pRight);
				//DiTimNodeTheMang(k, t->pLeft);
			}
			delete k;
		}
	}
}

void Xoa_Toan_Bo_Cay(TREE& t)
{
	if (t == NULL)
	{
		return;
	}
	Xoa_Toan_Bo_Cay(t->pLeft);
	Xoa_Toan_Bo_Cay(t->pRight);
	delete t;
}

void LeftRotate(TREE& t)
{
	NODE* temp = new NODE;
	temp = t;
	t = t->pRight;
	temp->pRight = t->pLeft;
	t->pLeft = temp;
}

void RightRotate(TREE& t)
{
	NODE* temp = new NODE;
	temp = t;
	t = t->pLeft;
	temp->pLeft = t->pRight;
	t->pRight = temp;
}

void Left_RightRotate(TREE& t)
{
	//Buoc 1:

	NODE* temp = new NODE;
	temp = t->pLeft;
	NODE* temp2 = new NODE;
	temp2 = t;
	t->pLeft = temp->pRight;
	temp->pRight = t->pLeft->pLeft;
	t->pLeft->pLeft = temp;

	//Buoc 2:

	t = t->pLeft;
	temp2->pLeft = t->pRight;
	t->pRight = temp2;
}

void Right_LeftRotate(TREE& t)
{
	//Buoc 1:

	NODE* temp = new NODE;
	temp = t->pRight;
	NODE* temp2 = new NODE;
	temp2 = t;
	t->pRight = temp->pLeft;
	temp->pLeft = t->pRight->pRight;
	t->pRight->pRight = temp;

	//Buoc 2:

	t = t->pRight;
	temp2->pRight = t->pLeft;
	t->pLeft = temp2;
}

void AVL(TREE& t, bool& check)
{
	if (t != NULL)
	{
		while (!((TimChieuCao(t->pLeft) == TimChieuCao(t->pRight)) || ((TimChieuCao(t->pLeft) - TimChieuCao(t->pRight) == 1) || (TimChieuCao(t->pRight) - TimChieuCao(t->pLeft) == 1))))
		{
			if ((TimChieuCao(t->pLeft) > TimChieuCao(t->pRight)) && (TimChieuCao(t->pLeft) - TimChieuCao(t->pRight)) > 1)
			{
				if (TimChieuCao(t->pLeft->pLeft) >= TimChieuCao(t->pLeft->pRight))
				{
					RightRotate(t);
				}
				else
				{
					if (TimChieuCao(t->pLeft->pLeft) < TimChieuCao(t->pLeft->pRight))
					{
						Left_RightRotate(t);
					}
				}
				check = true;
			}
			else
			{
				if ((TimChieuCao(t->pLeft) < TimChieuCao(t->pRight)) && (TimChieuCao(t->pRight) - TimChieuCao(t->pLeft)) > 1)
				{
					if (TimChieuCao(t->pRight->pLeft) <= TimChieuCao(t->pRight->pRight))
					{
						LeftRotate(t);
					}
					else
					{
						if (TimChieuCao(t->pRight->pLeft) > TimChieuCao(t->pRight->pRight))
						{
							Right_LeftRotate(t);
						}
					}
					check = true;
				}
			}
		}

		if (check == false)
		{
			AVL(t->pLeft, check);
			AVL(t->pRight, check);
		}
	}
}

void CB(TREE& t)
{
	bool check = false;
	AVL(t, check);
	if (check == true)
	{
		AVL(t, check);
		CB(t);
	}
}

void Menu(TREE t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ===================== AVL ========================";
		cout << "\n\t1. Them phan tu";
		cout << "\n\t2. Xuat phan tu";
		cout << "\n\t3. Tinh chieu cao cay";
		cout << "\n\t4. Tim node co data bat ky";
		cout << "\n\t5. Dem so node trong cay";
		cout << "\n\t6. KTCB";
		cout << "\n\t7. Xoa toan bo data trong cay";
		cout << "\n\t8. Xoa node co data bat ky trong cay";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ===================== END ========================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;

			cout << "\nNhap phan tu: ";
			cin >> x;

			ThemNode(t, x);
		}
		else if (luachon == 2)
		{
			bool check = false;
			cout << "\nChieu cao cay la: " << TimChieuCao(t);
			cout << "\nNLR: ";
			NLR(t);

			AVL(t, check);
			CB(t);
			cout << "\nChieu cao cay la: " << TimChieuCao(t);
			cout << "\nNLR: ";
			NLR(t);

			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\nChieu cao cay la: " << TimChieuCao(t);

			system("pause");
		}
		else if (luachon == 4)
		{
			int x;

			cout << "\nNhap phan tu can tim: ";
			cin >> x;

			if (TimNode(t, x) == false)
			{
				cout << "\nKhong tim thay " << x;
			}
			else
			{
				cout << x;
			}
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\nCo " << DemNode(t) << " node trong cay ";

			system("pause");
		}
		else if (luachon == 6)
		{
			bool check = false;
			if (t == NULL)
			{
				cout << "\nCay dang rong.";
			}
			Kiem_Tra_Can_Bang(t, check);

			system("pause");
		}
		else if (luachon == 7)
		{
			while (true)
			{
				system("cls");

				cout << "\n\t1. Yes";
				cout << "\n\t2. No";

				int chon;

				cout << "\nBan chac chan muon xoa toan bo cay?";
				cin >> chon;

				if (chon == 1)
				{
					Xoa_Toan_Bo_Cay(t);
					t = NULL;
					cout << "\nBan da xoa thanh cong.";
					break;
				}
				else
				{
					break;
				}
			}

			system("pause");
		}
		else if (luachon == 8)
		{
			int x;
			do
			{
				cout << "\nNhap node co data can xoa: ";
				cin >> x;

				if (t == NULL)
				{
					cout << "\nCay dang rong.";
					return;
				}
				if (TimNode(t, x) == false)
				{
					cout << "\nKhong co node " << x << " trong cay. Nhap lai!";
				}
			} while (TimNode(t, x) == false);

			while (true)
			{
				system("cls");

				cout << "\n\t1. Yes";
				cout << "\n\t2. No";

				int chon;

				cout << "\nBan chac chan muon xoa?";
				cin >> chon;

				if (chon == 1)
				{
					XoaNode(t, x);
					cout << "\nBan da xoa thanh cong.";
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