class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return majorityElement(nums, 3);
    }

private:
    vector<int> majorityElement(vector<int>& nums, int k) {
        vector<int> elements(k - 1, 0);
        vector<int> counts(k - 1, 0);
        int valid_element = 0;
        for (int num : nums) {
            bool has_found = false;
            for (int i = 0; i < k - 1; ++i) {
                if (elements.at(i) == num) {
                    ++counts.at(i);
                    if (counts.at(i) == 1) {
                        ++valid_element;
                    }
                    has_found = true;
                    break;
                }
            }
            
            if (!has_found) {
                if (valid_element < k - 1) {
                    for (int i = 0; i < k - 1; ++i) {
                        if (counts.at(i) == 0) {
                            elements.at(i) = num;
                            counts.at(i) = 1;
                            ++valid_element;
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < k - 1; ++i) {
                        --counts.at(i);
                        if (counts.at(i) == 0) {
                            --valid_element;
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < k - 1; ++i) {
            if (counts.at(i) > 0 && count(nums.begin(), nums.end(), elements.at(i)) > nums.size() / k) {
                ans.push_back(elements.at(i));
            }
        }
        return ans;
    }
};
