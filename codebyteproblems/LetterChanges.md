## **Challenge**
Have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm. Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a). Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string.

### Javascript:
Golf version:
```
LetterChanges=s=>(a='abcdefghijklmnopqrstuvwxyza',s.replace(/./g,v=>(i=a[r='indexOf'](v),i>-1?/[aeiou]/.test(c=a[i+1])?c.toUpperCase():c:v)))
```

### Python:
```
def LetterChanges(s):
    a='abcdefghijklmnopqrstuvwxyza'
    l=list(s)
    for u,i in enumerate(l):
        if i in a:
            ind = a.index(i)
            f = a[ind+1]
            if f in 'aeiou':
                f = f.upper()
            l[u]=f
    return ("").join(l)
  ```
