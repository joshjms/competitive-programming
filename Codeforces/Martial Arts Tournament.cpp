#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, arr[200005], pref[200005], ans;

void solve(){
    ans = 1e18 + 7;
    cin >> n;
    for(int i = 1; i <= n; i++){
        pref[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pref[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        pref[i] += pref[i - 1];
    }
    for(int i = 0, rem; i <= n; i++){
        rem = n - i;
        for(int j = 0; (1ll << j) <= 1e6; j++){
            int l = i, r = n, index = -1;
            while(l <= r){
                int md = (l + r) / 2;
                if(pref[md] - pref[i] <= (1ll << j))
                    l = md + 1, index = md;
                else r = md - 1;
            }
            int a = pref[i], b = pref[index] - pref[i], c = pref[n] - pref[index];
            int u = 1, v = 1, w = 1;
            while(a > u) u *= 2;
            while(b > v) v *= 2;
            while(c > w) w *= 2;
            ans = min(ans, u - a + v - b + w - c);
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}