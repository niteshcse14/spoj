#include <bits/stdc++.h>
using namespace std;
void findLongestPalindromicString(string str, int N)
{
	if(N == 0)
	{
		return;
	}
	N = 2 * N + 1;
	int L[N];
	L[0] = 0;
	L[1] = 1;
	int C = 1;
	int R = 2;
	int i = 0;
	int iMirror;
	int expand;
	int diff;
	int maxLPSLength = 0;
	int maxLPSCenterPosition = 0;
	int start = -1;
	int end = -1;
	for(i = 2; i < N; i++)
	{
		iMirror =  2 * C - i;
		diff = R - i;
		expand = 0;
		if(diff > 0)
		{
			if(L[iMirror] < diff)
			{
				L[i] = L[iMirror];
			}
			else if(L[iMirror] == diff && i == N - 1)
			{
				L[i] = L[iMirror];
			}
			else if(L[iMirror] == diff && i < N - 1)
			{
				L[i] = L[iMirror];
				expand = 1;
			}
			else if(L[iMirror] > diff)
			{
				L[i] = diff;
				expand = 1;
			}
		}
		else
		{
			expand = 1;
			L[i] = 0;
		}
		if(expand == 1)
		{
			while(((i + L[i]) < N && (i - L[i]) > 0) && (((i + L[i] + 1) % 2 == 0) || (str[(i + L[i] + 1) / 2] == str[(i - L[i] - 1) / 2])))
			{
				L[i]++;
			}
		}
		if(L[i] > maxLPSLength)
		{
			maxLPSLength = L[i];
			maxLPSCenterPosition = i;
		}
		if((i + L[i]) > R)
		{
			C = i;
			R = i + L[i];
		}
	}
	cout << maxLPSLength << "\n";
}
int main()
{
	int N;
	string str;
	cin >> N >> str;
	findLongestPalindromicString(str, N);
	return 0;
}