// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, k, a[1005], mini, maxi;

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < k; i++)
        if(a[i] != 1) mini += a[i];
    reverse(a, a + n);
    for(int i = 0; i < k; i++)
        if(a[i] != 1) maxi += a[i];
    cout << mini << " " << maxi << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}