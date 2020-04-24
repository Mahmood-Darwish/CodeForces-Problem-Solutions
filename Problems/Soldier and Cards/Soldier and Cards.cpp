#include <iostream>
#include <queue>
using namespace std;
int k,n,num,sum,m1,m2;
int main()
{
    queue<int> q1;
    queue<int> q2;
    cin>>k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        q1.push(num);
    }
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>num;
    q2.push(num);
    }
    while(!q1.empty()&&!q2.empty()){
            m1=q1.front();
            m2=q2.front();
        if(m1>m2){
            q1.push(q2.front());
            q1.push(q1.front());
            q1.pop();
            q2.pop();
            sum++;
        }
        if(sum>1900000) {
            cout<<-1;
            return 0;
        }
        if(q1.empty()||q2.empty()) break;
        m1=q1.front();
        m2=q2.front();
        if(m1<m2){
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
            sum++;
        }
    }
    cout<<sum<<" ";
    if(q1.empty()) cout<<2;
    if(q2.empty()) cout<<1;
    return 0;
}