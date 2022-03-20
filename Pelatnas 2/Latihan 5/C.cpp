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

int n, ans;
pair <int,int> pts[105];

int dist(int i, int j){
    return (pts[i].fi - pts[j].fi) * (pts[i].fi - pts[j].fi) + (pts[i].se - pts[j].se) * (pts[i].se - pts[j].se);
}

bool area(pair <int,int> a, pair <int,int> b, pair<int,int> c){
    int ar = a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
    if(ar == 0) return 0;
    return 1;
}

map <pair<int,pair<int,int>>, int> mp1;
map <pair<int,pair<int,int>>, int> mp2[105];
map <pair<int,pair<int,int>>, int> mp3[105][105];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> pts[i].fi >> pts[i].se;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                if(i == j || i == k || j == k) continue;
                int u = dist(i, j);
                int v = dist(i, k);
                int w = dist(j, k);
                if(area(pts[i], pts[j], pts[k]) == 0) continue;
                vector <int> peko = {u, v, w};
                sort(peko.begin(), peko.end());
                pair <int,pair<int,int>> tmp = {peko[0], {peko[1], peko[2]}};
                mp1[tmp]++;
                mp2[i][tmp]++;
                mp2[j][tmp]++;
                mp2[k][tmp]++;
                mp3[i][j][tmp]++;
                mp3[j][i][tmp]++;
                mp3[i][k][tmp]++;
                mp3[k][i][tmp]++;
                mp3[j][k][tmp]++;
                mp3[k][j][tmp]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                if(i == j || i == k || j == k) continue;
                int u = dist(i, j);
                int v = dist(i, k);
                int w = dist(j, k);
                if(area(pts[i], pts[j], pts[k]) == 0) continue;
                vector <int> peko = {u, v, w};
                sort(peko.begin(), peko.end());
                pair <int,pair<int,int>> tmp = {peko[0], {peko[1], peko[2]}};
                if(mp1[tmp] <= 1) continue;
                int add = max(0ll, (mp1[tmp] - 1)) - max(0ll, (mp2[i][tmp] - 1)) - max(0ll, (mp2[j][tmp] - 1)) - max(0ll, (mp2[k][tmp] - 1)) + max(0ll, (mp3[i][j][tmp] - 1)) + max(0ll, (mp3[i][k][tmp] - 1)) + max(0ll, (mp3[j][k][tmp] - 1));
                ans += add;
                if(u == v || v == w || u == w)
                    ans += add;
                if(u == v && v == w)
                    ans += add;
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