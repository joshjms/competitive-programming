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

int n, arr[300005], ans;
map <vector<int>, int> mp;

int minpr[10000005];

void sieve(){
    for(int i = 2; i <= 10000000; i++){
        if(minpr[i] == 0){
            minpr[i] = i;
            for(int j = i * i; j <= 10000000; j += i){
                if(minpr[j] == 0) minpr[j] = i;
            }
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sieve();
    for(int i = 1; i <= n; i++){
        vector <int> prfx;
        while(arr[i] != 1){
            int f = minpr[arr[i]];
            prfx.pb(f);
            while(arr[i] % f == 0)
                arr[i] /= f;
        }
        // for(auto i : prfx)
        //     cout << i << " ";
        // cout << "\n";
        mp[prfx]++;
    }
    for(auto i : mp)
        ans += (i.se * (i.se - 1)) / 2;
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}