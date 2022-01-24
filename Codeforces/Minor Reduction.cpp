#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int a, b;
string s;
bool exist;

void solve(){
    cin >> s;
    exist = 0;
    for(int i = s.size() - 2; i >= 0; i--){
        a = s[i] - '0' + s[i + 1] - '0';
        if(a >= 10){
            s[i] = a / 10 + '0';
            s[i + 1] = a % 10 + '0';
            exist = 1;
            break;
        }
    }
    if(exist){
        cout << s << "\n";
        return;
    }
    s[1] = s[0] - '0' + s[1] - '0' + '0';
    for(int i = 1; i < s.size(); i++)
        cout << s[i];
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}