// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, arr[305][305];

bool clockwise(int val, int steps, int x, int y, bool print){
    if(print == true){
        cout << x << " " << y << "\n";
    }
    if(val < 0) return false;
    if(steps == n * m) return true;
    if(x == 1){
        if(y == m)
            return clockwise(val + arr[x + 1][y], steps + 1, x + 1, y, print);
        else return clockwise(val + arr[x][y + 1], steps + 1, x, y + 1, print);
    }
    else{
        if(y == 1)
            return clockwise(val + arr[x - 1][y], steps + 1, x - 1, y, print);
        else return clockwise(val + arr[x][y - 1], steps + 1, x, y - 1, print);
    }
}

bool cclockwise(int val, int steps, int x, int y, bool print){
    if(print == true){
        cout << x << " " << y << "\n";
    }
    if(val < 0) return false;
    if(steps == n * m) return true;
    if(x == 1){
        if(y == 1)
            return cclockwise(val + arr[x + 1][y], steps + 1, x + 1, y, print);
        else return cclockwise(val + arr[x][y - 1], steps + 1, x, y - 1, print);
    }
    else{
        if(y == m)
            return cclockwise(val + arr[x - 1][y], steps + 1, x - 1, y, print);
        else return cclockwise(val + arr[x][y + 1], steps + 1, x, y + 1, print);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    if(n % 2 == 0){
        for(int i = n; i >= 1; i--){
            cout << i << " " << 1 << "\n";
        }
        for(int i = 1; i <= n; i++){
            if(i % 2 == 1){
                for(int j = 2; j <= m; j++)
                    cout << i << " " << j << "\n";
            }
            else{
                for(int j = m; j >= 2; j--)
                    cout << i << " " << j << "\n";
            }
        }
    }
    else if(m % 2 == 0){
        for(int i = m; i >= 1; i--){
            cout << 1 << " " << i << "\n";
        }
        for(int i = 1; i <= m; i++){
            if(i % 2 == 1){
                for(int j = 2; j <= n; j++)
                    cout << j << " " << i << "\n";
            }
            else{
                for(int j = n; j >= 2; j--)
                    cout << j << " " << i << "\n";
            }
        }
    }
    else{
        cout << -1 << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}