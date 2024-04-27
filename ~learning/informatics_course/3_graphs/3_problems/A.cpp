#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;

const int INF = 1E9;

vi getShortPath(vector<vi>& graph, int n, int start, int finish){
    vi dist(n, INF);
    vi from(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (int to : graph[v]){
            if (dist[to] > dist[v] + 1){
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    if (dist[finish] == INF){
        return {};
    }

    vi path;
    for (int v = finish; v != -1; v = from[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int n, start, finish;
    cin >> n;
    vector<vi> graph(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int num;
            cin >> num;
            if (num){
                graph[i].push_back(j);
            }
        }
    }
    cin >> start >> finish;

    vi path = getShortPath(graph, n, start-1, finish-1);

    int l = path.size()-1;
    cout << l << endl;
    if (l > 0){
        for (int v : path){
            cout << v+1 << " ";
        }
    }

    return 0;
}