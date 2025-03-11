//My template https://github.com/Wadedacoder/Competitive-Programming-Template - only reference
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

 
#define int long long
#define endl '\n'
 
//ordered set

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 

const int MOD = 1e9 + 7;
const int inf = 2e18;
const int maxn = 1000005;
const int N = 1e5 + 5;
constexpr int MAXN = 5e5 + 10;

vector<int> hash_map(1e6 + 5, -1);

// random number generator
long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}


int ceil(int a, int b){
    return (a + b - 1) / b;
}


void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(hash_map[a[i]] == -1){
            hash_map[a[i]] = rng();
        }
    }
    vector<int> prefix_xor(n + 1);
    prefix_xor[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix_xor[i] = prefix_xor[i - 1] ^ hash_map[a[i - 1]];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = (prefix_xor[r] ^ prefix_xor[l - 1]);
        if(ans == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    
    
}
 
signed main(){
    #ifdef mlocal
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();
    #endif
    // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    // precompute();
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