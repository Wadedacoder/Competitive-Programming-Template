#include <bits/stdc++.h>

using namespace std;

int check(){
    // TODO: Implement this function
}

int binary_search(int l, int r, vector<int> &v){
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}