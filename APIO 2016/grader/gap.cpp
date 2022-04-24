#include "gap.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

ll t, n, ans;
ll l, r, mn, mx, x;
vector <ll> vect;

ll T1() {
    l = 0, r = 1e18;
    while(vect.size() < n) {
        MinMax(l, r, &mn, &mx);
        vect.pb(mn);
        if(mn != mx) vect.pb(mx);
        l = mn + 1;
        r = mx - 1;
    }
    sort(vect.begin(), vect.end());
    for(int i = 0; i < vect.size() - 1; i++)
        ans = max(ans, vect[i + 1] - vect[i]);
	return ans;
}

ll T2() {
    MinMax(0, 1e18, &l, &r);
    x = (r - l + n) / (n - 1);
    for(; l <= r; l += x) {
        MinMax(l, l + x - 1, &mn, &mx);
        if(mn != -1) vect.pb(mn);
        if(mn != mx && mx != -1) vect.pb(mx);
    }
    sort(vect.begin(), vect.end());
    for(int i = 0; i < vect.size() - 1; i++)
        ans = max(ans, vect[i + 1] - vect[i]);
    return ans;
}

ll findGap(int T, int N) {
    t = T, n = N;
    if(t == 1) return T1();
    else return T2();
}
