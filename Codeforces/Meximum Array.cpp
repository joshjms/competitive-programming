#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, arr[200005], cur_r, next_r;
vector <int> pos[200005];
vector <int> ans;
int last;

void solve(){
    ans.clear();
    cin >> n;
    for(int i = 0; i <= n; i++){
        pos[i].clear();
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]].pb(i);
    }
    cur_r = 0, next_r = 0;
    while(cur_r < n){
        if(pos[0].empty()) break;
        if(pos[0].back() <= cur_r) break;
        last = 0;
        for(int i = 0; i <= n; i++){
            if(pos[i].empty()) break;
            if(pos[i].back() <= cur_r) break;
            int idx = upper_bound(pos[i].begin(), pos[i].end(), cur_r) - pos[i].begin();
            next_r = max(next_r, pos[i][idx]);
            last++;
        }
        ans.pb(last);
        cur_r = next_r;
    }
    for(int i = cur_r + 1; i <= n; i++)
        ans.push_back(0);
    cout << ans.size() << "\n";
    for(auto i : ans)
        cout << i << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}