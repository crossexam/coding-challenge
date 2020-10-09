## **Challenge**
Have the function SimpleSymbols(str) take the str parameter being passed and determine if it is an acceptable sequence by either returning the string true or false. The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. The string will not be empty and will have at least one letter.

## **Sample Test Cases**
```
Input:"+d+=3=+s+"
Output:true

Input:"f++d+"
Output:false
```

### 1. Javascript:
Hard to do with Regex
```
SimpleSymbols=x=>!(!/\w/[t='test'](x)||/^[a-z]+$/[t](x))&&!(/[^+][a-z]\+/gi[t](x)||/\+[a-z][^+]/gi[t](x))
```

### 2. Python 3:
```
def SimpleSymbols(str):
    l = list(str)

    for i,v in enumerate(l):
        if not i and v.isalpha():
            return False
        elif i == len(l) - 1:
            return not v.isalpha()
        elif v.isalpha() and (l[i-1] != '+' or l[i+1] != '+'):
            return False

    return True
```