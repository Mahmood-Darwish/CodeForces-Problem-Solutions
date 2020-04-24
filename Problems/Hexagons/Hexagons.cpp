//#if Debug
//# include <conio.h>
//#endif

#include <list>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional> 
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <string.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UNI;
typedef unsigned char UC;

#define STR(X) #X

#define ABS(a)      ((a>0)?a:-(a))
#define MIN(a,b)    ((a<b)?(a):(b))
#define MAX(a,b)    ((a<b)?(b):(a))
#define FOR(i,a,n)    for ( int i = (a); i < (n); ++i)
#define FOR_(i,a,n)     for ( int i = (a); i >= (n); --i)
#define FORI(n)        for(int i = 0; i < n; ++i)
#define MEMS(a,b)    memset(a,b,sizeof(a))

#define MP(p1, p2)      std::make_pair(p1, p2)
#define VI              std::vector<int>
#define SI              std::set<int>
#define PI              std::pair<int, int>
#define PUI             std::pair<UNI, UNI>
#define RNG(container)  container.begin(), container.end()
#define endl            "\n"

const int       MOD = 1000000007;
const double    EXP = 2.7182818284590452;
const double    Pi = 3.14159265;
const double    EPS = 1e-13;
const int       INF = 1000 * 1000 * 1001;
const long long INFL = (LL)INF * (LL)INF;

map< pair<LL, LL>, LL > hashgcd;

LL gcd(LL a, LL b)
{
    if (a < b) swap(a, b);

    if (hashgcd.find(MP(a, b)) != hashgcd.end())
        return hashgcd[MP(a, b)];

    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }

    hashgcd[MP(a, b)] = a;

    return a;
}

LL lcm(LL a, LL b)
{
    return (a / gcd(a, b)) * b;
}

LL extgcd(LL a, LL b, LL & x, LL & y)
{
    if (a == 0)
    {
        x = 0; y = 1;
        return b;
    }

    LL x11, y11;
    LL d = extgcd(b % a, a, x11, y11);
    x = y11 - (b / a) * x11;
    y = x11;
    return d;
}

LL poww(LL v, LL p, LL mod)
{
    if (p == 0) return 1;

    if (p & 1)
    {
        return (poww(v, p - 1, mod) * v) % mod;
    }
    else
    {
        LL t = poww(v, p / 2, mod);
        return (t * t) % mod;
    }
}

const ULL L31018 = 3000000000000000000L;

//////////////////
//////////////////
#define MAXN 100006

ULL n;

ULL steps(ULL v)
{
    if (v < 0) return 0;
    return (((v)*(v + 1)) / (ULL)2) * (ULL)6;
}

ULL circle(ULL st)
{
    ULL r = 1000000000L;
    ULL l = 0, s;
    ULL m = 0;

    while (r != l)
    {
        m = (r + l) / (ULL)2;
        s = steps(m);
        if (s < st)
            l = m + 1;
        else
            r = m;
    }

    s = steps(r);

    if (s >= st) return r - 1;
    else return r;
}

ULL st;
LL c;
pair<LL, LL> cur;

pair<LL, LL> findpos(ULL st, pair<LL, LL> p, LL c)
{
    LL s = 0;

    // < 1 
    s = MIN(c - 1, st);
    p.first -= s;
    p.second += (LL)2 * (s);

    st -= s;
    if (st <= 0) return p;
    //   1 >

    // < 2
    s = MIN(c, st);
    p.first -= (LL)2 * (s);

    st -= s;
    if (st <= 0) return p;
    //   2 >

    // < 3
    s = MIN(c, st);
    p.first -= s;
    p.second -= (LL)2 * (s);

    st -= s;
    if (st <= 0) return p;
    //   3 >

    // < 4 
    s = MIN(c, st);
    p.first += s;
    p.second -= (LL)2 * (s);

    st -= s;
    if (st <= 0) return p;
    //   4 >

    // < 5 
    s = MIN(c, st);
    p.first += (LL)2 * (s);

    st -= s;
    if (st <= 0) return p;
    //   5 >

    // < 6 
    s = MIN(c, st);
    p.first += s;
    p.second += (LL)2 * (s);

    st -= s;
    if (st <= 0) return p;
    //   6 >

    return p;
}


void accept()
{
    cin >> n;

    if (n == 0)
    {
        cout << "0 0";
        return;
    }

    c = circle(n);
    n -= steps(c); 

    --n; ++c;
    cur = MP((LL)2 * c - 1, 2);
    cur = findpos(n, cur, c);

    cout << cur.first << " " << cur.second;
}

//      ||
//      ||
//     \||/
//    \\||//
//   \\\\////
//    \\\///
//     \\//
//      \/


int main(void)
{

#if Debug
    LL startTime = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    accept();

#if Debug
    printf("\n\n\t TIME: %.5lf", double((clock() - startTime)) / 1000.0f); /// CLOCKS_PER_SEC));
    int l;
    cin >> l;
    //  _getch();
#endif
    return 0;
    
}