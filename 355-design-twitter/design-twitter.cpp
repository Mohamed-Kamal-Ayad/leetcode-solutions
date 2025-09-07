class Twitter {
private:
    unordered_map<int, pair<unordered_set<int>, vector<pair<int, int>>>> users;
    int incremental = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        users[userId].second.push_back({++incremental, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        pair<unordered_set<int>, vector<pair<int, int>>> userDetails =
            users[userId];
        priority_queue<pair<int, int>> tweets(userDetails.second.begin(),
                                              userDetails.second.end());
        for (auto f : userDetails.first) {
            for (auto fTweet : users[f].second) {
                tweets.push(fTweet);
            }
        }
        vector<int> res;
        for (int i = 0; i < 10 && !tweets.empty(); i++) {
            res.push_back(tweets.top().second);
            tweets.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        users[followerId].first.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        users[followerId].first.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */