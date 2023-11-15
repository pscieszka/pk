#pragma once
#include <iostream>
class Path
{
	std::string path;
public:
	Path() : path("") {};
	Path(std::string path);
	
	void setPath(std::string path);
	std::string getPath() { return path; };

	bool isPathCorrect(std::string path);

	Path operator+(std::string rhs);
	Path& operator+=(std::string rhs);
	Path& operator--(); 
	bool operator==(std::string rhs);
	bool operator!=(std::string rhs);
	bool operator<=(std::string rhs);
	friend std::ostream &operator<<(std::ostream& lhs,Path &rhs);

};

