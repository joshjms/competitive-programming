// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int k, s, n;
set <int> st;

void solve(){
    st.clear();
    cin >> k >> s >> n;
    k -= s;
    for(int i = 0; i < (1ll << n); i++){
        int mask = i;
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(mask & (1ll << j))
                sum += s * (j + 1);
            else sum -= s * (j + 1);
        }
        int cnt = 2 * __builtin_popcount(mask) - n;
        st.insert(cnt * k + sum);
    }
    if(floor(log10(st.size())) == 0)
        cout << 0;
    cout << st.size() << " ";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 10; i++){
        for(int j = -10; j <= 10; j++){
            k = j, s = 1, n = i;
            solve();
        }
        cout << "\n";
    }
}