#include <bits/stdc++.h>
using namespace std;

// AKARINNN!!!!!!!!! <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int k, l;
int n, m, a[100005], b[100005], c[100005], d[100005];
int extract_date[100005];

vector <pair<int,pair<int,int>>> ls1, ls2;
vector <pair<int,int>> v;

void solve(){
    cin >> k >> l;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        ls1.pb({a[i], {0, i}});
        ls2.pb({a[i], {1, i}});
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> c[i] >> d[i];
        ls1.pb({c[i], {1, i}});
        ls2.pb({c[i], {0, i}});
    }
    if(k <= l){
        cout << 0 << "\n";
        return;
    }
    for(int i = 1; i <= m; i++)
        extract_date[i] = 1e18 + 7;
    sort(ls1.begin(), ls1.end());
    sort(ls2.begin(), ls2.end());
    reverse(ls2.begin(), ls2.end());
    int u = -1e18 + 7;
    for(auto i : ls1){
        if(i.se.fi == 0){
            if(b[i.se.se] == 1){
                u = i.fi;
            }
        }
        else{
            extract_date[i.se.se] = min(extract_date[i.se.se], i.fi - u);
        }
    }
    u = 2e18 + 7;
    for(auto i : ls2){
        if(i.se.fi == 1){
            if(b[i.se.se] == -1){
                u = i.fi;
            }
        }
        else{
            extract_date[i.se.se] = min(extract_date[i.se.se], u - i.fi);
        }
    }
    /*
    You can skip at most K - L flowers :V
    */
    for(int i = 1; i <= m; i++){
        v.pb({extract_date[i], i});
    }
    v.pb({k, 0});
    sort(v.begin(), v.end());
    priority_queue <int> pq;
    int prv = 0, akari = 0;
    for(auto i : v){
        l -= i.fi - prv;
        prv = i.fi;
        while(!pq.empty() && l < 0){
            akari -= pq.top();
            l++;
            pq.pop();
        }
        if(l < 0){
            cout << -1 << "\n";
            return;
        }
        if(i.se == 0){
            cout << akari << "\n";
            return;
        }
        pq.push(-d[i.se]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

