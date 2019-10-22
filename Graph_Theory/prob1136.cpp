#include <bits/stdc++.h>
using namespace std;

struct tree {
    tree *left;
    tree *right;
    int val;
};

int main() {
    int N;
    scanf("%d", &N);

    int *parliament = new int[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &parliament[i]);
    }

    tree root;
    root.val = parliament[N - 1];

    tree current = root;
    for (int i = N - 2; i >= 0; i++) {
        if (N > )
    }

    delete[] parliament;
    return 0;
}