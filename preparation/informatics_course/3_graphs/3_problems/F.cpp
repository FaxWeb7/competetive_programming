#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1E9;

vs getOptions(string &v){
    int s = v.size();
    vs options(4, v);
    if (v[0] != '9') {
        options[0][0] = (char)((int)(v[0])+1);
    } if (v[s-1] != '1') {
        options[1][s-1] = (char)((int)(v[s-1])-1);
    }
    for (int i = 0; i < s; i++) options[2][(i+1)%s] = v[i];
    for (int i = 0; i < s; i++) options[3][i] = v[(i+1)%s];

    return options;
}

void printPath(vs &from, string &start, string &finish){
    vs path;
    for (auto v = from[stoi(finish)]; v != "-1"; v = from[stoi(v)]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (string &s : path){
        cout << s << endl;
    }
    cout << finish;
}

void bfs(string &start, string &finish){
    vi dist(stoi(finish)*10, INF);
    vs from(stoi(finish)*10, "-1");
    queue<string> q;

    dist[stoi(start)] = 0;
    q.push(start);

    while (!q.empty()){
        string v = q.front();
        q.pop();

        if (v == finish){
            printPath(from, start, finish);
            return;
        }

        for (string &option : getOptions(v)){
            if (dist[stoi(option)] > dist[stoi(v)] + 1) {
                dist[stoi(option)] = dist[stoi(v)] + 1;
                from[stoi(option)] = v;
                q.push(option);
            }
        }
    }
}

int main(){
    string start, finish;
    cin >> start >> finish;

    bfs(start, finish);

    return 0;
}