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

int q;
int t, x, y;
int lst[500005], nxt[500005];
vector <int> ans;

void solve(){
    cin >> q;
    fill(lst + 1, lst + 500005 + 1, -1);
    for(int i = 0; i < q; i++){
        cin >> t;
        if(t == 1){
            cin >> x;
            if(lst[x] != -1)
                nxt[lst[x]] = ans.size();
            lst[x] = ans.size();
            ans.pb(x);
        }
        else if(t == 2){
            cin >> x >> y;
            if(lst[x] == -1 || x == y) continue;
            ans[lst[x]] = y;
            if(lst[x] < lst[y] && lst[y] != -1)
                nxt[lst[x]] = lst[y];
            else if(lst[y] != -1) nxt[lst[y]] = lst[x];
            lst[y] = max(lst[y], lst[x]);
            lst[x] = -1;
        }
    }
    for(int i = ans.size(); i >= 0; i--){
        if(nxt[i])
            ans[i] = ans[nxt[i]];
    }
    for(auto i : ans)
        cout << i << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}