#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include<vector>
#include<string>
using namespace std;



class Autocomplete{
    private:
        struct TrieNode{
            char value;
            bool isEndOfWord;
            vector<TrieNode*> children;
            TrieNode(char val) : value(val), isEndOfWord(false){

            } 
        };
        TrieNode* root;

    public:

    Autocomplete() {
        root = new TrieNode(' '); // 初始化根节点
    }
    ~Autocomplete() {
    if (root != nullptr) {
        deleteTrie(root);
    }
    }

        void insert(string word){
            TrieNode* node = root;
            for(auto it = word.begin(); it != word.end(); it++){
                char c = *it;
                TrieNode* child = findChild(node,c);
                if(child != nullptr){
                    node = child;
                }
                else{
                    TrieNode* newNode = new TrieNode(c);
                    node->children.push_back(newNode);
                    node = newNode;
                }
            }
            node->isEndOfWord = true;
        }
        vector<string>getSuggestions(string partialWord)
        {
            vector<string> res;
            TrieNode* node = root;
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

        TrieNode* findChild(TrieNode* parent, char c){
            for(auto it = parent->children.begin(); it != parent->children.end(); it++){
                TrieNode* child = *it;
                if(child->value == c){
                    return child;
                }
            }
            return nullptr;
        }
        void findWords(TrieNode* node, string word, vector<string>& res){
            for(auto it = node->children.begin(); it != node->children.end(); it++){
                TrieNode* child = *it;
                findWords(child, word + child->value, res);
            }
            if(node->isEndOfWord){
                res.push_back(word);
            }
        }
        void deleteTrie(TrieNode* node) {
            for (auto child : node->children) {
                deleteTrie(child);
            }
            delete node;
        }
};

#endif