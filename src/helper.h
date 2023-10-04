#ifndef HELPER_H
#define HELPER_H

#include <QLineEdit>
#include <QTextEdit>
bool GetClipboardFirstLine(QString* line);
void SetLineTextWithUndoable(QLineEdit* pLE, const QString& text);
void SetLineTextWithUndoable(QTextEdit* pTE, const QString& text);


#endif // HELPER_H
