#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, k;
ll dp[100005], ne[100005], arr[100005], p[100005];
int backtrack[205][100005];
int aqua;

vector <int> ans;

struct line{
    ll m, c, idx;
    ll f(int x){
        return m * x + c;
    }
    ld intersect(line l){
        return (ld) (c - l.c) / (l.m - m);
    }
};

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        p[i] = p[i - 1] + arr[i];
    }
    fill(dp, dp + n + 1, 0);
    for(int i = 0; i <= k; i++){
        deque <line> dq;
        dq.push_front({-p[i], dp[i], i});
        for(int j = i + 1; j <= n; j++){
            while(dq.size() > 1 && dq.back().f(p[n] - p[j]) <= dq[dq.size() - 2].f(p[n] - p[j]))
                dq.pop_back();
            ne[j] = p[j] * (p[n] - p[j]) + dq.back().f(p[n] - p[j]);
            backtrack[i][j] = dq.back().idx;
            line cur = {-p[j], dp[j], j};
            while(dq.size() > 1 && cur.intersect(dq[1]) >= dq[0].intersect(dq[1]))
                dq.pop_front();
            dq.push_front(cur);
        }
        for(int j = i + 1; j <= n; j++){
            dp[j] = ne[j];
            ne[j] = 0;
        }
    }
    cout << dp[n] << "\n";
    aqua = n;
    for(int i = k; i >= 1; i--){
        aqua = backtrack[i][aqua];
        ans.push_back(aqua);
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
}  

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}