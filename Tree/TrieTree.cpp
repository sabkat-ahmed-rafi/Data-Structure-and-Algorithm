#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        fill(begin(children), end(children), nullptr);
    }
};





class Trie {
private: 
    TrieNode* root;
    bool deleteWord(TrieNode* node, const string& word, int depth) {
        if(node == nullptr) return false;

        if(depth == word.length()) {
            if(node->isEnd) node->isEnd = false;
            return empty(node);
        }
        char ch = word[depth] - 'a';
        if(node->children[ch]) {
            bool shouldDeleteChilde = deleteWord(node->children[ch], word, depth + 1);
            if(shouldDeleteChilde) {
                delete node->children[ch];
                node->children[ch] = nullptr;
                return empty(node) && !node->isEnd;
            }
        }
        return false;
    }
    bool empty(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i]) return false;
        }
        return true;
    }
public: 
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* node = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    bool search(const string& word) {
        TrieNode* node = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }
    void remove(const string& word) {
        deleteWord(root, word, 0);
    }
};


int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;

    trie.remove("app");
    cout << "Search 'app' after deletion: " << (trie.search("app") ? "Found" : "Not Found") << endl;    

    return 0;
}