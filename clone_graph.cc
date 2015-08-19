/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    using Node = UndirectedGraphNode;
    unordered_map<Node *, Node *> node_map;
public:
    Node *cloneGraph(Node *node) {
        if (!node) return nullptr;

        if (node_map.find(node) != node_map.end()) {
            return node_map[node];
        }

        Node *new_node = new Node(node->label);
        node_map[node] = new_node;

        for (auto p : node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(p));
        }

        return new_node;
    }
};
