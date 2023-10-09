#include <iostream>
#include <vector>
#include "Autocomplete.h"
#include "PrefixMatcher.h"


int main() {
    // Create an instance of the Autocomplete class
    Autocomplete autocomplete;

    // Insert some words into the autocomplete system
    autocomplete.insert("bat");
    autocomplete.insert("batter");
    autocomplete.insert("ball");
    autocomplete.insert("basket");
    autocomplete.insert("cat");
    autocomplete.insert("car");

    // Get suggestions for a partial word
    vector<string> suggestions = autocomplete.getSuggestions("ba");

    // Print the suggestions
    if (!suggestions.empty()) {
        cout << "Suggestions for 'ba':" << endl;
        for (const string& suggestion : suggestions) {
            cout << suggestion << endl;
        }
    } else {
        cout << "No suggestions found for 'ba'" << endl;
    }


    PrefixMatcher matcher;

    // 插入一些网络地址和路由器ID
    matcher.insert("10101", 1);
    matcher.insert("1100", 2);
    matcher.insert("10111", 3);
    matcher.insert("01010", 4);
    matcher.insert("001", 5);

    // 测试选择路由器
    std::string address1 = "101010"; // 匹配 "10101"
    int router1 = matcher.selectRouter(address1);
    std::cout << "Selected Router for " << address1 << ": " << router1 << std::endl;

    std::string address2 = "110010"; // 匹配 "1100"
    int router2 = matcher.selectRouter(address2);
    std::cout << "Selected Router for " << address2 << ": " << router2 << std::endl;

    std::string address3 = "001100"; // 匹配 "001"
    int router3 = matcher.selectRouter(address3);
    std::cout << "Selected Router for " << address3 << ": " << router3 << std::endl;
    return 0;
}
