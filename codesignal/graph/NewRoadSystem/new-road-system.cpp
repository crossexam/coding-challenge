#include <cstdio>
#include <vector>
#include <iostream>

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

int main()
{
  std::vector<std::vector<bool>> input1 = {
      {false, true, false},
      {false, false, false},
      {true, false, true},
  };

  std::vector<std::vector<bool>> input2 = {
      {false, true,  false, false},
      {false, false, true,  false},
      {true,  false, false, true},
      {false, false, true,  false},
  };

  bool testcase1 = newRoadSystem(input1);
  bool testcase2 = newRoadSystem(input2);
  printf("%d", testcase1);
  printf("%d", testcase2);
  return 0;
}