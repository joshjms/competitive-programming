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

int r, c, ans;
char arr[55][55];

int dist(char a, char b){
    int u = a - 'A';
    int v = b - 'A';
    return min((u - v + 26) % 26, (v - u + 26) % 26);
}

void solve(){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= (r + 1) / 2; i++){
        for(int j = 1; j <= (c + 1) / 2; j++){
            int x = i, y = j, rx = r - i + 1, ry = c - j + 1;
            int mini = 1e18 + 7;
            for(int k = 0; k < 26; k++){
                char cr = char(k + 'A');
                int cost = 0;
                cost += dist(arr[x][y], cr);
                if(x != rx)
                    cost += dist(arr[rx][y], cr);
                if(y != ry)
                    cost += dist(arr[x][ry], cr);
                if(x != rx && y != ry)
                    cost += dist(arr[rx][ry], cr);
                mini = min(mini, cost);
            }
            ans += mini;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}