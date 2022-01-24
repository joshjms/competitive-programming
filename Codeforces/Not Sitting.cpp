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

int n, m;
int initial, id;

void solve(){
    cin >> n >> m;
    int arr[n + 5][m + 5];
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            arr[i][j] = -1;
        }
    }
    id = n / 2 + m / 2;
    arr[(n + 1) / 2][(m + 1) / 2] = id;
    arr[(n + 1) / 2][m / 2 + 1] = id;
    arr[n / 2 + 1][(m + 1) / 2] = id;
    arr[n / 2 + 1][m / 2 + 1] = id;
    queue <pair<int,int>> bfs;
    bfs.push({(n + 1) / 2, (m + 1) / 2});
    bfs.push({n / 2 + 1, (m + 1) / 2});
    bfs.push({(n + 1) / 2, m / 2 + 1});
    bfs.push({n / 2 + 1, m / 2 + 1});
    while(!bfs.empty()){
        int x = bfs.front().fi;
        int y = bfs.front().se;
        bfs.pop();
        if(arr[x + 1][y] == -1){
            arr[x + 1][y] = arr[x][y] + 1;
            bfs.push({x + 1, y});
        }
        if(arr[x - 1][y] == -1){
            arr[x - 1][y] = arr[x][y] + 1;
            bfs.push({x - 1, y});
        }
        if(arr[x][y + 1] == -1){
            arr[x][y + 1] = arr[x][y] + 1;
            bfs.push({x, y + 1});
        }
        if(arr[x][y - 1] == -1){
            arr[x][y - 1] = arr[x][y] + 1;
            bfs.push({x, y - 1});
        }
    }
    vector <int> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans.push_back(arr[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}