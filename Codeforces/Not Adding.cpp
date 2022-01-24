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

int n, arr[1000005], cnt[1000005], ans;
bool exist[1000005];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        exist[arr[i]] = 1;
    }
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j += i){
            cnt[i] += exist[j];
        }
    }
    for(int i = 1000000; i >= 1; i--){
        bool take = (cnt[i] > 0 && !exist[i] ? 1 : 0);
        for(int j = 2 * i; j <= 1000000; j += i){
            if(cnt[j] >= cnt[i]){
                take = 0;
                break;
            }
        }
        ans += take;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}