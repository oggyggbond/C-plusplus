#include <iostream>
#include <fstream>
#define MAX 100
int CBT[MAX][2], a[MAX][MAX], n, chuaxet[MAX], sc, QUEUE[MAX];

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
		for (int j = 1; j <= n; j++)
		{
			filein >> a[i][j];
			cout << a[i][j] << "\t";
		}
	}
	filein.close();
	for (int i = 1; i <= n; i++)
	{
		chuaxet[i] = true;
	}
}

void TREE_DFS(int i)
{
	chuaxet[i] = false;
	if (sc == n - 1)
	{
		return;
	}
	for (int j = 1; j <= n; j++)
	{
		if (chuaxet[j] && a[i][j])
		{
			sc++;
			CBT[sc][1] = i;
			CBT[sc][2] = j;
			if (sc == n - 1) return;
			TREE_DFS(j);
		}
	}
}

void Result()
{
	for (int i = 1; i <= sc; i++)
	{
		cout << "\nCanh " << i << ":" << " ";
		for (int j = 1; j <= 2; j++)
		{
			cout << CBT[i][j] << " ";
		}
	}
}

void TREE_BFS(int u)
{
	int dauQ, cuoiQ, v;
	dauQ = 1; cuoiQ = 1; QUEUE[dauQ] = u; chuaxet[u] = false;
	while (dauQ <= cuoiQ)
	{
		v = QUEUE[dauQ]; dauQ = dauQ + 1;
		for (int p = 1; p <= n; p++)
		{
			if (chuaxet[p] && a[v][p])
			{
				chuaxet[p] = false;
				sc++;
				CBT[sc][1] = v;
				CBT[sc][2] = p;
				cuoiQ = cuoiQ + 1;
				QUEUE[cuoiQ] = p;
				if (sc == n - 1) return;
			}
		}
	}
}
void ReSult()
{
	for (int i = 1; i <= sc; i++) {
		cout << "\nCanh " << i << ":" << " ";
		for (int j = 1; j <= 2; j++)
			cout << CBT[i][j] << " ";
	}
}

int main()
{
	Doc_file();
	sc = 0;
	int i = 1;
	TREE_DFS(i);
	if (sc < n - 1)
	{
		cout << "\nDo thi khong lien thong";
	}
	else
	{
		Result();
	}
	/*TREE_BFS(i);
	if (sc < n - 1)
	{
		cout << "\nDo thi khong lien thong";
	}
	else
	{
		ReSult();
	}*/

	return 0;
}

