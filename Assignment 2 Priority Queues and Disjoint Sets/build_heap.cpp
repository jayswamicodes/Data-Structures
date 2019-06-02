#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  /*void swap(int& a, int& b) {
	  int temp = a;
	  a = b;
	  b = temp;
  }*/

  void ShiftUp(int i, vector<int>& a) {
	  while (i > 1 && a[i / 2] > a[i]){
		  swap(a[i / 2], a[i]);
		  i = i / 2;
	  }
  }

  void ShiftDown(int i, vector<int>& a) {
	  int maxIndex = i;
	  int l = 2 * i + 1;
	  if (l < a.size() && a[l] < a[maxIndex]){
		  maxIndex = l;
	  }
	  int r = 2 * i + 2;
	  if (r < a.size() && a[r] < a[maxIndex]) {
		  maxIndex = r;
	  }
	  if (i != maxIndex) {
		  swap(a[maxIndex], a[i]);
		  swaps_.push_back(make_pair(i, maxIndex));
		  ShiftDown(maxIndex, a);
	  }
  }

  void buildHeap(vector<int>& a) {
	  for (int i = a.size() / 2; i >= 0; i--) {
		  ShiftDown(i, a);
	  }
	  /*for (int i = 0; i< a.size(); i++) {
		  std::cout << a[i] << ", ";
	  }
	  std::cout << std::endl;*/
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }*/
	buildHeap(data_);
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
