#pragma once
#include <iostream>
class Path
{
	std::string path;
public:
	Path() : path("/") {};
	Path(std::string path);

	void setPath(std::string path);
	std::string getPath() { return path; };

	bool isPathCorrect(const std::string path);

	Path operator+(std::string rhs);
	Path& operator+=(std::string rhs);
	Path& operator--();
	bool operator==(const Path& rhs);
	bool operator!=(const Path& rhs);
	bool operator<=(const Path& rhs);
	friend std::ostream& operator<<(std::ostream& lhs, const Path& rhs);

};

