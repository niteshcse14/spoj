#include <bits/stdc++.h>
using namespace std;
long long const MAX = 1e9 + 7;
#define ll long long
ll dp[MAX][MAX];
int main()
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0 || i == j)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	ll T, N, M, R;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld %lld", &N, &R, &M);
		printf("%lld\n", dp[N][R] % M);
	}
	return 0;
}