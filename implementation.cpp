class Node{
    public:
    vector<Node*> arr;
    bool flag;

    Node(){
        arr.resize(26, NULL);
        flag = false;
    }
};


class Trie {
public:

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert_helper(Node* node, string word){
        if(word.size() == 0){
            node -> flag = true;
            return;
        }

        int ind = word[0] - 'a';
        if(node -> arr[ind] == NULL){
            node -> arr[ind] = new Node();
            insert_helper(node -> arr[ind], word.substr(1));
        }

       else{
         insert_helper(node -> arr[ind], word.substr(1));
       }
    }

    void insert(string word) {
        
       insert_helper(root, word);

    }

    bool search_helper(Node* node, string word){
        if(word.size() == 0){
            if(node -> flag == true){
                return true;
            }
            else{
                return false;
            }
        }
        int ind = word[0] - 'a';
        if(node -> arr[ind] == NULL){
            return false;
        }
        else{
            return search_helper(node -> arr[ind], word.substr(1));
        }
    }
    
    bool search(string word) {
        
       return search_helper(root, word);


    }

    bool startsWith_helper(Node* node, string word){
        if(word.size() == 0){
           return true;
        }

        int ind = word[0] - 'a';
        if(node -> arr[ind] == NULL){
            return false;
        }
        else{
            return startsWith_helper(node -> arr[ind], word.substr(1));
        }
    }
    
    bool startsWith(string prefix) {
       
       return startsWith_helper(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
