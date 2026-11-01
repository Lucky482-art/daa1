#include <iostream>
using namespace std;

int main() {
    int n, e;
    int u[100], v[100], w[100];
    int p[100], total = 0;

    cin >> n >> e;

    for (int i = 0; i < e; i++)
        cin >> u[i] >> v[i] >> w[i];

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                int t = w[j];
                w[j] = w[j + 1];
                w[j + 1] = t;

                t = u[j];
                u[j] = u[j + 1];
                u[j + 1] = t;

                t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++)
        p[i] = i;

    for (int i = 0, count = 0; i < e && count < n - 1; i++) {
        int a = u[i], b = v[i];

        while (p[a] != a)
            a = p[a];

        while (p[b] != b)
            b = p[b];

        if (a != b) {
            cout << u[i] << " - " << v[i] << " : " << w[i] << endl;
            total += w[i];
            p[a] = b;
            count++;
        }
    }

    cout << "Minimum cost = " << total;

    return 0;
}