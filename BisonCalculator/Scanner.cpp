#include "scanner.h"

namespace yy {

    Scanner::Scanner()
    {
        count = 0;
    }


    Scanner::~Scanner()
    {
    }

    yy::Parser::symbol_type Scanner::lex()
    {
        count++;

        if (count == 1)
        {
            double val = 1.0;
            return yy::Parser::make_DOUBLE(val);
        }
        else if (count == 2)
        {
            return yy::Parser::make_PLUS();
        }
        else if (count == 3)
        {
            double val = 10.0;
            return yy::Parser::make_DOUBLE(val);
        }
        else if (count == 4)
        {
            return yy::Parser::make_EOL();
        }
        else
        {
            return yy::Parser::make_END();
        }
    }

}