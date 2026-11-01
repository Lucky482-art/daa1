#include <iostream>
using namespace std;

int main() {
    int n, a[10][10], key[10], used[10] = {0};
    int total = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        key[i] = 99999;

    key[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || key[i] < key[u]))
                u = i;

        if (u == -1 || key[u] == 99999) {
            cout << "Graph is disconnected";
            return 0;
        }

        used[u] = 1;
        total += key[u];

        for (int v = 0; v < n; v++)
            if (a[u][v] != 0 && !used[v] && a[u][v] < key[v])
                key[v] = a[u][v];
    }

    cout << "Minimum cost = " << total;

    return 0;
}