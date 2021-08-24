#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, sum = 0;
    scanf("%d", &n);
    stack<int> nums;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 0) {
            sum -= nums.top();
            nums.pop();
        }
        else {
            sum += x;
            nums.push(x);
        }
    }
    printf("%d\n", sum);
    return 0;
}
