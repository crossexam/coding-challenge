def newRoadSystem(roadRegister):
  for x, y in zip(map(sum, roadRegister), map(sum, zip(*roadRegister))):
    if x != y:
      return False
  return True


roadRegister = [[False, True, False],
                [False, False, False],
                [True, False, False]]


print(newRoadSystem(roadRegister))
