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
#define mod 1000000007

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

vi fact(1e7+20);

void solve()
{
    int n,bu,ans;
    cin >> n;
    bu=(n+2)/3;
    if(bu<=1)
    {
        cout<<1<<endl;
        return;
    }
    if(n%3==0)
    {
        ans=fact[n];
        ans=(ans*power(mod_inverse(6,mod),bu,mod))%mod;
        ans=(ans*mod_inverse(fact[bu],mod))%mod;
        cout << ans << endl;
    }
    else if(n%3==2)
    {
        ans=fact[n];
        ans=(ans*power(mod_inverse(6,mod),bu-1,mod))%mod;
        ans=(ans*mod_inverse(fact[bu-1],mod))%mod;
        ans=(ans*mod_inverse(2,mod))%mod;
        cout << ans << endl;
    }
    else
    {
        int ans1=fact[n];
        ans1=(ans1*power(mod_inverse(6,mod),bu-1,mod))%mod;
        ans1=(ans1*mod_inverse(fact[bu-1],mod))%mod;
        int ans2=0;
        if(bu>=2)
        {
            ans2=fact[n];
            ans2=(ans2*power(mod_inverse(6,mod),bu-2,mod))%mod;
            ans2=(ans2*mod_inverse(fact[bu-2],mod))%mod;
            ans2=(ans2*power(mod_inverse(2,mod),2,mod))%mod;
            ans2=(ans2*mod_inverse(2,mod))%mod;
        }
        cout << (ans1+ans2)%mod << endl;
    }
}

int32_t main()
{
    fast
    for(int i=0;i<=1e7+10;i++)
        fact[i]=((i==0)?1:i*fact[i-1])%mod;
    solve();
    return 0;
}