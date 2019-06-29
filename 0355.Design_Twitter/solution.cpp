#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Post {
public:
    Post(int ID, int tweetID) {
        postId = ID;
        content = tweetID;
    }
    int getPostID() {
        return postId;
    }
    int getContent() {
        return content;
    }
private:
    int postId;
    int content;
};

class User {
public:
    User() {myID = -1;} // invalid user
    User(int userId) {
        following.push_back(userId);
        myID = userId;
    }
    vector<int> getFollowingList() {
        return following;
    }
    void follow(int userid) {
        for (auto id : following) {
            if (id == userid) return;
        }
        following.push_back(userid);
    }
    void unfollow(int userid) {
        if (userid == myID) return; // we can't unfollow ourselves
        for (int i = 0; i < following.size(); i++) {
            if (following[i] == userid) {
                following.erase(following.begin()+i);
            }
        }
    }
    void postTweet(Post tweet) {
        posts.push_back(tweet);
    }
    Post *getLatestPost(int postID) {
        for (int i = posts.size()-1; i >= 0; i--) {
            if (posts[i].getPostID() < postID) {
                return &posts[i];
            }
        }
        return NULL;
    }
private:
    vector<int> following;
    vector<Post> posts;
    int myID;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        post_num = 0;
    }
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post_num++;
        if (users.find(userId) == users.end()) {
            users[userId] = User(userId);
        }
        users[userId].postTweet(Post(post_num, tweetId));
        //cout << "postTweet userId:" << userId << ", tweetId:" << tweetId << endl;
    }
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (users.find(userId) == users.end()) return {};
        //cout << "Get " << userId << " news feed." << endl;
        vector<int> result;
        vector<int> following = users[userId].getFollowingList();
        int cur_postid = INT_MAX;
        Post *latest_post, *tmp_post;
        for (int i = 0; i < 10; i++) {
            latest_post = NULL;
            for (auto u : following) {
                tmp_post = users[u].getLatestPost(cur_postid);
                if (tmp_post == NULL) continue;
                if (latest_post == NULL) {
                    latest_post = tmp_post;
                    continue;
                }
                if (tmp_post->getPostID() > latest_post->getPostID()) {
                    latest_post = tmp_post;
                }
            }
            if (latest_post == NULL) break; // No latest post.
            cur_postid = latest_post->getPostID();
            result.push_back(latest_post->getContent());
        }
        return result;
    }
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end())
            users[followerId] = User(followerId);
        if (users.find(followeeId) == users.end())
            users[followeeId] = User(followeeId);
        users[followerId].follow(followeeId);
        //cout << followerId << " follows " << followeeId << endl;
    }
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end())
            users[followerId] = User(followerId);
        if (users.find(followeeId) == users.end())
            users[followeeId] = User(followeeId);
        users[followerId].unfollow(followeeId);
        //cout << followerId << " unfollows " << followeeId << endl;
    }
private:
    unordered_map<int,User> users;
    unsigned int post_num;
};

void printFeeds(int user, vector<int> feeds) {
    cout << "News Feed from User " << user << ":";
    for (auto num : feeds)
        cout << num << " ";
    cout << endl;
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main() {
    vector<int> result;
    Twitter *t = new Twitter();
    t->postTweet(1, 100);
    result = t->getNewsFeed(1);
    printFeeds(1, result);
    t->follow(1, 2);
    t->postTweet(2, 200);
    result = t->getNewsFeed(1);
    printFeeds(1, result);
    t->unfollow(1, 2);
    result = t->getNewsFeed(1);
    printFeeds(1, result);
    free(t);
    return 0;
}