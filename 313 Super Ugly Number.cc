class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int l = static_cast<int>(primes.size());
        vector<int> ptr(l, 0);
        
        vector<int> num_list;
        num_list.push_back(1);
        
        for (int i = 1; i < n; ++i) {
            priority_queue<int, vector<int>, greater<int> > heap;
            for (int i = 0; i < l; ++i) {
                heap.push(num_list.at(ptr.at(i)) * primes.at(i));
            }
            num_list.push_back(heap.top());
            
            for (int i = 0; i < l; ++i) {
                while (num_list.at(ptr.at(i)) * primes.at(i) <= num_list.back()) {
                    ptr.at(i) = ptr.at(i) + 1;
                }
            }
        }
        
        return num_list.back();
    }
};
