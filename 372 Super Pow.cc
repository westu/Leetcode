class Solution {
public:
    int superPow(int a, vector<int>& b) {
      if (a == 0 || a == 1) {
        return a;
      }
      if (b.empty()) {
        return a;
      }
      a = a % 1337;  // in case of a is very large
      vector<int> pow_list = get_pow_list(a);
      
      int len = static_cast<int>(b.size());
      int result = 1;
      for (int i = len - 1; i >= 0; --i) {
        int pow_rounds = len - 1 - i;
        result = result * get_10pow(pow_list.at(b.at(i)), pow_rounds) % 1337;
      }
      return result;
    }

 private:
  vector<int> get_pow_list(int a) {
    vector<int> pow_list(10);
    pow_list.at(0) = 1;
    for (int i = 1; i <= 9; ++i) {
      pow_list.at(i) = pow_list.at(i - 1) * a % 1337;
    }
    return pow_list;
  }
  
  int get_10pow(int a, int pow_rounds) {  // returns pow(a, 10 * pow_rounds)
    int result = a;
    for (int i = 1; i <= pow_rounds; ++i) {
      int result2 = get_square(result);
      int result8 = get_square(get_square(result2));
      result = (result2 * result8) % 1337;
    }
    return result;
  }
  
  int get_square(int num) {
    return num * num % 1337;
  }
};
