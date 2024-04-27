#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

struct Flight {
    int a, b, cost;
    Flight(int a, int b, int cost) : a(a), b(b), cost(cost) {}
};

int main() {
    int n, m, k, start, finish;
    cin >> n >> m >> k >> start >> finish;

    vector<Flight> flights;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        Flight flight(a, b, cost);
        flights.push_back(flight);
    }

    vector<vector<int>> g(k + 1, vector<int>(n + 1, INF));
    g[0][start] = 0;

    for (int i = 1; i <= k; ++i) {
        for (auto &[a, b, cost] : flights) {
            if (g[i - 1][a] != INF && g[i][b] > g[i - 1][a] + cost) {
                g[i][b] = g[i - 1][a] + cost;
            }
        }
    }

    int minCost = INF;
    for (int i = 1; i <= k; ++i) {
        minCost = min(minCost, g[i][finish]);
    }

    cout << (minCost == INF ? -1 : minCost);

    return 0;
}