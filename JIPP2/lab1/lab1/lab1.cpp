#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>



void printWithSeparator(const std::string& str) {
	bool first = false;
	for (auto& ch : str) { 
		if (first) {
			std::cout << " _ ";
		}
		std::cout << ch;
		first = true;
	}
}

int sumAll(std::vector<int>& vec) {
	int x = 0;
	for (auto& it : vec) {
		x += it;
	}
	return x;
}
 int searchVar(std::vector<std::string>& strVec, std::string str) {
	 for (int i = 0; i<strVec.size(); i++) {
		 if (strVec[i] == str) {
			 return i;
		 }
	 }
	 return -1; 
	
}
 double circleArea(int r) {
	 return M_PI * r * r;
 }
 double circleArea(double r) {
	 return M_PI * r * r;
 }
 double circleArea(unsigned long long r) {
	 return M_PI * r * r;
 }

int main()
{	//1
	printWithSeparator("lab1");
	std::cout << std::endl;

	//2
	std::vector<int> vec = { 3,2,4,5,6,7 };
	std::cout << sumAll(vec) << std::endl;

	//3
	std::vector<std::string> strVec = { "abc","cde","lab1","aaa" };
	std::cout << searchVar(strVec, "lab1") << " " << searchVar(strVec, "ddddd") << std::endl;

	//4
	int x = 5;
	double y = 3.5;
	unsigned long long z = 123;

	std::cout << circleArea(x) << " " << circleArea(y) << " " << circleArea(z);

	// lub tak też będzie działało. W trzecim wywołaniu, gdybym dał mniejsza liczbą kompilator mógłby potratkować ją jako long long albo int.
	// std::cout << circleArea(5) << " " << circleArea(5.43) << " " << circleArea(18446744073709551615);
	


}

