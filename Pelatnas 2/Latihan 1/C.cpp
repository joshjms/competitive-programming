// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, pre[500005];
vector <pair<int,int>> peko, s, t;

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        pair <int,int> akarin;
        cin >> akarin.fi >> akarin.se;
        if(s.size() && s.back().fi == akarin.fi){
            s[s.size() - 1].se += akarin.se;
        }
        else s.pb(akarin);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        pair <int,int> akarin;
        cin >> akarin.fi >> akarin.se;
        if(t.size() && t.back().fi == akarin.fi){
            t[t.size() - 1].se += akarin.se;
        }
        else t.pb(akarin);
    }
    n = s.size();
    m = t.size();
    if(m == 1){
        int akarin = 0;
        for(auto i : s){
            if(i.fi == t[0].fi)
                akarin += max(0ll, i.se - t[0].se + 1);
        }
        cout << akarin << "\n";
        return;
    }
    if(m == 2){
        int akarin = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i].fi == t[0].fi){
                if(s[i].se >= t[0].se && s[i + 1].se >= t[1].se)
                    akarin++;
            }
        }
        cout << akarin << "\n";
        return;
    }
    vector <pair<int,int>> akari;
    for(int i = 1; i < m - 1; i++)
        akari.pb(t[i]);
    akari.pb({69, -1});
    for(auto i : s)
        akari.pb(i);
    pre[0] = 0;
    for(int i = 1; i < akari.size(); i++){
        int akarin = pre[i - 1];
        while(akarin > 0 && akari[i] != akari[akarin])
            akarin = pre[akarin - 1];
        if(akari[i] == akari[akarin])
            akarin++;
        pre[i] = akarin;
    }
    pair <int,int> yuru = t[0];
    pair <int,int> yuri = t[m - 1];
    int akarin = 0;
    // for(auto i : akari){
    //     cout << "{" << i.fi << ", " << i.se << "}\n";
    // }
    // cout << "\n";
    // debug(m);
    // cout << yuru.fi << " " << yuru.se << "\n";
    // cout << yuri.fi << " " << yuri.se << "\n";
    for(int i = m - 1; i < akari.size() - 1; i++){
        // cout << "{" << akari[i].fi << ", " << akari[i].se << "}\n";
        // debug(pre[i]);
        if(pre[i] == m - 2){
            if(akari[i - m + 2].fi == yuru.fi && akari[i - m + 2].se >= yuru.se && akari[i + 1].fi == yuri.fi && akari[i + 1].se >= yuri.se)
                akarin++;
        }
    }
    cout << akarin << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}