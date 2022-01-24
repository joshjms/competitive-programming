#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int n, arr[100005], cnt[100005];
int mod = 1e9 + 7, ans;

int modex(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for(int i = 1; i <= 100000; i++){
		(ans += modex(2, cnt[i]) - 1 + mod) %= mod;
	}
	cout << ans << "\n";
}