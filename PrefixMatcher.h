#ifndef PREFIXMATCHER
#define PREFIXMATCHER

#include<string>
using namespace std;



class PrefixMatcher{
    private:
        struct Trie{
            int routerId;
            Trie* branch[2];

            Trie(){
            routerId = -1;
            branch[0] = nullptr;
            branch[1] = nullptr;
            }

        };
        Trie* root;

    public:
        PrefixMatcher(){
            root = new Trie();
        }

        void insert(const string& address, int routerId){
            Trie* current = root;
            for(auto it = address.begin(); it != address.end(); it++){
                int index = *it - '0';
                if(current->branch[index] == nullptr){
                    current->branch[index] = new Trie;
                }

                current = current->branch[index];
            }
            current->routerId = routerId;
        }
        int selectRouter(const string& networkAddress){
            Trie* current = root;
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