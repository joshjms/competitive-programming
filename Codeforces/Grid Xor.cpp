#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, ans;
int cnt[1005][1005];

void solve(){
    ans = 0;
    cin >> n;
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            cnt[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1, x; j <= n; j++){
            cin >> x;
            if(!cnt[i - 1][j] && !cnt[i + 1][j] && !cnt[i][j - 1] && !cnt[i][j + 1]){
                cnt[i - 1][j] = cnt[i + 1][j] = cnt[i][j - 1] = cnt[i][j + 1] = 1;
                ans ^= x;
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}