#include "viewer.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QSettings>
#include <QFileInfo>
#include <iostream>
#include <QDebug>

Viewer::Viewer(QWidget *parent) :
    QMainWindow(parent)
{
    lblImage = new QLabel;
    lblImage->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    lblImage->setScaledContents(true);
    scrollArea  = new QScrollArea;
    scrollArea->setWidget(lblImage);
    this->setCentralWidget(scrollArea);
    this->resize(1034,768);
    this->setWindowTitle("Simple Image Viewer");

    QIcon iconOpen = QIcon(":/open.png");
    actOpen = new QAction("Open",this);
    actOpen->setShortcut(QKeySequence::Open);
    actOpen->setIcon(iconOpen);
    actOpen->setToolTip("Open image");
    actOpen->setStatusTip("Open image from file");

    mnuFile = new QMenu("File", this);
    mnuFile->addAction(actOpen);

    //mnuNavigation = new QMenu()
    toolBar = this->addToolBar("Main tool bar");
    toolBar->addAction(actOpen);

    this->menuBar()->addMenu(mnuFile);
    this->statusBar()->showMessage("Application started",3000);

    connect(actOpen, SIGNAL(triggered()), this, SLOT(open()));
    QSettings settings("FJFI","ImageViewer");
    workDir = settings.value("general/workDir",QDir::homePath()).toString();
}

Viewer::~Viewer()
{
}

void Viewer::open(){
    QString fileName = QFileDialog::getOpenFileName(this, "Select image",
                                                    workDir, "Images (*.png *.xpm *.jpg *.jpes);;All files(*)");
    if(fileName.isEmpty()){
        return;
    }
    images.clear();
    QFileInfo info(fileName);
    QDir dir = info.path();
    workDir = dir.canonicalPath();
    qDebug() << workDir;
}

void Viewer::prev(){}

void Viewer::next(){}

void Viewer::closeEvent(QCloseEvent *event){}

/*

class Viewer : public QMainWindow
{
    Q_OBJECT
    QLabel *lblImage;
    QScrollArea *scrollArea;

    QAction *actQuit;
    QAction *actOpen;
    QAction *actNext;
    QAction *actPrev;

    QMenu *mnuFile;
    QMenu *mnuNavigation;
  //  QToolBox *toolBox;
    QToolBar *toolBar;

    QString workDir;
    QList<QString> images;
    qint16 currIndex;

    void open(qint16 index);
    void loadImages(QDir &dir);
    void closeEvent(QCloseEvent *event);


public:
    explicit Viewer(QWidget *parent = nullptr);
    ~Viewer();

public slots:
    void open();
    void next();
    void prev();

};

#endif // VIEWER_H
*/
