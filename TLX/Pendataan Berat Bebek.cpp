// アッカリ〜ン

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

int N, Q, L[100005], R[100005];
vector <int> A;

// int up_bound(int val){
//     int l = 1, r = N, ret = N + 1;
//     while(l <= r){
//         int mid = (l + r) / 2;
//         // Jika A[mid] diatas value yang kita ingin cek, maka pastinya index yang kita cari diatas index tengah sekarang.
//         if(A[mid] > val)
//             r = mid - 1, ret = mid;
//         else l = mid + 1;
//     }
//     return ret;
// }

void solve(){
    cin >> N;
    A.assign(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        cin >> L[i] >> R[i];
        // Cara alternatif non-binser:
        int left_index = upper_bound(A.begin(), A.end(), L[i]) - A.begin();
        int right_index = upper_bound(A.begin(), A.end(), R[i]) - A.begin();
        cout << max(0ll, right_index - left_index) << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}