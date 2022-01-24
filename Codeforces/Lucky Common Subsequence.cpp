#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

struct index{
    int i, j, k, take;
};

int dp[105][105][105];
index backtrack[105][105][105];
string s, t, v, ans;

string cmp(string a, string b){
    if(a.size() >= b.size()) return a;
    return b;
}

string dfs(int i, int j, int k){
    if(i == 0 || j == 0) return "";
    if(backtrack[i][j][k].take == 1)
        return dfs(backtrack[i][j][k].i, backtrack[i][j][k].j, backtrack[i][j][k].k) + s[i];
    else return dfs(backtrack[i][j][k].i, backtrack[i][j][k].j, backtrack[i][j][k].k);
}

int prefix_function(string s){
    int n = s.size();
    vector <int> pi(n);
    // pi[0] = 0
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n - 1];
}

signed main(){
    cin >> s >> t >> v;
    s = '0' + s;
    t = '0' + t;
    for(int i = 1; i < s.size(); i++){
        for(int j = 1; j < t.size(); j++){
            for(int k = 0; k < v.size(); k++){
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                if(dp[i - 1][j][k] >= dp[i][j - 1][k])
                    backtrack[i][j][k] = {i - 1, j, k, 0};
                else backtrack[i][j][k] = {i, j - 1, k, 0};
            }
            if(s[i] != t[j]) continue;
            for(int k = 0; k < v.size(); k++){
                string subseq = dfs(i - 1, j - 1, k) + s[i];
                int pi = prefix_function(v + '#' + subseq);
                if(dp[i - 1][j - 1][k] + 1 > dp[i][j][pi])
                    backtrack[i][j][pi] = {i - 1, j - 1, k, 1};
                dp[i][j][pi] = max(dp[i][j][pi], dp[i - 1][j - 1][k] + 1);
            }
        }
    }
    for(int i = 0; i < v.size(); i++){
        ans = cmp(ans, dfs(s.size() - 1, t.size() - 1, i));
    }
    if(ans == "") ans = "0";
    cout << ans << "\n";
}