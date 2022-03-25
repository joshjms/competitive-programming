#include "game.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

int n;
vector <int> ans;

inline void func(int bit, int x){
    if(bit < 0){
        ans.pb(x);
        return;
    }
    // is there yg has prefix `x` and has bit ke `bit`
    // semacam trie maybe
    int xor_by = x ^ (1ll << bit);
    int u = ask_minimum_xor(xor_by);
    if(u < (1ll << bit)){
        func(bit - 1, x ^ (1ll << bit));
    }
    int v = ask_minimum_xor(x);
    if(v < (1ll << bit)){
        func(bit - 1, x);
    }
}

vector<int> play_game(int N) {
    n = N;
    func(29, 0);
    // for(int i = 0; i < (1ll << 15) && ans.size() < n; i += 2){
    //     int u = ask_minimum_xor(i);
    //     if(u == 0){
    //         ans.pb(i);
    //         if(ask_minimum_xor(i + 1) == 0)
    //             ans.pb(i + 1);
    //     }
    //     else if(u == 1)
    //         ans.pb(i + 1);
    // }
    return ans;
}

namespace {

static const int NMAX = 10000;
static const int AMAX = 1 << 30;

static const int L = 20000;

static int N;
static std::vector<int> X;

static int ask_count;

static void WA(std::string msg) {
  puts(("Wrong Answer: " + msg).c_str());
  exit(0);
}

static void AC() {
  puts("Accepted");
  exit(0);
}

}  // namespace

int ask_minimum_xor(int x) {
  ask_count += 1;
//   if (ask_count > L) {
//     WA("you asked Pak Dengklek more than L times");
//   }
  if (x < 0 || x >= AMAX) {
    WA("x in ask_minimum_xor(x) does not satisfy constraints");
  }
  int ret = AMAX;
  for (int i = 0; i < N; i++) {
    ret = std::min(ret, X[i] ^ x);
  }
  //debug(ret);
  return ret;
}

int main() {
  scanf("%d", &N);
  X.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }
  std::vector<int> Y = play_game(N);
  std::sort(X.begin(), X.end());
  std::sort(Y.begin(), Y.end());
  if (X != Y) {
    WA("you guessed X incorrectly");
  }
  debug(ask_count);
  AC();
  return 0;
}
