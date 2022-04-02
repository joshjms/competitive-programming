#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[100005], ans, x;

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    ans = n;
    sort(arr + 1, arr + n + 1);
    x = 1;
    for(int i = 1; i <= n; i++)
        if(arr[i] < x)
            ans--;
        else x++;
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++) {
        cout << "Case #" << ntc << ": ";
        solve ();
    }
}