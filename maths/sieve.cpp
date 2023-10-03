#include <bits/stdc++.h>
using namespace std;


//sieve of eratosthenes
vector<int> primes;
vector<bool> is_prime;
void sieve(int n){
    if(n < is_prime.size()){
        return;
    }
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
}