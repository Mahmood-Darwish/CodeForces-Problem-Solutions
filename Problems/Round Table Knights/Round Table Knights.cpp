#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, a[100010];
vector < int > V;

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0 && n / i >= 3)
            V.push_back(i);
    }
    for(unsigned int i = 0 ; i < V.size() ; i++)
    {
        for(int k = 0 ; k <= V[i] ; k++)
        {
            bool bad = false;
            for(int j = 1 + k ; j <= n ; j += V[i])
            {
                if(a[j] == 0){
                    bad = true;
                    break;
                }
                if(j + V[i] > n){
                    if(a[(j + V[i]) % n] == 0){
                        bad = true;
                    }
                    break;
                }
            }
            if(!bad){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}