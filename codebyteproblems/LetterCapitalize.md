## **Challenge**
Have the function LetterCapitalize(str) take the str parameter being passed and capitalize the first letter of each word. Words will be separated by only one space.

## **Sample Test Cases**
```
Input:"hello world"
Output:Hello World

Input:"i ran there"
Output:I Ran There
```

### 1. JS:

```
LetterCapitalize=s=>s.replace(/\b\w/g,v=>v.toUpperCase())
```

### 2. Python 3:
- Solution 1 (this is mine, not so good because it causes side effect)
```
def LetterCapitalize(str):
  l = list(str)
  for i, v  in enumerate(l):
    if not i or l[i-1] == " ":
      l[i] = l[i].upper()
  return ("").join(l)
```
Solution 2
```
def LetterCapitalize(s): 
    l = s.split()
    for i in range(len(l)):
        l[i] = l[i][0].upper() + l[i][1:]
    return ' '.join(l)
```
```
def LetterCapitalize(string): 
   res = []
   for w in string.split():
      res.append(w[0].upper() + w[1:])
   return ' '.join(res)
```

Solution 3
```
def LetterCapitalize(str): 
  result = ''
  for x in str.split():
    result += " " + x[0].upper() + x[1:]
  return result 
```

Solution 4
```
def LetterCapitalize(str): 

    return ' '.join([x.capitalize() for x in str.split()])
```