#include <bits/stdc++.h>
using namespace std;
map <string , int > m;
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
  string s;
  cin>>s;
  if(m[s]!=0)cout<<s<<m[s];
  
  else cout<<"OK";
  m[s]++;
  cout<<endl;
      
  }
  
    return 0;
}