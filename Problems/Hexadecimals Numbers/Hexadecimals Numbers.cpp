#include <bits/stdc++.h>

using namespace std;

long long n , sum , ans;

string number_to_string(int x)
{
    if(!x) return "0";
    string s = "";
    while(x)
    {
        s.push_back(x%10 + '0');
        x /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int funt(int sum)
{
    string s = number_to_string(sum);
    for(int i = 0 ; i < s.size() ; i++)
    {
        bool sure = false;
        while(s[i] == '2')
        {
            sure = true;
            for(int j = i ; j < s.size() ; j++)
            {
                s[i] = '0';
            }
            i--;
            if(i == -1)
            {
                string s1 = "1";
                s1.append(s);
                s = s1;
                i = 0;
                break;
            }
            s[i] = (char)((int)s[i] + 1);
        }
        if(sure)break;
    }
    int b = atoi(s.c_str());
    return b;
}

int main()
{
    cin >> n;
    while(sum <= n)
    {
        sum++;
        sum = funt(sum);
        if(sum <= n)
            ans++;
    }
    cout << ans;
    return 0;
}