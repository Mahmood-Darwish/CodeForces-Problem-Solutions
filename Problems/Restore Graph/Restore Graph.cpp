#include <bits/stdc++.h>

using namespace std;

long long n , h , num , j = 1;
vector < pair < int , int > > sol;
pair < int , int > d[1000000];
int how_much[10000000];

int main()
{
    cin >> n >> h;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> num;
        d[i] = {num,i};
        how_much[i] = h;
    }
    sort(d+1,d+n+1);
    int temp2 = d[1].first;
    int temp3 = d[1].second;
    if(temp2 != 0)
    {
        cout << -1;
        return 0;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(d[i].first == temp2 + 1 && how_much[d[i].second] > 0 && how_much[temp3] > 0)
        {
            how_much[temp3]--;
            how_much[d[i].second]--;
            sol.push_back({d[i].second,temp3});
            continue;
        }
        if(d[i].first != temp2 + 1)
        {
            while(d[j].first == temp2)
            {
                j++;
            }
            if(d[j].first + 1 == d[i].first && how_much[d[i].second] > 0 && how_much[d[j].second] > 0)
            {
                temp2 = d[j].first;
                temp3 = d[j].second;
                how_much[temp3]--;
                how_much[d[i].second]--;
                sol.push_back({d[i].second,temp3});
                continue;
            }
        }
        if(how_much[temp3] == 0)
        {
            j++;
            if(d[j].first == temp2)
            {
                temp2 = d[j].first;
                temp3 = d[j].second;
                how_much[temp3]--;
                how_much[d[i].second]--;
                sol.push_back({d[i].second,temp3});
                continue;
            }
        }
        cout << -1;
        return 0;
    }
    cout << sol.size() << '\n';
    for(int i = 0 ; i < sol.size() ; i++)
        cout << sol[i].first << " " << sol[i].second << '\n';
    return 0;
}