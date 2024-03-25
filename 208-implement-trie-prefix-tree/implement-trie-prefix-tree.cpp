class TrieNode{
    public:
    TrieNode* links[26];
    bool flag=false;
    TrieNode(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
    }
    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,TrieNode* Node){
        links[ch-'a']=Node;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return (flag==true);
    }
};


class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root=new TrieNode();
            }
    
    void insert(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            
        if(!node->containskey(word[i])){
             node->put(word[i],new TrieNode);
        }
        node=node->get(word[i]);
        }
        node->setend();
        return;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
         }
         return node->isend();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containskey(prefix[i])){
                return false;

            }
            node=node->get(prefix[i]);
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