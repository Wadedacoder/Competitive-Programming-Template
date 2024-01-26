#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


const int MOD = 1000000007;
const int inf = 1e18;
const int maxn = 1000005;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
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
    cin >> t;
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