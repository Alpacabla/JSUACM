// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
    	vector<int> num(N);
        for(int i=0;i<N;i++) num[i]=i+1;
      	stable_sort(num.begin(),num.end(),compare);
      	return num;
    }
};