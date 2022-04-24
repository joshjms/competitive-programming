#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[200005], ans, sum;
int pd[200005];
int max_l[2];

void solve () {
    cin >> n;
    ans = 0;
    sum = 0;
    max_l[0] = max_l[1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(i % 2) sum += arr[i];
    }
    for(int i = 1; i <= n; i++) 
        pd[i] = pd[i - 1] + (i % 2 ? -arr[i] : arr[i]);
    for(int i = 1; i <= n; i++) {
        ans = max(ans, pd[i] - max_l[i % 2]);
        max_l[i % 2] = min(max_l[i % 2], pd[i]);
    }
    cout << sum + ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--) solve ();
}