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

int n, arr[200005], mini[505][505], ans;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++){
        mini[i][i] = arr[i];
        for(int j = i - 1; j >= 1; j--){
            mini[i][j] = min(mini[i][j + 1], arr[j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int cnt = 1, maxi = 0;
            for(int k = i; k <= j; k++){
                maxi = max(maxi, arr[k]);
                if(k == j) continue;
                if(mini[j][k + 1] >= maxi)
                    cnt++;
            }
            // debug(i);
            // debug(j);
            // debug(cnt);
            ans += cnt;
        }
    }
    cout << ans + n << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}