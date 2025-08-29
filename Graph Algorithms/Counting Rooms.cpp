#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <numeric> 
#include <functional>
#include <cassert>
#define ll long long
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define fi first
#define se second
#define pb push_back
#define endl "\n"
using namespace std;
ll n, m;
const int maxn = 1e3 + 5;
ll visited[maxn][maxn];
void ciin () {
    cin >> n >> m;
}
void dfs(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m) return;
    if (visited[i][j] == false) visited[i][j] = true;
    else return;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
    return;
}
void solve() {
    char c;
    FOR(i,1,n) FOR(j,1,m) {
        cin >> c;
        if (c == '#') visited[i][j] = true;
    }
    ll cnt = 0;
    FOR(i,1,n) FOR(j,1,m) if (visited[i][j] == false) {
        cnt++;
        dfs(i,j);
    }
    cout << cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ciin(); solve();
    return 0;
}
