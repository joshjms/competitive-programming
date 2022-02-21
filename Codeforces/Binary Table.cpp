// AKARINNN!!!!!!!!! <3

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int bn, bm;
int n, m, arr[105][105];
char c[105][105];

struct ops{
    int a, b, c, d, e, f;
};
vector <ops> akari;

void operate(int a, int b, int c, int d, int e, int f){
    arr[a][b] ^= 1;
    arr[c][d] ^= 1;
    arr[e][f] ^= 1;
    akari.pb({a, b, c, d, e, f});
}

void yuriseggs(int a, int b, int c, int d, int e, int f, int g, int h){
    int yuri = arr[a][b] + arr[c][d] + arr[e][f] + arr[g][h];
    if(yuri == 4){
        operate(a, b, c, d, e, f);
        yuriseggs(a, b, c, d, e, f, g, h);
    }
    else if(yuri == 3){
        if(arr[a][b] == 0)
            operate(c, d, e, f, g, h);
        else if(arr[c][d] == 0)
            operate(a, b, e, f, g, h);
        else if(arr[e][f] == 0)
            operate(a, b, c, d, g, h);
        else if(arr[g][h] == 0)
            operate(a, b, c, d, e, f);
        yuriseggs(a, b, c, d, e, f, g, h);
    }
    else if(yuri == 2){
        if(arr[a][b] == 1)
            operate(c, d, e, f, g, h);
        else if(arr[c][d] == 1)
            operate(a, b, e, f, g, h);
        else if(arr[e][f] == 1)
            operate(a, b, c, d, g, h);
        else if(arr[g][h] == 1)
            operate(a, b, c, d, e, f);
        yuriseggs(a, b, c, d, e, f, g, h);
    }
    else if(yuri == 1){
        if(arr[a][b] == 0)
            operate(c, d, e, f, g, h);
        else if(arr[c][d] == 0)
            operate(a, b, e, f, g, h);
        else if(arr[e][f] == 0)
            operate(a, b, c, d, g, h);
        else if(arr[g][h] == 0)
            operate(a, b, c, d, e, f);
        yuriseggs(a, b, c, d, e, f, g, h);
    }
}

void solve(){
    cin >> n >> m;
    akari.clear();
    bn = n, bm = m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            arr[i][j] = c[i][j] - '0';
        }
    }
    if(n % 2 && m % 2){
        if(arr[n][m] == 1)
            operate(n, m, n - 1, m, n, m - 1);
        n--, m--;
        for(int i = 1; i <= n; i++) if(arr[i][m + 1] == 1){
            if(i < n)
                operate(i, m + 1, i, m, i + 1, m);
            else operate(i, m + 1, i, m, i - 1, m);
        }
        for(int i = 1; i <= m; i++) if(arr[n + 1][i] == 1){
            if(i < m)
                operate(n + 1, i, n, i, n, i + 1);
            else operate(n + 1, i, n, i, n, i - 1);
        }
    }
    else if(n % 2){
        n--;
        for(int i = 1; i <= m; i++) if(arr[n + 1][i] == 1){
            if(i < m)
                operate(n + 1, i, n, i, n, i + 1);
            else operate(n + 1, i, n, i, n, i - 1);
        }
    }
    else if(m % 2){
        m--;
        for(int i = 1; i <= n; i++) if(arr[i][m + 1] == 1){
            if(i < n)
                operate(i, m + 1, i, m, i + 1, m);
            else operate(i, m + 1, i, m, i - 1, m);
        }
    }
    for(int i = 1; i <= n; i += 2){
        for(int j = 1; j <= m; j += 2){
            yuriseggs(i, j, i + 1, j, i, j + 1, i + 1, j + 1);
        }
    }
    cout << akari.size() << "\n";
    for(auto i : akari)
        cout << i.a << " " << i.b << " " << i.c << " " << i.d << " " << i.e << " " << i.f << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}