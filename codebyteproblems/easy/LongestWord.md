## **Challenge**
Have the function LongestWord(sen) take the sen parameter being passed and return the largest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty.

## **Sample Test Cases**

Input: `fun&!! time`

Output: `time`


Input: `I love dogs`

Output: `love`

### 1. Javascript

Golf version using `replace` trick:

```
LongestWord=s=>(A=[],s.replace(/[a-z0-9]+/ig,v=>(!A[l='length']||A[0][l]<v[l])?A[0]=v:''),A[0])
```

### 2. Python
Python best performance version:

```
def LongestWord(sen):
    t = ''
    k=['']
    newSen = sen + ' '
    for i in newSen:
        if i.isalnum():
            t += i
        else:
            if len(k):
                if len(k[0]) < len(t):
                    k[0] = t
            else:
                k.append(t)
            t = ''
    return None if k[0] == '' else k[0]
  ```