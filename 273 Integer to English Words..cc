class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> scale(4);
        scale.at(0) = "";
        scale.at(1) = "Thousand ";
        scale.at(2) = "Million ";
        scale.at(3) = "Billion ";
        
        string ans = "";
        int w = -1;
        while (num > 0) {
            ++w;
            if (num % 1000 > 0) {
                ans.insert(0, toWords(num % 1000) + scale.at(w));
            }
            num /= 1000;
        }
        if (ans.at(ans.size() - 1) == ' ') {
            ans.pop_back();
        }
        return ans;
    }

private:
    string below20[20] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string below100[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string toWords(int num) {
        string return_value = "";
        if (num >= 100) {
            return_value.append(below20[num / 100 - 1] + " Hundred ");
            num %= 100;
        }
        if (num >= 20) {
            return_value.append(below100[num / 10 - 2] + " ");
            num %= 10;
        }
        if (num > 0) {
            return_value.append(below20[num - 1] + " ");
        }
        return return_value;
    }
};
