#include <bits/stdc++.h>
using namespace std;
string pattern;
int T;
int main() {
    cin >> pattern >> T;
    bool has_front_wildcard =  pattern.front() == '*';
    bool has_back_wildcard =  pattern.back() == '*';
    vector<string> tokens;
    stringstream ss(pattern);
    for(string token; getline(ss, token, '*');) {
        if(!token.empty()) tokens.push_back(token);
    }
    
    for(int t = 0; t < T; t++) {
        string input;
        cin >> input;
        bool match = true;
        int char_idx = 0;
        for(int i = 0; i < tokens.size(); i++) {
            size_t found = input.find(tokens[i], char_idx);
            
            if(found == string::npos) {
                match = false; break;
            }
            if(!has_back_wildcard && i == tokens.size() - 1) {
                size_t rfound = input.rfind(tokens[i]);
                if(rfound < found) {
                    match = false; break;
                }
                char_idx = rfound + tokens[i].size(); break;
            }

            if(!has_front_wildcard && i == 0 && found != 0) {
                match = false; break;
            }
            char_idx = found + tokens[i].size();
        }
        if(!has_back_wildcard && char_idx != input.size()) {
            match = false;
        }
        if(match) {
            cout << input <<'\n';
        }
    }
    
}