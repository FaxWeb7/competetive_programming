#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

string generateToken(int k){
    string token;
    for (int i = 0; i < k; i++){
        int rnd = rand() % 16;
        char hex_digit = (rnd < 10) ? ('0' + rnd) : ('a' + rnd - 10);
        token.push_back(hex_digit);
    }
    return token;
}

bool checkToken(string token, vector<string>& tokens, int k){
    for (int i = 0; i < k; i++){
        string newToken = token;
        for (int j = 0; j < 16; j++){
            char hex_digit = (j < 10) ? ('0' + j) : ('a' + j - 10);
            newToken[i] = hex_digit;
            for (string currToken : tokens){
                if (currToken == newToken){
                    return false;
                }
            }
        }
    }

    return true;
}

int main(){
    int n = 70000;
    int k = 6;

    ofstream out;
    out.open("b2.txt");
    vector<string> tokens;
    for (int i = 0; i < n; i++){
        string token = generateToken(k);
        while (!checkToken(token, tokens, k)){
            token = generateToken(k);
        }
        tokens.push_back(token);
        cout << i << endl;
        out << token << endl;
    }
    out.close();

    return 0;
}