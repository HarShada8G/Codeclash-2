/*
==========================================================
  A poet residing in a coder's mind,
  Seeking the patterns others can't find.
  Brief are the variables, deep is the quest,
  Putting the logic and limits to test.

  From stumbling to soaring, the path is clear,
  Mukhtasar code for the problems here.
  No spaces to waste, let the verdict float,
  History agrees: ANAS IS GOAT;)
==========================================================
*/

/*
======================================
Author:         Md Anas Ali Usmani
Institution:    IIITL
======================================
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define pb push_back
#define popb pop_back()
#define ff first
#define ss second
#define be begin()
#define en end()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define mci map<char,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define mvi map<vi,int>
#define miv map<int,vi>
#define si set<int>
#define smi multiset<int>
#define spi set<pair<int,int>>
#define smpi multiset<pair<int,int>>
#define low lower_bound
#define up upper_bound
#define endl '\n'
#define bcnt(x) __builtin_popcount(x) // -> Number of set bits int
#define bctz(x) __builtin_ctz(x) // -> Count trailing zeros in binary
#define bclz(x) __builtin_clz(x) // -> Count leading zeros in binary
#define mod 998244353

// #pragma GCC target("popcnt")

using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

int power(int base, int exp, int m) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Modular inverse using Fermat's Little Theorem
int mod_inverse(int b, int m) {
    return power(b, m - 2, m);
}

void solve()
{
    int n,m,i,j,s=0,t;
    cin >> n >> m;
    t=((n-1)*(m-1)*6)%mod;
    vvi g(n+2, vi(m+2)), x(n+2, vi(m+2));
    for(i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        s='0'+s;
        for(j=1;j<=m;j++)
        {
            g[i][j]=(s[j]=='G')+g[i-1][j]+g[i][j-1]-g[i-1][j-1];
            x[i][j]=(s[j]=='X')+x[i-1][j]+x[i][j-1]-x[i-1][j-1];
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            vi gg={g[i][j],g[i][m]-g[i][j],g[n][j]-g[i][j],g[n][m]-g[n][j]-g[i][m]+g[i][j]};
            vi xx={x[i][j],x[i][m]-x[i][j],x[n][j]-x[i][j],x[n][m]-x[n][j]-x[i][m]+x[i][j]};
            s+=(gg[0]+gg[1]>xx[2]+xx[3])+(gg[0]+gg[2]>xx[1]+xx[3])+(gg[0]+gg[3]>xx[1]+xx[2])+(gg[1]+gg[2]>xx[0]+xx[3])+(gg[1]+gg[3]>xx[0]+xx[2])+(gg[2]+gg[3]>xx[0]+xx[1]);
            s%=mod;
        }
    }
    cout << (s*mod_inverse(t,mod))%mod << endl;
}

int32_t main()
{
    fast
    solve();
    return 0;
}