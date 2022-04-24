#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n;
vector <int> ans;

int digitSum(int x) {
    int res = 0;
    while(x) { res += x % 10; x /= 10; }
    return res;
}

void solve () {
    cin >> n;
    for(int i = n; i >= max(0ll, n - 100); i--) {
        if(i + digitSum(i) == n)
            ans.pb(i);
    }
    reverse(ans.begin(), ans.end()); // ascending order
    cout << ans.size() << "\n";
    for(int i : ans)
        cout << i << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}