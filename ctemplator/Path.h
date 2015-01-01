#pragma once

#include <string>
#include <iostream>

namespace ctemplator {

class Path
{
public:
    Path() {}
    Path(std::string path);
    Path(Path&&) = default;
    Path(const Path&) = default;
    Path& operator=(Path&&) = default;
    Path& operator=(const Path&) = default;

    Path& append(const char* part);
    Path& append(const std::string& part);
    Path& append(const Path& part);
    Path&& removeLast();
    std::string getBase() const;
    std::string getLast() const;
    std::string&& string();
    const std::string& string() const;
    bool empty() const;

private:
    std::string path_;
};

bool operator==(const Path& lhs, const Path& rhs);
bool operator==(const Path& lhs, const char* rhs);
bool operator==(const Path& lhs, const std::string& rhs);
bool operator==(const std::string& lhs, const Path& rhs);

Path operator+(const Path& lhs, const char* rhs);
Path operator+(const Path& lhs, const std::string& rhs);
Path operator+(const Path& lhs, const Path& rhs);

std::ostream& operator<<(std::ostream& lhs, const Path& rhs);

} // namespace ctemplator
