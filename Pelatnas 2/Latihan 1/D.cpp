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

int n, m, k, a[100005], b[100005];
map <int,int> mp;
int akarin, aqua;
vector <int> v;

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        mp[b[i]]--;
    }
    for(auto i : mp) if(i.se != 0)
        v.pb(i.se);
    if(v.size() == 0){
        cout << "TIDAK\n";
        return;
    }
    if(v.back() > 0 || n > m){
        cout << "BISA\n";
        return;
    }
    int lol = v.size();
    for(int i = lol - 1; i >= 0; i--){
        akarin += v[i];
        if(akarin > 0){
            cout << "BISA\n";
            return;
        }
    }
    cout << "TIDAK\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}