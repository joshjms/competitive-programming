#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int tc;

int n, l, r, md, hp, add, inc, lvl, ans;

int query(int c){
    add += c;
    cout << "+ " << c << "\n";
    cout.flush();

    int res; cin >> res;
    return res;
}

void solve(){
    cin >> n;
    // let's consider this the room hopping problem
    l = 1, r = n;
    while(l < r){
        // debug(l);
        // debug(r);
        md = (l + r + 1) / 2;
        hp = md + add;
        inc = n - hp % n;
        // if >= md + inc maka next level, else same level
        int nlvl = query(inc);
        if(nlvl > lvl)
            l = md;
        else r = md - 1;
        lvl = nlvl;
    }
    cout << "! " << l + add << "\n";
    cout.flush();
}

signed main(){
    solve();
} 