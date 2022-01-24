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

void solve(){
    int n, ans = 0;
    cin >> n;
    int k[n + 1], h[n + 1], s[n + 1];
    k[0] = h[0] = s[0] = -1e9-7;
    for(int i = 1; i <= n; i++)
        cin >> k[i];
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++){
        s[i] = k[i] - h[i] + 1;
        for(int j = i - 1; j >= 1; j--){
            if(s[i] <= k[j] && s[i] >= s[j]){
                h[i] = h[j] + (k[i] - k[j]);
                s[i] = s[j];
                break;
            }
        }
    }
    vector <pair<int,int>> vect;
    for(int i = 1; i <= n; i++){
        while(!vect.empty() && vect.back().fi >= s[i])
            vect.pop_back();
        vect.push_back({s[i], h[i]});
    }
    for(auto i : vect){
        ans += i.se * (i.se + 1) / 2;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}