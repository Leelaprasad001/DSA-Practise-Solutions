class Twitter {
public:
    map<int, set<int>> mp;
    int curr;
    priority_queue<vector<int>> pq;
    Twitter() {
        mp.clear();
        curr = 0;
        pq = priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({curr++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>> temp = pq;
        int n = 0;
        while(!temp.empty() && n < 10) {
            auto topTweet = temp.top();
            temp.pop();
            if(topTweet[2] == userId || mp[userId].count(topTweet[2])){
                res.push_back(topTweet[1]);
                n++;
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         mp[followerId].erase(followeeId);
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