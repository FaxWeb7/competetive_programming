#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    bool has_parallel_edges = false;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].first == edges[j].first && edges[i].second == edges[j].second) {
                has_parallel_edges = true;
                break;
            }
        }
        if (has_parallel_edges) {
            break;
        }
    }

    if (has_parallel_edges) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}