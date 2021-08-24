#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

set<set<int>> sanduiches;

int n, m, a, b;
set<int> adj[25];

bool valid(set<int> s) {
    for (int x : s)
        for (int k : adj[x])
            if (s.count(k)) return false;
    return true;
}

void genSanduiche(int i, set<int> v) {
    if (i == n + 1) {
        if (v.size() != 0 && valid(v))
            sanduiches.insert(v);
    } else {
        genSanduiche(i + 1, v);
        v.insert(i);
        genSanduiche(i + 1, v);
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int ans = n;
    set<int> s;
    genSanduiche(1, s);
    cout << sanduiches.size() << endl;
    return 0;
}