#include <bits/stdc++.h>
using namespace std;

// Template by YuriEnthusiast 2022 <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, l[100005], r[100005], ans;
vector <pair<int,int>> v;

int bit[100005];

void upd(int idx, int val){
    for(; idx <= m; idx += (idx & (-idx))){
        bit[idx] = max(bit[idx], val);
    }
}

int query(int idx){
    int res = 0;
    for(; idx > 0; idx -= (idx & (-idx))){
        res = max(res, bit[idx]);
    }
    return res;
}

pair<int,int> arr[100005];
int dp[100005][2];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        v.pb({l[i], 1});
        v.pb({r[i] + 1, -1});
    }
    sort(v.begin(), v.end());
    for(int i = 1, ii = 0, sum = 0; i <= m; i++){
        for(; ii < v.size() && v[ii].fi <= i; ii++)
            sum += v[ii].se;
        arr[i] = {sum, i};
    }
    sort(arr + 1, arr + m + 1, [&](pair<int,int> x, pair<int,int> y){
        if(x.fi < y.fi) return true;
        else if(x.fi > y.fi) return false;
        else{
            if(x.se < y.se) return true;
            else return false;
        }
    });
    memset(bit, 0, sizeof(bit));
    for(int i = 1; i <= m; i++){
        dp[arr[i].se][0] = query(arr[i].se) + 1;
        upd(arr[i].se, dp[arr[i].se][0]);
    }
    sort(arr + 1, arr + m + 1, [&](pair<int,int> x, pair<int,int> y){
        if(x.fi < y.fi) return true;
        else if(x.fi > y.fi) return false;
        else{
            if(x.se > y.se) return true;
            else return false;
        }
    });
    memset(bit, 0, sizeof(bit));
    for(int i = 1; i <= m; i++){
        dp[arr[i].se][1] = query(m - arr[i].se + 1) + 1;
        upd(m - arr[i].se + 1, dp[arr[i].se][1]);
    }
    for(int i = 1; i <= m; i++){
        ans = max(ans, dp[i][0] + dp[i][1] - 1);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}