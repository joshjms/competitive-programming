#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

string s, ans;
int q;
int ps[200005][3];

void solve() {
    cin >> s >> q;
    for(int i = 1; i <= s.size(); i++){
        if(s[i - 1] == 'C') ps[i][0]++;
        if(s[i - 1] == 'O') ps[i][1]++;
        if(s[i - 1] == 'W') ps[i][2]++;
        for(int j = 0; j < 3; j++){
            ps[i][j] += ps[i - 1][j];
        }
    }
    // for(int i = 1; i <= s.size(); i++){
    //     for(int j = 0; j < 3; j++){
    //         cout << ps[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int l, r; q--;){
        cin >> l >> r;
        int a = ps[r][0] - ps[l - 1][0];
        int b = ps[r][1] - ps[l - 1][1];
        int c = ps[r][2] - ps[l - 1][2];
        if(b % 2 != c % 2)
            ans += 'N';
        else{
            if((a + (b % 2)) % 2)
                ans += 'Y';
            else ans += 'N';
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}