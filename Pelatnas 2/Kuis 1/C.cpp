#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, t, arr[1005], dp[1005][10005];

void solve(){
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i < (1ll << n); i++){
        deque <int> deq;
        int mask = i;
        for(int j = 0; j < n; j++){
            if(mask & (1ll << j)){
                deq.push_back(arr[j + 1]);
                while(deq.size() > 1 && deq[deq.size() - 1] == deq[deq.size() - 2]){
                    deq[deq.size() - 2] *= 2;
                    deq.pop_back();
                }
            }
            else{
                deq.push_front(arr[j + 1]);
                while(deq.size() > 1 && deq[0] == deq[1]){
                    deq[1] *= 2;
                    deq.pop_front();
                }
            }
        }
        if(deq.size() == 1){
            cout << "YA\n";
            if(t){
                for(int j = 0; j < n; j++){
                    if(mask & (1ll << j))
                        cout << "L";
                    else cout << "R";
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "TIDAK\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}