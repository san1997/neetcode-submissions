class Twitter {
public:
    map<int, vector<pair<int,int> >> tweets;
    map<int, vector<int>> follows;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> userFollows = follows[userId];
        vector<pair<int, int>> allTweets;
        bool followsSelf = false;

        for (int i=0; i<userFollows.size(); i++) {
            int follow = userFollows[i];
            if (follow == userId) {
                followsSelf = true;
            }
        }

        if (!followsSelf) {
            userFollows.push_back(userId);
        }
        
        for (int i=0; i<userFollows.size(); i++) {
            int follow = userFollows[i];

            vector<pair<int, int>> followingTweets = tweets[follow];
            for (int j=0; j<followingTweets.size(); j++) {
                allTweets.push_back(followingTweets[j]);
            }
        }

        sort(allTweets.begin(), allTweets.end());

        vector<int> toptweets;
        int sz = 0;
        for (int i=allTweets.size() - 1; i >= 0 && sz < 10; i--) {
            sz++;
            toptweets.push_back(allTweets[i].second);
        }

        return toptweets;

    }
    
    void follow(int followerId, int followeeId) {
        bool alreadyFollows = false;
        for (int i=0; i < follows[followerId].size(); i++) {
            if (follows[followerId][i] == followeeId) {
                alreadyFollows = true;
            }
        }

        if (alreadyFollows) {
            return ;
        }

        follows[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int>& following = follows[followerId];
        for (auto it = following.begin(); it != following.end(); it++) {
            if (*it == followeeId) {
                following.erase(it);
                return ;
            }
        }
    }
};
