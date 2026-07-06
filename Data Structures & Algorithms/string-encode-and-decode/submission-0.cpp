class Solution {
public:

    string encode(vector<string>& strs) {
        string res,meta = "";
        int count = 0;
        int words = strs.size();
        for (int i = strs.size()-1; i>=0; --i){
            string s = strs[i];
            for (auto ch : s){
                count++;
            }
            if (count<10){
                meta = "00" + to_string(count);
            }
            else if (count<100){
                meta = "0" + to_string(count);
            }
            else {
                meta = to_string(count);
            }
            res += s + meta;
            count = 0;
            meta = "";
        }
        if (words<10){
            meta = "00" + to_string(words);
        }
        else if (words<100){
            meta = "0" + to_string(words);
        }
        else {
            meta = to_string(words);
        }
        res +=meta;
        return res;

    }

    vector<string> decode(string s) {
        int words = stoi(s.substr(s.size() - 3, 3));
        s.erase(s.size() - 3);

        string aux;
        int chars = 0;
        vector<string> res;
        for (int i = 0; i< words; ++i){
            chars = stoi(s.substr(s.size() - 3, 3));
            s.erase(s.size() - 3);
            aux = s.substr(s.size()-chars, chars);
            s.erase(s.size() - chars);
            res.push_back(aux);
        }
        return res;
    }
};
