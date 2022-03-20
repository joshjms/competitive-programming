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
    // for l[i] == r[i]
    sort(arr + 1, arr + n + 1);
    for(int i = n; i >= 1; i--){
        // n - i people gets normal pricing
        dp[i][0] = i * arr[n - i + 1].fi;
        if(i != n && arr[n - i + 1].fi == arr[n - i].fi)
            dp[i][0] = dp[i + 1][0];
        ans = max(ans, dp[i][0]);
    }
    deque <line> dq;
    dq.push_front({-arr[1].fi, dp[n][0]});
    // assuming all gets normal pricing
    for(int i = n; i >= 1; i--){
        // i people from the normal pricing will get a premium pricing
        // price if i people has special pricing -> arr[n - i + 1]
        while(dq.size() > 1 && dq.back().f(i) <= dq[dq.size() - 2].f(i))
            dq.pop_back();
        dp[i][1] = dq.back().f(i) + i * arr[n - i + 1].se;
        ans = max(ans, dp[i][1]);
        line newLine = {-arr[n - i + 2].fi, dp[i - 1][0]};
        while(dq.size() > 1 && newLine.isect(dq[1]) >= dq[0].isect(dq[1]))
            dq.pop_front();
        dq.push_front(newLine);
    }
    cout << ans << "\n";
}

/*
3
1234 1234
1
1
*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}