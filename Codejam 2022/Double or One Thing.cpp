#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n;
string s;
vector <pair<char,int>> v;

void solve () {
    cin >> s;
    n = s.size();
    v.clear();
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[i] != s[i - 1]) {
            v.pb({s[i], 1});
        }
        else v.back().se++;
    }
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i].fi < v[i + 1].fi) {
            v[i].se *= 2;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].se; j++) {
            cout << v[i].fi;
        }
    }
    cout << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC; cin >> TC;
    for(int ntc = 1; ntc <= TC; ntc ++) {
        cout << "Case #" << ntc << ": ";
        solve (); 
    }
}