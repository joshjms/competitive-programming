#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int ntc;

int e, w;
int arr[15][5];
vector <int> v[5][5][5];
int dp[15][105];

void solve () {
    cin >> e >> w;
    for(int i = 1; i <= e; i++) {
        for(int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i < 100; i++)
        dp[0][i] = 1e9 + 7;
    for(int ex = 1; ex <= e + 1; ex++) {
        for(int i = 0; i < 100; i++)
            dp[ex][i] = 1e9 + 7;
        queue <int> q;
        debug(arr[ex - 1][0]);
        debug(arr[ex - 1][1]);
        debug(arr[ex - 1][2]);
        for(auto i : v[arr[ex - 1][0]][arr[ex - 1][1]][arr[ex - 1][2]]) {
            debug(i);
            dp[ex][i] = dp[ex - 1][i];
            q.push(i);
        }
        while(!q.empty()) {
            int mask = q.front();
            q.pop();
            if(mask < (1ll << 4)) {
                for(int i = 1; i <= w; i++) {
                    int newMask = mask * 4 + i;
                    // debug(newMask);
                    if(dp[ex][newMask] > dp[ex][mask]) {
                        dp[ex][newMask] = dp[ex][mask] + 1;
                        q.push(newMask);
                    }
                }
            }
            int newMask = mask / 4;
            if(dp[ex][newMask] > dp[ex][mask]) {
                dp[ex][newMask] = dp[ex][mask] + 1;
                q.push(newMask);
            }
        }
    }
    for(int i = 0; i <= e + 1; i++) {
        for(int j = 0; j < 64; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
        cout << "\n";
    }
    cout << dp[e + 1][0] << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < (1ll << 6); i++) {
        int mask = i;
        int arr[] = {0, 0, 0, 0};
        while(mask) {
            arr[(mask % 4)]++;
            mask /= 4;
        }
        v[arr[1]][arr[2]][arr[3]].pb(i);
    }

    int TC; cin >> TC;
    for(ntc = 1; ntc <= TC; ntc ++) {
        cout << "Case #" << ntc << ":\n";
        solve (); 
    }
}