void remove_duplicates(vector<int> &v){
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}