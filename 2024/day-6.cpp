#include <bits/stdc++.h>

using namespace std;


void solve(){
    vector<string> vec;
    string in;
    while(getline(cin, in)){
        vec.push_back(in);
    }
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    pair<int, int> loc;
    for(int i = 0; i < vec.size(); i++){
        auto it = find(vec[i].begin(), vec[i].end(), '^');
        if(it != vec[i].end()){
            loc.first = i;
            loc.second = distance(vec[i].begin(), it);
        }
    }
    int face = 0;
    long ans = 1;
    
    vec[loc.first][loc.second] = 'x';

    while(true){
        int dirX = dir[face].first;
        int dirY = dir[face].second;
        int a = loc.first + dirX;
        int b = loc.second + dirY;

        if(a < 0 || a >= vec.size() || b < 0 || b >= vec[0].size()){
            break;
        }

        if(vec[a][b] != '#'){
            if(vec[a][b] != 'x'){
                vec[a][b] = 'x';
                ans++;
            }
            loc.first += dirX;
            loc.second += dirY;
        }else{
            face = (face + 1) % 4;
        }
    }
    cout << ans << endl;
}


int main(){
    solve();
}