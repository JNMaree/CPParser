#include "cpparser.hpp"
#include "cmd.hpp"


namespace cpparser{

    int process(std::string* fullCommand)
    {
        std::vector<lexer::Token> vecTokens = lexer::tokenise(fullCommand);


        return 0;
    }

    template<typename Function>
    void create(std::string mnemonic, Function& function)
    {
        function();
    }

}//namespace:cpparser