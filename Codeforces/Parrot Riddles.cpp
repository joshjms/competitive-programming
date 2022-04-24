#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int c, f;

void solve () {
    for(int i = 0; i < 15; i++) {
        cout << "? " << p[i] << "\n";
        cout.flush();

        string res; cin >> res;
        if(res == "yes") f = p[i], c++;
    }
    if(c > 1) {
        cout << "! composite\n";
        cout.flush();
        return;
    }
    if(c == 1 && f * f <= 100) {
        cout << "? " << f * f << "\n";
        cout.flush();

        string res; cin >> res;
        if(res == "yes"){
            cout << "! composite\n";
            cout.flush();
        }
        else {
            cout << "! prime\n";
            cout.flush();
        }
    }
    else {
        cout << "! prime\n";
        cout.flush();
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}