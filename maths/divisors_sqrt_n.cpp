#include <bits/stdc++.h>
using namespace std;

// sqrt(n) divisors

vector<int> divisors(int n){
        vector<int> factors_l, factors_r;
        factors_l.push_back(1);
        if(n >= 1){
            factors_r.push_back(n);
        }
        for(int i = 2; i * i <= n; i++){
            if(n % i != 0) continue;
            factors_l.push_back(i);
            factors_r.push_back(n / i);
        }

        vector<int> factors;
        for(int i = 0; i < factors_l.size(); i++){
            factors.push_back(factors_l[i]);
        }
        for(int i = factors_r.size() - 1; i >= 0; i--){
            factors.push_back(factors_r[i]);
        }
        return factors;
    }
