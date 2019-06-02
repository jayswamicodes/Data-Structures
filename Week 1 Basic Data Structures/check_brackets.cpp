#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
			opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
			if (opening_brackets_stack.empty()) {
				opening_brackets_stack.push(Bracket(next, position));
				break; 
			}
			Bracket b = opening_brackets_stack.top();
			opening_brackets_stack.pop();
			if (b.Matchc(next)==false) {
				opening_brackets_stack.push(Bracket(next, position));
				break;
			}
        }
    }
    // Printing answer, write your code here
	if (opening_brackets_stack.empty()) {
		std::cout << "Success";
	}
	else {
		Bracket b = opening_brackets_stack.top();
		opening_brackets_stack.pop();
		std::cout << b.position + 1;
	}
	//system("pause");
    return 0;
}
