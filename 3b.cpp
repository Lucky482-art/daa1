#include <iostream>
using namespace std;

int graph[10][10], path[10], n;

bool safe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool solve(int pos) {
    if (pos == n)
        return graph[path[n - 1]][path[0]] == 1;

    for (int v = 1; v < n; v++) {
        if (safe(v, pos)) {
            path[pos] = v;

            if (solve(pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    cin >> n;

    if (n < 3 || n > 10)
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (solve(1)) {
        for (int i = 0; i < n; i++)
            cout << path[i] << " -> ";

        cout << path[0];
    } else {
        cout << "No Hamiltonian cycle";
    }

    return 0;
}