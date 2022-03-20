// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, arr[5005], pm[5005], sm[5005];
bool vis[5005];
int ans[15005], cnt[15005];

void solve(){
    cin >> n;
    pm[0] = 1;
    for(int i = 1; i <= n + 1; i++){
        cin >> arr[i];
        pm[i] = (pm[i - 1] * arr[i]) % mod;
    }
    for(int i = n; i >= 0; i--){
        cnt[0] = pm[i];
        debug(pm[i]);
        for(int j = 0; j <= 2 * n; j++)
            cout << cnt[j] << " ";
        cout << "\n";
        int mul = 1;
        for(int j = i, steps = 0; j <= n; j++, steps++){
            for(int k = 0; k <= 2 * n; k++){
                if(k - steps >= 0)
                    (ans[k] += (cnt[k - steps] * mul) % mod) %= mod;
            }
            if(j == i) (mul *= (arr[j + 1] - 1)) %= mod;
            else (mul *= arr[j + 1]) %= mod;
        }
        for(int j = 2 * n; j >= 1; j--)
            cnt[j] = cnt[j - 1];
        for(int j = 1; j <= 2 * n; j++)
            cout << ans[j] << "\n";
    }
    for(int i = 1; i <= 2 * n; i++)
        cout << ans[i] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}