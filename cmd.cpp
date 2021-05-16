#include "cmd.hpp"
#include "cmdtree.hpp"

size_t source::size(size_t startChar, size_t stopChar)
{   
    size_t retSize = startChar;
    while (charArray[retSize] != '\0')
    {
        ++retSize;
    }
    return retSize;
}

namespace cpparse{

    int process(const char* cmdArgs)
    {
        
        return 0;
    }
    

}//namespace:cpparser

namespace lexer{

    std::vector<char*> tokenise(source sourceText)
    {
        std::vector<char*> retVec;
        size_t arrSize = sourceText.size();
        if (arrSize < 1){
            return retVec;
        }



    }


}//namespace:lexer

