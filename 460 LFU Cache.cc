class LFUCache {
 public:
  /*
  * @param capacity: An integer
  */
  LFUCache(int capacity) {
    capacity_ = capacity;
  }

  /*
   * @param key: An integer
   * @param value: An integer
   * @return: nothing
   */
  void put(int key, int value) {
    if (capacity_ == 0) {
      return;
    }
      
    if (get(key) != -1) {
      keys_[key].first = value;
      return;
    }
    if (keys_.size() == capacity_) {
      int del_key = freq_[min_freq_].front();
      freq_[min_freq_].pop_front();
      keys_.erase(del_key);
      key2it_.erase(del_key);
    }

    keys_[key] = make_pair(value, 1);
    freq_[1].push_back(key);
    key2it_[key] = --freq_[1].end();
    min_freq_ = 1;
  }

  /*
   * @param key: An integer
   * @return: An integer
   */
  int get(int key) {
    if (keys_.find(key) == keys_.end()) {
      return -1;
    }
    freq_[keys_[key].second].erase(key2it_[key]);
    ++keys_[key].second;
    freq_[keys_[key].second].push_back(key);
    key2it_[key] = --freq_[keys_[key].second].end();
    while (freq_[min_freq_].size() == 0) {
      ++min_freq_;
    }
    return keys_[key].first;
  }

 private:
  int capacity_;
  int min_freq_;
  unordered_map<int, pair<int, int>> keys_;  // key to pair of value & freq
  unordered_map<int, list<int>> freq_;  // freq to keys of this freq
  unordered_map<int, list<int>::iterator> key2it_;  // key to its iter in list
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
