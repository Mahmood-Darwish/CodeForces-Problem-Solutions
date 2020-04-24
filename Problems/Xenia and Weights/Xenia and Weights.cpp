#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

int ans;
int arr_ans[10000];
int dp[100][5][1007][11];
vector < int > myv;
char c;
int m;

short DP(short bal , short prev , short how_much , vector < short > vec , bool who_prev)
{
    if(dp[bal][who_prev][how_much][prev] != -1)return dp[bal][who_prev][how_much][prev];
    if(how_much == m)
    {
        ans = vec.size();
        for(int i = 0 ;  i < vec.size() ; i++)
            arr_ans[i] = vec[i];
        return dp[bal][who_prev][how_much][prev] = ans;
    }
    if(who_prev)
    {
        for(int i = 0 ; i < myv.size() ; i++)
        {
            if(prev != myv[i] && bal + myv[i] > 50)
            {
                vec.push_back(myv[i]);
                dp[bal][1][how_much][prev] = DP(bal + myv[i], myv[i] , how_much + 1 , vec , 0);
                vec.pop_back();
            }
        }
    }
    else
    {
        for(int i = 0 ; i < myv.size() ; i++)
        {
            if(prev != myv[i] && bal - myv[i] < 50)
            {
                vec.push_back(myv[i]);
                dp[bal][0][how_much][prev] = DP(bal - myv[i] , myv[i] , how_much + 1 , vec , 1);
                vec.pop_back();
            }
        }
    }
    return dp[bal][who_prev][how_much][prev] = max(0 , dp[bal][who_prev][how_much][prev]);
}


int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < 10 ; i++)
    {
        cin >> c;
        if(c == '1')
            myv.push_back(i+1);
    }
    cin >> m;
    vector < short > vec;
    DP(50 , - 1 , 0 , vec , 1);
    if(ans)
        cout << "YES\n";
    else cout << "NO\n";
    for(int i = 0 ; i < ans ; i++)
        printf("%d " , arr_ans[i]);
    return 0;
}