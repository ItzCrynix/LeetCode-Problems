#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
      bool contains(vector<string>& vet, string str) { // returns a boolean if the word is on the vector
        for (int i = 0; i < (int) vet.size(); i++)
          if (vet.at(i) == str) return true;
        return false;
      }

      int index(vector<string>& vet, string str) { // returns the index of the word, if it is on the vector
        for (int i = 0; i < (int) vet.size(); i++)
          if (vet.at(i) == str) return i;
        return -1;
      }

      int max(int vet[], int s) {
        int max = 0;
        for (int i = 0; i < s; i++) {
          if (vet[i] > vet[max]) max = i;
        }
        return max;
      }

      vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> noRepeatWords;
        for (int i = 0; i < (int) words.size(); i++) {
          if (!contains(noRepeatWords, words[i])) { // If the word is not on the vector
            noRepeatWords.push_back(words[i]); // Adds to the vector
          }
        }

        int count[(int)noRepeatWords.size()]; for (int i = 0; i < (int) noRepeatWords.size(); i++) count[i] = 0; // initialize a vector of integers to count the words

        for (int i = 0; i < (int) words.size(); i++) {
            count[index(noRepeatWords, words[i])]++; // counts the amount of times each word appears
        }

        vector<string> topFrequent;
        for (int i = 0; i < k; i++) { // creates a vector with the words in order by frequency
          topFrequent.push_back(noRepeatWords[max(count, (int) noRepeatWords.size())]);
          count[max(count, (int) noRepeatWords.size())] = 0; 
        }

        return topFrequent;
      }
};

int main() {
  vector<string> someWords = vector<string>({"the","day","is","sunny","the","the","the","sunny","is","is"});

  Solution s;
  vector<string> frequency = s.topKFrequent(someWords, 4);

  for (int i = 0; i < (int) frequency.size(); i++)
    cout << frequency[i] << endl;

  return 0;
}
