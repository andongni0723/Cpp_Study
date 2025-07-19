from collections import defaultdict
from heapq import heappush, heappop
from typing import List

class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.followees = defaultdict(set) # {'userId': set(userID)}
        self.tweets = defaultdict(list)  # {'userId': [(timestamp, tweetId)]}

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append((self.timestamp, tweetId))
        self.timestamp += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        self.followees[userId].add(userId)

        max_heap = [] # (-timestamp, tweetId, userId, tweedIdx)
        for id in self.followees[userId]:
            last_tweetId_idx = len(self.tweets[id]) - 1
            if last_tweetId_idx >= 0:
                last_timestamp, last_tweetId = self.tweets[id][last_tweetId_idx]
                heappush(max_heap, (-last_timestamp, last_tweetId, id, last_tweetId_idx))

        new_feed = []
        while max_heap and len(new_feed) < 10:
            _ , tweedId, userId, tweedIdx = heappop(max_heap)
            new_feed.append(tweedId)
            if tweedIdx - 1 >= 0:
                last_tweetId_idx = tweedIdx - 1
                last_timestamp, last_tweetId = self.tweets[userId][last_tweetId_idx]
                heappush(max_heap, (-last_timestamp, last_tweetId, userId, last_tweetId_idx))
        return new_feed

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followees[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId: return
        self.followees[followerId].discard(followeeId)