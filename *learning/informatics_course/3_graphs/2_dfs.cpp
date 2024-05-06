#include <iostream>
#include <vector>
using namespace std;

//dfs
void dfs(vector<vector<int>> &graph, int v, vector<int>& visited){
    visited[v] = 1;
    for (int to : graph[v]){
        if (!visited[to]){
            dfs(graph, to, visited);
        }
    }
}


// поиск цикла в ориентированном графе пир помощи dfs
void dfs(vector<vector<int>>& graph, int v, vector<int>& visited, bool& hasCycle){
    visited[v] = 1;
    for (int to : graph[v]){
        if (visited[to] == 0){
            dfs(graph, to, visited, hasCycle);
        } else if (visited[to] == 1){
            hasCycle = true;
        }
    }
    visited[v] = 2;
}


// восстановление цикла в ориентированном графе
vector<int> getCycle(vector<int>& from, int lastv){
    vector<int> cycle = { lastv };
    for (int v = from[lastv]; v != lastv; v = from[v]){
        cycle.push_back(v);
    }
    reverse(cycle.begin(), cycle.end());
    return cycle;
}
void dfs(vector<vector<int>>& graph, int v, vector<int>& visited, vector<int>& from, vector<int>& cycle){
    visited[v] = 1;
    for (int to : graph[v]){
        if (visited[to] == 0){
            from[to] = v;
            dfs(graph, to, visited, from, cycle);
            if (!cycle.empty()) return;
        } else if (visited[to] == 1){
            from[to] = v;
            cycle = getCycle(cycle, to);
        }
    }
    visited[v] = 2;
}


// поиск цикла в неориентированном графе при помощи dfs
void dfs(vector<vector<int>>& graph, int v, vector<int>& visited, int parent, bool& hasCycle){
    visited[v] = 1;
    for (int to : graph[v]){
        if (to == parent) {
            continue;
        } else if (visited[to] == 0){
            dfs(graph, to, visited, v, hasCycle);
        } else if (visited[to] == 1){
            hasCycle = true;
        }
    }
    visited[v] = 2;
}


// восстановление цикла в неориентированном графе
void dfs(vector<vector<int>>& graph, int v, vector<int>& visited, vector<int>& from, vector<int>& cycle){
    visited[v] = 1;
    for (int to : graph[v]){
        if (to == from[v]){
            continue;
        } else if (visited[to] == 0){
            from[to] = v;
            dfs(graph, to, visited, from, cycle);
            if (!cycle.empty()) return;
        } else if (visited[to] == 1){
            from[to] = v;
            cycle = getCycle(cycle, to);
        }
    }
    visited[v] = 2;
}

// двудольные графы
void dfs(vector<vector<int>> &graph, vector<int> &visited, int v, int color, bool &isBipartite){
    visited[v] = color;
    for (int to : graph[v]){
        if (!visited[to]) {
            dfs(graph, visited, to, 3-color, isBipartite);
        } else if (visited[to] == color){
            isBipartite = false;
        }
    }
}

// топологическа сортировка
void dfs(vector<vector<int>>& graph, int v, vector<int>& visited, vector<int>& order){
    visited[v] = 1;
    for (int to : graph[v]){
        if (visited[to] == 0){
            dfs(graph, to, visited, order);
        }
    }
    order.push_back(v);
}
//!!! reverse(order.begin(), order.end());

// Алгоритм поиска компонент сильной связности
/*
1. Построить вспомогательный граф, в котором направление всех ребер изменено на противоположное
2. Запустить на вспомогательном графе топологическую сортировку (для каждой вершины, перебором от 0 до n)
3. Раскрасить исходный граф, запуская DFS в порядке топологической сортировки
*/