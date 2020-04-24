#include <bits/stdc++.h>
using namespace std;
int A[100009];
int S,M;
void PrintAns(){
    for(int i=0;i<M;i++){
        cout<<A[i];
    }
    cout<<" ";
    memset(A,0,sizeof(A));
}
void Greedy_Algorithm(int start,int end){
    if(S == 0 && M == 1){
        cout<<0<<" ";
        return;
    }
    A[0] = 1;
    int sum = 1;
    if(sum==S){
        PrintAns();
        return;
    }
    for(int i=start;(start<end&&i<end)||(start>=end&&i>=end);(start<end)?i++:i--){
        while(A[i]<9){
            A[i]++;
            sum++;
            if(sum==S){
                PrintAns();
                return;
            }
        }
    }
    cout<<"-1 -1"<<endl;
    exit(0);
}
int main(){
    cin>>M>>S;
    Greedy_Algorithm(M-1,0);Greedy_Algorithm(0,M);
    cout<<endl;
}