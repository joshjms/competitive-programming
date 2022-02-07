#include <bits/stdc++.h>
using namespace std;

// Template by YuriEnthusiast 2022 <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, k, ans;
char c[8][8];
vector<vector<char>> arr;
set <vector<vector<char>>> st;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1)
        return true;
    return false;
}

void dfs(int c){
    if(st.count(arr)) return;
    st.insert(arr);
    if(c == k){
        ans++;
        return;
    }
    vector <pair<int,int>> nexts;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                for(int ii = 0; ii < 4; ii++){
                    if(valid(i + dx[ii], j + dy[ii])){
                        arr[i][j] = 1;
                        dfs(c + 1);
                        arr[i][j] = 0;
                    }
                }
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    arr.assign(n, vector<char>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            if(c[i][j] == '#') arr[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                arr[i][j] = 1;
                dfs(1);
                arr[i][j] = 0;
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