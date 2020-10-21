/*
  Link: https://leetcode.com/problems/longest-common-prefix/submissions/

  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

   

  Example 1:

  Input: strs = ["flower","flow","flight"]
  Output: "fl"
  Example 2:

  Input: strs = ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.
   

  Constraints:

  0 <= strs.length <= 200
  0 <= strs[i].length <= 200
  strs[i] consists of only lower-case English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (!size) return "";
        if (size == 1) return strs[0];
        string first = strs[0];
        int len = first.length();
        
        while (len) {
          bool ok = true;
          string string_to_check = first.substr(0, len);
          for (int i = 1; i < size; i++) {
            if(strs[i].find(string_to_check) != 0 ) {
              ok = false;
              break;
            }
          }
          if(ok) return string_to_check;
          len --;
        }
        return "";
    }
};


// lesson learned: for longest/maximum problem, you need to think greedy first!
