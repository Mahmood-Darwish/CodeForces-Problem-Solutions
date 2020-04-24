#include <iostream>
#include <stack>

using namespace std;

pair < pair < char , int > , bool > arr[1000000];
int n , m , pos ;
string s2;
stack < int > mys;
int dsu[10000000];
int dsu2[10000000];

int Find(int pos)
{
    if(dsu[pos] == pos || !arr[pos].second || pos >= n - 1)return pos;
    if(arr[pos].first.second < pos) pos++;
    return dsu[pos] = Find(dsu[pos] );
}

int Find2(int pos)
{
    if(dsu2[pos] == pos || !arr[pos].second)return pos;
    if(arr[pos].first.second > pos) pos--;
    return dsu2[pos] = Find2(dsu2[pos] );
}

int main()
{
    cin >> n >> m >> pos;
    pos--;
    for(int i = 0 ; i < n ; i++)
        {cin >> arr[i].first.first;dsu[i] = i;dsu2[i] = i;}
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i].first.first == '(')
        mys.push(i);
        else{
            arr[i].first.second = mys.top();
            arr[mys.top()].first.second = i;
            mys.pop();
        }
    }
    cin >> s2;
    for(int i = 0 ; i < m ; i++)
    {
        if(s2[i] == 'R'){pos = Find(pos + 1);}
        if(s2[i] == 'L'){pos = Find2(pos - 1);}
        if(s2[i] == 'D')
        {
            arr[pos].second = true;
            arr[arr[pos].first.second].second = true;
            dsu[pos] = arr[pos].first.second;
            dsu[arr[pos].first.second] = pos;
            dsu2[pos] = arr[pos].first.second;
            dsu2[arr[pos].first.second] = pos;
            pos = Find(pos);
            if(pos >= n - 1)pos = Find2(pos);
        }
    }
    for(int i = 0 ; i < n ; )
    {
        if(!arr[i].second){cout << arr[i].first.first;i++;}
        else
        {
            i = arr[i].first.second + 1;
        }
    }
    return 0;
}
/*
6 4 1

()()()

DRRD

*/