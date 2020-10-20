/*
  Link: https://leetcode.com/problems/longest-common-prefix/

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


longestCommonPrefix = s => {
    if (s.length === 1) return s[0];
    if (!s.length) return "";
    s.sort((a,b)=> a.length - b.length);
    
    const tails = s.slice(1);
    let [a] = s;
    while(a.length) {
        if (tails.every(v=>v.startsWith(a))) {
            return a;
        }
        a = a.slice(0,a.length-1);
    }
    return a;
}
