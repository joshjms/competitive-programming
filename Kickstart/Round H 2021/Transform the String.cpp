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

int ans, mini;
string s, f;
bool exist[26];

void solve(){
    ans = 0;
    cin >> s >> f;
    fill(exist, exist + 26, 0);
    for(auto i : f)
        exist[i - 'a'] = 1;
    for(auto i : s){
        mini = 1e18 + 7;
        for(int j = 0; j < 26; j++) if(exist[j]){
            int u = min((int) i - 'a', j), v = max((int) i - 'a', j);
            mini = min(mini, min(v - u, 26 - (v - u)));
        }
        ans += mini;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++){
        cout << "Case #" << ntc << ": ";
        solve();
    }
}