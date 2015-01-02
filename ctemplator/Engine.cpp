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
    auto content = fileStorage_.readFileContent(templatePath);
    nodes::Node node = parser_.parse(content);
    std::ostringstream stream;
    node.render(vars, stream);
    return stream.str();
}

} // namespace ctemplator