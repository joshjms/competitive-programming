#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define NL '\n'

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vi a(1 << n);
    map<int, int> pos, val;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
        pos[a[i]] = i;
        val[i] = a[i];
    }
    sort(all(a));
    int j = 0;
    vector<pii> ans;
    for (auto i : a) {
        int pa = pos[i];
        int va = i;
        int dest = pa ^ j;
        // cout << i << " " << pa << " " << dest << NL;
        while (pos[i] != j) {
            // cout << j << " " << pos[i] << NL;
            for (int k = 0; k < n; k++) {
                if (dest >> k & 1) {
                    pa = pos[i];
                    int x = pos[i] ^ (1 << k);
                    int y = val[x];
                    pos[i] = x;
                    pos[y] = pa;
                    val[pa] = y;
                    val[x] = va;
                    ans.pb({min(pa, x), max(pa, x)});
                }
            }
        }
        j++;
    }
    cout << sz(ans) << NL;
    for (auto [x, y] : ans) cout << x << " " << y << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
