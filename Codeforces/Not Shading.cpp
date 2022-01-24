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

int n, m, r, c;
char arr[55][55];
bool rb, cb, aw;

void solve(){
    cin >> n >> m >> r >> c;
    rb = cb = 0;
    aw = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'B')
                aw = 0;
        }
    }
    if(arr[r][c] == 'B'){
        cout << 0 << "\n";
        return;
    }
    for(int i = 1; i <= m; i++)
        if(arr[r][i] == 'B')
            rb = 1;
    for(int i = 1; i <= n; i++)
        if(arr[i][c] == 'B')
            cb = 1;
    if(rb || cb){
        cout << 1 << "\n";
        return;
    }
    if(aw){
        cout << -1 << '\n';
        return;
    }
    cout << 2 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}