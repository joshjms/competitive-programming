#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int n, a, b, x, y;
vector <int> p;

signed main(){
    cin >> n >> a >> b;
    for(; a * x <= n; x++){
        if((n - a * x) % b == 0){
            y = (n - a * x) / b;
            break;
        }
    }
    if(a * x > n){
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 1; i <= x; i++){
        p.push_back(i * a);
        for(int j = 1; j < a; j++){
            p.push_back((i - 1) * a + j);
        }
    }
    for(int i = 1; i <= y; i++){
        p.push_back(i * b + a * x);
        for(int j = 1; j < b; j++){
            p.push_back((i - 1) * b + j + a * x);
        }
    }
    for(auto i : p)
        cout << i << " ";
    cout << "\n";
}