#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAXN = 1e6;
ll arr[MAXN];
ll ans[MAXN];
ll N, T, U, sum = 0, Q, val;
int l, r, ind;
int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld", &N, &U);
		for(int i = 0; i < N; i++)
		{
			//arr[i] = 0;
			ans[i] = 0;
		}
		while(U--)
		{
			scanf("%d %d %lld", &l, &r, &val);
			ans[l] += val;
			if((r + 1) < N)
			{
				ans[r + 1] -= val;
			}
		}
		for(int i = 1; i < N; i++)
		{
			ans[i] += ans[i - 1];
		}
		scanf("%lld", &Q);
		while(Q--)
		{
			scanf("%d", &ind);
			printf("%lld\n", ans[ind]);
		}
	}
	return 0;
}