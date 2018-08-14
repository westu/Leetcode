class Solution {
 public:
  /**
   * @param flights: the airline status from the city i to the city j
   * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
   * @return: the maximum vacation days you could take during K weeks
   */
  int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
    int city_num(flights.size()), week_num(days[0].size());
    for (int i = 0; i < city_num; ++i) {
      flights[i][i] = 1;
    }
    vector<vector<int>> vacation_days(city_num, vector<int>(week_num + 1, -1));
    // -1 means cant go there

    vacation_days[0][0] = 0;
    for (int j = 1; j <= week_num; ++j) {
      for (int i = 0; i < city_num; ++i) {
        for (int last_city = 0; last_city < city_num; ++last_city) {
          if (vacation_days[last_city][j - 1] > -1 && flights[last_city][i] == 1) {
            vacation_days[i][j] = max(vacation_days[i][j], 
                vacation_days[last_city][j - 1] + days[i][j - 1]);  // days' index starts from 0
          }
        }
      }
    }

    int res(0);
    for (int i = 0; i < city_num; ++i) {
      res = max(res, vacation_days[i][week_num]);
    }
    return res;
  }
};
