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

int n, arr[3005], ne[3005], akari;
int fr[3005], bk[3005];

void solve(){
    cin >> n;
    akari = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    fill(fr + 1, fr + n + 1, 0);
    for(int i = 1; i <= n; i++){
        fill(bk + 1, bk + n + 1, 0);
        for(int j = n; j > i; j--){
            akari += fr[arr[j]] * bk[arr[i]];
            bk[arr[j]]++;
        }
        fr[arr[i]]++;
    }
    cout << akari << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}