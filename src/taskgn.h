#ifndef TASKGN_H
#define TASKGN_H

#include <QObject>
#include <QThread>

class TaskGn : public QThread
{
    Q_OBJECT

public:
    enum TASK_KIND {
        TASK_KIND_NONE,
        TASK_KIND_DESC,
    };
    struct ProcessResults {
        bool threadRun_ = false;
        bool processStarted_ = false;
        QString output_;
        QString error_;
        int exitCode_;
    };

private:
    TASK_KIND taskKind_ = TASK_KIND_NONE;
    QString path_;
    QString sourceRoot_;
    QString outDir_;
    QString arg_;
    ProcessResults results_;

public:
    TaskGn() { Q_ASSERT(false);}
    TaskGn(TASK_KIND taskKind, const QString& path, const QString& sourceRoot, const QString& outdir, const QString& arg) :
        taskKind_(taskKind), path_(path), sourceRoot_(sourceRoot), outDir_(outdir), arg_(arg) {
        results_.processStarted_=false;
    }

    void run() override;

    QString getResults() const;
};

#endif // TASKGN_H
