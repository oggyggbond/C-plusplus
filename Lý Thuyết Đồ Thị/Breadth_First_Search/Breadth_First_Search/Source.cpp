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

int main()
{
	int u;

	Doc_File();

	cout << "\nDinh bat dau duyet: ";
	cin >> u;

	BFS(u);

	return 0;
}