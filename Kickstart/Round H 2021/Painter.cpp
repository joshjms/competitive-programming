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

int n, arr[100005][3], ans;
string p;

void solve(){
    cin >> n >> p;
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++){
        if(p[i] == 'R' || p[i] == 'O' || p[i] == 'P' || p[i] == 'A')
            arr[i + 1][0] = 1;
        if(p[i] == 'Y' || p[i] == 'O' || p[i] == 'G' || p[i] == 'A')
            arr[i + 1][1] = 1;
        if(p[i] == 'B' || p[i] == 'P' || p[i] == 'G' || p[i] == 'A')
            arr[i + 1][2] = 1;
    }
    ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            ans += (arr[j][i] > arr[j - 1][i] ? 1 : 0);
        }
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