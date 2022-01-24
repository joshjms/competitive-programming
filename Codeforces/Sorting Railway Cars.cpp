#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int n, arr[100005], dp[100005], maxi;

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		dp[arr[i]] = dp[arr[i] - 1] + 1;
		maxi = max(maxi, dp[arr[i]]);
	}
	cout << n - maxi << "\n";
}