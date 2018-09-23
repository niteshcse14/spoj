#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
const int MAX = 1e6 + 5;
int arr[MAX];
vector< pair<int, int> > nums;
vector<int> seg[MAX];
void build(int t, int i, int j)
{
	if(i == j)
	{
		seg[t].pb(nums[i].second);
		return;
	}
	int left = t << 1;
	int right = left | 1;
	int mid = (i + j) / 2;
	build(left, i, mid);
	build(right, mid + 1, j);
	merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(), back_inserter(seg[t]));
}
int query(int t, int i, int j, int l, int r, int k)
{
	if(i == j)
	{
		return seg[t][0];
	}
	int left = t << 1;
	int right = left | 1;
	int mid = (i + j) / 2;
	int total = upper_bound(seg[left].begin(), seg[left].end(), r) - lower_bound(seg[left].begin(), seg[left].end(), l);
	if(total >= k)
	{
		return query(left, i, mid, l, r, k);
	}
	else
	{
		return query(right, mid + 1, j, l, r, k - total);
	}
}
int bst(int S,int E){
    int s=S,e=E;
    while(s<e){
        int len=m-s+1;
        int m=(s+e)/2;
        if(len<3)s=m,continue;
        int a=arr[query(1,0,n-1,S,m,1)];
        int b=arr[query(1,0,n-1,S,m,2)];
        int c=arr[query(1,0,n-1,S,m,len)];
        if(a+b>=c)s=m;
        else e=m;
    }
    return s;
}
int main(){
	int ans=0,n, m, x, y, k, idx, ans;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		nums.pb(make_pair(arr[i], i));
	}
	sort(nums.begin(), nums.end());
	build(1, 0, n - 1);
	/*
    while(m--){
		scanf("%d %d %d", &x, &y, &k);
		x--;
		y--;
		idx = query(1,0,n-1,x,y,2);
		printf("%d\n", arr[idx]);
	}
    */
    for(int i=0;i<n-2;++i){
        ans=bst(i,n-1);
        printf("%d %d\n",i,ans);
    }
	return 0;
}