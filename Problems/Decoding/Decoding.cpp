#include <iostream>
#include <queue>

using namespace std;

deque < char > V;
string s;
int n;

int main()
{
    cin >> n;
    cin >> s;
    if(n % 2)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(i % 2 == 0)
            {
                V.push_back(s[i]);
            }
            else V.push_front(s[i]);
        }
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(i % 2 != 0)
            {
                V.push_back(s[i]);
            }
            else V.push_front(s[i]);
        }
    }
    while(V.size())
    {
        cout << V.front();
        V.pop_front();
    }
    return 0;
}