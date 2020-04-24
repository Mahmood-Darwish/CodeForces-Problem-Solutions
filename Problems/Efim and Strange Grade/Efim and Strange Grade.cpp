#include <bits/stdc++.h>
using namespace std;
const int  lim = 1e6+2;
int inp[lim+3];
string s;
int last=INT_MAX;
int cnt = 0;
int trap;
void inc(int i)
{
    if(i<0)
    {
        s = '1'+s;
        trap++,cnt++;
        return ;
    }
    if(s[i]=='9')s[i]='0',inc(i-1);
    else if(s[i]=='.')inc(i-1);
    else s[i]++;
}

void start(int i,int t)
{
    while(i)
    {
        i+=cnt;
        cnt = 0;
        if(s[i]=='.'&&s[i+1]>='5')
        {
            t--,inc(i-1),last = i+cnt-1;
            break;
        }
        else if(s[i]=='.')break;
        else if(s[i+1]>='5')t--,inc(i),last = i+cnt;
        i--;
        if(!t)break;
    }
}

int main()
{
    int t;
    cin >> trap >>t;
    cin >> s;
    bool dis=false;
    last = trap - 1;
    for(int i = 0; i<trap; i++)
    {
        if(s[i]=='.')dis = true;
        if(dis && s[i]>='5')
        {
            start(i-1,t);
            break;
        }
    }
    last = min(last,trap-1);
    bool check = false;
    for(int i = 0; i<=last; i++)
    {
        if(s[i]=='.')check = true;
    }
    while(check&&s[last]=='0')last--;
    if(s[last]=='.')last--;
    for(int i =0; i<=last; i++)
        cout << s[i];
    cout << endl;
    return 0;
}