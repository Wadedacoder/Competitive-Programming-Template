struct Node{
    int max_element;
    int sum;

    Node(int val = 0, int sum = 0): max_element(val), sum(sum){}
    Node merge(Node &a, Node &b){
        Node res;
        res.max_element = max(a.max_element, b.max_element);
        res.sum = a.sum + b.sum;
        return res;
    }
};

Node seg[4*maxn];

void build(int v, int tl, int tr, vector<int> &a){
    if(tl == tr){
        seg[v].max_element = a[tl];
        seg[v].sum = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm, a);
    build(2*v + 1, tm + 1, tr, a);
    seg[v] = seg[v].merge(seg[2*v], seg[2*v + 1]);
    return;
}

void assignment(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        seg[v].max_element = val;
        seg[v].sum = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos <= tm){
        assignment(2*v, tl, tm, pos, val);
    }else{
        assignment(2*v + 1, tm + 1, tr, pos, val);
    }
    seg[v] = seg[v].merge(seg[2*v], seg[2*v + 1]);
    return;
}

void mod_range(int v, int tl, int tr, int l, int r, int mod){
    if(l > r){
        return;
    }
    if(tl == l && tr == r){
        // to update
        // cout << "htl: " << tl << " tr: " << tr << " " << "initial max_element: " << seg[v].max_element << " sum: " << seg[v].sum << endl;
        if(seg[v].max_element < mod){
            return;
        }
    }
    if(tl >= l && tr <= r){ // completely inside
        if(seg[v].max_element < mod){
            return;
        }
    }
    if(tl == tr){
        // cout << "tl: " << tl << " tr: " << tr << " " << "initial max_element: " << seg[v].max_element << " sum: " << seg[v].sum << endl;
        seg[v].max_element = seg[v].max_element % mod;
        seg[v].sum = seg[v].sum % mod;
        // cout << "max_element: " << seg[v].max_element << " sum: " << seg[v].sum << endl;
        return;
    }
    int tm = (tl + tr) / 2;
    mod_range(2*v, tl, tm, l, min(r, tm), mod);
    mod_range(2*v + 1, tm + 1, tr, max(l, tm + 1), r, mod);
    seg[v] = seg[v].merge(seg[2*v], seg[2*v + 1]);
    return;
}

int sum_query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(tl == l && tr == r){
        return seg[v].sum;
    }
    int tm = (tl + tr) / 2;
    return sum_query(2*v, tl, tm, l, min(r, tm)) + sum_query(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
}
