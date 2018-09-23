#include <bits/stdc++.h>
using namespace std;
void Return_arr(string str, int arr[])
{
	int i = 1, j = 0, N = str.size();
	while(i < N)
	{
		if(str[i] == str[j])
		{
			arr[i] = j + 1;
			i++;
			j++;
		}
		else if((j - 1) >= 0)
		{
			j = arr[j - 1];
		}
		else
		{
			if(j == 0)
			{
				if(str[i] == str[j])
				{
					str[i] = 1;
					j++;
					i++;
				}
				else
				{
					i++;
				}
			}
		}
	}
}
int main()
{
	int T = 1, N, M;
	string str, match;
	//cin >> T;
	while(T--)
	{
		cin >> str >> match;
		N = str.size();
		M = match.size();
		int arr[M];
		for(int i = 0; i < M; i++)
		{
			arr[i] = 0;
		}
		Return_arr(match, arr);
		/*
		for(int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		printf("\n");
		*/
		int j = 0, sum = 0;
		for(int i = 0; i < N; )
		{
			if(str[i] == match[j])
			{
				i++;
				j++;
			}
			else if((j - 1) >= 0)
			{
				j = arr[j - 1];
			}
			else
			{
				if(str[i] == match[0])
				{
					i++;
					j++;
				}
				else
				{
					i++;
				}
			}
			if(j >= M)
			{
				break;
			}
		}
		if(j >= M)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}