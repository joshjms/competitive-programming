#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define debug(x)    cout << #x << " => " << x << "\n"
#define pb          push_back
#define fi          first
#define se          second
#define sp          " "

int n, dp[150005][2], ans;
pair <int,int> arr[150005];

struct line{
    int m, c;
    int f(int x){
        return m * x + c;
    }
    ld isect(line other){
        return (ld) (other.c - c) / (m - other.m);
    }
};

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].se >> arr[i].fi;
    sort(arr + 1, arr + n + 1, greater<pair<int,int>>());
    for(int i = 1; i <= n; i++){
        int price = arr[i].fi;
        int cost = price * i;
        vector <pair<int,int>> tmp;
        for(int j = i + 1; j <= n; j++){
            tmp.pb(arr[j]);
            swap(tmp.back().fi, tmp.back().se);
        }
        sort(tmp.begin(), tmp.end(), greater<pair<int,int>>());
        for(int j = 0; j < tmp.size(); j++){
            int price2 = tmp[j].fi;
            cost = max(cost, price * i + price2 * (j + 1));
        }
        ans = max(ans, cost);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}