
 #include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int wsum=0,bsum=0;
    for(int i=0;i<8;i++){
            cin>>s;
            for(int i3=0;i3<8;i3++){
                if(s[i3]=='Q') {wsum+=9;}
                if(s[i3]=='q') {bsum+=9;}
                if(s[i3]=='R') {wsum+=5;}
                if(s[i3]=='r') {bsum+=5;}
                if(s[i3]=='N'||s[i3]=='B') {wsum+=3;}
                if(s[i3]=='n'||s[i3]=='b') {bsum+=3;}
                if(s[i3]=='P') {wsum++;}
                if(s[i3]=='p') {bsum++;}
            }
        }
    if(wsum>bsum) {cout<<"White";}
    else {if (wsum<bsum) {cout<<"Black";}
    else {cout<<"Draw";}}
    return 0; 
}