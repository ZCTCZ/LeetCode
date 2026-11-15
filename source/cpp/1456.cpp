#include <algorithm>
#include <print>
#include <string>
#include <unordered_set>
class Solution {
public:
  int maxVowels(std::string s, int k) {
    int result = 0, temp = 0, left = 0, right = 0;
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    while (right < s.size()) {
      if (vowels.contains(s[right])) {
        ++temp;
      }
      if (right < k - 1) {
        ++right;
        continue;
      }
      result = std::max(result, temp);
      if (vowels.contains(s[left])) {
        --temp;
      }
      ++left;
      ++right;
    }

    return result;
  }
};

int main(int argc, char **argv) {
  std::println("{}", Solution().maxVowels("abciiidef", 3));
  return 0;
}