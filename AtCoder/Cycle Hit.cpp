#include <bits/stdc++.h>
using namespace std;

// Template by YuriEnthusiast 2022 <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

string arr[4] = {"H", "2B", "3B", "HR"};
string s[4];

void solve(){
    sort(arr, arr + 4);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    sort(s, s + 4);
    for(int i = 0; i < 4; i++)
        if(s[i] != arr[i]){
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}