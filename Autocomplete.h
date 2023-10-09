#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include<vector>
#include<string>
using namespace std;



class Autocomplete{
    private:
        struct Trie{
            char value;
            bool isEndOfWord;
            vector<Trie*> children;
            Trie(char val) : value(val), isEndOfWord(false){

            } 
        };
        Trie* root;

    public:

    Autocomplete() {
        root = new Trie(' '); // 初始化根节点
    }
    ~Autocomplete() {
    if (root != nullptr) {
        deleteTrie(root);
    }
    }

        void insert(string word){
            Trie* node = root;
            for(auto it = word.begin(); it != word.end(); it++){
                char c = *it;
                Trie* child = findChild(node,c);
                if(child != nullptr){
                    node = child;
                }
                else{
                    Trie* newNode = new Trie(c);
                    node->children.push_back(newNode);
                    node = newNode;
                }
            }
            node->isEndOfWord = true;
        }
        vector<string>getSuggestions(string partialWord)
        {
            vector<string> res;
            Trie* node = root;
            for(auto it = partialWord.begin(); it!=partialWord.end(); it++)
            {
                char c = *it;
                node = findChild(node,c);
                if(node == nullptr)
                {
                    return res;
                }
            }
            findWords(node, partialWord, res);
            return res;
        }

        Trie* findChild(Trie* parent, char c){
            for(auto it = parent->children.begin(); it != parent->children.end(); it++){
                Trie* child = *it;
                if(child->value == c){
                    return child;
                }
            }
            return nullptr;
        }
        void findWords(Trie* node, string word, vector<string>& res){
            for(auto it = node->children.begin(); it != node->children.end(); it++){
                Trie* child = *it;
                findWords(child, word + child->value, res);
            }
            if(node->isEndOfWord){
                res.push_back(word);
            }
        }
        void deleteTrie(Trie* node) {
            for (auto child : node->children) {
                deleteTrie(child);
            }
            delete node;
        }
};

#endif