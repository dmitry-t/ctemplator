#include "ctemplator/Engine.h"

#include "ctemplator/compiler/Tokenizer.h"
#include "ctemplator/vars/Var.h"

#include <sstream>

namespace ctemplator {

Engine::Engine(const std::string& templateStorageRoot) :
    fileStorage_(templateStorageRoot)
{
}

std::string Engine::render(
    const std::string& templatePath,
    const vars::Var& vars)
{
    std::ostringstream stream;

    auto nodePtr = cache_.get(templatePath);
    if (nodePtr)
    {
        nodePtr->render(vars, stream);
    }
    else
    {
        auto content = fileStorage_.readFileContent(templatePath);
        nodes::Node node = parser_.parse(content);
        node.render(vars, stream); // Render before move below
        cache_.put(templatePath, std::move(node));
    }
    return stream.str();
}

} // namespace ctemplator
