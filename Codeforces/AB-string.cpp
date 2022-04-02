#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, ans;
string s;
vector <int> v;

void solve (){
    cin >> n >> s;
    ans = n * (n - 1) / 2;
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[i] != s[i - 1])
            v.pb(1);
        else v.back()++;
    }
    for(int i = 0; i < v.size(); i++) {
        if(i > 0) ans -= v[i - 1];
        if(i < v.size() - 1) ans -= v[i + 1];
    }
    ans += v.size() - 1;
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}