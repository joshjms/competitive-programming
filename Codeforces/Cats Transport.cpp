// AKARINNN!!!!!!!!! <3

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

struct line{
    int m, c;
    int f(int x){
        return m * x + c;
    }
    ld intersect(line v){
        return (ld) (c - v.c) / (v.m - m);
    }
};

int n, m, p, ans;
int d[100005], sd[100005], h[100005], t[100005];
int dp[105][100005];
int st[100005];
deque <line> dq;

void solve(){
    cin >> n >> m >> p;
    for(int i = 2; i <= n; i++){
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for(int i = 1; i <= m; i++){
        cin >> h[i] >> t[i];
        st[i] = t[i] - d[h[i]];
    }
    sort(st + 1, st + m + 1);
    // for(int i = 1; i <= m; i++)
    //     cout << st[i] << " ";
    // cout << "\n";
    for(int i = 1; i <= m; i++)
        sd[i] = sd[i - 1] + st[i];
    // for(int i = 1; i <= m; i++)
    //     cout << sd[i] << " ";
    // cout << "\n";
    dq.push_back({0, 0});
    for(int j = 1; j <= m; j++){
        while(dq.size() > 1 && dq.back().f(st[j]) > dq[dq.size() - 2].f(st[j]))
            dq.pop_back();
        dp[1][j] = dq.back().f(st[j]) + j * st[j] - sd[j];
    }
    for(int i = 2; i <= p; i++){
        while(!dq.empty()) dq.pop_back();
        dq.push_back({-(i - 1), dp[i - 1][i - 1] + sd[i - 1]});
        for(int j = i; j <= m; j++){
            while(dq.size() > 1 && dq.back().f(st[j]) >= dq[dq.size() - 2].f(st[j]))
                dq.pop_back();
            dp[i][j] = dq.back().f(st[j]) + j * st[j] - sd[j];
            line akari = {-j, dp[i - 1][j] + sd[j]};
            while(dq.size() > 1 && akari.intersect(dq[1]) <= dq[0].intersect(dq[1]))
                dq.pop_front();
            dq.push_front(akari);
        }
    }
    // for(int i = 1; i <= p; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    ans = 1e18 + 7;
    for(int i = 1; i <= p; i++)
        ans = min(ans, dp[i][m]);
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}