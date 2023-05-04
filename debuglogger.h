#ifndef DEBUGLOGGER_H
#define DEBUGLOGGER_H
#include <QObject>
#include <QStringListModel>


class DebugLogger: public QObject
{
     Q_OBJECT
public:
    DebugLogger(QObject* parent = nullptr) : QObject(parent)
        {
            m_model = new QStringListModel(this);
        }
    void log(const QString& message)
       {
           // Thêm thông tin mới vào danh sách
           QStringList list = m_model->stringList();
           list << message;

           // Cập nhật model để ListView hiển thị thông tin mới nhất
           m_model->setStringList(list);

           // Kích hoạt sự kiện để thông báo cho UI cập nhật ListView
           emit logAdded();
       }

       // Getter để truy cập vào model từ UI
       QStringListModel* model() const
       {
           return m_model;
       }

   signals:
       // Tín hiệu để thông báo cho UI cập nhật ListView
       void logAdded();

private:
    QStringListModel* m_model;
};

#endif
