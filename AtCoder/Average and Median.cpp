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

int n, arr[100005];
ld mean;
int median;

void getmean(){
    ld l = 0, r = 1e9;
    while(r - l > err){
        ld md = (l + r) / 2;
        ld dp[n + 1], dp2[n + 1];
        fill(dp, dp + n + 1, 0);
        fill(dp2, dp2 + n + 1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i - 1], dp2[i - 1]) + (ld) arr[i] - md;
            dp2[i] = dp[i - 1];
        }
        if(max(dp[n], dp2[n]) >= 0)
            l = md + err, mean = md;
        else r = md - err;
    }
}

void getmedian(){
    int l = 0, r = 1e9;
    while(l <= r){
        int md = (l + r) / 2;
        int dp[n + 1], dp2[n + 1];
        fill(dp, dp + n + 1, 0);
        fill(dp2, dp2 + n + 1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i - 1], dp2[i - 1]) + (arr[i] >= md ? 1 : -1);
            dp2[i] = dp[i - 1];
        }
        if(max(dp[n], dp2[n]) > 0)
            l = md + 1, median = md;
        else r = md - 1;
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    getmean();
    getmedian();
    cout << mean << "\n" << median << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(5);
    solve();
}