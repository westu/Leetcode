class LRUCache {
 public:
  /*
  * @param capacity: An integer
  */
  LRUCache(int capacity) {
    size_ = capacity;
  }

  /*
   * @param key: An integer
   * @return: An integer
   */
  int get(int key) {
    if (hash_.find(key) == hash_.end()) {
      return -1;
    }
    move_front(hash_.find(key));
    return (*hash_.find(key)->second).value_;
  }

  /*
   * @param key: An integer
   * @param value: An integer
   * @return: nothing
   */
  void put(int key, int value) {
    cout << key << " " << value << endl;
    if (hash_.find(key) != hash_.end()) {  // don't need elimination
      (*hash_.find(key)->second).value_ = value;
      move_front(hash_.find(key));
      return;
    }

    elements_.push_front(ListElem(key, value));
    hash_[key] = elements_.begin();
    if (elements_.size() > size_) {
      // int del_value = *(elements_.rbegin());
      auto last_it = elements_.end();
      --last_it;
      int del_key = (*last_it).key_;
      elements_.erase(last_it);
      hash_.erase(del_key);
    }
  }

 private:
  struct ListElem {
    ListElem(int key, int value) {
      key_ = key;
      value_ = value;
    }

    int key_;
    int value_;  // in order to modify hash table
  };

  void move_front(unordered_map<int, list<ListElem>::iterator>::iterator hash_it) {
    ListElem list_elem((*hash_it->second).key_, (*hash_it->second).value_);
    elements_.erase(hash_it->second);
    elements_.push_front(list_elem);
    hash_it->second = elements_.begin();
  }

  list<ListElem> elements_;
  unordered_map<int, list<ListElem>::iterator> hash_;
  int size_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
