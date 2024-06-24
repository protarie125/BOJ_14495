#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl dp;

ll foo(ll x) {
  if (x <= 3) {
    return 1;
  }

  if (dp[x] < 0) {
    dp[x] = foo(x - 1) + foo(x - 3);
  }

  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  if (n <= 3) {
    cout << 1;
    return 0;
  }

  dp = vl(n + 3, -1);
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;

  cout << foo(n);

  return 0;
}