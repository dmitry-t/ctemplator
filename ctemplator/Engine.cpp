#include "ctemplator/Engine.h"

#include "ctemplator/compiler/Tokenizer.h"

#include "Poco/Dynamic/Var.h"

#include <sstream>

namespace ctemplator {

Engine::Engine(const std::string& templateStorageRoot) :
    fileStorage_(templateStorageRoot)
{
}

std::string Engine::render(
    const std::string& templatePath,
    const Poco::Dynamic::Var& vars)
{
    std::ostringstream stream;

    auto i = cache_.find(templatePath);
    if (i != cache_.end())
    {
        auto& node = cache_.at(templatePath);
        node.render(vars, stream);
    }
    else
    {
        auto content = fileStorage_.readFileContent(templatePath);
        nodes::Node node = parser_.parse(content);
        cache_.emplace(templatePath, std::move(node));
        node.render(vars, stream);
    }
    return stream.str();
}

} // namespace ctemplator