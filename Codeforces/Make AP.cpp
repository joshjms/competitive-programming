#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int tc;

int A, B, C;

void solve(){
    cin >> A >> B >> C;
    if(2 * B - C > 0 && (2 * B - C) % A == 0){
        cout << "YES\n";
        return;
    }
    if(2 * B - A > 0 && (2 * B - A) % C == 0){
        cout << "YES\n";
        return;
    }
    if((A + C) % 2 == 0 && ((A + C) / 2) % B == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

signed main(){
    cin >> tc;
    while(tc--) solve();
} 