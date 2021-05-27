#include "cpparser.hpp"


namespace cpparser{

    int process(std::string* fullCommand)
    {
        std::vector<lexer::Token> vecTokens = lexer::tokenise(fullCommand);
        int cmdexe = command::execute(&vecTokens);
        if(cmdexe < 0)
            return cmdexe;
    }

    void initialise()
    {
           
    }


}//namespace:cpparser