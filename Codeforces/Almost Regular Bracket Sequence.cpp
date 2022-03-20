// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, maxi[1000005], mini[1000005], cur, ans;
string s;

void solve(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        maxi[i] = maxi[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        mini[i] = maxi[i];
    }
    for(int i = n - 1; i >= 1; i--)
        mini[i] = min(mini[i], mini[i + 1]);
    for(int i = 2; i <= n; i++)
        maxi[i] = max(maxi[i], maxi[i - 1]);
    for(int i = 1; i <= n; i++){
        if(cur < 0) break;
        if(s[i - 1] == '('){
            if(mini[n] == 2 && mini[i] >= 2)
                ans++;
            cur++;
        }
        else{
            if(mini[n] == -2 && mini[i] >= -2)
                ans++;
            cur--;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}