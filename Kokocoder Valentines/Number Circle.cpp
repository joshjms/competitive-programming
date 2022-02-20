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

int n, arr[100005];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    if(arr[n] >= arr[n - 1] + arr[n - 2])
        cout << "NO\n";
    else{
        cout << "YES\n";
        swap(arr[n], arr[n - 1]);
        for(int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}