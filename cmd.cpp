#include "cmd.hpp"

namespace cpparser
{
namespace command
{
    std::vector<cmd> cmdList;

    cmd::cmd(std::string cmdName, std::string cmdFullName)
    {
        cmd push;
        push.name = cmdName;
        if(!cmdFullName.empty())
            push.nameFull = cmdFullName;
        cmdList.push_back(push);
    }

    cmd::~cmd()
    {
        for (size_t i = 0; i < cmdList.size(); ++i)
        {
            if(cmdList[i].name == name)
                cmdList.erase(cmdList.begin() + i);
        }
        
    }

    void cmd::addOption(std::string optionName, 
                        std::string optionFullName, 
                        std::string optionDescription)
    {
        option newOption;
        newOption.name = optionName;
        newOption.fullname = optionFullName;
        newOption.description = optionDescription;
        options.push_back(newOption);
    }

    void add(std::string mnemonic, std::function<int()>)
    {
           
    }

    

} //namespace:command
} //namespace:cpparser
