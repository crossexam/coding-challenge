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
