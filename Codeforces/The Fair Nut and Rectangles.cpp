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

struct rect{
    int p, q, a;
} arr[1000005];

bool cmp(rect a, rect b){
    return a.p < b.p;
}

struct line{
    int m, c;
    int f(int x){
        return m * x + c;
    }
    ld intersect(line l){
        return (ld) (c - l.c) / (l.m - m);
    }
};

deque <line> dq;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].p >> arr[i].q >> arr[i].a;
    dq.push_front({0, 0});
    sort(arr + 1, arr + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        while(dq.size() > 1 && dq.back().f(arr[i].q) <= dq[dq.size() - 2].f(arr[i].q))
            dq.pop_back();
        int f = dq.back().f(arr[i].q) + arr[i].p * arr[i].q - arr[i].a;
        ans = max(ans, f);
        line cur = {-arr[i].p, f};
        while(dq.size() > 1 && cur.intersect(dq[0]) >= dq[0].intersect(dq[1]))
            dq.pop_front();
        dq.push_front(cur);
    }
    cout << ans << "\n";
}  

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}