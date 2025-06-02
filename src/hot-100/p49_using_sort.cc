#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  // This map will hold the key as the letter count string and the value as a
  // vector of strings that are anagrams of each other.
  std::unordered_map<std::string, std::vector<std::string>> anagramsCategories;

public:
  // Construct the key by sorting the string.
  std::string constructKeyBasedOnString(const std::string &str) {
    std::string key = str;
    std::sort(key.begin(), key.end(), [](char a, char b) { return a < b; });
    return key;
  }

  std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    // For each string, construct the key based on the letter count and
    // insert the string into the corresponding vector in the map.
    for (const auto &str : strs) {
      const auto key = constructKeyBasedOnString(str);
      auto it = anagramsCategories.find(key);
      // If not found, create a new entry.
      if (it == anagramsCategories.end()) {
        anagramsCategories.insert({key, {str}});
        continue;
      }
      // Otherwise, add the string to the existing vector.
      it->second.push_back(str);
    }

    // Prepare the result vector.
    std::vector<std::vector<std::string>> result;
    // Iterate through the map and add each vector of anagrams to the result.
    for (const auto &pair : anagramsCategories) {
      result.push_back(pair.second);
    }

    return result;
  }
};

// int main(int argc, char const *argv[]) {
//   Solution solution;
//   std::cout << solution.constructKeyBasedOnLetterCount("arandomstring")
//             << std::endl;
//   std::cout << solution.constructKeyBasedOnLetterCount("bbbbbbbbbbc")
//             << std::endl;
//   std::cout << solution.constructKeyBasedOnLetterCount("bdddddddddd")
//             << std::endl;
//   return 0;
// }