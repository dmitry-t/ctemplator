#include "ctemplator/Path.h"

#include "Poco/String.h"
#include "Poco/StringTokenizer.h"
#include "contrib/poco-1.6.0/Foundation/include/Poco/String.h"
#include "contrib/poco-1.6.0/Foundation/include/Poco/StringTokenizer.h"

#include <cstring>

namespace ctemplator {

namespace {

const char SLASH_CHAR = '/';
const std::string SLASH = &SLASH_CHAR;

inline void removeTrailingSlash(std::string& path)
{
    if (!path.empty() && path[path.size() - 1] == SLASH_CHAR)
    {
        path.erase(path.size() - 1);
    }
}

inline void collapseSegments(std::string& path)
{
    static std::string UP = "..";
    if (path.find(UP) == std::string::npos)
    {
        return;
    }
    Poco::StringTokenizer segments(path, SLASH, 0);
    path.clear();
    for (size_t i = 0; i < segments.count() - 1; ++i)
    {
        auto& segment = segments[i];
        if (segment == UP)
        {
            path += UP;
            path += SLASH;
            continue;
        }
        auto& nextSegment = segments[i + 1];
        if (nextSegment == UP)
        {
            ++i;
            continue;
        }
        path += segment;
        path += SLASH;
    }
    path += segments[segments.count() - 1];
}

inline void canonize(std::string& path)
{
    static std::string BACKSLASH = "\\";
    Poco::replaceInPlace(path, BACKSLASH, SLASH);
    removeTrailingSlash(path);
    collapseSegments(path);
}

} // namespace

Path::Path(std::string path) :
        path_(std::move(path))
{
    canonize(path_);
}

Path& Path::append(const char* part)
{
    if (std::strlen(part))
    {
        if (part[0] != SLASH_CHAR)
        {
            path_ += SLASH_CHAR;
        }
        path_ += part;
        canonize(path_);
    }
    return *this;
}

Path& Path::append(const std::string& part)
{
    if (!part.empty())
    {
        if (part[0] != SLASH_CHAR)
        {
            path_ += SLASH_CHAR;
        }
        path_ += part;
        canonize(path_);
    }
    return *this;
}

Path& Path::append(const Path& part)
{
    if (!part.empty())
    {
        if (part.string()[0] != SLASH_CHAR)
        {
            path_ += SLASH_CHAR;
        }
        path_ += part.string();
    }
    return *this;
}

Path&& Path::removeLast()
{
    path_.erase(path_.find_last_of(SLASH));
    return std::move(*this);
}

std::string Path::getBase() const
{
    size_t lastSlash = path_.find_last_of(SLASH);
    switch (lastSlash)
    {
    case 0:
        return SLASH;

    case std::string::npos:
        return std::string();

    default:
        return path_.substr(0, lastSlash);
    }
}

std::string Path::getLast() const
{
    return path_.substr(path_.find_last_of(SLASH) + 1);
}

std::string&& Path::string()
{
    return std::move(path_);
}

const std::string& Path::string() const
{
    return path_;
}

bool Path::empty() const
{
    return path_.empty();
}

bool operator==(const Path& lhs, const Path& rhs)
{
    return lhs.string() == rhs.string();
}

bool operator==(const Path& lhs, const std::string& rhs)
{
    return lhs.string() == rhs;
}

bool operator==(const std::string& lhs, const Path& rhs)
{
    return lhs == rhs.string();
}

Path operator+(const Path& lhs, const char* rhs)
{
    return Path(lhs).append(rhs);
}

Path operator+(const Path& lhs, const std::string& rhs)
{
    return Path(lhs).append(rhs);
}

Path operator+(const Path& lhs, const Path& rhs)
{
    return Path(lhs).append(rhs);
}

std::ostream& operator<<(std::ostream& lhs, const Path& rhs)
{
    return lhs << rhs.string();
}

} // namespace ctemplator
