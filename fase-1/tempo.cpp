#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, time = 0;
    char c;
    scanf("%d", &n);
    stack<int> events[101];
    set<int> friends;
    int totalTime[101] = {0};
    for (int i = 0; i < n; i++) {
        scanf(" %c%d", &c, &x);
        if (c == 'T')
            time += x - 1;
        else {
            time++;
            friends.insert(x);
            if (c == 'R')
                events[x].push(time);
            else {
                int diff = time - events[x].top();
                events[x].pop();
                totalTime[x] += diff;
            }
        }
    }
    for (auto f : friends) {
        if (events[f].size() == 0)
            printf("%d %d\n", f, totalTime[f]);
        else
            printf("%d %d\n", f, -1);
    }
    return 0;
}