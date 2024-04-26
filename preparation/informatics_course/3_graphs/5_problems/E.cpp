#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

struct Flight {
    int a, b, weight;
    Flight(int a, int b, int weight) : a(a), b(b), weight(weight) {}
};

int main() {
    int n, m, k, start, finish;
    cin >> n >> m >> k >> start >> finish;

    vector<Flight> flights;
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        Flight flight(a, b, weight);
        flights.push_back(flight);
    }

    vector<vector<int>> g(k + 1, vector<int>(n + 1, INF));
    g[0][start] = 0;

    for (int i = 1; i <= k; ++i) {
        for (auto &[a, b, weight] : flights) {
            if (g[i - 1][a] != INF) {
                g[i][b] = min(g[i][b], g[i - 1][a] + weight);
            }
        }
    }

    int minWeight = INF;
    for (int i = 1; i <= k; ++i) {
        minWeight = min(minWeight, g[i][finish]);
    }

    cout << (minWeight == INF ? -1 : minWeight);

    return 0;
}