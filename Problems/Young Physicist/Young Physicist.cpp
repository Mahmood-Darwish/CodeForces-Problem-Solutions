#include <bits/stdc++.h>
using namespace std;
int n,i,i2,sum1,sum2,sum3;
int a[1000];

int main() {
	cin>>n;
for(int i=0;i<(n*3);i++){
cin>>a[i];
}
for(int i=0;(i<n*3);){
sum1+=a[i];
i++;
sum2+=a[i];
i++;
sum3+=a[i];
i++;
}
if(sum1==0&&sum2==0&&sum3==0)
cout<<"YES";
else cout<<"NO";
	return 0;
}