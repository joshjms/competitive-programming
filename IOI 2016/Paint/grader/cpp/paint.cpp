#include "paint.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, k, c[105], p[200005];
string s;
bool dp[200005][105][2];
pair <pair<int,int>,int> bt[200005][105][2];
bool ans[200005][2];
bool vis[200005][105][2];
string ret;

void backtrack(int i, int j, int l) {
    if(!l) {
        if(bt[i][j][l] != make_pair(make_pair(-1, -1), -1)) {
            ans[i][0] = true;
            if(vis[bt[i][j][0].fi.fi][bt[i][j][0].fi.se][bt[i][j][0].se] == false)
                backtrack(bt[i][j][0].fi.fi, bt[i][j][0].fi.se, bt[i][j][0].se);
        }
    }
    if(l) {
        if(i == 3 && j == 1 && l == 1) {
            debug(bt[i][j][1].fi.fi + 1);
        }
        if(bt[i][j][1] != make_pair(make_pair(-1, -1), -1)) {
            for(int ii = bt[i][j][1].fi.fi + 1; ii <= i; ii++)
                ans[ii][1] = true;
            if(vis[bt[i][j][1].fi.fi][bt[i][j][1].fi.se][bt[i][j][1].se] == false)
                backtrack(bt[i][j][1].fi.fi, bt[i][j][1].fi.se, bt[i][j][1].se);
        }
    }
}

string solve_puzzle(string S, vector <int> C) {
    n = S.size(); k = C.size(); s = '3' + S;
    for(int i = 0; i < k; i++)
        c[i + 1] = C[i];
    for(int i = 1; i <= n; i++) 
        p[i] = p[i - 1] + (s[i] != '_' ? 1 : 0);
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= k; j++) {
            for(int l = 0; l < 2; l++) {
                bt[i][j][l] = {{-1, -1}, -1};
            }
        }
    }
    dp[0][0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int l = 0; l < 2; l++) {
                if(!dp[i][j][l]) continue;
                // create c[j + 1] 'X'
                if(l == 0 && j < k && i + c[j + 1] <= n && p[i + c[j + 1]] - p[i] == c[j + 1]) {
                    dp[i + c[j + 1]][j + 1][1] = true;
                    bt[i + c[j + 1]][j + 1][1] = {{i, j}, l};
                }
                // use 1 '_'
                if(s[i + 1] != 'X') {
                    dp[i + 1][j][0] = true;
                    bt[i + 1][j][0] = {{i, j}, l};
                }
            }
        }
    }
    // for(int i = 0; i <= n + 1; i++) {
    //     for(int j = 0; j <= k; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    backtrack(n, k, 0);
    backtrack(n, k, 1);
    for(int i = 1; i <= n; i++) {
        if(ans[i][0] && ans[i][1]) ret += '?';
        else if(ans[i][0]) ret += '_';
        else ret += 'X';
    }
    return ret;
}

const int S_MAX_LEN = 200 * 1000;
char buf[S_MAX_LEN + 1];

int main() {
    assert(1 == scanf("%s", buf));
    std::string s = buf;
    int c_len;
    assert(1 == scanf("%d", &c_len));
    std::vector<int> c(c_len);
    for (int i = 0; i < c_len; i++) {
        assert(1 == scanf("%d", &c[i]));
    }
    std::string ans = solve_puzzle(s, c);


    printf("%s\n", ans.data());
    return 0;
}