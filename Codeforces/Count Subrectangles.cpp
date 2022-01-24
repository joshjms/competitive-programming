#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int n, m, k, a[40005], b[40005], c;
vector <int> factors;
int cnt[40005], ans;

signed main(){
	cin >> n >> m >> k;
	for(int i = 1; i * i <= k; i++){
		if(k % i == 0){
			factors.push_back(i);
			if(i * i != k) factors.push_back(k / i);
		}
	}
	sort(factors.begin(), factors.end());
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]) c++;
		else if(c){
			for(int i = 0; i < factors.size() && factors[i] <= c; i++){
				cnt[factors[i]] += c - factors[i] + 1;
			}
			c = 0;
		}
	}
	if(c){
		for(int i = 0; i < factors.size() && factors[i] <= c; i++){
			cnt[factors[i]] += c - factors[i] + 1;
		}
		c = 0;
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		if(b[i]) c++;
		else if(c){
			for(int i = 0; i < factors.size() && factors[i] <= c; i++){
				if(k / factors[i] <= n)
					ans += (c - factors[i] + 1) * cnt[k / factors[i]];
			}
			c = 0;
		}
	}
	if(c){
		for(int i = 0; i < factors.size() && factors[i] <= c; i++){
			if(k / factors[i] <= n)
				ans += (c - factors[i] + 1) * cnt[k / factors[i]];
		}
		c = 0;
	}
	cout << ans << "\n";
}