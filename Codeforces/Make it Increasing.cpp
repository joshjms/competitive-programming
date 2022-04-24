#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[5005], ans = 1e18 + 7;

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        int cost = 0;
        for(int j = i - 1, p = 0; j >= 1; j--) {
            int x = (p + arr[j]) / arr[j];
            cost += x;
            p = x * arr[j];
        }
        for(int j = i + 1, p = 0; j <= n; j++) {
            int x = (p + arr[j]) / arr[j];
            cost += x;
            p = x * arr[j];
        }
        ans = min(ans, cost);
    }
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}