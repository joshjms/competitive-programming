#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, a, b, l;

int N = 10;
int arr[] = {0, 5, 7, 6, 4, 10, 9, 1, 3, 8, 2};

void bantal() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j > 1; j /= 2) {
            if (arr[j] > arr[j/2]) {
                swap(arr[j], arr[j/2]);
            }
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bantal ();
    for(int i = 1; i <= N; i++) 
        cout << arr[i] << " ";
    cout << "\n";
}