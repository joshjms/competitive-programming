#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 9;

pair <int,int> arr[3];
int miny = 1e18, maxy = -1e18;

vector<pair<pair<int,int>,pair<int,int>>> ans;

void solve () {
    miny = 1e18, maxy = -1e18;
    for(int i = 0; i < 3; i++) {
        cin >> arr[i].fi >> arr[i].se;
        miny = min(miny, arr[i].se);
        maxy = max(maxy, arr[i].se);
    }
    sort(arr, arr + 3);
    ans.pb({{arr[1].fi, miny}, {arr[1].fi, maxy}});
    if(arr[0].fi != arr[1].fi)
        ans.pb({{arr[0].fi, arr[0].se}, {arr[1].fi, arr[0].se}});
    if(arr[2].fi != arr[1].fi)
        ans.pb({{arr[2].fi, arr[2].se}, {arr[1].fi, arr[2].se}});
    cout << ans.size() << "\n";
    for(auto i : ans){
        cout << i.fi.fi << " " << i.fi.se << " " << i.se.fi << " " << i.se.se << "\n";
    }
    ans.clear();
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}