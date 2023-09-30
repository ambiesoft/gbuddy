#include <QDebug>
#include <QProcess>
#include <QFileInfo>

#include "taskgn.h"


void TaskGn::run()
{
    qDebug() << "TTT";
    results_.threadRun_ = true;

    QProcess process;
    QString output;
    QString error;
    std::optional<QProcess::ProcessError> processError;

    QObject::connect(&process, static_cast<void(QProcess::*)(QProcess::ProcessError)>(&QProcess::errorOccurred),
                     [&processError](QProcess::ProcessError error){
                         processError = error;
                     });

    process.setWorkingDirectory(sourceRoot_);

    // Set PATH
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString newPath;

#ifdef Q_OS_WIN
    newPath = path_ + ";" + env.value("PATH");
#else
    newPath = path_ + ":" + env.value("PATH");
#endif

    env.insert("PATH", newPath);
    env.insert("DEPOT_TOOLS_WIN_TOOLCHAIN", "0");
    process.setProcessEnvironment(env);

    QStringList args;

#ifdef Q_OS_WIN
    process.setProgram("cmd");
    args.append("/C");
    args.append("gn");
    // args.append("C:/Linkout/argCheck/x86/argCheck.exe");
#else
    process.setProgram("gn");
#endif

    switch(taskKind_) {
    case TASK_KIND_DESC:
        args.append("desc");
        break;
    case TASK_KIND_REFS:
        args.append("refs");
        break;
    default:
        Q_ASSERT(false);
        return;
    }

    args.append(outDir_);
    args.append(arg_);
    process.setArguments(args);

    qDebug() << args;
    process.start(QProcess::ReadOnly);

    if(processError.has_value())
    {
        switch (processError.value()) {
        case QProcess::FailedToStart:
            error += "Failed to start process!";
            error += "Error message:" + process.errorString();
            break;
        default:
            error += "Error message:" + process.errorString();
            break;
        }
        return;
    }

    results_.processStarted_ = true;

    while (process.state() == QProcess::Running) {
        if (process.waitForReadyRead()) {
            output += QString::fromUtf8( process.readAllStandardOutput());
            qDebug() << output;
        }
    }

    process.waitForFinished();

    error += QString::fromUtf8(process.readAllStandardError());
    int exitCode = process.exitCode();

    // set results
    results_.output_ = output;
    results_.error_ = error;
    results_.exitCode_ = exitCode;

}
QString TaskGn::getResults() const
{
    return results_.output_;
}
