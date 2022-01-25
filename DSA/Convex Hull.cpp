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

int n;
vector <pair<int,int>> pts, hull;

int area(pair<int,int> o, pair<int,int> p, pair<int,int> q){
    return (p.fi - o.fi) * (q.se - o.se) - (p.se - o.se) * (q.fi - o.fi);
}

void convex_hull(){
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if(n < 3){
        hull = pts;
        return;
    }
    for(int i = 0; i < n; i++){
        while(hull.size() > 1 && area(hull[hull.size() - 2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.pb(pts[i]);
    }
    int lower_hull = hull.size();
    for(int i = n - 2; i >= 0; i--){
        while(hull.size() > lower_hull && area(hull[hull.size() - 2], hull.back(), pts[i] <= 0))
            hull.pop_back();
        hull.pb(pts[i]);
    }
    hull.pop_back();
}

void solve(){
    cin >> n;
    pts.assign(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> pts[i].fi >> pts[i].se;
    convex_hull();
}  

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}