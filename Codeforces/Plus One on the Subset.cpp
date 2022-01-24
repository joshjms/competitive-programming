#include <bits/stdc++.h>
using namespace std;

signed main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int arr[n], maxi = 0, mini = 1e9 + 7;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        cout << maxi - mini << "\n";
    }
}