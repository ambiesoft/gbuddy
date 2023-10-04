
#include "../../lsMisc/stdosd/stdosd.h"
#include "../../lsMisc/stdQt/stdQt.h"

#include "optiondialog.h"
#include "globals.h"
#include "analyzer.h"

using namespace Ambiesoft::stdosd;
using namespace AmbiesoftQt;

void Analyzer::Initialize(const QString& text)
{
    text_ = text;
    category_ = 0;
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
QString Analyzer::getPath() const
{
    if(category_ & IS_FULLTARGET_PATH) {
        Q_ASSERT(text_[0]=='/' && text_[1]=='/');
        return pathCombine(gpOptionDialog->sourceRoot(), text_.right(text_.length()-2));
    }
    if(category_ & IS_FULLPATH)
        return text_;
    if(category_ & IS_PATH)
        return pathCombine(gpOptionDialog->sourceRoot(), text_);
    return QString();

}
