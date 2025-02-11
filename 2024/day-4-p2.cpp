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

    vector<pair<int, int>> pos = {{1, 1}, {1, -1}};

    for(int i = 1; i < numRow - 1; i ++){
        for(int j = 1; j < numCol - 1; j++){
            if(vec[i][j] == 'A'){
                bool first = false;
                bool second = false;

                for(auto it: pos){
                    int row = i + it.first, col = j + it.second;
                    int oppRow = i - it.first, oppCol = j - it.second;
                    if(vec[row][col] == 'M' && vec[oppRow][oppCol] == 'S' || vec[row][col] == 'S' && vec[oppRow][oppCol] == 'M'){
                        if(first){
                            second = true;
                        }
                        first = true;
                    }
                }
                if(first && second){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}


int main(){
    solve();
}