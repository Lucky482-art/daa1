#include <iostream>
using namespace std;

int graph[10][10], color[10], n, m;

bool safe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] == 1 && color[i] == c)
            return false;

    return true;
}

bool solve(int v) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (safe(v, c)) {
            color[v] = c;

            if (solve(v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    if (n < 1 || n > 10 || m < 1)
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    if (solve(0)) {
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " = Color " << color[i] << endl;
    } else {
        cout << "No valid coloring";
    }

    return 0;
}