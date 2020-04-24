#include <iostream>

using namespace std;

long long ans;
int k;
string s;
string Bad;

struct node
{
    bool is_end;
    int prefix_count;
    struct node* child[26];
}*head;

void init()
{
    head = new node();
    head -> is_end = false;
    head -> prefix_count = 0;
    for(int i = 0 ; i < 26 ; i++)
        head -> child[i] = NULL;
}

void insertt(int pos , int bad)
{
    if(pos == s.size())return;
    node* current = head;
    for(int i = pos ; i < s.size() ; i++)
    {
        int letter = (int)s[i] - (int)'a';
        if(Bad[(int)s[i] - (int)'a'] == '0')
            bad++;
        if(bad > k)break;
        if(current -> child[letter] == NULL)
        {
            current -> child[letter] = new node();
            ans++;
        }
        current = current -> child[letter];
    }
    insertt(pos + 1 , 0);
}

int main()
{
    init();
    cin >> s;
    cin >> Bad;
    cin >> k;
    int n = s.size();
    insertt(0 , 0 );
    cout << ans;
    return 0;
}