#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int r, c;
char arr[25][25];

void solve () {
    cin >> r >> c;
    for(int i = 1; i <= 2 * r + 1; i++) {
        for(int j = 1; j <= 2 * c + 1; j++) {
            if(i % 2 && j % 2) arr[i][j] = '+';
            if(i % 2 && !(j % 2)) arr[i][j] = '-';
            if(!(i % 2) && j % 2) arr[i][j] = '|';
            if(!(i % 2) && !(j % 2)) arr[i][j] = '.';
        }
    }
    arr[1][1] = arr[1][2] = arr[2][1] = arr[2][2] = '.';
    for(int i = 1; i <= 2 * r + 1; i++) {
        for(int j = 1; j <= 2 * c + 1; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++) {
        cout << "Case #" << ntc << ":\n";
        solve ();
    }
}