#include<iostream>
using namespace std;
#include<string>

// khai báo c?u trúc 1 cái node
struct NODE
{
	string data;
	NODE* pNext;
};

// ================================================== C?U TRÚC STACK ======================================================

// khai báo c?u trúc STACK
struct STACK
{
	NODE* pTop;
};

// hàm kh?i t?o node
NODE* KhoiTaoNode(string x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

// hàm ki?m tra xem stack có r?ng không
bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return true; // stack r?ng
	}
	return false; // stack ?ang có ph?n t?
}
// hàm thêm node p vào ??u danh sách 
bool Push(STACK& s, NODE* p)
{
	// stack r?ng
	if (IsEmpty(s) == true)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}

// hàm l?y ph?n t? ra kh?i stack <=> l?y ph?n t? ??u stack ra và xóa nó ?i
bool Pop(STACK& s, string& x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE* k = s.pTop;
		x = s.pTop->data; // gi? l?i d? li?u bên trong ph?n t? ??u stack 
		s.pTop = s.pTop->pNext;
		delete k;
	}
	return true;
}

// hàm l?y ph?n t? ??u stack ra ?? xem
bool Top(STACK s, string& x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

// hàm gi?i phòng vùng nh?
void Giai_Phong_STACK(STACK& s)
{
	NODE* k = s.pTop;
	while (s.pTop != NULL)
	{
		s.pTop = s.pTop->pNext;
		delete k;
		k = s.pTop;
	}
}

// ========================================= C?U TRÚC QUEUE =======================================================
// khai báo c?u trúc QUEUE
struct QUEUE
{
	NODE* pTop;
};

// hàm ki?m tra xem QUEUE có r?ng không
bool IsEmpty(QUEUE q)
{
	if (q.pTop == NULL)
	{
		return true; // QUEUE r?ng
	}
	return false; // QUEUE ?ang có ph?n t?
}
// hàm thêm node p vào cu?i danh sách 
bool Push(QUEUE& q, NODE* p)
{
	// QUEUE r?ng
	if (IsEmpty(q) == true)
	{
		q.pTop = p;
	}
	else
	{
		for (NODE* k = q.pTop; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
	return true;
}

// hàm l?y ph?n t? ra kh?i QUEUE <=> l?y ph?n t? ??u QUEUE ra và xóa nó ?i
bool Pop(QUEUE& q, string& x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE* k = q.pTop;
		x = q.pTop->data; // gi? l?i d? li?u bên trong ph?n t? ??u stQUEUEack 
		q.pTop = q.pTop->pNext;
		delete k;
	}
	return true;
}

// hàm l?y ph?n t? ??u QUEUE ra ?? xem
bool Top(QUEUE q, string& x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pTop->data;
	return true;
}

// hàm gi?i phòng vùng nh?
void Giai_Phong_QUEUE(QUEUE& q)
{
	NODE* k = q.pTop;
	while (q.pTop != NULL)
	{
		q.pTop = q.pTop->pNext;
		delete k;
		k = q.pTop;
	}
}

// hàm x? lý chuy?n bi?u th?c trung t? sang h?u t?
void TrungTo_HauTo(STACK& s, QUEUE& q, string trungto)
{
	// duy?t qua t?ng ph?n t? trong bi?u th?c trungto
	for (int i = 0; i < trungto.length(); i++)
	{

		// n?u ph?n t? ?ang xét là toán h?ng...
		if (trungto[i] >= '0' && trungto[i] <= '9')
		{
			// ...push vào trong QUEUE
			string str;
			str.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
			NODE* x = KhoiTaoNode(str);
			Push(q, x); // thêm node x vào queue
		}
		else if (trungto[i] == '(') // n?u ph?n t? ?ang xét là d?u m? ngo?c (...
		{
			// ...push vào trong STACK
			string str;
			str.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
			NODE* x = KhoiTaoNode(str);
			Push(s, x); // thêm node x vào stack
		}
		else if (trungto[i] == ')') // n?u ph?n t? ?ang xét là d?u ?óng ngo?c )...
		{
			// duy?t qua t?ng ph?n trong stack
			while (IsEmpty(s) == false)
			{
				string str;
				Pop(s, str);
				if (str[0] == '(')
				{
					// ...g?p ký t? m? ngo?c thì d?ng
					break;
				}
				else
				{
					// ...push vào trong QUEUE
					NODE* x = KhoiTaoNode(str);
					Push(q, x); // thêm node x vào QUEUE
				}
			}
		}
		else if (trungto[i] == '+' || trungto[i] == '-' || trungto[i] == '*' || trungto[i] == '/')
		{
			//... n?u stack r?ng
			if (IsEmpty(s) == true)
			{
				// ...push vào trong STACK
				string str;
				str.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
				NODE* x = KhoiTaoNode(str);
				Push(s, x); // thêm node x vào stack
			}
			else //...stack không r?ng <=> có ph?n t?
			{
				string str;
				Top(s, str); // l?y ph?n t? ??u STACK ra ki?m tra
				//...ph?n t? ??u STACK là toán t? thì...
				if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
				{
					// ...ph?n t? ??u stack là + và -
					if (str[0] == '+' || str[0] == '-')
					{
						// ..ph?n t? ?ang xét là * và /
						if (trungto[i] == '*' || trungto[i] == '/')
						{
							// ===> ?? ?u tiên c?a ph?n t? ??u STACK(str[0]) < ph?n t? ?ang xét X(trungto[i])
							// ...push vào trong STACK
							string str_1;
							str_1.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
							NODE* x = KhoiTaoNode(str_1);
							Push(s, x); // thêm node x vào stack
						}
						else
						{
							if (trungto[i] == '+' || trungto[i] == '-')
							{
								while (IsEmpty(s) == false)
								{
									// ...n?u ph?n t? ??u STACK(str[0]) = X(trungto[i]) 
									
									// ===> ?? ?u tiên c?a ph?n t? ??u STACK(str[0]) >= ph?n t? ?ang xét X(trungto[i])
											// ...l?y ph?n t? ??u STACK push vào trong QUEUE
									string str_1;
									str_1.push_back(str[0]); // ??y ký t? vào cu?i chu?i str
									NODE* x = KhoiTaoNode(str_1);
									Push(q, x); // thêm node x vào QUEUE

									Pop(s, str); // l?y ph?n t? ??u STACK ra ki?m tra
									// ..ph?n t? ??u STACK không ph?i là toán t? thì d?ng
									if (str[0] != '+' || str[0] != '-' || str[0] != '*' || str[0] != '/')
									{
										break; // d?ng l?i không l?y n?a
									}
								}

								// ...push X vào trong STACK
								string str_1;
								str_1.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
								NODE* x = KhoiTaoNode(str_1);
								Push(s, x); // thêm node x vào stack
							}
						}
					}
					else // ...ph?n t? ??u stack là * và / >= X
					{
						// ..stack r?ng thì d?ng		
						while (IsEmpty(s) == false)
						{
							// ...n?u ph?n t? ??u STACK(str[0]) >= X(trungto[i]) 
							if (str[0] == '*' || str[0] == '/')
							{
								// ===> ?? ?u tiên c?a ph?n t? ??u STACK(str[0]) >= ph?n t? ?ang xét X(trungto[i])
									// ...l?y ph?n t? ??u STACK push vào trong QUEUE
								string str_1;
								str_1.push_back(str[0]); // ??y ký t? vào cu?i chu?i str
								NODE* x = KhoiTaoNode(str_1);
								Push(q, x); // thêm node x vào QUEUE

								Pop(s, str); // l?y ph?n t? ??u STACK ra ki?m tra
								// ..ph?n t? ??u STACK không ph?i là toán t? thì d?ng
								if (str[0] != '+' || str[0] != '-' || str[0] != '*' || str[0] != '/')
								{
									break; // d?ng l?i không l?y n?a
								}
							}
						}

						// ...push X vào trong STACK
						string str_1;
						str_1.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
						NODE* x = KhoiTaoNode(str_1);
						Push(s, x); // thêm node x vào stack
					}
				}
				else //...ph?n t? ??u STACK không ph?i là toán t? thì
				{
					// ...push vào trong STACK
					string str_1;
					str_1.push_back(trungto[i]); // ??y ký t? vào cu?i chu?i str
					NODE* x = KhoiTaoNode(str_1);
					Push(s, x); // thêm node x vào stack
				}
			}
		}
	}

	// ...trong stack còn ph?n t? nào thì push h?t sang QUEUE
	while (IsEmpty(s) == false)
	{
		string str;
		Pop(s, str);
		NODE* x = KhoiTaoNode(str);
		Push(q, x); // thêm node x vào QUEUE
	}
}

// xu?t bi?u th?c trung t?
void Xuat_BIEU_THUC_TRUNG_TO(QUEUE& q)
{
	while (IsEmpty(q) == false)
	{
		string str;
		Pop(q, str);
		cout << str;
	}
}

int main()
{
	STACK s;
	s.pTop = NULL; // kh?i t?o stack r?ng
	QUEUE q;
	q.pTop = NULL;

	string trungto = "8/2+5-((8-4)*2)+8/2";
	// 8 2 / 5 + 8 4 - 2 * - 8 2 / +
	TrungTo_HauTo(s, q, trungto);
	cout << "\n\n\t\t BIEU THUC TRUNG TO NHAN DUOC LA: ";
	Xuat_BIEU_THUC_TRUNG_TO(q);

	Giai_Phong_STACK(s); // gi?i phóng stack
	Giai_Phong_QUEUE(q); // gi?i phóng queue
	system("pause");
	return 0;
}