#include<iostream>
#include<stdio.h>
#include<vector>


void prepare(std::vector<int>& vec, int& rem){
	rem = 0;int temp = 0;
	int n = vec.size();
	for(int i(n); i >= 0; --i) {
		temp = vec[i] + rem;
		vec[i] = temp % 10;
		rem = temp / 10;		
	} 
}
void convolve(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& conv){
	int n = vec1.size() + vec2.size() -1;
	conv.resize(n);
	for(int i(0); i < vec1.size(); i++) 
	for(int j(0); j < vec2.size(); j++){
			conv[i + j] += vec1[i] * vec2[j];		
	} 
}

int main(){
	std::string val1, val2;
	std::cin >> val1;
	std::cin >> val2;
	
	std::vector<int> val1data, val2data;
	std::vector<int> conv;
	std::string result;

	for (auto& val: val1)
		val1data.push_back((int) val - 48);

	for (auto& val: val2)
		val2data.push_back((int) val - 48);

	convolve(val1data, val2data, conv);
	int rem = 0;
	prepare(conv, rem);
	result.reserve(conv.size() + 1);
	if (rem > 0)
		result += std::to_string(rem);

	for(auto& val: conv)
		result += std::to_string(val);

	std::cout << result << std::endl;
	return 0;
}
