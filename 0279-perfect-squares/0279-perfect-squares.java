class Solution {
     int[] squares = new int[100];
  int[] marked;
  List<Integer> toCheck = new ArrayList<>();

  public int numSquares(int n) {
    marked = new int[n+1];
    for (int i = 1; i <= 100 && i*i <= n; i++) {
      int square = i*i;
      if (square == n) {
        return 1;
      }
      squares[i] = square;
      marked[i] = 1;
      toCheck.add(square);
    }
    for (int k = 2; ; k++) {
      List<Integer> tmpToCheck = new ArrayList<>();
      for (int i = 0; i < 100; i++) {
        for (int j = 0; j < toCheck.size(); j++) {
          int tmp = squares[i];
          int check = toCheck.get(j);
          int sum = tmp + check;
          if (sum == n) {
            return k;
          }
          if (sum < n && marked[sum] == 0) {
            marked[sum] = k;
            tmpToCheck.add(sum);
          }
        }
      }
      toCheck = tmpToCheck;
    }
  }
}