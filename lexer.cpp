#include "lexer.hpp"

namespace cpparser
{
namespace lexer
{

    void Token::setType()
    {        
        std::string tmp = *text;
        switch (tmp[0])    //Check first character of Token
        {
        case flagPre:
            if(tmp[1] == flagPre){     //--
                type = flagFull;
            }else{                      //-
                type = flag;
            }
            break;
        case stringPre:                 //"
            type = quoted;

            break;
        default:
            break;
        }
    }

    Token::Token()
    {
        text = nullptr;
        type = undetermined;
    }

    Token::Token(std::string* source)
    {
        text = source;
        setType();
    }

    Token::Token(std::string& source)
    {
        text = &source;
        setType();
    }

    Tokentainer::~Tokentainer()
    {
        arraySize = 0;
        arrayCapacity = 0;
        if  (arrayPtr)
            delete []arrayPtr;
    }

    void Tokentainer::push(Token& toki)
    {

    }

    bool Tokentainer::empty()
    {
        if(arraySize == 0)
            return true;
        else
            return false;
    }

    Tokentainer tokenise(std::string* source)
    {
        Tokentainer retTokens;
        if (source->size() < 1){   //Empty String
            return retTokens;
        }

        condense(source);

        size_t posEnd = source->find_first_of(delimiter);
        if(posEnd != std::string::npos)           //If >1 tokens
        {
            size_t pos = 0;
            do{
                Token token(source->substr(pos, posEnd));
                retTokens.push(token);
                pos = posEnd;
                posEnd = source->find_first_of(delimiter, ++posEnd);
            }
            while( posEnd != std::string::npos);
        }else{                                      //If 1 token
            Token token(source);
            retTokens.push(token);
        }

    }

    void condense(std::string* source)
    {
        //remove pre- & -post whiteSpace
        source->erase(0, source->find_first_not_of(whiteSpace));
        source->erase(source->find_last_not_of(whiteSpace) + 1);

        //create array of chars to search for in source
        std::string rem = delimiter;
        rem += whiteSpace;
        
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