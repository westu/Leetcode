class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ++timestamp;
        check_id(userId);
        auto it = user_set.find(userId);
        it->second.tweet_list.push_back(make_pair(timestamp,tweetId));
        it->second.news_feed_list.insert(make_pair(timestamp,tweetId));
        
        for (auto follower_it = it->second.follower_list.begin();
            follower_it != it->second.follower_list.end(); ++follower_it) {
            user_set.find(*follower_it)->second.news_feed_list.
                insert(make_pair(timestamp,tweetId));
        }
        it = user_set.find(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        check_id(userId);
        User user = user_set.find(userId)->second;
        int count = 0;
        vector<int> ans;
        
        for (auto it = user.news_feed_list.rbegin();
            it != user.news_feed_list.rend(); ++it) {
            ans.push_back(it->second);
            ++count;
            if (count == 10) {
                break;
            }
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        check_id(followerId);
        check_id(followeeId);
        auto it1 = user_set.find(followerId);
        auto it2 = user_set.find(followeeId);
        it2->second.follower_list.push_back(followerId);
        for (auto tweet : it2->second.tweet_list) {
            it1->second.news_feed_list.insert(tweet);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        check_id(followerId);
        check_id(followeeId);
        auto it1 = user_set.find(followerId);
        auto it2 = user_set.find(followeeId);
        it2->second.follower_list.remove(followerId);
        for (auto tweet : it2->second.tweet_list) {
            it1->second.news_feed_list.erase(tweet.first);
        }
    }

private:
    class User {
    public:
        vector<pair<int, int> > tweet_list;  // tweets of this user
        list<int> follower_list;
        map<int, int> news_feed_list;  // tweets of his/her timeline
    };

    int timestamp;
    unordered_map<int, User> user_set;

    void check_id(int id) {
        if (user_set.find(id) == user_set.end()) {
            User tmp_user;
            user_set.insert(make_pair(id, tmp_user));
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
