#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>


namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    Task(const QString &name, QWidget *parent = 0);
    void setName(const QString &name);
    QString getName() const;
    bool isCompleted() const;
    ~Task();

public slots:
    void rename();
private:
    Ui::Task *ui;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *removeButton;
};

#endif // TASK_H
