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

int n, ans;
pair <int,int> arr[100005];
set <int> st, add;

void solve(){
    cin >> n;
    for(int i = 1; i < (1ll << n); i++){
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr + 1, arr + (1ll << n));
    st.insert(0);
    for(int i = 1; i < (1ll << n); i++){
        if(st.count(arr[i].se)) continue;
        ans += arr[i].fi;
        add.clear();
        for(auto j : st) add.insert(arr[i].se ^ j);
        for(auto j : add) st.insert(j);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}