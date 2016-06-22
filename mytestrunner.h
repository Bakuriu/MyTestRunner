#ifndef MYTESTRUNNER_H
#define MYTESTRUNNER_H

#include "mytestrunner_global.h"

#include <KRunner/AbstractRunner>

class MYTESTRUNNERSHARED_EXPORT MyTestRunner : public Plasma::AbstractRunner
{

    Q_OBJECT

public:
    MyTestRunner(QObject *parent, const QVariantList & args);
    void match(Plasma::RunnerContext &context);
    void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match);
    void createRunOptions(QWidget *widget);
    void reloadConfiguration();

protected Q_SLOTS:
    void prepareForMatchSession();
    void matchSessionFinished();
};

#endif // MYTESTRUNNER_H
