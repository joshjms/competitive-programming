// AKARINNN!!!!!!!!! <3

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

int n;
int g[2005][2005];
queue <int> q;

int node = 3;
int cnt[32];
pair <int,int> par;

int akari = 0;

void connect(pair<int,int> a, pair<int,int> b){
    g[a.fi][b.fi] = 1;
    if(a.se != -1) g[a.se][b.fi] = 1;
    if(b.se != -1) g[a.fi][b.se] = 1;
    if(a.se != -1 && b.se != -1) g[a.se][b.se] = 1;
}

void solve(){
    cin >> n;
    par = {1, -1};
    for(int i = 0; i < 30; i++){
        if(n & (1ll << i)){
            pair <int,int> prv = par;
            for(int j = i; j < 30; j++){
                connect(prv, {node, -1});
                prv = {node, -1};
                node++;
            }
            connect(prv, {2, -1});
        }
        connect(par, {node, node + 1});
        par = {node, node + 1};
        node += 2;
        cnt[i] += 2;
    }
    cout << 1000 << "\n";
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            if(g[i][j] || g[j][i])
                cout << 'Y';
            else cout << 'N';
        }
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}