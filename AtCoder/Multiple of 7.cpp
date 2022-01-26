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

int n;
vector <int> v;
string ans;

int modex(int a, int b){
    int res = 1;
    while(b){
        if(b % 2) res = (res * a) % 7;
        a = (a * a) % 7;
        b /= 2;
    }
    return res;
}

int binser(int x){
    int l = 1, r = 1e6, ret = -1;
    while(l <= r){
        int md = (l + r) / 2;
        if(md * (md + 1) / 2 <= x)
            l = md + 1, ret = md;
        else r = md - 1;
    }
    return ret;
}

void solve(){
    cin >> n;
    while(n){
        v.pb(binser(n));
        n -= v.back() * (v.back() + 1) / 2;
    }
    for(auto i : v){
        for(int j = i; j--;)
            ans += '7';
        for(int j = 1, ok, sum; j <= 9; j++){
            ans.pb(char(j + '0'));
            sum = 0, ok = 1;
            for(int k = ans.size() - 1, p = 0; k >= 0; k--, p++){
                (sum += modex(10, p) * (ans[k] - '0')) %= 7;
                if(sum == 0){
                    ok = 0;
                    break;
                }
            }
            if(ok) break;
            ans.pop_back();
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}