#include <bits/stdc++.h>
using namespace std;
int n,sum;
int a[100000];
int b[100000];
pair<int,int> p[1023];

int num1,num2;
int main()
{
cin>>n;
for(int i=0;i<n;i++){
cin>>num1>>num2;
p[i].first=num1;
p[i].second=num2;
}
sort(p,p+n);
for(int i=1;i<n;i++){
    if(p[i].second<p[i-1].second && p[i].first>p[i-1].first) {cout<<"Happy Alex"; return 0;}
}
cout<<"Poor Alex";
    return 0;
}