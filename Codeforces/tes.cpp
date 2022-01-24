#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int N = 5;
vector <int> vect = {1, 2, 3, 4};

void brute(int n, vector <int> config){
	if(n == 2){
		for(int i = 0; i < n; i++)
			cout << config[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = 1; i <= N; i++){
		config.push_back(i);
		brute(n + 1, config);
		config.pop_back();
	}
}

signed main(){	
	do{
		for(int i = 0; i < vect.size(); i++)
			cout << vect[i] << " ";
		cout << "\n";
	} while(next_permutation(vect.begin(), vect.end()));
}