class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum_list.push_back(0);
        int sum = 0;
        for (int num : nums) {
            sum += num;
            sum_list.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sum_list.at(j + 1) - sum_list.at(i);
    }

private:
    vector<int> sum_list;
};
