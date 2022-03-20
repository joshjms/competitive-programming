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

int n, h[100005], w[100005];
int dp[100005];

struct line{
    mutable int m, c, p;
    bool operator<(const line& o) const { return m < o.m; }
	bool operator<(int x) const { return p < x; }
};

struct line_container : multiset <line, less<>> {
    int div(int a, int b){
        if((a > 0) ^ (b > 0) >= 0)
            return a / b;
        return - abs(a) / abs(b);
    }
    bool intersect(iterator x, iterator y){
        if(y == end()){
            x -> p = 1e18 + 7;
            return 0;
        }
        if(x -> m == y -> m){
            if(x -> c > y -> c) x -> p = 1e18 + 7;
            else x -> p = -1e18 - 7;
        }
        else x -> p = div(y -> c - x -> c, x -> m - y -> m);
        return x -> p >= y -> p;
    }
    void add(int m, int c){
        auto z = insert({-m, -c, 0});
        auto y = z;
        auto x = y;
        z++;
        while(intersect(y, z))
            z = erase(z);
        if(x != begin() && intersect(--x, y)){
            y = erase(y);
            intersect(x, y);
            return;
        }
        y = x;
        while(y != begin() && (--x) -> p >= y -> p){
            y = erase(y);
            intersect(x, y);
            y = x;
        }
    }
    int f(int x){
        assert(!empty());
        auto l = *lower_bound(x);
        return -l.m * x - l.c;
    }
} cht;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        w[i] += w[i - 1];
    }
    cht.add(-2 * h[1], h[1] * h[1] - w[1]);
    for(int i = 2; i <= n; i++){
        dp[i] = cht.f(h[i]) + w[i - 1] + h[i] * h[i];
        cht.add(-2 * h[i], dp[i] + h[i] * h[i] - w[i]);
    }
    // for(int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}