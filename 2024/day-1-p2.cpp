#include <bits/stdc++.h>

using namespace std;


void solve(){
    multiset<int> left;
    map<int, int> right;
    int a, b;
    while(cin >> a >> b){
        left.insert(a);
        right[b]++;
    }
    long ans = 0;
    for(auto it = left.begin(); it != left.end(); it++){
        auto find = right.find(*it);
        if(find != right.end()){
            ans += *it * find->second;
        }
    }
    cout << ans << endl;
}


int main(){
    solve();
}