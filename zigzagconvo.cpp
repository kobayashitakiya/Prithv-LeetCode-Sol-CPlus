#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: If 1 row or string is shorter than rows, no zigzag happens
        if (numRows == 1 || s.length() <= numRows) return s;

        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            // Change direction when hitting the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        string result;
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};
