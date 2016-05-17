/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null) {
            return null;
        }
        HashSet<Integer> hashSet = new HashSet<Integer>();
        HashMap<Integer, UndirectedGraphNode> hashMap = new HashMap<Integer, UndirectedGraphNode>();
        Queue<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>();
        queue.offer(node);
        hashSet.add(node.label);
        while (!queue.isEmpty()) {
            UndirectedGraphNode tmpNode = queue.poll();
            UndirectedGraphNode cloneNode = new UndirectedGraphNode(tmpNode.label);
            hashMap.put(cloneNode.label, cloneNode);
            for (UndirectedGraphNode iteNode : tmpNode.neighbors) {
                if (hashSet.contains(iteNode.label) == false) {
                    queue.offer(iteNode);
                    hashSet.add(iteNode.label);
                }
            }
        }
        
        hashSet.clear();
        queue.offer(node);
        hashSet.add(node.label);
        while (!queue.isEmpty()) {
            UndirectedGraphNode tmpNode = queue.poll();
            UndirectedGraphNode cloneNode = hashMap.get(tmpNode.label);
            if (cloneNode.neighbors.size() != 0) {
                System.out.println(cloneNode.label);
            }
            for (UndirectedGraphNode iteNode : tmpNode.neighbors) {
                cloneNode.neighbors.add(hashMap.get(iteNode.label));
                if (hashSet.contains(iteNode.label) == false) {
                    queue.offer(iteNode);
                    hashSet.add(iteNode.label);
                }
            }
        }
        
        return hashMap.get(node.label);
    }
}
