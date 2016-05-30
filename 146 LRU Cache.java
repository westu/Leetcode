public class Solution {
    
    private HashMap<Integer, Integer> hashMap;
    private int capacity;
    private int count;
    private LRUList lruList;
    
    private class ListNode {
        public int key;
        public ListNode next;
        public ListNode prev;
        
        public ListNode(int key) {
            this.key = key;
            next = null;
        }
    }
    
    private class LRUList {
        public ListNode dummpyNode;
        public ListNode lastNode;
        private HashMap<Integer, ListNode> nodeFinder;
        
        public LRUList() {
            dummpyNode = new ListNode(0);
            lastNode = dummpyNode;
            nodeFinder = new HashMap<Integer, ListNode>();
        }
        
        public void addNode(int key) {
            lastNode.next = new ListNode(key);
            lastNode.next.prev = lastNode;
            lastNode = lastNode.next;
            nodeFinder.put(key, lastNode);
        }
        
        public void addNode(ListNode node) {
            lastNode.next = node;
            lastNode.next.prev = lastNode;
            lastNode = lastNode.next;
            nodeFinder.put(node.key, node);
        }
        
        public ListNode findNode(int key) {
            return nodeFinder.get(key);
            /*ListNode node = dummpyNode.next;
            while (node.key != key) {
                node = node.next;
            }
            return node;*/
        }
        
        public int getAndDeleteFirst() {
            int key = dummpyNode.next.key;
            dummpyNode.next = dummpyNode.next.next;
            if (dummpyNode.next != null) {
                dummpyNode.next.prev = dummpyNode;
            } else {
                lastNode = dummpyNode;
            }
            nodeFinder.remove(key);
            return key;
        }
        
        public void moveToTail(ListNode node) {
            if (node == lastNode) {
                return;
            }
            node.prev.next = node.next;
            node.next.prev = node.prev;
            addNode(node);
        }
    }

    // @param capacity, an integer
    public Solution(int capacity) {
        this.capacity = capacity;
        count = 0;
        hashMap = new HashMap<Integer, Integer>();
        lruList = new LRUList();
    }

    // @return an integer
    public int get(int key) {
        if (hashMap.containsKey(key)) {
            ListNode node = lruList.findNode(key);
            lruList.moveToTail(node);
            return hashMap.get(key);
        } else {
            return -1;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    public void set(int key, int value) {
        if (hashMap.containsKey(key)) {
            hashMap.put(key, value);
            ListNode node = lruList.findNode(key);
            lruList.moveToTail(node);
        } else {
            if (count < capacity) {
                ++count;
                hashMap.put(key, value);
                lruList.addNode(key);
            } else {
                int firstKey = lruList.getAndDeleteFirst();
                hashMap.remove(firstKey);
                hashMap.put(key, value);
                lruList.addNode(key);
            }
        }
    }
}
