class Solution {
 public:
  /**
   * @param sentence: a list of string
   * @param rows: an integer
   * @param cols: an integer
   * @return: return an integer, denote times the given sentence can be fitted on the screen
   */
  int wordsTyping(vector<string> &sentence, int rows, int cols) {
    string whole_sen = "";
    for (auto word : sentence) {
      whole_sen += word + " ";
    }
    int len(static_cast<int>(whole_sen.size())), space_num(0);
    for (int i = 0; i < rows; ++i) {
      space_num += cols;
      if (whole_sen.at(space_num % len + 1 - 1) == ' ') {  // put a word at ending of row
        ++space_num;
      } else {
        while (space_num > 0 && whole_sen.at((space_num - 1) % len) != ' ') {
          // this word can't be put in this row
          --space_num;
        }
      }
    }
    return space_num / len;
  }
};
