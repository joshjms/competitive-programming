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

int n;
string s[100005];
map <string,int> mp;
bool ans;

bool palindrome(string a){
    string b = a;
    reverse(b.begin(), b.end());
    if(a == b) return true;
    return false;
}

void solve(){
    ans = 0;
    cin >> n;
    mp.clear();
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        if(palindrome(s[i]))
            ans = 1;
        mp[s[i]]++;
    }
    if(ans){
        cout << "YES\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        string rev = s[i];
        if(mp[rev] <= 0) continue; 
        reverse(rev.begin(), rev.end());
        if(mp[rev] > 0){
            cout << "YES\n";
            return;
        }
        if(s[i].size() > 2){
            rev = s[i].substr(0, 2);
            reverse(rev.begin(), rev.end());
            if(mp[rev] > 0){
                cout << "YES\n";
                return;
            }
        }
        else{
            for(int j = 0; j < 26; j++){
                rev = s[i] + char(j + 'a');
                reverse(rev.begin(), rev.end());
                if(mp[rev] > 0){
                    cout << "YES\n";
                    return;
                }
            }
        }
        mp[s[i]]--;
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}