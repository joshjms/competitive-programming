// AKARINNN!!!!!!!!! <3

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

int n, a[200005], b[200005], akari;
priority_queue <pair<int,int>> pq;

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        pq.push({b[i], i});
    }
    while(!pq.empty()){
        int kyouko = pq.top().fi;
        int yui = pq.top().se;
        pq.pop();
        if(a[yui] == kyouko) continue;
        if(a[yui] > kyouko) break;
        int chinatsu = b[(yui - 1 + n) % n] + b[(yui + 1) % n];
        if(b[yui] < chinatsu) continue;
        int owo = max(1ll, (b[yui] - a[yui]) / chinatsu);
        akari += owo;
        b[yui] -= owo * chinatsu;
        pq.push({b[yui], yui});
    }
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]){
            cout << -1 << "\n";
            return;
        }
    cout << akari << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}