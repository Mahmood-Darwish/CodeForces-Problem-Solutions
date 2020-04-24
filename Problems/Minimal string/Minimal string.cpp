#include <iostream>

using namespace std;

int I, letter;
string s, temp, ans;
int arr[27];
int a[27];
int b[27];

int main()
{
    cin >> s;
    for(int i = 0; i < s.size() ; i++){
        a[s[i] - 'a']++;
        arr[s[i] - 'a']++;
    }
    while(I < s.size() || temp.size()){
        if(!a[letter]){
            letter++;
            continue;
        }
        //cout << s << ' ' << I << endl << temp << endl << ans << endl;
        if(s.size() <= I){
            while(temp.size()){
                ans.push_back(temp[temp.size() - 1]);
                b[temp[temp.size() - 1] - 'a']--;
                arr[temp[temp.size() - 1] - 'a']--;
                temp.pop_back();
            }
            break;
        }
        while(temp.size() && temp[temp.size() - 1] - 'a' <= letter){
            b[temp[temp.size() - 1] - 'a']--;
            arr[temp[temp.size() - 1] - 'a']--;
            ans.push_back(temp[temp.size() - 1]);
            temp.pop_back();
        }
        while(I < s.size() && a[letter]){
            if(s[I] - 'a' == letter){
                a[letter]--;
                arr[letter]--;
                ans.push_back(s[I]);
            }
            else{
                temp.push_back(s[I]);
                a[s[I] - 'a']--;
                b[s[I] - 'a']++;
            }
            I++;
        }
        letter++;
    }
    cout << ans << endl;
    return 0;
}
//abcbabbcc aabbbcbcc