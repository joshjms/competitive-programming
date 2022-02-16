// AKARINNN!!!!!!!!! <3

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

int n, arr[200005], q, x[200005];
vector <pair<int,int>> v;

void f(int val, int m){
    if(val % 2 == 0)
        f(val / 2, m * 2);
    else v.pb({m, val});
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> q;
    for(int i = 1; i <= q; i++)
        cin >> x[i];
    for(int i = 1; i <= n; i++){
        f(arr[i], 1);
        if(v.size() > 1)
            v[v.size() - 1].fi += v[v.size() - 2].fi;
    }
    for(int i = 1; i <= q; i++){
        pair<int,int> kyouko = make_pair(x[i], -1);
        int akari = lower_bound(v.begin(), v.end(), kyouko) - v.begin();
        cout << v[akari].se << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}