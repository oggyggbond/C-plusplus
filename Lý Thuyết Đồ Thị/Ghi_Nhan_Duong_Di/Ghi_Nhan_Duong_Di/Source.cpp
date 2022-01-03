#include <iostream>
#include <fstream>
#include <queue>
#define MAX 100

using namespace std;

int a[MAX][MAX], n, chuaxet[MAX], truoc[MAX], s, t;

void Doc_File()
{
	ifstream filein;
	filein.open("dothi.txt", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai. Xin kiem tra lai";
		system("pause");
		return;
	}

	filein >> n;
	cout << "\nSo dinh do thi: " << n;
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
		chuaxet[i] = true;
		cout << endl;
		truoc[i] = 0;
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
			truoc[v] = u;
			cout << " ";
			DFS_De_Quy(v);
		}
	}
}

void BFS(int u)
{
	cout << "\nBFS(" << u << "): ";
	queue<int> Q;
	Q.push(u);
	chuaxet[u] = false;

	while (!Q.empty())
	{
		u = Q.front();
		cout << u << " ";
		Q.pop();
		for (int v = 1; v <= n; v++)
		{
			if (chuaxet[v] && a[u][v])
			{
				Q.push(v);
				truoc[v] = u;
				chuaxet[v] = false;
			}
		}
	}
}

void Duong_Di()
{
	if (truoc[t] == 0)
	{
		cout << "\nKhong ton tai duong di";
		system("pause");
		return;
	}
	cout << "\nDuong di: ";
	int j = t;
	cout << j << " ";
	while (truoc[j] != s)
	{
		cout << truoc[j] << " ";
		j = truoc[j];
	}
	cout << s;
}

int main()
{
	Doc_File();
	cout << "\nNhap dinh dau: ";
	cin >> s;
	cout << "\nNhap dinh cuoi: ";
	cin >> t;
	BFS(s);
	//cout << "\nDFS(" << s << "): ";
	//DFS_De_Quy(s);
	Duong_Di();

	return 0;
}