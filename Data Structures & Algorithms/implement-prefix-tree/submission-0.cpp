class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isLeaf = false;
    }
};

class PrefixTree {
    TrieNode* root = new TrieNode();
public:
    PrefixTree() {

    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(auto &c: word){
            if(curr->children[c-'a'] == NULL){
                TrieNode* newNode = new TrieNode();
                curr->children[c-'a'] = newNode;
            }

            curr = curr->children[c-'a'];
        }

        // mark end as leaf
        curr->isLeaf = true;
    }
    
    bool search(string word) {

        TrieNode* curr = root;

        for(auto &c: word){
            if(curr->children[c-'a'] == NULL) return false;
            curr = curr->children[c-'a'];
        }

        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;

        for(auto &c: prefix){
            if(curr->children[c-'a'] == NULL){
                return false;
            }

            curr = curr->children[c - 'a'];
        }
        
        return true;
    }
};
