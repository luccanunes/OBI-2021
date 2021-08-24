#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAXN = 110;
int n, m;
string grid[MAXN][MAXN];
int line[MAXN], col[MAXN];
map<string, int> ans;
set<string> vars, found;

void solve() {
    for (int i = 0; i < n; i++) {
        string not_found = "";
        int tot = 0, cnt = 0;
        bool solvable = true;
        for (int j = 0; j < m; j++) {
            if (found.count(grid[i][j])) {
                tot += ans[grid[i][j]];
            } else if (not_found == "") {
                not_found = grid[i][j];
                cnt++;
            } else if (not_found == grid[i][j]) {
                cnt++;
            } else {
                solvable = false;
                break;
            }
        }
        if (!solvable || not_found == "") continue;
        found.insert(not_found);
        ans[not_found] = (line[i] - tot) / cnt;
        return;
    }
    for (int j = 0; j < m; j++) {
        string not_found = "";
        int tot = 0, cnt = 0;
        bool solvable = true;
        for (int i = 0; i < n; i++) {
            if (found.count(grid[i][j])) {
                tot += ans[grid[i][j]];
            } else if (not_found == "") {
                not_found = grid[i][j];
                cnt++;
            } else if (not_found == grid[i][j]) {
                cnt++;
            } else {
                solvable = false;
                break;
            }
        }
        if (!solvable || not_found == "") continue;
        found.insert(not_found);
        ans[not_found] = (col[j] - tot) / cnt;
        return;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            vars.insert(grid[i][j]);
        }
        scanf("%d", &line[i]);
    }
    for (int i = 0; i < m; i++) scanf("%d", &col[i]);
    while (found.size() != vars.size())
        solve();
    for (string s : vars)
        cout << s << ' ' << ans[s] << endl;
    return 0;
}