#include <bits/stdc++.h>

using namespace std;

int main(){
    multiset<int> left, right;
    int a, b;
    while(cin >> a >> b){
        left.insert(a);
        right.insert(b);
    }
    long ans = 0;
    for(auto ll = left.begin(), rr = right.begin(); ll != left.end(); ll++, rr++){
        ans += abs(*ll - *rr);
    }
    cout << ans << endl;
}