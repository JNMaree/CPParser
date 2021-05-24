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

    void add(std::string mnemonic,)
    {
        
    }

} //namespace:command
} //namespace:cpparser
