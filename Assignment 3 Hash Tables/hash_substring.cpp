#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

long long poly_hash(string S, long long p, long long x) {
	long long hash = 0;
	for (int i = S.length()-1; i >= 0; i--) {
		hash = (((hash*x + (S[i] - '0')) % p) + p) % p;
	}
	return hash;
}

void pre_compute_hash(vector<long long>& H, const string T, long long len_p, long long p, long long x) {
	long long len_t = T.length();

	string S = T.substr(len_t-len_p, len_p);
	int y = 1;
	H[len_t - len_p] = poly_hash(S, p, x);
	for (int i = 1; i <= len_p; i++)
		y = (y*x)%p;
	for (int i = (len_t - len_p - 1); i >= 0; i--) {
		H[i] = ((x*H[i + 1]) + (T[i] - '0') - (y * (T[i + len_p] - '0'))) % p;
	}
}

bool are_equal(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    /*for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);*/
	long long p = 100000123; //check how to select this, causes few tests to fail
	long long x = rand() % (p-1) + 1;
	long long pHash = poly_hash(s, p, x);
	vector<long long> H;
	long long len_t = t.length();
	long long len_s = s.length();
	for (int i = 0; i <= (len_t - len_s); i++) {
		H.push_back(0);
	}
	pre_compute_hash(H, t, len_s, p, x);
	for (int i = 0; i <= (len_t - len_s); i++) {
		if (H[i] != pHash)
			continue;
		if (are_equal(t.substr(i, len_s), s))
			ans.push_back(i);
	}
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
	system("pause");
    return 0;
}
