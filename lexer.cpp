#include "lexer.hpp"

namespace cpparser
{
namespace lexer
{

    void Token::set()
    {        
        switch (text[0])
        {
        case flagPre:
            if(text[1] == flagPre){     //--flagFull
                text = text.substr(2);
            }else{                      //-flag
                text = text.substr(1);
            }
            break;
        case stringPre:
            
            break;
        default:
            break;
        }
    }

    Token::Token(std::string* source)
    {
        text = *source;
        set();
    }

    Token::Token(std::string& source)
    {
        text = source;
        set();
    }

    std::vector<Token> tokenise(std::string* source)
    {
        std::vector<Token> retVecTokens;
        if (source->size() < 1){   //Empty String
            return retVecTokens;
        }

        condense(source);

        size_t posEnd = source->find_first_of(delimiter);
        if(posEnd != std::string::npos)           //If >1 tokens
        {
            size_t pos = 0;
            do{
                Token token(source->substr(pos, posEnd));
                retVecTokens.push_back(token);
                pos = posEnd;
                posEnd = source->find_first_of(delimiter, ++posEnd);
            }
            while( posEnd != std::string::npos);
        }else{                                      //If 1 token
            Token token(source);
            retVecTokens.push_back(token);
        }

    }

    void condense(std::string* source)
    {
        //remove pre- & -post whiteSpace
        source->erase(0, source->find_first_not_of(whiteSpace));
        source->erase(source->find_last_not_of(whiteSpace) + 1);

        //create array of chars to search for in source
        std::string rem = delimiter + whiteSpace;
        
        //condense to remove false occurences and accidental whitespaces or delimiters
        size_t f = source->find_first_of(rem);
        while(f != std::string::npos)
        {
            size_t g = source->find_first_not_of(rem, f) - f;
            source->replace(f, g, 1, delimiter[0]);
            f = source->find_first_of(rem, f + 1);
        }
    }

    bool isSame(std::string& str, std::string& cmp)
    {
        if(!isSameCase(str, cmp)){
            std::string strTr = str;         
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            std::string cmpTr = cmp;
            std::transform(cmp.begin(), cmp.end(), cmp.begin(), ::toupper);
            if(strTr.compare(cmpTr) == 0){
                return true;
            }else{
                return false;
            }
        }else{
            return true;            
        }
    }

    bool isSameCase(std::string& str, std::string& cmp)
    {
        if(str.compare(cmp) == 0){
            return true;
        }else{
            return false;
        }
    }

}//namespace:lexer
}//namespace:cpparser