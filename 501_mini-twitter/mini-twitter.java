/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/mini-twitter
@Language: Java
@Datetime: 16-06-07 08:26
*/

/**
 * Definition of Tweet:
 * public class Tweet {
 *     public int id;
 *     public int user_id;
 *     public String text;
 *     public static Tweet create(int user_id, String tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
public class MiniTwitter {

    public MiniTwitter() {
        // initialize your data structure here.
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    public Tweet postTweet(int user_id, String tweet_text) {
        //  Write your code here
        List<Tweet> myTweets = tweets.get(user_id);
        if (null == myTweets) {
            myTweets = new ArrayList<Tweet>();
            tweets.put(user_id, myTweets);
        }
        Tweet t = Tweet.create(user_id, tweet_text);
        myTweets.add(t);
        return t;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    public List<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        class Item {
            public Tweet tweet;
            public int index;
            public Item(Tweet t, int i) {
                this.tweet = t;
                this.index = i;
            }
        }
        Comparator<Item> cmp = new Comparator<Item>() {
            public int compare(Item a, Item b) {
                Tweet t = a.tweet, s = b.tweet;
                if (t.id > s.id) return -1;
                if (t.id < s.id) return 1;
                return 0;
            }
        };
        
        PriorityQueue<Item> pq = new PriorityQueue<Item>(11, cmp);
        List<List<Tweet>> list = new ArrayList<List<Tweet>>();
        List<Integer> friends = follows.get(user_id);
        List<Tweet> result = new ArrayList<Tweet>();
        if (friends != null) {
            for (Integer f : friends) {
                List<Tweet> fTweets = tweets.get(f);
                if (fTweets != null && fTweets.size() > 0) {
                    list.add(fTweets);
                }
            }
        }
        List<Tweet> own = tweets.get(user_id);
        if (own != null && own.size() > 0) list.add(own);
        
        int[] p = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            p[i] = list.get(i).size() - 1;
            pq.offer(new Item(list.get(i).get(p[i]), i));
        }
        
        for (int k = 0; k < 10 && pq.size() > 0; ++k) {
            Item it = pq.poll();
            result.add(it.tweet);
            p[it.index]--;
            if (p[it.index] >= 0) {
                pq.offer(new Item(list.get(it.index).get(p[it.index]), it.index));
            }
            
        }
        
        return result;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    public List<Tweet>  getTimeline(int user_id) {
        // Write your code here
        List<Tweet> result = new ArrayList<Tweet>();
        List<Tweet> list = tweets.get(user_id);
        if (list == null) return result;
        for (int p = list.size() - 1, i = 0; p >= 0 && i < 10; --p, ++i) {
            result.add(list.get(p));
        }
        return result;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    public void follow(int from_user_id, int to_user_id) {
        // Write your code here
        List<Integer> friends = follows.get(from_user_id);
        if (null == friends) {
            friends = new ArrayList<Integer>();
            follows.put(from_user_id, friends);
        }
        friends.add(new Integer(to_user_id));
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    public void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        List<Integer> friends = follows.get(from_user_id);
        if (null == friends) return;
        friends.remove(new Integer(to_user_id));
    }
    
    private Map<Integer, List<Tweet>> tweets = new HashMap<Integer, List<Tweet>>();
    private Map<Integer, List<Integer>> follows = new HashMap<Integer, List<Integer>>();
}