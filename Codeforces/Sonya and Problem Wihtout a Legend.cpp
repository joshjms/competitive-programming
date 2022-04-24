#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, a[3005];
int ans;

priority_queue <int> pq;

// int n, arr[3005];

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        pq.push(a[i]);
        pq.push(a[i]);
        ans += pq.top() - a[i];
        pq.pop();
    }
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}