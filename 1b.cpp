#include <iostream>
using namespace std;

int main() {
    int n, e, u[100], v[100], w[100];
    int d[100], source;

    cin >> n >> e;

    for (int i = 0; i < e; i++)
        cin >> u[i] >> v[i] >> w[i];

    cin >> source;

    for (int i = 0; i < n; i++)
        d[i] = 99999;

    d[source] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < e; j++) {
            if (d[u[j]] != 99999 &&
                d[u[j]] + w[j] < d[v[j]]) {
                d[v[j]] = d[u[j]] + w[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Distance to " << i << " = " << d[i] << endl;

    return 0;
}