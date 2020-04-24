#include <iostream>
#include <algorithm>

using namespace std;

int n ;
pair < int , int > a[10000000];
vector < int > fir , sec;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a,a+n);
    for(int i = 0 ; i < n ; i += 2)
    {
        fir.push_back(a[i].second);
        if(i + 1 < n)
            sec.push_back(a[i+1].second);
    }
    cout << fir.size() << '\n';
    for(int i = 0 ; i < fir.size() ; i++)
        cout << fir[i] << " ";
    cout << '\n';
    cout << sec.size() << '\n';
    for(int i = 0 ; i < sec.size() ; i++)
        cout << sec[i] << " ";
    return 0;
}