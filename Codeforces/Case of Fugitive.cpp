#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int n, m;
int ans[200005];
pair <int,int> arr[200005], bridge[200005];
priority_queue <pair<int,int>> p, q;

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].fi >> arr[i].se;
    for(int i = 1; i <= m; i++){
        cin >> bridge[i].fi;
        bridge[i].se = i;
    }
    if(m < n - 1){
        cout << "No\n";
        return;
    }
    for(int i = 1; i < n; i++){
        p.push({-(arr[i + 1].fi - arr[i].se), i});
    }
    sort(bridge + 1, bridge + m + 1);
    for(int i = 1; i <= m; i++){
        while(!p.empty() && -p.top().fi <= bridge[i].fi){
            q.push({-(arr[p.top().se + 1].se - arr[p.top().se].fi), p.top().se});
            p.pop();
        }
        if(q.empty()) continue;
        if(!q.empty() && -q.top().fi < bridge[i].fi){
            cout << "No\n";
            return;
        }
        ans[q.top().se] = bridge[i].se;
        q.pop();
    }
    for(int i = 1; i < n; i++){
        if(ans[i] == 0){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for(int i = 1; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}