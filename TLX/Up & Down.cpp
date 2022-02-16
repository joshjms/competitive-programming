#include <bits/stdc++.h>
using namespace std;

// AKARINNN!!!!!!!!! <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, arr[205][205], sum[2], at;

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1)
                at = (i + j) % 2;
            else sum[(i + j) % 2] += arr[i][j];
        }
    }
    if(sum[at] > sum[at ^ 1])
        cout << "NO\n";
    else{
        cout << "YES\n";
        cout << sum[at ^ 1] - sum[at] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}