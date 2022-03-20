#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define debug(x)    cout << #x << " => " << x << "\n"
#define pb          push_back
#define fi          first
#define se          second
#define sp          " "

string s = "NANYANG";
set <string> st;

int A, N;

void solve(){
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            for(int k = 0; k < s.size(); k++){
                if(i == j || i == k || j == k) continue;
                string newString = "";
                A = 0, N = 0;
                if(s[i] == 'A') A++;
                if(s[j] == 'A') A++;
                if(s[k] == 'A') A++;
                if(s[i] == 'N') N++;
                if(s[j] == 'N') N++;
                if(s[k] == 'N') N++;
                if(A != 0 || N != 1) continue;
                newString += s[i];
                newString += s[j];
                newString += s[k];
                st.insert(newString);
            }
        }
    }
    for(auto i : st)
        cout << i << "\n";
    cout << st.size() << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}