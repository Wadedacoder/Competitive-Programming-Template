#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define maxn 1000005
#define inf 1e18

const int MOD = 1000000007;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}