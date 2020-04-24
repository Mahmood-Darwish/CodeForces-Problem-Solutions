#include <bits/stdc++.h>

using namespace std;

int n, S, R;
string s;

int main()
{
    cin >> n;
    cin >> s;
    while(true)
    {
        S = R = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == 'R')
            {
                if(S)
                {
                    S--;
                    s[i] = 'X';
                }
                else R++;
            }
            if(s[i] == 'D')
            {
                if(R)
                {
                    R--;
                    s[i] = 'X';
                }
                else S++;
            }
        }
        if(R)
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(s[i] == 'D' && R)
                {
                    s[i] = 'X';
                    R--;
                }

            }
        }
        else
        {
            if(S)
            {

                for(int i = 0 ; i < n ; i++)
                {
                    if(s[i] == 'R' && S)
                    {
                        s[i] = 'X';
                        S--;
                    }
                }
            }
        }
        S = R = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == 'D')
                S++;
            if(s[i] == 'R')
                R++;
        }
        if(R && !S)
        {
            cout << 'R';
            return 0;
        }
        if(S && !R)
        {
            cout << 'D';
            return 0;
        }
    }
    return 0;
}