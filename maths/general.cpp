#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int floor(int a, int b){
    return a/b;
}

int ceil(int a, int b){
    return (a+b-1)/b;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int power(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

int mod(int a, int b){
    return ((a % b) + b) % b;
}
