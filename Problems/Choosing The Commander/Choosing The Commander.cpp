#include <iostream>
#include <algorithm>

using namespace std;

int n, q, ans, t;
string str_y;

int xxor(char x, char y)
{
    if(x == '1' && y == '1')
        return 0;
    if(x == '0' && y == '0')
        return 0;
    if(x == '1' && y == '0')
        return 1;
    if(x == '0' && y == '1')
        return 1;
}

struct node
{
    bool is_end;
    int cnt;
    struct node* child[2];
}*head;

void init()
{
    head = new node();
    head -> is_end = false;
    head -> cnt = 0;
    for(int i = 0 ; i < 2 ; i++)
        head -> child[i] = NULL; //new node();
}

void insertt(string word)
{
    //cout << word << endl;
    node* current = head;
    current -> cnt++;
    for(unsigned int i = 0 ; i < word.size() ; i++)
    {
        int letter = (word[i] == '1');
        //cout << letter << endl;
        if(current -> child[letter] == NULL)
            current -> child[letter] = new node();
        current -> child[letter] -> cnt++;
        current = current -> child[letter];
    }
    current -> is_end = true;
    return;
}

void deletee(string word)
{
    node* current = head;
    current -> cnt--;
    int i = 0;
    while(i < word.size())
    {
        int temp = (word[i] == '1');
        current -> child[temp] -> cnt--;
        if(current -> child[temp] -> cnt == 0)
        {
            current -> child[temp] = NULL;
            return;
        }
        current = current -> child[temp];
        i++;
    }
    if((current -> cnt) == 0){
        current -> is_end = false;
    }
}

string to_bin(int x)
{
    string temp = "";
    while(x){
        if(x % 2)
            temp.push_back('1');
        else
            temp.push_back('0');
        x /= 2;
    }
    while(temp.size() < 32) temp.push_back('0');
    reverse(temp.begin(), temp.end());
    return temp;
}

string wordd;

void comp()
{
    node* current = head;
    for(int i = 0 ; i < wordd.size() ; i++){
        if(str_y[i] == '0'){
            if(wordd[i] == '0'){
                if(current -> child[0] != NULL){
                    current = current -> child[0];
                    continue;
                }
                else return;
            }
            else{
                if(current -> child[1] != NULL){
                    current = current -> child[1];
                    continue;
                }
                else return;
            }
        }
        else{
            if(wordd[i] == '0'){
                if(current -> child[0] != NULL)
                    ans += current -> child[0] -> cnt;
                if(current -> child[1] != NULL){
                    current = current -> child[1];
                    continue;
                }
                else return;
            }
            else{
                if(current -> child[1] != NULL)
                    ans += current -> child[1] -> cnt;
                if(current -> child[0] != NULL){
                    current = current -> child[0];
                    continue;
                }
                else return;
            }
        }
    }
}

int main()
{
    init();
    cin >> q;
    int x, y;
    while(q--){
        scanf("%d" ,&t);
        if(t == 1){
            scanf("%d", &x);
            //cout << (to_bin(x)) << endl;
            insertt(to_bin(x));
        }
        if(t == 2){
            scanf("%d", &x);
            //cout << to_bin(x) << endl;
            deletee(to_bin(x));
        }
        if(t == 3){
            scanf("%d %d", &x, &y);
            str_y = to_bin(y);
            wordd = to_bin(x);
            node* current = head;
            comp();
            printf("%d\n", ans);
            ans = 0;
        }
    }
    return 0;
}