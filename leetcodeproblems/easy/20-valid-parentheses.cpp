/*
  Link: https://leetcode.com/problems/valid-parentheses/
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
   

  Example 1:

  Input: s = "()"
  Output: true
  Example 2:

  Input: s = "()[]{}"
  Output: true
  Example 3:

  Input: s = "(]"
  Output: false
  Example 4:

  Input: s = "([)]"
  Output: false
  Example 5:

  Input: s = "{[]}"
  Output: true
   

  Constraints:

  1 <= s.length <= 104
  s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<string, string> m({
            {"}", "{"},
            {"]", "["},
            {")", "("},
        });
        vector<string> v;
        vector<string> open_sign{"{", "[", "("};
        for (auto c: s) {
            string key = string(1, c);
            if(count(open_sign.begin(), open_sign.end(), key)) {
                v.push_back(key);
                continue;
            }
            if(!v.size()) return false;
            if(v[v.size() - 1] !=  m[key]) return false;
            v.pop_back();
        }
        return v.size() == 0;
    }
};


// This is another solution that faster than 100% submissions (notice we are use "char" instead of "string"): 

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m({
            {'}', '{'},
            {']', '['},
            {')', '('},
        });
        vector<char> v;
        vector<char> open_sign{'{', '[', '('};
        for (auto c: s) {
            if(count(open_sign.begin(), open_sign.end(), c)) {
                v.push_back(c);
                continue;
            }
            if(!v.size()) return false;
            if(v[v.size() - 1] !=  m[c]) return false;
            v.pop_back();
        }
        return v.size() == 0;
    }
};
