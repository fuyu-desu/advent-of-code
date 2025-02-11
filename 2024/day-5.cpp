#include <bits/stdc++.h>

using namespace std;


void solve(){
    string in;
    vector<pair<int, int>> first;
    long ans = 0;

    while(getline(cin, in)){
        if(in.find('|') != string::npos){
            regex reg("(\\d+)\\|(\\d+)");
            sregex_iterator it(in.begin(), in.end(), reg);
            smatch match = *it;
            first.emplace_back(stoi(match[1].str()), stoi(match[2].str()));
        }else{
            stringstream ss(in);
            string str;
            unordered_map<int, int> mp;
            bool is = true;
            vector<int> second;

            int i = 0;
            while(getline(ss, str, ',')){
                int n = stoi(str);
                mp[n] = i;
                second.push_back(n);
                i++;
            }

            for(auto it : first){
                if(mp.count(it.first) && mp.count(it.second)){
                    if(mp[it.first] > mp[it.second]){
                        is = false;
                        break;
                    }
                }
            }
            if(is && !second.empty()){
                ans += second[mp.size() / 2];
            }
        }
    }
    cout << ans << endl;
}


int main(){
    solve();
}