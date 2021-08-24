#include <bits/stdc++.h>

using namespace std;

int main()
{
    int idades[3];
    scanf("%d%d%d", &idades[0], &idades[1], &idades[2]);
    sort(idades, idades + 3);
    printf("%d", idades[1]);
    return 0;
}