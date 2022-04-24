#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int N, M, P;
int A[105][105], B[105][105], C[105][105];

int main () {
    cin >> N >> M >> P;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= P; j++) {
            cin >> B[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= P; j++) {
            for(int k = 1; k <= M; k++) {
                // sigma k=1->m A[i][k] * B[k][j]
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= P; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}