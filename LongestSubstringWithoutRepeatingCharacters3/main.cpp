//
//  main.cpp
//  LongestSubstringWithoutRepeatingCharacters3
//
//  Created by Aj Gill on 9/26/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int length = 0;
    //Let for loop control one pointer while using
    for(int beginPtr = 0; beginPtr<s.length(); beginPtr++){
        //Temp string to contain characters from the window
        string container = "";
        //Start the endPtr from the begin pointer each time
        int endPtr = beginPtr;
        while(endPtr < s.length()){
            //If it's not found, then add it to the container and increment
            if(container.find(s[endPtr]) == string::npos){
                container += s[endPtr];
                endPtr++;
            }
            //If it exists, exit the while loop
            else{
                break;
            }
            //Compare and set length if the container is larger
            length = max(length, int(container.length()));
        }
    }
    return length;
}

int main() {
    string s = "abcabcbb";
    cout << "The largest substring without repeating characters is of size: " << lengthOfLongestSubstring(s) << "\n";
}
