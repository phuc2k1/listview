#ifndef LISVIEWDEBUG_H
#define LISVIEWDEBUG_H
#include <QListView>
#include <QStringListModel>
#include <QApplication>
#include <QDebug>
class lisviewdebug: public QListView
{
    Q_OBJECT

  public:
      explicit lisviewdebug(QWidget *parent = nullptr);

  public slots:
      void addMessage(const QString &message, QtMsgType type = QtDebugMsg);

  private:
      QStringListModel *m_stringListModel;

      static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};


#endif // LISVIEWDEBUG_H
