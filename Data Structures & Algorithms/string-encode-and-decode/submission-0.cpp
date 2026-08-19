class Solution {
public:

     string encode(vector<string>& strs) {
        string encoded = "";

        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;

        while (i < s.size()) {

            // Find '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Extract length
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract actual string
            decoded.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return decoded;
    }
};
