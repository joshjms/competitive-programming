#include <iostream>
#include <vector>
using namespace std;

long long T, N, E, Q, R, a, b, cnt, ans;
bool explord[50005];
bool special[50005];
long long graphs[50005];
long long arr[200005];
long long brr[200005];
bool bol[200005];
vector<long long> connec[50005];
vector<long long> helpme[50005];

void goexplor(long long area, long long district) {
	if (special[area]) {
		graphs[district]++;
	}
	explord[area] = true;
	for (long long z = 0; z < connec[area].size(); z++) {
		if (not explord[connec[area][z]]) {
			goexplor(connec[area][z], district);
		}
	}
}

int main() {
	cin >> T;
	for (long long pp = 0; pp < T; pp++) {
		cin >> N >> E >> Q >> R;
		for (long long i = 0; i <= N; i++) {
			explord[i] = false;
            connec[i].clear();
		}
		for (long long i = 0; i <= N; i++) {
			special[i] = false;
		}
		for (long long i = 1; i <= E; i++) {
			cin >> arr[i] >> brr[i];
		}
		for (long long i = 1; i <= E; i++) {
			bol[i] = true;
		}
        for (long long i = 0; i < Q; i++) {
			cin >> a;
			special[a] = true;
		}
		for (long long i = 0; i < R; i++) {
			cin >> a;
			bol[a] = false;
		}
		for (long long i = 1; i <= E; i++) {
			if (bol[i]) {
				connec[arr[i]].push_back(brr[i]);
				connec[brr[i]].push_back(arr[i]);
			}
		}
		for (long long i = 0; i <= N; i++) {
			graphs[i] = 0;
		}
		cnt = 0;
		for (long long i = 1; i <= N; i++) {
			if (not explord[i]) {
				cnt++;
				goexplor(i, cnt);
			}
		}
		ans = 0;
		for (long long i = 1; i <= cnt; i++) {
			for (long long j = i+1; j <= cnt; j++) {
				ans += graphs[i]*graphs[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}