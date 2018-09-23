#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int BIT[MAX];
int ans[MAX];
vector< pair<int, int> > inp;
int N, Q, data, l, r, k;
struct quries
{
	int start;
	int end;
	int val;
	int idx;
};
bool cmp(quries q1, quries q2)
{
    return q1.val < q2.val;
}
void update(int ind, int val)
{
	while(ind <= N)
	{
		BIT[ind] += val;
		ind += ind & -ind;
	}
}
int query(int ind)
{
	int sum = 0;
	while(ind > 0)
	{
		sum += BIT[ind];
		ind -= ind & -ind;
	}
	return sum;
}
int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		inp.push_back(make_pair(data, i));
	}
	sort(inp.begin(), inp.end());
	scanf("%d", &Q);
	quries qre[Q];
	for(int i = 0; i < Q; i++)
	{
		scanf("%d %d %d", &l, &r, &k);
		qre[i].start = l - 1;
		qre[i].end = r - 1;
		qre[i].val = k;
		qre[i].idx = i;
	}
	sort(qre, qre + Q, cmp);
	int curr = 0;
	for(int i = 0; i < Q; i++)
	{
		while(curr < N && inp[curr].first <= qre[i].val)
		{
			update(inp[curr].second + 1, 1);
			curr++;
		}
		int len = qre[i].end - qre[i].start + 1;
		int A = query(qre[i].end + 1) - query(qre[i].start);
		ans[qre[i].idx] = len - A;
		//qre[i].end - qre[i].start + 1
	}
	for(int i = 0; i < Q; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}