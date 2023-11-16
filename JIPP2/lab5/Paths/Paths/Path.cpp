#include "Path.h"

Path::Path(std::string path)
{
    if (isPathCorrect(path)) {
        this->path = path;
    }
    else this->path = "";
}

void Path::setPath(std::string path)
{
    if (isPathCorrect(path)) {
        this->path = path;
    }
    else this->path = "";
}

bool Path::isPathCorrect(const std::string path)
{
    if (path[0] != '/') {
        return false;
    }
    for (int i = 0; i < path.size() - 1; i++) {
        if (path[i] == '/' && path[i + 1] == '/') {
            return false;
        }
    }
    return true;
}

Path Path::operator+(std::string rhs)
{
    if (path == "") return path;
    if (rhs[0] == '/') rhs = rhs.substr(1, rhs.size()-1);// "/" z przodu
    if (rhs[rhs.size() - 1] == '/') rhs = rhs.substr(0, rhs.size() - 1); // "/" z tylu
    if (rhs.find('/') != std::string::npos)  return path; // ma inne "/"
    else {
        return path + '/' + rhs;
    }
    

}

Path& Path::operator+=(std::string rhs)
{
    if (path == "") return *this;
    if (rhs[0] == '/') rhs = rhs.substr(1, rhs.size() - 1);// "/" z przodu
    if (rhs[rhs.size() - 1] == '/') rhs = rhs.substr(0, rhs.size() - 1); // "/" z tylu
    if (rhs.find('/') != std::string::npos)  return *this; // ma inne "/"
    else {
        path = path + '/' + rhs;
        return *this;
    }
}

Path& Path::operator--()
{
    if (path == "/") return *this;
    for (int i = path.size() - 1; i >= 0; i--) {
        if (path[i] == '/') {
            path = path.substr(0, i);
            break;
        }
    }
    return *this;
}

bool Path::operator==(const Path& rhs)
{
    return rhs.path == path;
}

bool Path::operator!=(const Path& rhs)
{
    return rhs.path != path;
}

bool Path::operator<=(const Path& rhs)
{
    if (!isPathCorrect(rhs.path))  return false;
    if (rhs.path.substr(0, path.size()) == path) return true; //?

    for (int i = 0; i < path.size() - rhs.path.size() + 1; i++) {
        if (path.substr(i, rhs.path.size()) == rhs.path) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& lhs,const Path& rhs)
{
    return lhs << rhs.path;
}
