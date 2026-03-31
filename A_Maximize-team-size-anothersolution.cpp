/*
==========================================================
  A poet residing in a coder's mind,
  Seeking the patterns others can't find.
  Brief are the variables, deep is the quest,
  Putting the logic and limits to test.

  From stumbling to soaring, the path is clear,
  Mukhtasar code for the problems here.
  No spaces to waste, let the verdict float,
==========================================================
*/

/*
======================================
Author:         Harshada Ghube
Institution:    IIIT LUCKNOW
======================================
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll M = 1e7 +9
int main() {
ios_base::sync_with_stdio(false);
 cin.tie(0);
      int t;
      cin>>t;
       while(t--){
        int n ,gc=0;
        
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            gc = __gcd(gc, a[i]);
        } 
        cout << gc << endl;
           
        }
    return 0;
}