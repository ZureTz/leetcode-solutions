#include <cstddef>
#include <functional>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

// Hash the vector of counts
struct CountHasher {
  size_t operator()(const std::vector<int> &counts) const {
    return std::accumulate(counts.begin(), counts.end(), 0u,
                           [](size_t acc, int count) {
                             return (acc << 1) ^ std::hash<int>()(count);
                           });
  }
};

class Solution {
  // This map will hold the key as the letter count string and the value as a
  // vector of strings that are anagrams of each other.
  std::unordered_map<std::vector<int>, std::vector<std::string>, CountHasher>
      anagramsCategories;

public:
  std::vector<int> constructKeyBasedOnLetterCount(const std::string &str) {
    // Construct a key based on the letter count of the string.
    // The key is a string of 26 characters, each representing the count of
    // the corresponding letter in the alphabet.
    std::vector<int> letterCount(26, 0);
    for (const char c : str) {
      ++letterCount[c - 'a'];
    }

    return letterCount;
  }

  std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    // For each string, construct the key based on the letter count and
    // insert the string into the corresponding vector in the map.
    for (const auto &str : strs) {
      const auto key = constructKeyBasedOnLetterCount(str);
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