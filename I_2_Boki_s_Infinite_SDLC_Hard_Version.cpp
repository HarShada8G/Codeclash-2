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
#define bcnt(x) __builtin_popcount(x) 
#define bctz(x) __builtin_ctz(x) 
#define bclz(x) __builtin_clz(x) 
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void add(int x, vvi &tr, vi &cnt, int &nodes)
{
    int u=1,i,b;
    for(i=30;i>=0;i--)
    {
        b=(x>>i)&1;
        if(!tr[u][b]) tr[u][b]=++nodes;
        u=tr[u][b];
        cnt[u]++;
    }
}

int query(int x, int k, vvi &tr, vi &cnt)
{
    int u=1,ans=0,i,b,kb;
    for(i=30;i>=0;i--)
    {
        if(!u) break;
        b=(x>>i)&1;
        kb=(k>>i)&1;
        if(!kb)
        {
            if(tr[u][!b]) ans+=cnt[tr[u][!b]];
            u=tr[u][b];
        }
        else u=tr[u][!b];
    }
    if(u) ans+=cnt[u];
    return ans;
}

int subarraysWithXorAtleastK(vi &pf, int k) 
{
    int n=pf.size(),ans=0,i,nodes=1;
    vvi tr(n*32,vi(2)); 
    vi cnt(n*32);
    add(0,tr,cnt,nodes);
    for(i=1;i<n-1;i++)
    {
        ans+=query(pf[i],k,tr,cnt);
        add(pf[i],tr,cnt,nodes);
    }
    return ans;
}

void solve()
{
    int n,i,q,k,mx=0;
    cin >> n >> q >> k;
    vi a(n+2),pre1(n+2),pre2(n+2),pre3(n+2),pre4(n+2),pre5(n+2),res(n+2),pf(n+2);
    for(i=1;i<=n;i++)
        cin >> a[i],
        mx=max(mx,a[i]);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        pre1[l]+=2;
        pre1[r+1]-=2;
        pre2[r+1]+=-2*(r-l+1);
        pre3[r+1]-=(r-l+1)*(r-l+2);
        pre4[l]+=1;
        pre4[r+1]-=1;
        pre5[r+1]-=(r-l+1);
    }
    for(i=1;i<=n;i++)
    {
        pre1[i]+=pre1[i-1];
        pre4[i]+=pre4[i-1];
        pre2[i]+=pre2[i-1]+pre1[i];
        pre5[i]+=pre5[i-1]+pre4[i];
        pre3[i]+=pre3[i-1]+pre2[i];
        res[i]=(pre3[i]-pre5[i])%a[i];
        pf[i]=pf[i-1]^res[i];
    }
    cout << subarraysWithXorAtleastK(pf,k) << endl;
}

int32_t main()
{
    fast
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}