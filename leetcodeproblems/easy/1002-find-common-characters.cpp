/*

Link: https://leetcode.com/problems/find-common-characters/
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates). 
For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter

*/
class Solution {
public:
  vector<string> commonChars(vector<string>& A) {
    vector<int> V1(26, INT_MAX);
    vector<string> res;
    int sizeOfA = A.size();
    for(int i = 0; i< sizeOfA; i++) {
      vector<int> V2(26,0);
      for(char c: A[i]) {
        V2[c-'a'] ++;
      }
      for(int i = 0; i<V1.size(); i++) {
        V1[i] = min(V1[i], V2[i]);
      }
    }
    for (int i = 0; i < V1.size(); i++) {
      for (int j = 0; j < V1[i]; j++) {
        string s(1, char(97+i));
        res.push_back(s);
      }
    }
    return res;
  }
};
