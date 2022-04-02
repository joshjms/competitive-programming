#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

struct item {
    int key, priority;
    item * l, * r;
    item () { }
    item (int key) : key(key), prior(rand()), l(NULL), r(NULL) { }
};

void split (item * t, int key, item * &l, item * &r) {
    if(!t) l = r = NULL;
    else if(t -> key <= key)
        split(t -> r, key, t -> r, r), l = t;
    else split(t -> l, key, l, t -> l), r = t;
}

void merge

void solve() {

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}