#include <bits/stdc++.h>

using namespace std;


void solve(){
    regex reg("(do\\(\\)|don't\\(\\))|mul\\((\\d{1,3}),(\\d{1,3})\\)");
    string in;
    long ans = 0;
    bool isDo = true;

    while(getline(cin, in)){
        sregex_iterator it(in.begin(), in.end(), reg);
        sregex_iterator last;

        while(it != last){
            smatch match = *it;
            if(match.str(1) == "do()"){
                isDo = true;
            }else if(match.str(1) == "don't()"){
                isDo = false;
            }else if(isDo){
                int a = stoi(match.str(2));
                int b = stoi(match.str(3));
                ans += a * b;
            }
            it++;
        }
    }
    cout << ans << endl;
}


int main(){
    solve();
}