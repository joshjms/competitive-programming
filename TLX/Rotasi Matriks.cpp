#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int N, M;

int main () {
    cin >> N >> M;
    int A[N][M];

    /*
        0 1 2 3 ... N - 1 [N gada]
    */

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = N - 1; j >= 0; j--) {
            cout << A[j][i] << " ";
        }
        cout << "\n";
    }
}