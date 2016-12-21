/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/flatten-nested-list-iterator
@Language: Java
@Datetime: 16-06-20 09:33
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
import java.util.Iterator;

public class NestedIterator implements Iterator<Integer> {

    public NestedIterator(List<NestedInteger> nestedList) {
        // Initialize your data structure here.
        this.list = nestedList;
    }

    // @return {int} the next element in the iteration
    @Override
    public Integer next() {
        // Write your code here
        return list.get(i++).getInteger();
    }

    // @return {boolean} true if the iteration has more element or false
    @Override
    public boolean hasNext() {
        // Write your code here
        while (i < list.size() || stack.size() > 0) {
            if (i < list.size()) {
                if (list.get(i).isInteger()) {
                    return true;
                }
                else {
                    stack.push(new Item(list, i + 1));
                    list = list.get(i).getList();
                    i = 0;
                }
            }
            else {
                Item item = stack.pop();
                i = item.index;
                list = item.list;
            }
        }
        
        return false;
    }

    @Override
    public void remove() {}
    private class Item {
        List<NestedInteger> list;
        int index;
        public Item(List<NestedInteger> list, int index) {
            this.list = list;
            this.index = index;
        }
    }
    private Stack<Item> stack = new Stack<Item>();
    private int i = 0;
    private List<NestedInteger> list;
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v.add(i.next());
 */