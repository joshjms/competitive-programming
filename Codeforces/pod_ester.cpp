#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define fi first 
#define se second
#define pb push_back
#define pii pair<ll,ll> 

const ll nax = 1e5; 
vector<pair<ll,pii>> adj[nax+5]; 
ll dist[nax+5]; 
ll a[nax+5]; 

ll calc(ll from, ll to, ll where) {
  if(to < from) swap(from, to); 

   ll md = a[where]; 
   return min ((to-from), (from+md-to) % md); 
}

int e[100005];

void dfs(ll cabin, ll pod, ll prv) {
   for(auto p : adj[cabin]) if(p.fi != prv) {
      ll nxt = p.fi;
      ll cpod = p.se.fi; 
      dist[nxt] = dist[cabin] + calc(pod, cpod, cabin) + 1; 
    //cout << cabin << " to " << nxt << " costs " << pod << " " << cpod << ' ' << calc(pod, cpod, cabin) << endl; 

      dfs(nxt, p.se.se, cabin); 
   }
}

signed main () {
   ll n; cin >> n; 
   for(ll i=0; i<n; i++) cin >> a[i]; 

    e[0] = 0;
   for(ll i=0; i<n-1; i++) {
      ll ki, pi, kj, pj;
      cin >> ki >> pi >> kj >> pj; 

      if(kj < ki){
          swap(ki, kj);
          swap(pi, pj);
      }

      adj[ki].pb({kj, {pi, pj}}); 
      e[kj] = pj;
   }

   dist[0] = 0;
   dfs(0, 0, -1);
//    for(int i = 0; i < n - 1; i++){
//        dist[i + 1] = dist[i] + calc(e[i], adj[i][0].se.fi, i) +
//    }
//    for(ll i=0; i<n; i++) {
//      cerr << i << " " << dist[i] << endl; 
//    }

   cout << dist[n-1] << "\n";
}

/*
*/