#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("d2.txt");
    ofstream out("d2ans.txt");

    if (in.is_open() && out.is_open()) {
        int t;
        in >> t;

        for (int i = 0; i < t; i++) {
            int n, m, k;
            in >> n >> m >> k;

            vector<vector<int>> roads(m, vector<int>(2));
            for (int j = 0; j < m; j++) {
                in >> roads[j][0] >> roads[j][1];
            }

            vector<int> companies(m, 0);
            map<pair<int, int>, int> roadToCompany;

            for (int j = 0; j < m; j++) {
                int from = roads[j][0];
                int to = roads[j][1];

                int company = 1;
                while (roadToCompany.count({from, company}) || roadToCompany.count({to, company})) {
                    company++;
                    if (company > k + 1) {
                        company = k + 1; 
                        break;
                    }
                }

                roadToCompany[{from, company}] = j + 1;
                roadToCompany[{to, company}] = j + 1;
                companies[j] = company;
            }

            for (int j = 0; j < m; j++) {
                out << companies[j] << " ";
            }
            out << endl;
        }
    } else {
        cout << "Error: Unable to open files" << endl;
        return 1;
    }

    in.close();
    out.close();

    return 0;
}
