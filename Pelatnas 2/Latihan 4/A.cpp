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

int n, m;
char g[1005][1005];
vector <int> pos[1005], pos2[1005];

int sl[1005][1005];
int su[1005][1005];

int minlast = 1e18 + 7;

pair<vector<int>,int> shvert, shhori;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == '*'){
                pos[i].pb(j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(pos[i].empty()) continue;
        int akarin = 0;
        int lst = pos[i].back();
        for(int j = 0; j < m; j++){
            if(j > pos[i][akarin])
                lst = pos[i][akarin];
            sl[i][j] = (lst - j + m) % m;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}