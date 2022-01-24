#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int N, M, DP[25][200005];
int fact[250005], stnbr[20];
int ans;

const int mod = 998244353;

int modex(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

int inv(int x){
	return modex(x, mod - 2);
}

int cmb(int n, int r){
	return (fact[n] * ((inv(fact[r]) * inv(fact[n - r])) % mod)) % mod;
}

int snb(int s, int b){ // b jumlah elemen
	return cmb(s + b - 1, b - 1) % mod;
}

signed main(){
	cin >> N >> M;
	fact[0] = 1;
	for(int i = 1; i <= 250000; i++){
		(fact[i] = fact[i - 1] * i) %= mod;
	}
	for(int i = 2; i <= M; i++)
		DP[1][i] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 2; j <= M; j++){
			if(DP[i][j] == 0) continue;
			for(int k = 2; j * k <= M; k++){
				(DP[i + 1][j * k] += DP[i][j]) %= mod;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 2; j <= M; j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	for(int i = 1; i <= 20; i++){
		stnbr[i] = snb(N, i + 1);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 2; j <= M; j++){
			if(DP[i][j] == 0) continue;
			(ans += stnbr[i] * DP[i][j]) %= mod;
		}
	}
	cout << ans << "\n";
}