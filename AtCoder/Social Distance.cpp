#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m, arr[100005], i, j;

void solve () {
    cin >> n >> m;
    for(int x = 0; x < n; x++)
        cin >> arr[x];
    if(n > m) {cout << "NO\n"; return;}
    sort(arr, arr + n, greater<int>());
    for(i = arr[0], j = 0; i < m && j < n; i += arr[j] + 1, j++){
        // debug(i);
        // debug(j);
    }
    if(j < n) cout << "NO\n";
    else cout << "YES\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while(tc--)
        solve ();
}