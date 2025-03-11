
struct matrix{
    int mat[7][7];
    matrix(){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                mat[i][j] = 0;
            }
        }
    }

    matrix operator*(matrix &other){
        matrix res;
        
        // cout << "Multiplying\n";
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                for(int k = 0; k < 7; k++){
                    res.mat[i][j] = (res.mat[i][j] + (mat[i][k]*other.mat[k][j]) % MOD + MOD) % MOD;
                    res.mat[i][j] = (res.mat[i][j] + MOD) % MOD;
                    // res.mat[i][j] = (res.mat[i][j] + (mat[i][k]*other.mat[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }  
};

matrix power(matrix a, int n){
    matrix res;
    for(int i = 0; i < 7; i++){
        res.mat[i][i] = 1;
    }
    while(n > 0){
        if(n % 2 == 1){
            res = res*a;
        }
        a = a * a;
        n /= 2;
    }
    return res;
}
