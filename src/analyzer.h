#ifndef ANALYZER_H
#define ANALYZER_H

#include <QString>

class Analyzer
{
    QString text_;
    enum CATEGORY_FLAG {
        IS_FULLPATH = 1 << 0,
        IS_PATH = 1 << 1,
        IS_TARGET_PATH = 1 << 2,
        IS_FULLTARGET_PATH = 1 << 3,
        IS_ALL_DIGITS = 1 << 4,
        IS_ALL_ALPAH = 1 << 5,
        IS_ALL_ASCII = 1 << 6,
    };
    int category_ = 0;
public:
    Analyzer(){}
    void Initialize(const QString& text);
    QString getPath() const;
};

#endif // ANALYZER_H
