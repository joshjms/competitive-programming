#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, ans;
pair <int,int> arr[100005];
int dp[100005];

int segment_tree[400005];

void upd(int idx, int l, int r, int u, int v) {
    if(l == r) {
        segment_tree[idx] = v;
        return;
    }
    int mid = (l + r) / 2;
    int left_child = idx * 2;
    int right_child = idx * 2 + 1;
    if(u <= mid) upd(left_child, l, mid, u, v);
    else upd(right_child, mid + 1, r, u, v);
    segment_tree[idx] = max(segment_tree[idx * 2], segment_tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y) {
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return segment_tree[idx];
    int mid = (l + r) / 2;
    return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++) {
        dp[arr[i].se] = query(1, 1, n, 1, arr[i].se) + 1;
        upd(1, 1, n, arr[i].se, dp[arr[i].se]);
    }
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}