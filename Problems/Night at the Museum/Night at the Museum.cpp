#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string s;
int sum, pos;

int main()
{
	cin >> s;
    int n = s.size();
	for(int  i = 0 ; i < n ; i++){
		sum += min((int)abs(pos - (int)(s[i] - 'a')),abs((int)26 - abs(pos - (int)(s[i] - 'a'))));
		pos = s[i] - 'a';
	}
	cout << sum << endl;
}