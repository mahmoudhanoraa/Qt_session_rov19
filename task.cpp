#include "task.h"
#include "ui_task.h"
#include <QInputDialog>
#include <QDebug>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent)
  /*,ui(new Ui::Task)*/
{
    //ui->setupUi(this);
    if (this->objectName().isEmpty())
        this->setObjectName(QStringLiteral("Task"));
    this->resize(400, 300);
    horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    checkBox = new QCheckBox(this);
    checkBox->setObjectName(QStringLiteral("checkBox"));

    horizontalLayout->addWidget(checkBox);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    editButton = new QPushButton(this);
    editButton->setObjectName(QStringLiteral("editButton"));

    horizontalLayout->addWidget(editButton);

    removeButton = new QPushButton(this);
    removeButton->setObjectName(QStringLiteral("removeButton"));

    horizontalLayout->addWidget(removeButton);

    this->setWindowTitle(QApplication::translate("Task", "Form", Q_NULLPTR));
    checkBox->setText(QApplication::translate("Task", "CheckBox", Q_NULLPTR));
    editButton->setText(QApplication::translate("Task", "Edit", Q_NULLPTR));
    removeButton->setText(QApplication::translate("Task", "Remove", Q_NULLPTR));

    setName(name);

    connect(editButton, SIGNAL(clicked(bool)), this, SLOT(rename()));
}

void Task::setName(const QString &name)
{
    checkBox->setText(name);
}

QString Task::getName() const
{
    return checkBox->text();
}

bool Task::isCompleted() const
{
    return checkBox->isChecked();
}


Task::~Task()
{
    delete ui;
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this,
                                          "Edit task",
                                          "Task name",
                                          QLineEdit::Normal,
                                          this->getName(),
                                          &ok);
    if(ok && !value.isEmpty()){
        setName(value);
    }

}
