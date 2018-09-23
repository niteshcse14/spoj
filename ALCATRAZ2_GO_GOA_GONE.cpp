#include <bits/stdc++.h>
using namespace std;
int M, a, b;
int answer;
int arr[10], bit_mask[10][10];
int main()
{
    for(int i = 0; i < 8; i ++)
    {
        cin >> arr[i];
    }
    cin >> M;
    for(int i = 0; i < M; i ++)
    {
        cin >> a >> b;
        bit_mask[a - 1][b - 1] = bit_mask[b - 1][a - 1] = 1;
    }
    
    for(int i = 1; i < (1 << 8); i ++)
    {
        int good = 1;
        for(int j = 0; j < 8; j ++)
        {
            if(i & (1 << j))
            {
                for(int k = 0; k < 8; k ++)
                {
                    if(i & (1 << k))
                    {
                        if(go[j][k])
                        {
                            good = 0;
                        }
                    }
                }
            }
        }
        if(good){
            int s = 0;
            for(int j = 0; j < 8; j ++)
                if(i & (1 << j))
                    s += arr[j];
            answer = max(answer, s);
        }
    }
    
    cout << answer << endl;
    
    return 0;
}