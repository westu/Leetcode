class Worker {
 public:
  Worker(int quality, int wage) {
    quality_ = quality;
    wage_ = wage;
    rate_ = wage_ / quality_;
  }
  bool operator<(const Worker &worker) {
    return rate_ < worker.rate_;
  }

  double quality_;
  double wage_;
  double rate_;
};

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    if (K == 0) {
      return 0;
    }
    vector<Worker> workers;
    for (int i = 0; i < quality.size(); ++i) {
      workers.push_back(Worker(quality[i], wage[i]));
    }
    sort(workers.begin(), workers.end());
    priority_queue<double> qualities;
    double ans(0), sum(0);
    for (auto worker : workers) {
      sum += worker.quality_;
      qualities.push(worker.quality_);
      if (qualities.size() > K) {
        sum -= qualities.top();
        qualities.pop();
      }
      if (qualities.size() == K) {
        ans = ans == 0 ? sum * worker.rate_ : min(ans, sum * worker.rate_);
      }
    }
    return ans;
  }
};
