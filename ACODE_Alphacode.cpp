#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int arr[50005];
int main()
{
	char ch[50005];
	ll N;
	while(1)
	{
		ll count = 0, zero = 0;
		scanf("%s", ch);
		ll N = strlen(ch);
		if(N == 1 && ch[0] == '0')
		{
			break;
		}
		for(int i = 0; i < N; i++)
		{
			arr[i] = (int)ch[i] - 48;
		}
		ll dp[N + 2];
		memset(dp, 0, sizeof(dp));
		dp[N] = dp[N + 1] = 1;
		if(arr[N - 1] == 0)
		{
			dp[N - 1] = 0;
		}
		else
		{
			dp[N - 1] = 1;
		}
		for(int i = N - 2; i >= 0; i--)
		{
			if(arr[i] != 0)
			{
				dp[i] += dp[i + 1];
				if((arr[i] == 2 && arr[i + 1] <= 6) || arr[i] < 2)
				{
					dp[i] += dp[i + 2];
				}
			}
		}
		printf("%lld\n", dp[0]);
	}
	return 0;
}