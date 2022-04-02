#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, k, arr [105];
vector <int> recipe [105];
int l, r, ans;

bool check(int x) {
    int need[n + 1];
    memset(need, 0, sizeof(need));
    need[n] = x;
    for(int i = n; i >= 1; i--) {
        need[i] -= arr[i];
        if(need[i] > 1e6) return false;
        if(need[i] > 0 && recipe[i].size() == 0) return false;
        if(need[i] > 0){
            for(auto j : recipe[i]){
                need[j] += need[i];
            }
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> k;
    for(int i = 1, f, m; i <= k; i++){
        cin >> f >> m;
        for(int j = 1, u; j <= m; j++){
            cin >> u;
            recipe[f].pb(u);
        }
    }
    l = 0, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid))
            l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}