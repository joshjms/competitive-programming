#include <bits/stdc++.h>
#define ll long long
#define debug(x) cout << #x << " => " << x << "\n"
using namespace std;

ll a, b, c, n, ans;

ll fpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a)%n;
        a = (a*a)%n;
        b /= 2;
    }
    return ans % n;
}

int main() {
    cin >> a >> b >> c >> n;
    if(a == 0) cout << "0\n";
    else if(b == 0) cout << 1%n + 1 << "\n";
    else if(c == 0) cout << a%n + 1 << "\n";
    else {
        ans = a;
        for(ll i = 1; i <= c; i++) {
            ans = fpow(ans, b);
        }
    }
    cout << ans+1 << "\n";
}