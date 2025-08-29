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
int x1, y11, x2, y2;
const int maxn = 1e3 + 5;
bool visited[maxn][maxn];
pair<int, int> pr[maxn][maxn];
char lt[maxn][maxn];
struct tt {
    int x; int y;
};
queue<tt> q;
bool check(int a, int b) {
    if (a < 1 || a > n || b < 1 || b > m) return false;
    else return true;
}
void ciin () {
    cin >> n >> m;
    char c;
    FOR(i,1,n) FOR(j,1,m) {
        cin >> c;
        if (c == 'A') {
            visited[i][j] = true;
            x1 = i; y11 = j;
        }
        else if (c == 'B') {
            visited[i][j] = true;
            x2 = i; y2 = j;
        }
        else if (c == '.') visited[i][j] = true;
    }
}
void xuli(int a, int b) {
    if (check(a + 1, b) && visited[a + 1][b]) {
        q.push({a + 1, b}); visited[a + 1][b] = false;
        pr[a + 1][b].fi = a, pr[a + 1][b].se = b;
        lt[a + 1][b] = 'D';
    }
    if (check(a, b + 1) && visited[a][b + 1]) {
        q.push({a, b + 1}); visited[a][b + 1] = false;
        pr[a][b + 1].fi = a, pr[a][b + 1].se = b;
        lt[a][b + 1] = 'R';
    }
    if (check(a - 1, b) && visited[a - 1][b]) {
        q.push({a - 1, b}); visited[a - 1][b] = false;
        pr[a - 1][b].fi = a, pr[a - 1][b].se = b;
        lt[a - 1][b] = 'U';
    }
    if (check(a, b - 1) && visited[a][b - 1]) {
        q.push({a, b - 1}); visited[a][b - 1] = false;
        pr[a][b - 1].fi = a, pr[a][b - 1].se = b;
        lt[a][b - 1] = 'L';
    }
    return;
}
void backtrack(int tm1, int tm2) {
    string res = "";
    while (true) {
        if (tm1 == x1 && tm2 == y11) break;
        res += lt[tm1][tm2];
        int tmp1 = pr[tm1][tm2].fi, tmp2 = pr[tm1][tm2].se;
        tm1 = tmp1; tm2 = tmp2;
    }
    reverse(res.begin(), res.end());
    cout << "YES" << endl << res.size() << endl << res;
}
void solve() {
    q.push({x1, y11}); visited[x1][y11] = false;
    while (!q.empty()) {
        tt tmp = q.front(); q.pop();
        if (tmp.x == x2 && tmp.y == y2) {
            backtrack(x2, y2);
            exit(0);
        }
        xuli(tmp.x, tmp.y);
    }
    cout << "NO";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ciin(); solve();
    return 0;
}
