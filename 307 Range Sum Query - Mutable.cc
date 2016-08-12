class NumArray {
public:
    NumArray(vector<int> &nums) {
        int l = static_cast<int>(nums.size()) + 1;
        binary_indexed_tree = vector<int>(l, 0);
        prev_num = vector<int>(l, 0);
        for (int i = 1; i < l; ++i) {
            update(i - 1, nums.at(i - 1));
        }
    }

    void update(int i, int val) {
        int j = i + 1;
        while (j < binary_indexed_tree.size()) {
            binary_indexed_tree.at(j) += val - prev_num.at(i + 1);
            j += j & (-j);
        }
        prev_num.at(i + 1) = val;
    }

    int sumRange(int i, int j) {
        return get_sum(j + 1) - get_sum(i);
    }

private:
    vector<int> binary_indexed_tree;
    vector<int> prev_num;
    
    int get_sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += binary_indexed_tree.at(i);
            i -= i & (-i);
        }
        return sum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
