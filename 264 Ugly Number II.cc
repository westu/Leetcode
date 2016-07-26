class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
                if (n == 1) {
            return 1;
        }
        vector<queue<long long> > queue_list(3);
        vector<int> factors(3);
        factors.at(0) = 2;
        factors.at(1) = 3;
        factors.at(2) = 5;
        for (int k = 0; k < 3; ++k) {
            queue_list.at(k).push(factors.at(k));
        }
        
        long long min_v;
        for (int i = 1; i < n; ++i) {
            int k(0);
            min_v = queue_list.at(0).front();
            for (int j = 1; j < 3; ++j) {
                if (queue_list.at(j).front() < min_v) {
                    k = j;
                    min_v = queue_list.at(j).front();
                }
            }
            if (i == n - 1) {
                break;
            }
            
            queue_list.at(k).pop();
            for (int j = k; j < 3; ++j) {
                queue_list.at(j).push(factors.at(j) * min_v);
            }
        }
        return min_v;
    }
};
