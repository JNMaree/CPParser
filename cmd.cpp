#include "cmd.hpp"

namespace cpparser
{
namespace command
{
    std::vector<cmd> vectorList;

    cmd::cmd(std::string cmdName, std::string cmdFullName)
    {
        cmd push;
        push.name = cmdName;
        if(!cmdFullName.empty())
            push.nameFull = cmdFullName;
        vectorList.push_back(push);
    }

    cmd::~cmd()
    {
        for (size_t i = 0; i < vectorList.size(); ++i)
        {
            if(lexer::isSame(name, vectorList[i].name))
                vectorList.erase(vectorList.begin() + i);
        }
        
    }

    void cmd::addOption(std::string optionName, 
                        std::string optionFullName, 
                        std::string optionDescription)
    {
        option newOption;
        newOption.flag = optionName;
        newOption.flagFull = optionFullName;
        newOption.description = optionDescription;
        options.push_back(newOption);
    }

    void add(std::string mnemonic, std::function<int(std::vector<lexer::Token>)>)
    {
        
    }

    int execute(std::string& commandName)
    {
        for (size_t i = 0; i < command::vectorList.size(); i++)
        {
            if(lexer::isSame(commandName, command::vectorList[i].name)){
                
                return (int) i;
            }
        }
        return -1;
    }   

} //namespace:command
} //namespace:cpparser
