#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[100005], cnt[1005];
pair <int,int> ans;

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    for(int i = 1; i <= n; i++)
        cnt[arr[i]]++;
    for(int i = 1; i <= 1000; i++)
        ans = max(ans, {cnt[i], i});
    cout << ans.second << "\n"; // number
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}