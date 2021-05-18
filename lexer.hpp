#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <string>
#include <vector>

// Character definitions to be used by the lexer to tokenise the input string.

/** delimiter:          - char: seperates tokens
*/
#define delimiter ' '

/** whiteSpace:         - String: characters considered to be whiteSpace
*/
#define whiteSpace " \t"

/*flagPre:              - char: parse the following text as a flag/switch
*/
#define flagPre '-'
/*stringPre:            - char: the pre- and -post markers for strings
*/
#define stringPre '"'

/*commentLinePre:         - String/char: treats subsequent text on line as a comment
*/
#define commentLinePre ["//","#"]

/*commentMultiLinePre/Post:    - pre-String: treats subsequent text as a comment 
                                until post-String is parsed
*/
#define commentMultiLinePre ["/*"]
#define commentMultiLinePost ["*/"]


namespace lexer{
    
    enum Type{
        flag,
        flagFull,
        string,
        integer,
        floatingP,
    };

    class Token{
    public:
        std::string text;
        Type type;
        Token(std::string* source);
        Token(std::string& source);
        void set();
    };

    


    //Function Prototypes

    std::vector<Token> tokenise(std::string* source);
    void condense(std::string* source);


}//namespace:lexer

#endif