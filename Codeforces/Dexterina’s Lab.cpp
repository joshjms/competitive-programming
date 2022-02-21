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

struct matrix{
    ld mat[128][128];
    matrix(){
        for(int i = 0; i < (1ll << 7); i++){
            for(int j = 0; j < (1ll << 7); j++){
                mat[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix b) const {
        matrix res;
        for(int i = 0; i < (1ll << 7); i++){
            for(int j = 0; j < (1ll << 7); j++){
                for(int k = 0; k < (1ll << 7); k++){
                    res.mat[i][k] += mat[i][j] * b.mat[j][k];
                }
            }
        }
        return res;
    }
    void print(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

matrix modex(matrix a, int b){
    matrix res = a;
    while(b){
        if(b & 1) res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

int n, x;
ld p[155];
matrix m, r;

void solve(){
    cin >> n >> x;
    for(int i = 0; i <= x; i++)
        cin >> p[i];
    for(int i = 0; i < (1ll << 7); i++){
        for(int j = 0; j < (1ll << 7); j++){
            m.mat[i][j] = p[i ^ j];
        }
    }
    r = modex(m, n - 1);
    cout << fixed << setprecision(6) << 1.0 - r.mat[0][0] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}