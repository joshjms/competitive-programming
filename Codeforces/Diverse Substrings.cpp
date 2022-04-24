#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int d, ans[30];
string s, t;

void solve () {
    cin >> s;
    t = s;
    sort(t.begin(), t.end());
    for(int i = 0; i < t.size(); i++)
        if(i == 0 || t[i] != t[i - 1])
            d++;
    cout << d << "\n";
    for(int nd = 1; nd <= d; nd++) {
        int l[2], r;
        int cnt[26][2];
        memset(cnt, 0, sizeof(cnt));
        int cur[2] = {0, 0};
        for(l[0] = 0, l[1] = 0, r = 0; r < s.size(); r++) {
            if(cnt[s[r] - 'a'][0] == 0) cur[0]++;
            if(cnt[s[r] - 'a'][1] == 0) cur[1]++;
            cnt[s[r] - 'a'][0]++;
            cnt[s[r] - 'a'][1]++;
            if(cur[0] < nd) continue;
            while(cur[0] > nd && l[0] <= r) {
                cnt[s[l[0]] - 'a'][0]--;
                if(cnt[s[l[0]] - 'a'][0] == 0) cur[0]--;
                l[0]++;
            }
            while(cur[1] >= nd && l[1] <= r) {
                cnt[s[l[1]] - 'a'][1]--;
                if(cnt[s[l[1]] - 'a'][1] == 0) cur[1]--;
                l[1]++;
            }
            ans[nd] += l[1] - l[0];
        }
    }
    for(int i = 1; i <= d; i++) 
        cout << ans[i] << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}