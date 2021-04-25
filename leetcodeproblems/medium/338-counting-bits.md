Link: https://leetcode.com/problems/counting-bits/

Given an integer num, return an array of the number of 1's in the binary representation of every number in the range [0, num].

Example 1:

```
Input: num = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

Example 2:

```
Input: num = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

Constraints:

```
0 <= num <= 105
```

Follow up:

- It is very easy to come up with a solution with run time O(32n). Can you do it in linear time O(n) and possibly in a single pass?
- Could you solve it in O(n) space complexity?
- Can you do it without using any built-in function (i.e., like popcount in C++)?


Solution:

CPP Dynamic programming
```c
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        for (int i = 1; i < num + 1; i++) {
            dp[i] = dp[i/2] + i % 2;
        }
        return dp;
    }
};
```

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for(int n = 1; n <= num; n++)
            ans[n] = ans[n-(n&(-n))] + 1;
        return ans;
    }
};
```


JS codegolf
```javascript
countBits=n=>[...Array(n+1).keys()].map((v,i,A)=>i?(A[i]=A[i>>1]+i%2):0) 
```


