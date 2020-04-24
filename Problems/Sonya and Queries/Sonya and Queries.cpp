#include <bits/stdc++.h>
#define F first
#define S second
#define ii pair < int , int >
#define SF(a) scanf("%I64d",&a)
#define MEM(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long ll;

ll GCD(ll a , ll b){
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b){
    return (a * b) / GCD(a , b);
}

ll n;
map < string , ll > my;

string to_bin(ll num){
    ll a[70];
    MEM(a,0);
    string sum = "";
    for(int i = 0 ; i < 64 ; i++){
        if(num){
            int temp = num % 2;
            num /= 10;
            if(temp)a[i] = 1;
            else a[i] = 0;
        }
        else a[i] = 0;
    }
    for(int i = 63 ; i >= 0 ; i--){
        if(a[i])
        sum.push_back('1');
        else
        sum.push_back('0');
    }
    return sum;
}

int main()
{
    cin >> n;
    while(n--){
        char c;
        ll num1;
        scanf("%s %I64d",&c , &num1);
        string num;
        num = to_bin(num1);
        if(c == '+'){
            if(my.find(num) != my.end())
                my[num]++;
            else my.insert({num,1});
        }
        if(c == '-'){
            my[num]--;
        }
        if(c == '?'){
            if(my.find(num) != my.end())
                printf("%I64d",my[num]);
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}