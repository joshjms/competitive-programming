#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[200005];
bool ok = true;

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] -= (n - i + 1);
    }
    sort(arr + 1, arr + n + 1, greater<int>());
    for(int i = 1; i <= n; i++)
        arr[i] += i;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i + 1])
            ok = false;
    }
    if(!ok) cout << ":(\n";
    else {
        for(int i = n; i >= 1; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}