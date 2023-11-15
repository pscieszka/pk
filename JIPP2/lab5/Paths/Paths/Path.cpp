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

bool Path::isPathCorrect(std::string path)
{
    if (path[0] != '/') {
        return false;
    }
    for (int i = 0; i<path.size()-1; i++) {
        if (path[i] == '/' && path[i + 1] == '/') {
            return false;
        }
    }
    return true;
}

Path Path::operator+(std::string rhs)
{
    if (path == "") return path;
    if (rhs == "") return path;
    if (rhs[rhs.size() - 1] == '/') rhs.pop_back();
    if (rhs[0] == '/') return path += rhs;
    
    return path + '/' + rhs;

}

Path& Path::operator+=(std::string rhs)
{
    if (path=="") {
        path = rhs;
    }
    else if (rhs!="") {
        if (rhs[rhs.size()-1] == '/') {
            rhs.pop_back();
            path += rhs;
        }
        else if (rhs[0] == '/') {
            path += rhs;
        }
        else {
            path += '/' + rhs;
        }
    }
    return *this;
}

Path& Path::operator--()
{
    if (path == "") return *this;
    for (int i = path.size() - 1; i >= 0; i--) {
        if (path[i] == '/') {
            path = path.substr(0, i );
            break;
        }
    }
    return *this;
}

bool Path::operator==(std::string rhs)
{
    return rhs == path;
}

bool Path::operator!=(std::string rhs)
{
    return rhs != path;
}

bool Path::operator<=(std::string rhs)
{
    for (int i = 0; i < path.size() - rhs.size()+1; i++) {
        if (path.substr(i, rhs.size()) == rhs) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& lhs, Path& rhs)
{
    return lhs << rhs.path;
}
