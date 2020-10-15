/*
  https://leetcode.com/problems/reverse-integer/
  Given a 32-bit signed integer, reverse digits of an integer.

  Note:
  Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

   

  Example 1:

  Input: x = 123
  Output: 321
  Example 2:

  Input: x = -123
  Output: -321
  Example 3:

  Input: x = 120
  Output: 21
  Example 4:

  Input: x = 0
  Output: 0
   

  Constraints:

  -231 <= x <= 231 - 1
*/

class Solution {
  public:
    int reverse(int x) {
      int r = 0;
      while (true) {
        if(!x) break;
        // We need to check it r * 10 is overflow
        if((r>INT_MAX/10) || (r<INT_MIN/10)) {
          return 0;
        }
        r = r*10 + x %10;
        x /= 10;
      }
     return r;
   }
};
