#include <bits/stdc++.h>

using namespace std;

string str;
bool ans;

struct node
{
    bool is_end;
    struct node* child[3];
}*head;

void init()
{
    head = new node();
    head -> is_end = false;
    head -> child[0] = NULL;
    head -> child[1] = NULL;
    head -> child[2] = NULL;
}

void insertt (string str)
{
    node* current = head;
    for(int i = 0 ; i < str.size() ; i++)
    {
        int letter = (int)str[i] - (int)'a';
        if(current -> child[letter] == NULL)
            current -> child[letter] = new node();
        current = current -> child[letter];
    }
    current -> is_end = true;
}

inline void query(int sum , node* cur , int pos)
{
    if(sum > 1)return;
    if(pos == str.size()){ans = max(sum == 1 && cur -> is_end == true, ans);return;}
    if(cur -> child[0] != NULL)
        query(sum + (0 !=(int) str[pos] - (int) 'a'), cur -> child[0] , pos + 1);
    if(cur -> child[1] != NULL)
        query(sum + (1 !=(int) str[pos] - (int) 'a'), cur -> child[1] , pos + 1);
    if(cur -> child[2] != NULL)
        query(sum + (2 !=(int) str[pos] - (int) 'a'), cur -> child[2] , pos + 1);
}

int main()
{
    int n , m;
    cin >> n >> m;
    init();
    while (n--)
    {
        cin >> str;
        insertt(str);
    }
    while (m--)
    {
        ans = 0;
        cin >> str;
        node* cur = head;
        query(0 , cur , 0);
        if(ans)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}