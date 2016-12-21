/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/add-and-search-word
@Language: Java
@Datetime: 15-12-14 05:43
*/

class WordDictionary {

    // Adds a word into the data structure.
    public void addWord(String word) {
        trie.put(word, new Object());
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        return trie.get(word) != null;
    }
    private static class Trie<V> {
        public  class TrieNode {
        	V v;
            TrieNode[] next =   (Trie<V>.TrieNode[]) new Trie.TrieNode[26];
        }
        private TrieNode root = new TrieNode();
        private TrieNode put(TrieNode node, String key, int i, V value) {
            if (node == null) node = new TrieNode();
            if (i == key.length()) {
            	node.v = value;
            	return node;
            }
            node.next[key.charAt(i) - 'a'] = put(node.next[key.charAt(i) - 'a'], key, i + 1, value);
            return node;
        }
        public void put(String key, V value) {
            put(root, key, 0, value);
        }
        private TrieNode get(TrieNode node, String key, int i) {
            if (node == null) return null;
            if (i == key.length()) return node.v == null ? null : node;
            char c = key.charAt(i);
            if (c != '.') return get(node.next[c - 'a'], key, i + 1);
            for (int k = 0; k < 26; ++k) {
                TrieNode x = get(node.next[k], key, i + 1);
                if (x != null && x.v != null) return x;
            }
            return null;
        }
        public V get(String key) {
            TrieNode x = get(root, key, 0);
            return x == null ? null : x.v;
        }
    }
    private Trie<Object> trie = new Trie<Object>();
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");