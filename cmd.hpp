#include <string>
#include <vector>

/*
Character definitions to be used by the lexer to tokenise the input string.

Delimiter:              - char: seperates tokens
flagPre:                - char: tells parser the text is a flag or switch
commentLinePre:         - String/char: treats subsequent text on line as a comment

commentMultiLinePre/Post:    - pre-String/char: treats subsequent text as a comment 
                                until post-String/char is parsed
*/
#define delimiter [' ','_']
#define flagPre ['-','/']
#define commentLinePre ["//","#"]

#define commentMultiLinePre ["/*"]
#define commentMultiLinePost ["*/"]

struct source{        
    const char* charArray;

    size_t size(size_t startChar = 0, size_t stopChar = 0);
};

namespace cpparse{

    class cmd{

        public:
            char* mnemonic;
            std::vector<char*> arguments;
    };

    //Function Prototypes
    int process(const char* cmdArgs);


}//namespace:cpparser

namespace lexer{

   

    //Function Prototypes
    std::vector<char*> tokenise(const char* charArray);
    size_t size(const char* charArray);

}//namespace:lexer

