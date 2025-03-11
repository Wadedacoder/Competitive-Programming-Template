 #include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define int long long


/* Useful in SIMD */

int _abs(int a){
    int mask = a >> 63;
    return (a + mask) ^ mask;
}

int _max(int a, int b){
    return a ^ ((a ^ b) & -(a < b));
}

int _min(int a, int b){
    return b ^ ((a ^ b) & -(a < b));
}

int _next_power_of_2(int n){
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int _popcount(int n){
    return __builtin_popcount(n);
}

int _clz(int n){
    return __builtin_clz(n);
}

int _ctz(int n){
    return __builtin_ctz(n);
}


