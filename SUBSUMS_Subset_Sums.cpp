#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll X[2000005], Y[2000005], A, B;
void call_sub_array(ll arr[], ll X[], int N, int c)
{
	for(int i = 0; i < (1 << N); i++)
	{
		ll sum = 0;
		for(int j = 0; j < N; j++)
		{
			if(i & (1 << j))
			{
				sum += arr[j + c];
			}
		}
		X[i] = sum;
	}
}
ll solve_subset_sum(ll arr[], ll N, ll sum)
{
	call_sub_array(arr, X, N / 2, 0);
	call_sub_array(arr, Y, N - N / 2, N / 2);
	int size_X = 1 << (N / 2);
	int size_Y = 1 << (N - N / 2);
	sort(X, X + size_X);
	ll max = 0;
	for(int i = 0; i < size_Y; i++)
	{
		ll low = lower_bound(X, X + size_X, A - Y[i]) - X;
		ll high = upper_bound(X, X + size_X, B - Y[i]) - X;
		//printf("%lld  %lld\n", low, high);
		max += high - low;
	}
	return max;
}
int main()
{
	ll T, N, sum;
	T = 1;
	//scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld %lld", &N, &A, &B);
		ll arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
		}
		printf("%lld\n", solve_subset_sum(arr, N, sum));
	}
}