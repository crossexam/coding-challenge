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

//Solution 1:
const thousandSeparator=n=>n/1e3>1?thousandSeparator(n/1e3|0)+'.'+(n%1e3+'').padStart(3,0):n%1e3+'';

//Solution 2:
const thousandSeparator=x=>{
  x=x+'';s=''
  for(let i = x.length-1; i>=0; i -= 3){
    // s=(i<=2?'':'.')+ (x[i-2]===undefined?'':x[i-2])+(x[i-1]===undefined?'':x[i-1])+x[i]+s;
    if(i<=2) {
      let t = '';
      for (let j = 0; j<=i; j++) {
        t += x[j];
      }
      s = t + (s.length ? '.' : '') + s;
    } else {
      s = x[i-2] + x[i-1] + x[i] + (s.length?'.':'') + s;
    }
  }

  return s;
}

//Solution 3:
const thousandSeparator=x=>x.toLocaleString('de-DE');
