#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "StringMatching.cpp"
#include "LongestCommonSubstring.cpp"
#include "LongestPalindromicSubstring.cpp"

using namespace std;

string getFileContentAsString(string filePath){
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cout << "Could not open the file - '" 
            << filePath << "'" << endl; 
    }
    stringstream buffer;
    buffer << inputFile.rdbuf();
    return buffer.str();
}

int main(){
    vector<string> transmissions;
    vector<string> maliciousCodes;
    transmissions.push_back(getFileContentAsString("transmission1.txt"));
    transmissions.push_back(getFileContentAsString("transmission2.txt"));
    maliciousCodes.push_back(getFileContentAsString("mcode1.txt"));
    maliciousCodes.push_back(getFileContentAsString("mcode2.txt"));
    maliciousCodes.push_back(getFileContentAsString("mcode3.txt"));
    
    for(string transmission : transmissions) {
        for (string maliciousCode : maliciousCodes) {
            StringMatching::solve(transmission, maliciousCode);
        }
    }

    for(string transmission : transmissions) {
        LongestPalindromicSubstring::solve(transmission);
    }

    LongestCommonSubstring::solve(transmissions[0],transmissions[1]);


    // StringMatching.solve(transmissions[0], maliciousCodes[0]);
    // StringMatching.solve(transmission1, mcode2);
    // StringMatching.solve(transmission1, mcode3);
    // StringMatching.solve(transmission2, mcode1);
    // StringMatching.solve(transmission2, mcode2);
    // StringMatching.solve(transmission2, mcode3);

    // LongestPalindromicSubstring.solve(transmission1);
    // LongestPalindromicSubstring.solve(transmission2);
    return 0;
}