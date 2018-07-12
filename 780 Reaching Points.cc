class Solution {
 public:
  /**
   * @param sx: x for starting point
   * @param sy: y for starting point
   * @param tx: x for target point 
   * @param ty: y for target point
   * @return: if a sequence of moves exists to transform the point (sx, sy) to (tx, ty)
   */
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx > sx && ty > sy) {
      if (tx > ty) {
        tx %= ty;
      } else {
        ty %= tx;
      }
    }
    return tx == sx && (ty - sy) % sx == 0 ||
        ty == sy && (tx - sx) % sy == 0;
  }
};
