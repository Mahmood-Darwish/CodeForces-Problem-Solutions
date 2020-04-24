#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, temp, ans;
ll a[100100];
ll arr[100100];

ll Mypow(ll X,ll Y){
    if(Y < 0)return 0;
    if(Y == 0)return 1;
    if(Y == 1){
        return X;
    }
    else{
        ll x = Mypow(X ,Y / 2);
        x *= x;
        if(Y % 2)
            return (x * X);
        else
            return x;
    }
}

string to_bin(ll number)
{
    string X = "";
    for(ll i = 0 ; i < 63 ; i++){
        if(number % 2 == 1){
            X.append("1");
        }
        else{
            X.append("0");
        }
        number /= 2;
    }
    reverse(X.begin(), X.end());
    return X;
}

struct node{
    ll prefix_count;
    struct node* child[2];
}*head;

void init()
{
    head = new node();
    head -> prefix_count = 0;
    head -> child[0] = NULL;
    head -> child[1] = NULL;
    return;
}

void add(string word)
{
    node* current = head;
    current -> prefix_count++;
    for(unsigned int i = 0 ; i < word.size() ; i++)
    {
        ll letter = (word[i] == '1');
        if(current -> child[letter] == NULL)
            current -> child[letter] = new node();
        current -> child[letter] -> prefix_count++;
        current = current -> child[letter];
    }
    return;
}

ll searchh(string word)
{
    //cout << word << endl;
    ll sum = 0LL;
    node* current = head;
    for(unsigned int i = 0 ; i < word.size() ; i++)
    {
        ll letter = (word[i] == '1');
        //cout << letter << ' ';
        if(current -> child[1 - letter] == NULL){
            current = current -> child[letter];
            continue;
        }
        sum += Mypow(2, 62 - i);
      //  cout << sum << endl;
        current = current -> child[1 - letter];
    }
    //cout << endl;
    return sum;
}

void removee(string word)
{
    node* current = head;
    current -> prefix_count--;
    for(unsigned int i = 0 ; i < word.size() ; i++)
    {
        ll bit = (word[i] == '1');
        current -> child[bit] -> prefix_count--;
        if(current -> child[bit] -> prefix_count == 0)
        {
            current -> child[bit] = NULL;
            return;
        }
        current = current -> child[bit];
    }
    return;
}

int main()
{
    init();
    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(ll i = n - 1 ; i >= 0 ; i--){
        temp ^= a[i];
        arr[i] = temp;
        add(to_bin(arr[i]));
    }
    temp = 0;
    for(ll i = 0 ; i < n ; i++){
        temp ^= a[i];
        ans = max(temp, ans);
    }
    temp = 0;
    for(ll i = n - 1 ; i >= 0 ; i--){
        temp ^= a[i];
        ans = max(temp, ans);
    }
    temp = 0LL;
    for(ll i = 0 ; i < n ; i++){
        temp ^= a[i];
        ll temp2 = searchh(to_bin(temp));
        ans = max(ans, temp2);
        removee(to_bin(arr[i]));
    }
    cout << ans << endl;
    return 0;
}