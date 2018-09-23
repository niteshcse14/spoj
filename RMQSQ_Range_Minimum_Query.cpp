#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int arr[MAXN];
int sparse[MAXN][20];
int N;
void sparse_table()
{
	for(int i = 0; i < N; i++)
	{
		sparse[i][0] = i;
	}
	for(int j = 1; (1 << j) <= N; j++)
	{
		for(int i = 0; (i + (1 << j) - 1) < N; i++)
		{
			if(arr[sparse[i][j - 1]] < arr[sparse[i + (1 << (j - 1))][j - 1]])
			{
				sparse[i][j] = sparse[i][j - 1];
			}
			else
			{
				sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}
int RMQ(int L, int R)
{
	int j = (int)floor(log2(R - L + 1));
	if(arr[sparse[L][j]] <= arr[sparse[R - (1 << j) + 1][j]])
	{
		return arr[sparse[L][j]];
	}
	return arr[sparse[R - (1 << j) + 1][j]];
}
int main()
{
	//printf("%intd\n", (int)(log2(MAXN)));
	int Q, L, R;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sparse_table();
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d %d", &L, &R);
		printf("%d\n", RMQ(L, R));
	}
	return 0;
}