## Problem: New road system (https://app.codesignal.com/arcade/graphs-arcade/kingdom-roads/nCMisf4ZKpDLdHevE)


Once upon a time, in a kingdom far, far away, there lived a King Byteasar I. As a kind and wise ruler, he did everything in his (unlimited) power to make life for his subjects comfortable and pleasant. One cold evening a messenger arrived at the king's castle with the latest news: all kings in the Kingdoms Union had started enforcing traffic laws! In order to not lose his membership in the Union, King Byteasar decided he must do the same within his kingdom. But what would the citizens think of it?

The king decided to start introducing the changes with something more or less simple: change all the roads in the kingdom from two-directional to one-directional (one-way). He personally prepared the roadRegister of the new roads, and now he needs to make sure that the road system is convenient and there will be no traffic jams, i.e. each city has the same number of incoming and outgoing roads. As the Hand of the King, you're the one who he has decreed must check his calculations.

## Example:

For
```
roadRegister = [[false, true,  false, false],
                [false, false, true,  false],
                [true,  false, false, true ],
                [false, false, true,  false]]
```

the output should be

```
newRoadSystem(roadRegister) = true
```

For
```
roadRegister = [[false, true,  false, false, false, false, false],
                [true,  false, false, false, false, false, false],
                [false, false, false, true,  false, false, false],
                [false, false, true,  false, false, false, false],
                [false, false, false, false, false, false, true ],
                [false, false, false, false, true,  false, false],
                [false, false, false, false, false, true,  false]]
```

the output should be
```
newRoadSystem(roadRegister) = true
```

For
```
roadRegister = [[false, true,  false],
                [false, false, false],
                [true,  false, false]]
```
the output should be:
```
newRoadSystem(roadRegister) = false
```

## Solution:

### Javascript:

```
function newRoadSystem(roadRegister) {
  const len = roadRegister.length;
  for (let i = 0; i < len; i++) {
    let count = 0;
    for (let j = 0; j < len; j++) {
      count += roadRegister[i][j];
      count -= roadRegister[j][i];
    }
    if (count !== 0) {
      return false;
    }
  }
  return true;
}
```

### C++:

```
bool newRoadSystem(std::vector<std::vector<bool>> data){
  int len = data.size();
  for (int i = 0; i < len; i++) {
    int count = 0;
    for (int j = 0; j < len; j++) {
      count += data[i][j] - data[j][i];
    }
    if (count != 0) {
      return false;
    }
  }
  return true;
}
```

### Python3 (solution by dav23r):

```
def newRoadSystem(roadRegister):
  for x, y in zip(map(sum, roadRegister), map(sum, zip(*roadRegister))):
    if x != y:
      return False
  return True
```