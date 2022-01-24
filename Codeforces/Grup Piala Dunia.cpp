#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int T, N, K, matches;

vector <pair<int,int>> M[6];
map <vector<int>, bool> configs;

void init(){
	for(int i = 2; i <= 5; i++){
		for(int j = 0; j < i; j++){
			for(int k = j + 1; k < i; k++){
				M[i].push_back({j, k});
			}
		}
	}
}

signed main(){
	cin >> T;
	init();
	for(int i = 2; i <= 5; i++){
		matches = M[i].size();
		K = pow(3, matches);

		for(int j = 0; j < K; j++){
			int mask = j;
			vector <int> scoreboard;
			scoreboard.assign(i, 0);

			for(int k = 0; k < matches; k++, mask /= 3){
				if(mask % 3 == 0){
					scoreboard[M[i][k].fi] += 3;
				}
				else if(mask % 3 == 1){
					scoreboard[M[i][k].fi] += 1;
					scoreboard[M[i][k].se] += 1;
				}
				else if(mask % 3 == 2){
					scoreboard[M[i][k].se] += 3;
				}
			}

			configs[scoreboard] = 1;
		}
	}
	for(; T--;){
		cin >> N;
		vector<int>scoreboard;
		scoreboard.assign(N, 0);
		for(int i = 0; i < N; i++)
			cin >> scoreboard[i];

		if(configs[scoreboard] == true)
			cout << "YES\n";
		else cout << "NO\n";
	}
}