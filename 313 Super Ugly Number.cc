class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int l = static_cast<int>(primes.size());
        vector<int> ptr(l, 0);
        
        vector<int> num_list;
        num_list.push_back(1);
        
        for (int i = 1; i < n; ++i) {
            int min_num = num_list.at(ptr.at(0)) * primes.at(0);
            for (int i = 1; i < l; ++i) {
                min_num = min(min_num, num_list.at(ptr.at(i)) * primes.at(i));
            }
            num_list.push_back(min_num);
            
            for (int i = 0; i < l; ++i) {
                if (num_list.at(ptr.at(i)) * primes.at(i) == num_list.back()) {
                    ++ptr.at(i);
                }
            }
        }
        
        return num_list.back();
    }
};
