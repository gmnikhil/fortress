#include<iostream>
#include<string>

using namespace std;

class Solution {
public:

    int strStr(string haystack, string needle) {
          for(int i=0; i<haystack.length(); i++) {
              bool f = true;
              for(int j=0; j<needle.length(); j++) {
                  if(i+j >= haystack.length()) {
                      f = false;
                      break;
                  }
                  if(haystack[i+j] != needle[j]) f = false;
              }
              if(f) return i;
          }
          return -1;
    }

};