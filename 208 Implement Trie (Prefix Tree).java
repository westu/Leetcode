class TrieNode {
public:
    // Initialize your data structure here.
    unordered_map<char, TrieNode*> child;
    bool is_end;

    TrieNode() {
        is_end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (char& ch : word) {
            if (node->child.find(ch) != node->child.end()) {
                node = node->child.find(ch)->second;
            } else {
                TrieNode* tmp_node = new TrieNode();
                node->child.insert(make_pair(ch, tmp_node));
                node = tmp_node;
            }
        }
        node->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (char& ch : word) {
            unordered_map<char, TrieNode*>::iterator it =
                node->child.find(ch);
            if (it == node->child.end()) {
                return false;
            }
            node = it->second;
        }
        return node->is_end == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char& ch : prefix) {
            unordered_map<char, TrieNode*>::iterator it =
                node->child.find(ch);
            if (it == node->child.end()) {
                return false;
            }
            node = it->second;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
