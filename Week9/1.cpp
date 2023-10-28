class Trie {
public:
    class Node{
        public:
        bool present = false;
        Trie * child = nullptr;
        Node(){
            present = false;
            child = nullptr;
        }
    };
    bool end_of_word = false;
    Node** parent_arr;

    Trie() {
        parent_arr = new Node*[26];
        for(int i=0;i<26;i++){
            parent_arr[i] = new Node();
        }
    }
    
    void insert(string word) {
        for(int i=0;i<word.size();i++){
            word[i] = (char)tolower(word[i]);
        }
        int i=0;
        Trie*temp = this;
        while(i<word.length()){
            if(!(temp->parent_arr[static_cast<int>(word[i])-static_cast<int>('a')])->present){
                temp->parent_arr[static_cast<int>(word[i])-static_cast<int>('a')]->present = true;
                temp->parent_arr[static_cast<int>(word[i])-static_cast<int>('a')]->child = new Trie();
            }
            if(i==word.length()-1){
                temp->end_of_word = true;
            }
            temp = temp->parent_arr[static_cast<int>(word[i])-static_cast<int>('a')]->child;
            i++;
        }
    }
    
    bool search(string word) {
        for(int i=0;i<word.size();i++){
            word[i] = (char)tolower(word[i]);
        }
        int i=0;
        Trie*temp = this;
        while(i<word.length()){
            if(!temp->parent_arr[static_cast<int>(word[i])-static_cast<int>('a')]->present){
                return false;
            }
            if(i==word.length()-1){
                if(temp->end_of_word){
                    return true;
                }
                else{
                    return false;
                } 
            } 
            temp = temp->parent_arr[static_cast<int>(word[i])-static_cast<int>('a')]->child;
            i++;    
        } 
        return false;     
    }
    
    bool startsWith(string prefix) {
        for(int i=0;i<prefix.size();i++){
            prefix[i] = (char)tolower(prefix[i]);
        }
        int i=0;
        Trie*temp = this;
        while(i<prefix.length()){
            if(!temp->parent_arr[static_cast<int>(prefix[i])-static_cast<int>('a')]->present){
                return false;
            }
            temp = temp->parent_arr[static_cast<int>(prefix[i])-static_cast<int>('a')]->child;
            i++;
        }
        return true;         
    }
};