#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll T, N, count, temp;
	scanf("%lld", &T);
	while(T--)
	{
		count = 0;
		scanf("%lld", &N);
		temp = N;
		while(N > 0)
		{
			if(N & 1)
			{
				count++;
			}
			N = N / 2;
		}
		count = pow(2, count);
		printf("%lld %lld\n", temp - count + 1, count);
	}
	return 0;
}