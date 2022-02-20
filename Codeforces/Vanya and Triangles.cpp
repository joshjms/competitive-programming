// AKARINNN!!!!!!!!! <3

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

int n, ans, fact[2005];

struct pt{
    int x, y;
} arr[2005];

pair<pair<int, int>, pair<int,int>> getline(pt a, pt b){
    if(a.x == b.x){
        return {{1e18, 1e18}, {a.x, a.x}};
    }
    int mn = b.y - a.y, md = b.x - a.x, g = __gcd(mn, md);
    mn /= g;
    md /= g;
    int cn = a.y * md - a.x * mn;
    int cd = md;
    g = __gcd(cn, cd);
    cn /= g;
    cd /= g;
    return {{mn, md}, {cn, cd}};
}

map <pair<pair<int,int>,pair<int,int>>, int> mp[2005], akari;

int c2(int p){
    return p * (p - 1) / 2;
}

int c3(int p){
    return (p * (p - 1) * (p - 2)) / 6;
}

void solve(){
    cin >> n;
    ans = c3(n);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            pair<pair<int,int>,pair<int,int>> p = getline(arr[i], arr[j]);
            mp[i][p]++;
        }
        for(auto j : mp[i])
            ans -= c2(j.se);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}