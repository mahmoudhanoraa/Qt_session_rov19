#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QInputDialog>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::MainWindow)
{
  // ui->setupUi(this);
    //connect(addTaskButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

   this->resize(800, 600);
   centralWidget = new QWidget(this);
   verticalLayout = new QVBoxLayout(centralWidget);

   toolbarLayout = new QHBoxLayout();
   statusLabel = new QLabel(centralWidget);
   addTaskButton = new QPushButton(centralWidget);


   statusLabel->setText("0 todo/ 0 done ");
   addTaskButton->setText("Add Task");
   toolbarLayout->addWidget(statusLabel);
   horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
   toolbarLayout->addItem(horizontalSpacer);
   toolbarLayout->addWidget(addTaskButton);

   verticalLayout->addLayout(toolbarLayout);
   tasksLayout = new QVBoxLayout();
   verticalLayout->addLayout(tasksLayout);

   verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
   verticalLayout->addItem(verticalSpacer);

   this->setCentralWidget(centralWidget);
   this->setWindowTitle("TODOs");


   connect(addTaskButton, SIGNAL(clicked(bool)), this, SLOT(addTask()));
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add task",
                                               "Task name",
                                               QLineEdit::Normal,
                                               "Untitled task", &ok);
    if(ok && !name.isEmpty()){
        qDebug() << "user clicked on the button" << endl;
        Task* task = new Task(name);
        tasksLayout->addWidget(task);
    }

}
