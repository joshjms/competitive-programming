#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int t, n, arr[1005], mex;
vector <int> ans;

int getmex(){
    bool exist[n + 1];
    memset(exist, 0, sizeof(exist));
    for(int i = 1; i <= n; i++)
        exist[arr[i]] = 1;
    for(int i = 0; i <= n; i++)
        if(!exist[i])
            return i;
}

bool decreasing(){
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[i + 1])
            return true;
    return false;
}

int main(){
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> arr[i];
        ans.clear();
        while(decreasing()){
            mex = getmex();
            if(mex >= n){
                for(int i = 1; i <= n; i++){
                    if(arr[i] != i - 1){
                        arr[i] = mex;
                        ans.push_back(i);
                        break;
                    }
                }
            }
            else{
                arr[mex + 1] = mex;
                ans.push_back(mex + 1);
            }
        }
        cout << ans.size() << "\n";
        for(auto i : ans)
            cout << i << sp;
        cout << "\n";
    }
}