#include <iostream>
using namespace std;
int a[100000];
int main() {
	int n,x,y,q,i,i2,i3;
	cin>>n>>x;
	for(i=0;i<x;i++){
		cin>>q;
		a[q]=1;
	}
	cin>>y;
	for(i2=0;i2<y;i2++){
		cin>>q;
		a[q]=1;
	}
	for(i3=1;i3<=n;i3++){
		if(a[i3]==0){
			cout<<"Oh, my keyboard!";
			return 0;
		}
	}
	cout<< "I become the guy.";
	return 0;
}