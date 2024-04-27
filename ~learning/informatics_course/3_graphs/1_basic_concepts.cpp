#include <iostream>
#include <vector>
using namespace std;

int main(){
    // кол-во вершин и ребер
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    // способ представления графа в виде списка ребер
    vector<pair<int, int>> edgeList(edgeCount);
    for (int i = 0; i < edgeCount; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edgeList[i] = {a, b};
    }

    // способ представления графа в виде матрицы смежности
    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount, 0));
    for (int i = 0; i < edgeCount; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = 1;
        graph[b][a] = 1; //только если неориентированный граф
    }

    // способ представления графа в виде списка смежности
    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a); //только если неориентированный граф
    }
}