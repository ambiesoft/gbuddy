
#include "../../lsMisc/stdosd/stdosd.h"
#include "../../lsMisc/stdQt/stdQt.h"

#include "analyzer.h"

using namespace Ambiesoft::stdosd;
using namespace AmbiesoftQt;

Analyzer::Analyzer(const QString& text) : text_(text)
{
    init();
}

void Analyzer::init()
{
    if(text_.isEmpty())
    {
        category_ = 0;
        return;
    }

    if(stdIsAsciiString(QStringToStdString(text_)))
        category_ |= IS_ALL_ASCII;
    if(stdIsAsciiDigitString(QStringToStdString(text_)))
        category_ |= IS_ALL_DIGITS;
    if(stdIsAsciiAlphaString(QStringToStdString(text_)))
        category_ |= IS_ALL_ALPAH;

    if(text_.length() > 2 && text_[0]=='/' && text_[1]=='/')
    {
        category_ |= IS_FULLTARGET_PATH;
    }
    if( (category_ & IS_ALL_ALPAH) && !(category_ & IS_ALL_DIGITS))
    {
        category_ |= IS_TARGET_PATH;
        category_ |= IS_PATH;
    }
    if(text_.indexOf('/') >=0 || text_.indexOf('\\') >=0 )
    {
        category_ |= IS_PATH;
        if(stdIsFullPath(QStringToStdString(text_)))
            category_ |= IS_FULLPATH;
    }
}
