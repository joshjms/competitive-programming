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

int k, cnt[200005], ans;

void solve(){
    cin >> k;
    for(int i = 1; i <= 200000; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                cnt[i]++;
                if(j * j != i) cnt[i]++;
            }
        }
    }
    for(int i = 1; i <= k; i++){
        ans += cnt[i] * floor(k / i);
    }
    cout << ans << "\n";
}

signed main(){
    solve();
}