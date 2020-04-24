#include<bits/stdc++.h>

#define C continue
#define F first
#define S second
#define pb push_back
#define Int long long

using namespace std;

Int arr[5000000];
set < pair < Int , Int > > ans;
Int x[20] ,y[20];

int main()
{
    for(Int i = 0; i < 3 ;i++)
        cin >> x[i] >> y[i];
    for(Int i = 0; i < 3 ;i++)
    {
        for(Int j = 0; j < 3 ;j++)
        {
            if(i == j)C;
            Int temp = 0;
            if(i != 1 && j != 1)temp = 1;
            if(i != 0 && j != 0)temp = 0;
            if(i != 2 && j != 2)temp = 2;
            Int diffrencey = y[i] - y[j];
            Int diffrencex = x[i] - x[j];
            Int y1 = y[temp] + diffrencey;
            Int x1 = x[temp] + diffrencex;
            ans.insert({x1 ,y1});
            x1 = x[temp] - diffrencex;
            y1 = y[temp] - diffrencey;
            ans.insert({x1 , y1});
        }
    }
    cout << ans.size() <<endl;
    for(auto it = ans.begin();it != ans.end(); it++)
    {
        cout << it -> F << " " << it -> S << endl;
    }
    return 0;
}