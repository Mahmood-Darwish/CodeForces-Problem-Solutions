#include <iostream>
using namespace std;
int n,i2,c,num1,num2;
int b[100000];
int main() {
	cin>>n;
	cin>>num1;
	b[i2]++;
	for(int i=1;i<n;i++){
		cin>>num2;
		i++;
		if(num1<=num2){
			b[i2]++;
		}
		else {
			i2++;
			b[i2]++;
		}
		if(i>=n){
		break;
		}
		cin>>num1;
		if(num1>=num2){
			b[i2]++;
		}
		else {
			i2++;
			b[i2]++;
		}
		
	}
	c=b[0];
	for(int i=0;i<n;i++){
		c=max(c,b[i]);
	}
	cout<<c;
	return 0;
}