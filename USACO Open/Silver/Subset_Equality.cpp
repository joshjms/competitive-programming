#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

string s, t;
int q;
string qry, ans;

vector <int> pos[2][20];
int itr[20];

set <int> ban;
set <int> dislike[20];
int twin[100005], maxi[20];

void solve() {
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++)
        pos[0][s[i] - 'a'].pb(i);
    for(int i = 0; i < t.size(); i++)
        pos[1][t[i] - 'a'].pb(i);
    memset(twin, -1, sizeof(twin));
    for(int i = 0; i < 18; i++){
        if(pos[0][i].size() != pos[1][i].size())
            ban.insert(i);
        else{
            for(int j = 0; j < pos[0][i].size(); j++)
                twin[pos[0][i][j]] = pos[1][i][j];
        }
    }
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 18; j++){
            if(maxi[j] > twin[i]){
                dislike[s[i] - 'a'].insert(j);
                dislike[j].insert(s[i] - 'a');
            }
        }
        maxi[s[i] - 'a'] = twin[i];
    }
    // for(int i = 0; i < 18; i++){
    //     for(auto j : dislike[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }
    cin >> q;
    for(; q--;){
        cin >> qry;
        bool Y = true;
        for(int i = 0; i < qry.size(); i++)
            if(ban.count(qry[i] - 'a'))
                Y = false;
        for(int i = 0; i < qry.size(); i++){
            for(int j = i + 1; j < qry.size(); j++){
                if(dislike[qry[i] - 'a'].count(qry[j] - 'a'))
                    Y = false;
            }
        }
        if(Y) ans += 'Y';
        else ans += 'N';
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}