#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, ans;
vector<int> adj[25];

bool valid(set<int> s) {
    for (int x : s)
        for (int k : adj[x])
            if (s.count(k)) return false;
    return true;
}

void genSanduiche(int i, set<int> subarr) {
    if (i == n + 1) {
        if (subarr.size() != 0 && valid(subarr))
            ans++;
    } else {
        genSanduiche(i + 1, subarr);
        subarr.insert(i);
        genSanduiche(i + 1, subarr);
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> s;
    genSanduiche(1, s);
    printf("%d\n", ans);
    return 0;
}
