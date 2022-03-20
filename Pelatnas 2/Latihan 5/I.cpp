// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, t[55], cost[55][5], ans;
string tags;
int DP[51][16][16][16][16][16];

int mini[5], maxi[5];

void solve(){
    cin >> n;
    for(int i = 0, t; i < n; i++){
        cin >> t;
        while(t--){
            cin >> tags;
            if(tags == "dp")
                cost[i][0] = 1;
            else if(tags == "graph")
                cost[i][1] = 1;
            else if(tags == "mathgeo")
                cost[i][2] = 1;
            else if(tags == "ds")
                cost[i][3] = 1;
            else if(tags == "adhoc")
                cost[i][4] = 1;
        }
    }
    for(int i = 0; i < 5; i++)
        cin >> mini[i] >> maxi[i];
    DP[0][0][0][0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int dp = 0; dp <= maxi[0]; dp++){
            for(int graph = 0; graph <= maxi[1]; graph++){
                for(int mathgeo = 0; mathgeo <= maxi[2]; mathgeo++){
                    for(int ds = 0; ds <= maxi[3]; ds++){
                        for(int adhoc = 0; adhoc <= maxi[4]; adhoc++){
                            if(DP[i][dp][graph][mathgeo][ds][adhoc] == 0) continue;
                            DP[i + 1][dp][graph][mathgeo][ds][adhoc] += DP[i][dp][graph][mathgeo][ds][adhoc];
                            if(dp + cost[i][0] <= maxi[0] && graph + cost[i][1] <= maxi[1] && mathgeo + cost[i][2] <= maxi[2] && ds + cost[i][3] <= maxi[3] && adhoc + cost[i][4] <= maxi[4]){
                                DP[i + 1][dp + cost[i][0]][graph + cost[i][1]][mathgeo + cost[i][2]][ds + cost[i][3]][adhoc + cost[i][4]] += DP[i][dp][graph][mathgeo][ds][adhoc];
                            }
                        }
                    }
                }
            }
        }
    }
    for(int dp = mini[0]; dp <= maxi[0]; dp++){
        for(int graph = mini[1]; graph <= maxi[1]; graph++){
            for(int mathgeo = mini[2]; mathgeo <= maxi[2]; mathgeo++){
                for(int ds = mini[3]; ds <= maxi[3]; ds++){
                    for(int adhoc = mini[4]; adhoc <= maxi[4]; adhoc++){
                        if(dp + graph + mathgeo + ds + adhoc > 0){
                            ans += DP[n][dp][graph][mathgeo][ds][adhoc];
                        }
                    }
                }
            }
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