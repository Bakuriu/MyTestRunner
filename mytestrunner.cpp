#include "mytestrunner.h"
#include <QMessageBox>


MyTestRunner::MyTestRunner(QObject *parent, const QVariantList &args)
    : AbstractRunner(parent, args)
{
    setIgnoredTypes(Plasma::RunnerContext::FileSystem | Plasma::RunnerContext::NetworkLocation);
    setSpeed(NormalSpeed);
    setPriority(HighestPriority);
    setHasRunOptions(true);
    reloadConfiguration();

    connect(this, SIGNAL(prepare()), this, SLOT(prepareForMatchSession()));
    connect(this, SIGNAL(teardown()), this, SLOT(matchSessionFinished()));
}


void MyTestRunner::reloadConfiguration()
{
    // does nothing atm.
}


void MyTestRunner::prepareForMatchSession()
{
    // does nothing atm.
}

void MyTestRunner::matchSessionFinished()
{
    // does nothing atm.
}


void MyTestRunner::match(Plasma::RunnerContext &context)
{
    if (!context.isValid())
    {
        return;
    }

    QString query = context.query();

    Plasma::QueryMatch match(this);
    match.setText("You typed this: " + query);
    match.setData(query);
    match.setType(Plasma::QueryMatch::ExactMatch);

    context.addMatch(match);
}


void MyTestRunner::run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match)
{
    Q_UNUSED(context)

    QMessageBox box;
    box.setText( QString("You typed this: ") + match.data().toString());
    box.setWindowTitle(QString("You typed something"));
    box.exec();
}

K_EXPORT_PLASMA_RUNNER(my-test-runner, MyTestRunner)
