//My template https://github.com/Wadedacoder/Competitive-Programming-Template - only reference
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


const int MOD = 1000000007;
const int inf = 1e18;
const int maxn = 1000005;

int check(){
    // TODO: Implement this function
}

int binary_search(int l, int r, vector<int> &v){
    while(l < r){
        int mid = (l/2 + r/2);
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}
void solve(){


    return;
}

signed main(){
    #ifdef mlocal
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    #ifdef mlocal
    end = chrono::steady_clock::now();
    cerr << "\nTime Elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
    #endif

    return 0;
}