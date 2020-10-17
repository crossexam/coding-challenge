/*
  https://leetcode.com/problems/find-common-characters/

  Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

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

commonChars = A => {
  const B = A.map(v=>[...v].reduce((m,n) => ({...m, [n]: -~m[n]}) , {}));
  const O = {};
  for (const obj of B) {
    for (const o of Object.keys(obj) ) {
      if (O[o]) {
        O[o].push(obj[o]);
      } else {
        O[o] = [obj[o]];
      }
    }
  }
  const res = [];
  for (const k in O) {
    if (O[k].length != A.length) continue;
    const m = Math.min(...O[k]);
    for(let i=0; i < m; i++) {
      res.push(k);
    }
  }
  return res;
}

// Semi-final solution
commonCharsRefactor = A => {
  const res = [];
  const o = {}
  if(A.length <2 )return [];
  for(let i =0; i< A.length;i++) {
      for(const char of A[i]) {
        if (o[char] === undefined) {
          o[char] = {
            missed: i?true:false,
            quantity:Infinity,
            c: char,
            count: 1,
          }
          continue
        }
        else if(o[char]["missed"]) {
          continue
        }
        else (o[char].count += 1);
      }
      for(const key in o) {
        if(o[key]["count"] < o[key]["quantity"]) {
           o[key]["quantity"] = o[key]["count"];
        }
        o[key]["count"] = 0;
      }
      
    }
  
  for (const k in o) {
    if(!o[k]["missed"]) {
      for (let j = 0;j < o[k]["quantity"];j++) {
        res.push(o[k]["c"]);
      }
    }
  }
  return res;
}

//Final solution (after get the idea from other's approach)
commonCharsFinal = A => {
  if (A.length < 2) return [];
  const res = [];
  const [first] = A.sort((a,b) => a.length - b.length);
  for (const char of first) {
    let isMissed = false;
    for(let i = 1; i< A.length; i++) {
      if(A[i].includes(char)) {
        A[i] = A[i].replace(char,"");
      } else {
        isMissed = true;
        break;
      }
    }
    
    if (!isMissed)res.push(char);
  }
  return res;
}

// Things learned after first solution
// Number of submissions: 2
// --> The most challenge is logic of code, selecting algorithm, performance and general cases

// Things learned after final solution
// Analyze problems first: What is input/output, scope of the problem
// Think about some high level designs, try atleast 2 or 3 of them
// Pick suitable solution and submit code

