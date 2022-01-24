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

int n, m, k, x[100005];

struct ladder{
    int floor_in, room_in, floor_out, room_out, hp, val;
};

ladder dp[100005];

vector <pair<int,int>> v[100005];

int cf;
bool cmp(pair<int,int> a, pair<int,int> b){
    int pos_a, pos_b;

    if(dp[a.fi].floor_in == cf) pos_a = dp[a.fi].room_in;
    else pos_a = dp[a.fi].room_out;

    if(dp[b.fi].floor_in == cf) pos_b = dp[b.fi].room_in;
    else pos_b = dp[b.fi].room_out;

    return pos_a < pos_b;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        v[i].clear();
    }
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1, a, b, c, d, h; i <= k; i++){
        cin >> a >> b >> c >> d >> h;
        dp[i] = {a, b, c, d, h, (int) 1e18 + 7};
        v[a].push_back({i, 0});
        v[c].push_back({i, 1});
    }
    dp[0] = {-1, -1, 1, 1, 0, 0};
    dp[k + 1] = {n, m, -1, -1, 0, (int) 1e18 + 7};
    v[1].push_back({0, 1});
    v[n].push_back({k + 1, 0});
    for(int i = 1; i <= n; i++){
        cf = i;
        sort(v[i].begin(), v[i].end(), cmp);
    }
    for(int i = 1, mini, prv; i <= n; i++){
        // left to right
        mini = (int) 1e18 + 7;
        prv = 0;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j].se == 0){
                // entry
                mini += x[i] * (dp[v[i][j].fi].room_in - prv);
                dp[v[i][j].fi].val = min(dp[v[i][j].fi].val, mini - dp[v[i][j].fi].hp);
                prv = dp[v[i][j].fi].room_in;
            }
            else{
                // exit
                mini += x[i] * (dp[v[i][j].fi].room_out - prv);
                mini = min(mini, dp[v[i][j].fi].val);
                prv = dp[v[i][j].fi].room_out;
            }
        }
        // right to left
        mini = (int) 1e18 + 7;
        prv = m + 1;
        for(int j = v[i].size() - 1; j >= 0 && v[i].size() > 0; j--){
            if(v[i][j].se == 0){
                // entry
                mini -= x[i] * (dp[v[i][j].fi].room_in - prv);
                dp[v[i][j].fi].val = min(dp[v[i][j].fi].val, mini - dp[v[i][j].fi].hp);
                prv = dp[v[i][j].fi].room_in;
            }
            else{
                // exit
                mini -= x[i] * (dp[v[i][j].fi].room_out - prv);
                mini = min(mini, dp[v[i][j].fi].val);
                prv = dp[v[i][j].fi].room_out;
            }
        }
    }
    if(dp[k + 1].val > 1e16)
        cout << "NO ESCAPE\n";
    else cout << dp[k + 1].val << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();
}