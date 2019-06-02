#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator> 
using namespace std;
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries_map(const vector<Query>& queries) {
	vector<string> result;
	map<int, string> contacts;
	map<int, string>::iterator it;

	for (size_t i = 0; i < queries.size(); ++i) {
		it = contacts.find(queries[i].number);
		if (queries[i].type == "add") {
			contacts[queries[i].number] = queries[i].name;
		}
		else if (queries[i].type == "del") {
			if (it != contacts.end())
				contacts.erase(queries[i].number);
		}
		else {
			if (it == contacts.end())
				result.push_back("not found");
			else
				result.push_back(contacts[queries[i].number]);
		}
	}
	return result;
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
	//map<double, string> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        } else if (queries[i].type == "del") {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        } else {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries_map(read_queries()));
    return 0;
}
