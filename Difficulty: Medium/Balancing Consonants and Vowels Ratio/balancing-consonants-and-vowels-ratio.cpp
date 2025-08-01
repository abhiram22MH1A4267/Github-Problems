class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<int, int> freqMap;
        freqMap[0] = 1;

        int result = 0;
        int prefixDiff = 0;

        for (const string& s : arr) {
            int vowelCount = 0, consonantCount = 0;

            for (char ch : s) {
                if (vowels.count(ch)) vowelCount++;
                else consonantCount++;
            }

            prefixDiff += (vowelCount - consonantCount);

            result += freqMap[prefixDiff];
            freqMap[prefixDiff]++;
        }

        return result;
  }
};