#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    string  s = "#", temp;
    cin >> n >> k;
    cin >> temp;
    s += temp;
    int pos = k;
    if(n - k < k)
    {
        while(pos < n){
            printf("RIGHT\n");
            pos++;
        }
        pos = n;
        while(pos != 0){
            printf("PRINT %c\n", s[pos]);
            if(pos != 1)
                printf("LEFT\n");
            pos--;
        }
    }
    else{
        while(pos > 1){
            printf("LEFT\n");
            pos--;
        }
        pos = 1;
        while(pos != n + 1){
            printf("PRINT %c\n", s[pos]);
            if(pos != n)
                printf("RIGHT\n");
            pos++;
        }
    }
    return 0;
}