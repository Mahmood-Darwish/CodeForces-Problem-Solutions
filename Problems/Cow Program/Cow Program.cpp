#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;
ll n, arr[200100][3];
ll INF = (1 << 60);
ll a[200100];

ll DFS(int pos, int op, ll y)
{
    //cout << pos << ' ' << op << ' ' << y << ' ' << arr[pos][op] << endl;
    if(pos > n || pos <= 0){
        return 0;
    }
    if(arr[pos][op] == -1){
        return -1;
    }
    if(arr[pos][op] != -INF){
        return arr[pos][op] + y;
    }
    arr[pos][op] = -1;
    if(op == 1){
        DFS(pos + a[pos], 2, y + a[pos]);
        if(pos + a[pos] > 0 && pos + a[pos] <= n){
            if(arr[pos + a[pos]][2] == -1){
                return -1;
            }
            else
                return arr[pos][op] = arr[pos + a[pos]][2] + a[pos];
        }
        else
            return arr[pos][op] = a[pos];
    }
    else{
        DFS(pos - a[pos], 1, y + a[pos]);
        if(pos - a[pos] > 0 && pos - a[pos] <= n){
            if(arr[pos - a[pos]][1] == -1){
                return -1;
            }
            else
                return arr[pos][op] = arr[pos - a[pos]][1] + a[pos];
        }
        else
            return arr[pos][op] = a[pos];
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i++)
        arr[i][1] = arr[i][2] = -INF;
    for(int i = 2 ; i <= n ; i++){
        scanf("%I64d", &a[i]);
    }
    for(int i = 1 ; i <= n - 1 ; i++){
        a[1] = i;
        arr[1][1] = arr[1][2] = -INF;
        printf("%I64d\n", DFS(1, 1, 0));
        /*cout << "###";
        for(int i = 1 ; i <= n ; i++){
            cout << arr[i][1] << ' ' << arr[i][2] << endl;
        }
        cout << "###";*/
    }
    return 0;
}