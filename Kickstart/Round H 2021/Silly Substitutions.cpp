#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, arr[500005], p;
string s;

struct node{
    int val = 0;
    int idx = 0;
    struct node* next = NULL;
    struct node* prev = NULL;
    bool deleted = false;
} def;

vector <node> linklist;
vector <int> upd[10];
bool deleted[500005];

void solve(){
    cin >> n >> s;
    linklist.assign(n, def);
    for(int i = 0; i < n; i++)
        arr[i] = s[i] - '0';
    for(int i = 0; i < n; i++){
        linklist[i].val = arr[i];
        linklist[i].idx = i;
        if(i > 0) linklist[i].prev = &linklist[i - 1];
        if(i < n - 1) linklist[i].next = &linklist[i + 1];
    }
    for(int i = 0; i < n - 1; i++){
        if((linklist[i].val + 1) % 10 == linklist[i + 1].val){
            upd[linklist[i].val].pb(i);
        }
    }
    while(true){
        bool change = 0;
        for(int d = 0; d < 10; d++){
            for(int i; upd[d].empty() == false;){
                i = upd[d].back();
                upd[d].pop_back();
                if(linklist[i].deleted == false && (linklist[i].val + 1) % 10 == linklist[i].next->val){
                    (linklist[i].val += 2) %= 10;
                    linklist[i].next->deleted = true;
                    if(linklist[i].next->next != NULL)
                        linklist[i].next->next->prev = &linklist[i];
                    linklist[i].next = linklist[i].next->next;
                    if(linklist[i].next != NULL) if((linklist[i].val + 1) % 10 == linklist[i].next->val){
                        upd[linklist[i].val].pb(i);
                    }
                    if(linklist[i].prev != NULL) if((linklist[i].val - 1 + 10) % 10 == linklist[i].prev->val){
                        upd[linklist[i].prev->val].pb(linklist[i].prev->idx);
                    }
                }
                change = 1;
            }
            // for(int i = 0; i < n; i++){
            //     if(linklist[i].deleted == false){
            //         cout << linklist[i].val;
            //     }
            //     else cout << " ";
            // }
            // cout << "\n";
        }
        if(!change) break;
    }
    for(int i = 0; i < n; i++){
        if(linklist[i].deleted == false){
            cout << linklist[i].val;
        }
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++){
        cout << "Case #" << ntc << ": ";
        solve();
    }
}