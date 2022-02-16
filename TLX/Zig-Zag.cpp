#include <bits/stdc++.h>
using namespace std;

// AKARINNN!!!!!!!!! <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, arr[10005], sz, odds, evens, ps[10005], idx;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sz += arr[i];
        ps[i] = ps[i - 1] + arr[i];
    }
    odds = (sz + 1) / 2;
    evens = sz - odds;
    for(int i = 1; i <= n; i++){
        if(ps[i] == evens){
            cout << "YES\n";
            return;
        }
        if(ps[i] > evens){
            idx = i;
            break;
        }
    }
    int akari = ps[idx - 1] + 1;
    int akari_pos = akari * 2;

    int chinatsu = ps[idx] - evens;
    int chinatsu_pos = chinatsu * 2 - 1;

    if(akari_pos - chinatsu_pos > 1){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}