#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

class Twitter {
private:
    struct Tweet {
        int tweetId;
        int timestamp;
        Tweet(int id, int time) : tweetId(id), timestamp(time) {}
    };

    int timestamp;
    std::unordered_map<int, std::vector<Tweet>> tweets;
    std::unordered_map<int, std::unordered_set<int>> followers;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp++);
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<Tweet> feed;

        feed.insert(feed.end(), tweets[userId].begin(), tweets[userId].end());

        for (int followeeId : followers[userId]) {
            feed.insert(feed.end(), tweets[followeeId].begin(), tweets[followeeId].end());
        }

        std::sort(feed.begin(), feed.end(), [](const Tweet &a, const Tweet &b) {
            return a.timestamp > b.timestamp;
        });

        std::vector<int> newsFeed;
        for (int i = 0; i < std::min(10, int(feed.size())); ++i) {
            newsFeed.push_back(feed[i].tweetId);
        }

        return newsFeed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
