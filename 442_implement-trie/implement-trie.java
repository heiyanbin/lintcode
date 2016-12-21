/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/implement-trie
@Language: Java
@Datetime: 15-10-13 06:43
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie = new Trie();
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
    // Initialize your data structure here.
    public TrieNode() {
        
    }
    Object value;
	TrieNode[] next = new TrieNode[256];
}

public class Solution {
    private TrieNode root;

    public Solution() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        insert(root, word, new Object(), 0);
    }
	private TrieNode insert(TrieNode node, String word, Object value, int i) {
		if (node == null) node = new TrieNode();
		if (i == word.length()) {
		    node.value = value;
		    return node;
		}
		char p = word.charAt(i);
		node.next[p] = insert(node.next[p], word, value, i + 1);
		return node;
	}

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode node = search(root, word, 0);
		return node != null && node.value != null;
    }
	private TrieNode search(TrieNode node, String word, int i) {
		if (node == null) return null;
		if (i == word.length()) return node;
		char p = word.charAt(i);
		return search(node.next[p], word, i + 1);
	}
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode node = search(root, prefix, 0);
		return hasKey(node);
    }
	boolean hasKey(TrieNode node) {
		if (node == null) return false;
		if (node.value != null) return true;
		for (char c = 0; c < 256; ++c){
			if (hasKey(node.next[c])) return true;
		}
		return false;
	}
}
