#include <bits/stdc++.h>

using namespace std;

string s , t;
int ans;
int arr[200000][2];

struct node
{
    int val;
    bool reve;
    struct node* child[26];
}*head;

void init()
{
    head = new node();
    head -> val = -1;
    head -> reve = 0;
    for(int i = 0 ; i < 26 ; i++)
        head -> child[i] = NULL;
}

void insertt(int pos,bool rev)
{
    if(pos >= s.size())return;
    node* current = head;
    int value;
    if(rev)
        value = s.size() - pos;
    else
        value = pos + 1;
    for(int i = pos ; i < s.size() ; i++)
    {
        int letter = (int)s[i] - (int)'a';
        if(current -> child[letter] == NULL)
            current -> child[letter] = new node();
        current = current -> child[letter];
        current -> val = value;
        current -> reve = rev;
    }
    insertt(pos + 1 , rev);
}

void funt(int pos)
{
    if(pos >= t.size())return;
    ans++;
    node* current = head;
    for(int i = pos ; i < t.size() ; i++)
    {
        int letter = (int)t[i] - (int)'a';
        if(current -> child[letter] == NULL)
        {
            if(current == head)
            {
                cout << -1 << '\n';
                exit(0);
            }
            if(!current -> reve)
            {
                arr[ans][0] = current -> val;
                arr[ans][1] = current -> val + (i - pos) - 1;
            }
            else
            {
                arr[ans][0] = current -> val;
                arr[ans][1] = current -> val - (i - pos) + 1;
            }
            funt(i);
            return;
        }
        current = current -> child[letter];
    }
    if(!current -> reve)
    {
        arr[ans][0] = current -> val;
        arr[ans][1] = current -> val + ((t.size()) - pos) - 1;
    }
    else
    {
        arr[ans][0] = current -> val;
        arr[ans][1] = current -> val - ((t.size()) - pos) + 1;
    }
}

int main()
{
    init();
    cin >> s >> t;
    insertt(0,0);
    string s1 = s;
    reverse(s.begin() , s.end());
    if(s != s1)
        insertt(0,1);
    funt(0);
    cout << ans << '\n';
    for(int i = 1 ; i <= ans ; i++)
        cout << arr[i][0] << " " << arr[i][1] << '\n';
    return 0;
}