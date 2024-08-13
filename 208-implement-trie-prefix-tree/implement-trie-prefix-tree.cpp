class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];

    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == nullptr) {
                crawler->children[idx] = new TrieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return (crawler != nullptr && crawler->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for(int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
