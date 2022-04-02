#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define debug(x) cout << #x << " => " << x << "\n"

#define fi first
#define se second

const int mod = 1e9 + 7;

int n;
pair <int,int> arr[500005];
vector <int> v;
int ans;
int dp[5005][5005];

// int bit[500005];

// void upd(int idx, int d){
//     for(; idx <= n; idx += (idx & -idx))
//         bit[idx] += d;
// }

// void sum(int idx){
//     int res = 0;
//     for(; idx >= 1; idx -= (idx & -idx))
//         res += bit[idx];
//     return res;
// }

// void sum(int l, int r){
//     return sum(r) - sum(l - 1);
// }

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].se;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].fi;
    // NOTE THEY SWAPPED!!!
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}