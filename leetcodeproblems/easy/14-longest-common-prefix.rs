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

// impl Solution {
//     pub fn longest_common_prefix(strs: Vec<String>) -> String {
//         if strs.len() == 0 {return String::new()}
//         if strs.len() == 1 {return strs[0].clone()}
//         let mut cnt = 1;
//         let mut ideal = strs[0].clone();
//         let mut sum = String::new();
//         let mut min_len = strs[0].len();
//         while min_len != 0 {
//             sum = ideal[..cnt].to_string();
//             for j in 1..strs.len() {
//                 if strs[j].len() < min_len {
//                     if strs[j].len() == 0 {return String::new()}
//                     min_len = strs[j].len()
//                 }
//                 if sum != strs[j][..cnt]{
//                     sum.pop();
//                     return sum;
//                 }
//             }
//             cnt+=1;
//             min_len-=1;
//         }
//         sum
//     }
// }

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String { 
        match strs.is_empty() {
            true => "".to_string(),
            _ => {
                strs.iter().skip(1).fold(strs[0].clone(), |acc, x| {
                     acc
                        .chars()
                        .zip(x.chars())
                        .take_while(|(x,y)| x == y)
                        .map(|(x, _)| x)
                        .collect()
                })
            }
        }
    }
}
