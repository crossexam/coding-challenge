/*
  Link: https://leetcode.com/problems/power-of-three/
  Given an integer n, return true if it is a power of three. Otherwise, return false.

  An integer n is a power of three, if there exists an integer x such that n == x3.

   

  Example 1:

  Input: n = 27
  Output: true
  Example 2:

  Input: n = 0
  Output: false
  Example 3:

  Input: n = 9
  Output: true
  Example 4:

  Input: n = 45
  Output: false
   

  Constraints:

  -231 <= n <= 231 - 1
   

  Follow up: Could you do it without using any loop / recursion?

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
         if(n<=0) return false; // We can not devide/mod to zero
         long _n = n;
         long v = pow(3,19);
         return !(v%_n);
    }
};

class loopSolution {
public:
   bool isPowerOfThree(int n) {
   	if(n<=0) return false;
        while(!(n%3)) n/=3;
        return n == 1;
   } 

}
