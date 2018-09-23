#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, K;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &K);
		int arr[K], va;
		int dp[K + 1];
		N = K;
		for(int i = 1; i <= K; i++)
		{
			scanf("%d",&arr[i]);
			dp[i] = arr[i];
		}
		for(int i = 2; i <= K; i++)
		{
			for(int j = 1; j < i; j++)
			{
				if(arr[i - j] == -1  || dp[j] == -1)
				{
					continue;
				}
				if(dp[i] == -1)
				{
					dp[i] = dp[j] + arr[i - j];
				}
				else
				{
					dp[i] = min(dp[i], dp[j] + arr[i - j]);
				}
			}
		}
		printf("%d\n", dp[K]);
	}
	return 0;
}