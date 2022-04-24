#include "boxes.h"
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";
 
const int mod = 1e9 + 7;
 
ll n, k, l, p[10000005], idx;
 
ll le = 0, ri = 0;
ll dp[10000005][2];
 
ll ans = 1e18 + 7;
 
ll delivery(int N, int K, int L, int P[]) {
    n = N, k = K, l = L;
    for(int i = 0; i < n; i++) {
        if(P[i]) p[++idx] = P[i];
    }
    n = idx;
    if(n == 0) return 0;
    le = 0, ri = 1;
    for(; ri <= n; ri++) {
        while(ri - le > k) 
            le++;
        dp[ri][0] = dp[le][0] + min(l, p[ri] * 2);
    }
    reverse(p + 1, p + n + 1);
    le = 0, ri = 1;
    for(; ri <= n; ri++) {
        while(ri - le > k)
            le++;
        dp[ri][1] = dp[le][1] + min(l, ((l - p[ri]) % l) * 2);
    }
    ans = min(dp[n][0], dp[n][1]);
    for(int i = 1; i < n; i++) {
        ans = min(ans, dp[i][0] + dp[n - i][1]);
    }
    return ans;
}
 
// static char _buffer[1024];
// static int _currentChar = 0;
// static int _charsNumber = 0;
// static FILE *_inputFile, *_outputFile;
 
// static inline int _read() {
//     if (_charsNumber < 0) {
//         exit(1);
//     }
//     if (!_charsNumber || _currentChar == _charsNumber) {
//         _charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), _inputFile);
//         _currentChar = 0;
//     }
//     if (_charsNumber <= 0) {
//         return -1;
//     }
//     return _buffer[_currentChar++];
// }
 
// static inline int _readInt() {
//     int c, x, s;
//     c = _read();
//     while (c <= 32) c = _read();
//     x = 0;
//     s = 1;
//     if (c == '-') {
//         s = -1;
//         c = _read();
//     }
//     while (c > 32) {
//         x *= 10;
//         x += c - '0';
//         c = _read();
//     }
//     if (s < 0) x = -x;
//     return x;
// }
 
// int main() {
// 	_inputFile = stdin;
// 	_outputFile = stdout;
 
//     int N, K, L, i;
//     N = _readInt();
//     K = _readInt();
//     L = _readInt();
 
//     int *p = (int*)malloc(sizeof(int) * (unsigned int)N);
 
//     for (i = 0; i < N; i++) {
//         p[i] = _readInt();
//     }
 
//     fprintf(_outputFile, "%lld\n", delivery(N, K, L, p));
//     return 0;
// }