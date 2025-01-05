#include <bits/stdc++.h>

using namespace std;


bool is_safe(vector<int> vec){
    bool dif = true, asc = true, desc = true;
    for(int i = 0; i < vec.size() - 1; i++){
        int n = vec[i] - vec[i + 1];

        if(abs(n) < 1 || abs(n) > 3){
            return false;
        }
        if(n > 0){
            asc = false;
        }
        if(n < 0){
            desc = false;
        }
    }
    return asc || desc;
}


void solve(){
    string in;
    long ans = 0;

    while(getline(cin, in)){
        vector<int> vec;
        stringstream ss(in);
        int n;

        while(ss >> n){
            vec.push_back(n);
        }
        if(is_safe(vec)){
            ans++;
        }else{
            for(int i = 0; i < vec.size(); i++){
                vector <int> temp = vec;
                temp.erase(temp.begin() + i);
                if(is_safe(temp)){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}


int main(){
    solve();
}