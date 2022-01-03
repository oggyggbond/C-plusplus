#include <iostream>
#include <fstream>
#include <queue>
#define MAX 100

using namespace std;

int a[MAX][MAX], n, chuaxet[MAX];

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
		cout << endl;
		for (int j = 1; j <= n; j++)
		{
			filein >> a[i][j];
			cout << a[i][j] << "\t";
		}
	}
	cout << "\n\n";

	filein.close();
}

void DFS_De_Quy(int u)
{
	//cout << u;
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
				chuaxet[v] = false;
			}
		}
	}
}

void ReInit()
{
	for (int i = 1; i <= n; i++)
	{
		chuaxet[i] = true;
	}
}

int Test_So_Lien_Thong()
{
	for (int u = 1; u <= n; u++)
	{
		if (chuaxet[u])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	Doc_File();
	ReInit();

	for (int u = 1; u < n; u++)
	{
		for (int v = u + 1; v <= n; v++)
		{
			if (a[u][v])
			{
				a[u][v] = 0;
				a[v][u] = 0;
				DFS_De_Quy(1);
				//BFS(1);
				if (Test_So_Lien_Thong())
				{
					cout << "\nCanh " << u << " , " << v << " la canh cau";
				}
				a[u][v] = 1;
				a[v][u] = 1;
				ReInit();
			}
		}
	}

	return 0;
}