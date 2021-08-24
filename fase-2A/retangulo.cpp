#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int v[n], sum = 0;
    unordered_map<int, int> l;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        l[sum] = i;
        sum += v[i];
    }
    if (sum % 2 != 0) {
        cout << "N\n";
        return 0;
    }
    sum /= 2;
    int cur = 0;
    int cnt;
    for (int i = n - 1; i >= 0; i--) {
        cur += v[i];
        if (l.count(sum - cur))
            cnt++;
    }
    cout << (cnt >= 2 ? 'S' : 'N') << endl;
    return 0;
}