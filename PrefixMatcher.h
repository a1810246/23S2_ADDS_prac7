#ifndef PREFIXMATCHER
#define PREFIXMATCHER

#include<string>
using namespace std;



class PrefixMatcher{
    private:
        struct TrieNode{
            int routerId;
            TrieNode* branch[2];

            TrieNode(){
            routerId = -1;
            branch[0] = nullptr;
            branch[1] = nullptr;
            }

        };
        TrieNode* root;

    public:
        PrefixMatcher(){
            root = new TrieNode();
        }

        void insert(const string& address, int routerId){
            TrieNode* current = root;
            for(auto it = address.begin(); it != address.end(); it++){
                int index = *it - '0';
                if(current->branch[index] == nullptr){
                    current->branch[index] = new TrieNode;
                }

                current = current->branch[index];
            }
            current->routerId = routerId;
        }
        int selectRouter(const string& networkAddress){
            TrieNode* current = root;
            int lastRouterId = -1;

            for(auto it = networkAddress.begin(); it != networkAddress.end(); it++){
                int index = *it -'0';
                if(current->branch[index]==nullptr){
                    break;
                }
                current = current->branch[index];
                if(current->routerId != -1){
                    lastRouterId = current->routerId;
                }
            }
            return lastRouterId;
        }
};

#endif