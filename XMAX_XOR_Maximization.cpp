#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll arr[maxn];
ll n, t;
int main(){
	//scanf("%lld", &t);
	t = 1;
	while(t--){
		scanf("%lld", &n);
		for(int i = 0; i < n; ++i){
			scanf("%lld", &arr[i]);
		}
		ll idx = 0;
		for(ll bits = 63; bits >= 0; --bits){
			ll maxEle = INT_MIN;
			ll maxInd = idx;
			for(ll i = idx; i < n; ++i){
				if((arr[i] & (1 << bits)) != 0 && (maxEle < arr[i])){
					maxEle = arr[i];
					maxInd = i;
				}
			}
			if(maxEle == INT_MIN){
				continue;
			}
			swap(arr[idx], arr[maxInd]);
			maxInd = idx;
			for(ll i = 0; i < n; ++i){
				if((i != maxInd) && (arr[i] & (1 << bits)) != 0){
					arr[i] ^= arr[maxInd];
				}
			}
			idx++;
		}
		ll res = 0;
		for(ll i = 0; i < n; ++i){
			res ^= arr[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}
