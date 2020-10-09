## **Challenge**
Have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it. For example: if num = 4, then your program should return (4 * 3 * 2 * 1) = 24. For the test cases, the range will be between 1 and 18 and the input will always be an integer.

### 1. Recursion:

Python 3:
```
def FirstFactorial(num):
  return 1 if num is 0 or num is 1 else num * FirstFactorial(num - 1)
```

### 2. Loop:

Python 3:
```
def FirstFactorial(num):
  r = 1
  for i in range(1, num + 1):
    r *= i
  return r
```