typedef struct {
    char operators;
    int operands;
} element;

class Solution {
private:
    stack<element> se;
    void add_number(int number) {
        element e;
        if (!se.empty()) {
            if (se.top().operators == '+') {
                se.pop();
            } else if (se.top().operators == '-') {
                se.pop();
                number *= -1;
            }
            if (!se.empty() && se.top().operators == 0) {
                number += se.top().operands;
                se.pop();
            }
        }
        e.operators = 0;
        e.operands = number;
        se.push(e);
    }
public:
    int calculate(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                int number = s[i] - '0';
                while (i+1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9') {
                    number = number * 10 + (s[i+1] - '0');
                    i++;
                }
                add_number(number);
            } else {
                if (s[i] == ')') {
                    int number = se.top().operands;
                    se.pop(); // pop operands
                    se.pop(); // pop '('
                    add_number(number);
                } else {
                    element e;
                    e.operators = s[i];
                    se.push(e);
                }
            }
        }
        return se.top().operands;
    }
};