/*
#include<vector>
#include "PrefixMatcher.h"
#include "Autocomplete.h"
using namespace std;

int main()
{
    Autocomplete test;
    test.insert("b");
    test.insert("ball");
    test.insert("ballet");

    //vector<string> suggestions = test.getSuggestions("ba");

    return 0;



}
*/

#include <iostream>
#include <vector>
#include "Autocomplete.h"

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

    return 0;
}
