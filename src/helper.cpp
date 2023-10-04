#include <QString>
#include <QApplication>
#include <QClipboard>
#include <QLineEdit>

#include "helper.h"

// static
bool GetClipboardFirstLine(QString* line)
{
    QString text = QApplication::clipboard()->text();
    if(text.isEmpty())
        return false;

    // Get FirstLine
    qsizetype i =  text.indexOf('\n');
    if( i < 0 ) {
        *line = text;
    } else {
        *line = text.first(i);
    }
    return true;
}

void SetLineTextWithUndoable(QLineEdit* pLE, const QString& text)
{
    pLE->selectAll();
    pLE->insert(text);
}
void SetLineTextWithUndoable(QTextEdit* pTE, const QString& text)
{
    pTE->selectAll();
    pTE->insertPlainText(text);
}
