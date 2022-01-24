#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, arr[200005], ans, cnt[200005];
map <int,int> theme;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        theme[arr[i]]++;
    }   
    for(auto i : theme)
        cnt[i.se]++;
    for(int i = 200000; i >= 1; i--)
        cnt[i] += cnt[i + 1];
    for(int i = 200000, u, v, w; i >= 1; i--){
        u = i, v = cnt[i], w = 0;
        while(u && v){
            w += u;
            u = (u % 2 == 0 ? u / 2 : 0);
            v += cnt[u] - cnt[u * 2] - 1;
        }
        ans = max(ans, w);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}