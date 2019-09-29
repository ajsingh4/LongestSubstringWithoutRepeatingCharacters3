//
//  main.cpp
//  LongestSubstringWithoutRepeatingCharacters3
//
//  Created by Aj Gill on 9/26/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> table;
    int beginPtr = 0, endPtr = 0, length = 0;
    while(endPtr < s.length()){
        char currentChar = s[endPtr];
        //check if the current character exists in the table
        if(table.count(currentChar) == 1 && table[currentChar] >= beginPtr){
            //if it exists, increment beginPtr
            beginPtr = table[currentChar] + 1;
        }
        else{
            //otherwise add it in and increment endPtr
            table[currentChar] = endPtr;
            endPtr++;
        }
        //check if the current string length is greater than the recorded max
        if(endPtr - beginPtr > length){
            length = endPtr - beginPtr;
        }
    }
    
    return length;
}

int main() {
    string s = "abcabcbb";
    cout << "The largest substring without repeating characters is of size: " << lengthOfLongestSubstring(s) << "\n";
}
