/*
  Link: https://leetcode.com/problems/thousand-separator/

  Given an integer n, add a dot (".") as the thousands separator and return it in string format.

   

  Example 1:

  Input: n = 987
  Output: "987"
  Example 2:

  Input: n = 1234
  Output: "1.234"
  Example 3:

  Input: n = 123456789
  Output: "123.456.789"
  Example 4:

  Input: n = 0
  Output: "0"
   

  Constraints:

  0 <= n < 2^31

*/

class Solution {
public:
  string thousandSeparator(int n) {
    string s = to_string(n);
    string r = "";
    int l = s.length();
    int count = 0;
    for (int i = l - 1; i >= 0 ; i--) {
      count += 1;
      if (count == 3) {
	string t = i ? "." : "";
	t+=s[i];
	r = t + r;
	count = 0;
      } else {
	r = s[i] + r;
      }
    }
    return r;
  }
};
