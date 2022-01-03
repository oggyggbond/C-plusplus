#include <iostream>
#include <fstream>
#define MAX 100
int a[MAX][MAX], n, chuaxet[MAX];

using namespace std;

void Doc_file()
{
	ifstream filein;
	filein.open("matrix.txt", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai. Xin kiem tra lai";
		system("pause");
	}
	filein >> n;
	cout << "\nSo dinh do thi: " << n;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << endl;
		chuaxet[i] = true;
		for (int j = 1; j <= n; j++)
		{
			filein >> a[i][j];
			cout << a[i][j] << "\t";
		}
	}
	filein.close();
}

void DFS_De_Quy(int u)
{
	cout << u;
	chuaxet[u] = false;
	for (int v = 1; v <= n; v++)
	{
		if (a[u][v] && chuaxet[v])
		{
			cout << " ";
			DFS_De_Quy(v);
		}
	}
}

void DFS_STACK(int u)
{
	int Stack[MAX], dau = 1, s;
	Stack[dau] = u;
	chuaxet[u] = false;
	cout << u;
	while (dau > 0)
	{
		s = Stack[dau];
		dau--;
		for (int t = 1; t <= n; t++)
		{
			if (chuaxet[t] && a[s][t])
			{
				cout << " ";
				cout << t;
				chuaxet[t] = false;
				Stack[++dau] = s;
				Stack[++dau] = t;
				break;
			}
		}
	}
}

int main()
{
	int u;
	Doc_file();
	cout << "\nDinh bat dau duyet: ";
	cin >> u;
	
	//DFS_De_Quy(u);
	DFS_STACK(u);

	return 0;
}