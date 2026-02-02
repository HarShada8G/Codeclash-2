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

int N=1e6+11;
vi no(N),st(N,-1);
int spf()
{
    int i,j;
    for(i=2;i<N;i++)
        if(no[i]==0)
            for(j=i;j<N;j+=i)
                no[j]=i;
    return 0;
}

int nof(int n)
{
    if(st[n]!=-1) return st[n];
    int ret=1,tem=n;
    while(n>1)
    {
        int p=no[n],c=0;
        while(n%p==0)
        {
            n/=p;
            c++;
        }
        ret*=(c+1);
    }
    return st[tem]=ret;
}

void solve()
{
    int n,i,k,ans=0;
    cin >> n >> k;
    vi a(n);
    smi s;
    mii mp;
    for(i=0;i<n;i++)
        cin >> a[i];
    sort(all(a));
    s.insert(a[0]);
    mp[nof(a[0])]++;
    for(i=1;i<n;i++)
    {
        s.insert(a[i]);
        mp[nof(a[i])]++;
        while(!s.empty() && a[i]-*s.be>k)
        {
            mp[nof(*s.be)]--;
            s.erase(s.be);
        }
        ans+=mp[nof(a[i])]-1;
    }
    cout << ans << endl;
}

int32_t main()
{
    fast
    spf();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}