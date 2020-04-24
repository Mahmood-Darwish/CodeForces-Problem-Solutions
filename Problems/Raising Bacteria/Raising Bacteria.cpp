#include<iostream>
using namespace std;
int main(){
int x,w=0;
cin>>x;
while(x>0){
if(x%2!=0){
x--;
w++;
}
else
x/=2;
}
cout<<w;
return 0;
}