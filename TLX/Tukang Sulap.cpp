#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, a[1005][2], t;

void tukar(int p, int x, int q, int y) {
    swap(a[x][p], a[y][q]);
}

int main () {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i][0];
    for(int i = 1; i <= n; i++)
        cin >> a[i][1];
    cin >> t;
    for(; t--;) {
        char p, q;
        int x, y;
        cin >> p >> x >> q >> y;
        tukar(p - 'A', x, q - 'A', y);
    }
    for(int i = 1; i <= n; i++)
        cout << a[i][0] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++)
        cout << a[i][1] << " ";
    cout << "\n";
}