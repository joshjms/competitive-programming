#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[200005], ans, tmp, s;
int p[500005], dp[200005];

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        p[arr[i]]++;
        s += arr[i];
    }
    for(int i = 1; i <= 500000; i++)
        p[i] += p[i - 1];
    for(int i = 1; i <= n; i++) {
        if(arr[i] == 1) {ans = s; break;}
        if(dp[arr[i]]) continue;
        tmp = 0;
        for(int j = arr[i]; j <= 200000; j += arr[i]) {
            tmp += j * (p[j + arr[i] - 1] - p[j - 1]);
        }
        ans = max(ans, tmp);
        dp[arr[i]] = 1;
    }
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}