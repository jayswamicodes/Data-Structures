#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
	int max = -1;
	vector<int> track;

  public:

	void pushTrackStack(int value) {
		if (value > track.back())
			track.push_back(value);
		else
			track.push_back(track.back());
		//std::cout << track.back()<<std::endl;
	}

	void popTrackStack() {
		while (track.back() == stack.back())
			track.pop_back();
	}

    void Push(int value) {
        stack.push_back(value);
		if (track.size() > 0)
			pushTrackStack(value);
		else
			track.push_back(value);
    }

    void Pop() {
        assert(stack.size());
		track.pop_back();
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
		return track.back();
        //return *max_element(stack.begin(), stack.end());
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
	//system("pause");
    return 0;
}