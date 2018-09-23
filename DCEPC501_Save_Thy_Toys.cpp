#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, N;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &N);
		ll arr[N + 8], dp[N + 8];
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
		}
		memset(dp, 0, sizeof(dp));
		memset(arr + N, 0, sizeof(ll) * 7);
		for(int i = N - 1; i >= 0; i--)
		{
			dp[i] = arr[i] + dp[i + 2];
			if((i + 1) < N)
			{
				dp[i] = max(dp[i], arr[i] + arr[i + 1] + dp[i + 4]);
			}
			if((i + 2) < N)
			{
				dp[i] = max(dp[i], arr[i] + arr[i + 1] + arr[i + 2] + dp[i + 6]);
			}
			printf("%lld   ", dp[i]);
		}
		printf("\n");
		printf("%lld\n", dp[0]);
	}
	return 0;
} 