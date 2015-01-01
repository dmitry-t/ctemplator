#include "ctemplator/Engine.h"

#include "ctemplator/compiler/Tokenizer.h"
#include "contrib/poco-1.6.0/Foundation/include/Poco/Dynamic/Var.h"

namespace ctemplator {

Engine::Engine(const std::string& templateStorageRoot) :
    fileStorage_(templateStorageRoot)
{
}

std::string Engine::render(
    const std::string& templatePath,
    const Poco::Dynamic::Var& vars)
{
    auto content = fileStorage_.readFileContent(templatePath);
    size_t cursor = 0;
    while (cursor < content.size())
    {
        size_t varBegin = content.find("{", cursor);
        if (varBegin == std::string::npos)
        {
            break;
        }
        size_t varEnd = content.find("}", varBegin + 1);
        if (varEnd == std::string::npos)
        {
            throw std::logic_error("No closing '}'");
        }
        std::string varName = content.substr(varBegin + 1, varEnd - varBegin - 1);
        auto varValue = vars[varName].toString();
        content.replace(
                varBegin,
                varEnd - varBegin + 1,
                varValue);
        cursor = varBegin + varValue.size();
    }
    return content;
}

} // namespace ctemplator