#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
#define mod 100000007
int arr_A[1025];
int arr_B[1025];
int arr_B_index[1025];
int dp[1025][1025];
int main()
{
	int T, N, M;
	scanf("%d", &T);
	for(int test = 1; test <= T; test++)
	{
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr_A[i]);
		}
		memset(arr_B_index, 0, sizeof(arr_B_index));
		for(int i = 0; i < M; i++)
		{
			scanf("%d", &arr_B[i]);
			arr_B_index[arr_B[i]] = 1;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j < 1024; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ arr_A[i - 1]];
				dp[i][j] %= mod;
			}
		}
		int ans = 0;
		for(int i = 0; i < 1024; i++)
		{
			if(!arr_B_index[i])
			{
				ans += dp[N][i];
				ans %= mod;
			}
		}
		printf("Case %d: %d\n",test, ans);
	}
	return 0;
}