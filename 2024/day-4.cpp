#include <bits/stdc++.h>

using namespace std;


void solve(){
    string in;
    vector<string> vec;
    while(getline(cin, in)){
        vec.push_back(in);
    }
    int numRow = vec.size();
    int numCol = vec[0].size();
    long ans = 0;
    vector<pair<int, int>> pos = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {-1, 0}, {1, 0}};
    string s = "XMAS";
    
    for(int i = 0; i < numRow; i++){
        for(int j = 0; j < numCol; j++){
            if(vec[i][j] == 'X'){
                int row = i;
                int col = j;
                for(auto it : pos){
                    int newRow = row;
                    int newCol = col;
                    bool flag = true;
                    for(int k = 1; k < 4; k++){
                        newRow += it.first;
                        newCol += it.second;
                        if(newRow < 0 || newRow >= numRow || newCol < 0 || newCol >= numCol || vec[newRow][newCol] != s[k]){
                            break;
                        }
                        if(k == 3){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    solve();
}