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

    vector<string> transmissionsFilePaths = { "transmissions1.txt", "transmission2.txt" };
    vector<string> maliciousCodesFilePaths = { "mcode1.txt", "mcode2.txt", "mcode3.txt" };

    for (string path : transmissionsFilePaths) {
        transmissions.push_back(getFileContentAsString(path));
    }

    for (string path : maliciousCodesFilePaths) {
        maliciousCodes.push_back(getFileContentAsString(path));
    }
    
    for(string transmission : transmissions) {
        for (string maliciousCode : maliciousCodes) {
            StringMatching::solve(transmission, maliciousCode);
        }
    }

    for(string transmission : transmissions) {
        LongestPalindromicSubstring::solve(transmission);
    }

    LongestCommonSubstring::solve(transmissions[0],transmissions[1]);

    return 0;
}
