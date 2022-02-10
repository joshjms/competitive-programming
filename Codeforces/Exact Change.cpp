#include <bits/stdc++.h>
using namespace std;

// Template by YuriEnthusiast 2022 <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, arr[105], ans, m;

bool poss(int a, int b, int c, int v){
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if((v - (i + 2 * j)) % 3 == 0 && (v - (i + 2 * j)) / 3 <= c && (v - (i + 2 * j)) / 3 >= 0){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n;
    m = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    ans = (m + 2) / 3 + 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i + 2 * j + 3 * ((m + 2) / 3 - i - j) < m) continue;
            bool ok = 1;
            for(int k = 1; k <= n; k++){
                if(!poss(i, j, ((m + 2) / 3 - i - j), arr[k]))
                    ok = 0;
            }
            if(ok){
                cout << ans - 1 << "\n";
                return;
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