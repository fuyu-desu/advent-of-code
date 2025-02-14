#include <bits/stdc++.h>

using namespace std;


bool is_Stuck(vector<string> vec, tuple<int, int, int> loc, tuple<int, int, int> first, bool place){
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    map<tuple<int, int, int>, int> mp;
    set<pair<int, int>> answer;

    while(true){
        int locX = get<0>(loc) + dir[get<2>(loc)].first;
        int locY = get<1>(loc) + dir[get<2>(loc)].second;
        if(locX < 0 || locX >= vec.size() || locY < 0 || locY >= vec[0].size()){
            if(place){
                break;
            }
            return false;
        }

        if(mp[loc] == 1){
            return true;
        }else{
            mp[loc]++;
        }

        if(vec[locX][locY] != '#'){
            if(place){
                vector<string> temp = vec;
                temp[locX][locY] = '#';

                if(is_Stuck(temp, first, first, false)){
                    answer.insert(make_pair(locX, locY));
                    // cout << answer.size() << endl;
                }
            }
            get<0>(loc) = locX;
            get<1>(loc) = locY;
        }else{
            get<2>(loc) = (get<2>(loc) + 1) % 4;
        }
    }
    cout << answer.size() << endl;
    return true;
}


void solve(){
    vector<string> vec;
    string in;
    while(getline(cin, in)){
        vec.push_back(in);
    }
    
    pair<int, int> loc;
    for(int i = 0; i < vec.size(); i++){
        auto it = find(vec[i].begin(), vec[i].end(), '^');
        if(it != vec[i].end()){
            loc.first = i;
            loc.second = distance(vec[i].begin(), it);
        }
    }
    tuple first = make_tuple(loc.first, loc.second, 0);
    is_Stuck(vec, first, first, true);
}


int main(){
    solve();
}