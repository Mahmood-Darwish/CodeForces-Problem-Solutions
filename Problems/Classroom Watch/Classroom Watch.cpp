#include <iostream>
#include <vector>

using namespace std;

vector < int > V;

int get(int i)
{
    int sum = 0;
    for(int j = 0 ; j <= 10 ; j++){
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

int main()
{
    int n, sum = 0;
    cin >> n;
    for(int i = max(1, n - 150); i <= n ; i++){
        if(i + get(i) == n) {
            sum++;
            V.push_back(i);
        }
    }
    cout << sum << endl;
    for(int i = 0 ; i < V.size() ; i++){
        cout << V[i] << endl;
    }
    return 0;
}