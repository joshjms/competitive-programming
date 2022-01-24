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

int n, arr[55], tmp[55], ans;
map <int,int> mp;

void solve(){
    ans = 0;
    mp.clear();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += 1e6;
    }
    for(int i = 1; i <= n; i++){
        mp[arr[i]]++;
        if(mp[arr[i]] >= n / 2){
            cout << -1 << "\n";
            return;
        }
    }
    for(int i = 1, duplicates; i <= n; i++){
        mp.clear();
        duplicates = 0;
        for(int j = 1; j <= n; j++){
            tmp[j] = arr[j] - arr[i];
            if(tmp[j] == 0) duplicates++;
        }
        for(int j = 1; j <= n; j++){
            for(int k = 1; k * k <= tmp[j]; k++){
                if(tmp[j] % k == 0){
                    mp[k]++;
                    if(k * k != tmp[j]) mp[tmp[j] / k]++;
                    if(mp[k] >= n / 2 - duplicates) ans = max(ans, k);
                    if(mp[tmp[j] / k] >= n / 2 - duplicates) ans = max(ans, tmp[j] / k);
                }
            }
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