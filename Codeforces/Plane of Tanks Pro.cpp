#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, a;
string s;
map <string,int> mp;

int sum[1005];
ld p;

vector <pair<string,string>> ans;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s >> a;
        mp[s] = max(mp[s], a);
    }
    for(auto i : mp)
        sum[i.se]++;
    for(int i = 1; i <= 1000; i++)
        sum[i] += sum[i - 1];
    cout << mp.size() << "\n";
    for(auto i : mp){
        cout << i.fi << " ";
        p = (ld) sum[i.se] / (ld) mp.size();

        if(p < 0.5) cout << "noob\n";
        else if(p < 0.8 - err) cout << "random\n";
        else if(p < 0.9 - err) cout << "average\n";
        else if(p < 0.99 - err) cout << "hardcore\n";
        else cout << "pro\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    solve();
}