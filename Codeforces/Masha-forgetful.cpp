#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int tc;

int n, m;
string s, phones[1005];

struct segment{
    int l, r, i;
};

vector <segment> dp[1005];
bool valid[1005];

void solve(){
    map <string,pair<bool,segment>> mp;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        dp[i].clear();
        valid[i] = 0;
    }
    valid[0] = 1;

    for(int i = 1; i <= n; i++){
        cin >> phones[i];
        for(int j = 0; j < m - 1; j++){
            string tmp = phones[i].substr(j, 2);
            mp[tmp] = {1, {j, j + 1, i}};
        }
        for(int j = 0; j < m - 2; j++){
            string tmp = phones[i].substr(j, 3);
            mp[tmp] = {1, {j, j + 2, i}};
        }
    }

    cin >> s;

    s = "s" + s;
    for(int i = 1; i <= m; i++){
        // take 2
        if(i > 1 && valid[i - 2] == 1){
            if(mp[s.substr(i - 1, 2)].fi == true){
                valid[i] = true;
                dp[i] = dp[i - 2];
                dp[i].push_back(mp[s.substr(i - 1, 2)].se);
            }
        }
        
        // take 3

        if(i > 2 && valid[i - 3] == 1){
            if(mp[s.substr(i - 2, 3)].fi == true){
                valid[i] = true;
                dp[i] = dp[i - 3];
                dp[i].push_back(mp[s.substr(i - 2, 3)].se);
            }
        }
    }

    // for(int i = 0; i <= m; i++){
    //     debug(i);
    //     if(valid[i]){
    //         for(auto j : dp[i]){
    //             cout << j.l + 1 << sp << j.r + 1 << sp << j.i << "\n";
    //         }
    //         cout << "\n";
    //     }
    //     else cout << "-1\n\n";
    // }

    if(valid[m] == 0){
        cout << -1 << "\n";
        return;
    }
    cout << dp[m].size() << "\n";
    for(auto i : dp[m]){
        cout << i.l + 1 << sp << i.r + 1 << sp << i.i << "\n";
    }
}

signed main(){
    cin >> tc;
    while(tc--) solve();
} 