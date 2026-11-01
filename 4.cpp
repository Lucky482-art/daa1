#include <iostream>
using namespace std;

int cost[10][10], visited[10], n;
int best = 999999;

void tsp(int city, int count, int total) {
    if (count == n) {
        if (cost[city][0] != 0 && total + cost[city][0] < best)
            best = total + cost[city][0];
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = 1;
            tsp(i, count + 1, total + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;

    if (n < 2 || n > 10)
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    visited[0] = 1;

    tsp(0, 1, 0);

    if (best == 999999)
        cout << "No valid route";
    else
        cout << "Minimum cost = " << best;

    return 0;
}