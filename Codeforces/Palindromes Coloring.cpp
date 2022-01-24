#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int tc;

int n, k, cnt[26], pairs, lone, ppg, ans, lo;
string s;

void solve(){
    memset(cnt, 0, sizeof(cnt));
    pairs = 0, lone = 0;

    cin >> n >> k >> s;
    for(auto i : s)
        cnt[i - 'a']++;
    for(int i = 0; i < 26; i++){
        pairs += cnt[i] / 2;
        lone += cnt[i] % 2;
    }
    ppg = pairs / k;
    lo = pairs % k;
    lone = min(lone + lo * 2, k);
    if(lone == k) ans = 2 * ppg + 1;
    else ans = 2 * ppg;

    cout << ans << "\n";
}

signed main(){
    cin >> tc;
    while(tc--) solve();
} 