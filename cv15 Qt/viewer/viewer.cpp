#include "viewer.h"
#include <QScrollArea>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QDebug>
#include <iostream>


Viewer::Viewer(QWidget *parent) : QMainWindow(parent)
{
    lblImage = new QLabel;
    lblImage->setSizePolicy(QSizePolicy::Ignored,
                            QSizePolicy::Ignored);
    lblImage->setScaledContents(true);
    scrollArea = new QScrollArea;
    scrollArea->setWidget(lblImage);
    this->setCentralWidget(scrollArea);
    this->resize(1024, 768);
    this->setWindowTitle(tr("Simple Image Viewer"));

    QIcon iconOpen = QIcon::fromTheme("document-open",
            QIcon(":/icons/open.png"));
    actOpen = new QAction(tr("&Open"), this);
    actOpen->setShortcut(QKeySequence::Open);
    actOpen->setIcon(iconOpen);
    actOpen->setToolTip(tr("Open image"));
    actOpen->setStatusTip(tr("Open image from file"));

    //akce Quit
    QIcon iconQuit = QIcon::fromTheme("application-exit",
            QIcon(":/icons/quit.png"));
    actQuit = new QAction(tr("E&xit"), this);
    actQuit->setShortcut(QKeySequence::Quit);
    actQuit->setIcon(iconQuit);
    actQuit->setToolTip(tr("Exits the viewer"));
    actQuit->setStatusTip(tr("Closes the application"));

    //akce zoom in
    QIcon iconZoomIn = QIcon::fromTheme("zoom-in", QIcon(":/icons/zoomIn.png"));
    actZoomIn = new QAction(tr("Zoom &In"), this);
    actZoomIn->setShortcut(QKeySequence::ZoomIn);
    actZoomIn->setToolTip(tr("Zooms image in"));
    actZoomIn->setStatusTip(tr("Zooms image in"));
    actZoomIn->setIcon(iconZoomIn);

    //akce zoom 100%
    QIcon iconZoom1 = QIcon::fromTheme("zoom-original", QIcon(":/icons/Zoom1.png"));
    actZoom1 = new QAction(tr("Original &size"), this);
    actZoom1->setShortcut(tr("Ctrl+1"));
    actZoom1->setToolTip(tr("Resets zoom"));
    actZoom1->setStatusTip(tr("Resets zoom"));
    actZoom1->setIcon(iconZoom1);

    //akce zoom out
    QIcon iconZoomOut = QIcon::fromTheme("zoom-out", QIcon(":/icons/zoomOut.png"));
    actZoomOut = new QAction(tr("Zoom &Out"), this);
    actZoomOut->setShortcut(QKeySequence::ZoomOut);
    actZoomOut->setToolTip(tr("Zooms image out"));
    actZoomOut->setStatusTip(tr("Zooms image out"));
    actZoomOut->setIcon(iconZoomOut);

    //akce zoom fit
    QIcon iconZoomFit = QIcon::fromTheme("zoom-fit-best", QIcon(":/icons/zoomFit.png"));
    actZoomFit = new QAction(tr("&Fit to window"), this);
    actZoomFit->setToolTip(tr("Fits image to window"));
    actZoomFit->setStatusTip(tr("Fits image to window"));
    actZoomFit->setIcon(iconZoomFit);
    actZoomFit->setCheckable(true);
    actZoomFit->setChecked(false);

    mnuFile = new QMenu(tr("&File"), this);
    mnuFile->addAction(actOpen);
    mnuFile->addAction(actQuit);


    mnuZoom = new QMenu(tr("&Zoom"), this);
    mnuZoom->addAction(actZoomIn);
    mnuZoom->addAction(actZoom1);
    mnuZoom->addAction(actZoomOut);
    mnuZoom->addSeparator();
    mnuZoom->addAction(actZoomFit);

    //akce Prev
    QIcon iconPrev = QIcon::fromTheme("go-previous", QIcon(":/icons/prev.png"));
    actPrev = new QAction(tr("&Previous"), this);
    actPrev->setToolTip(tr("Loads previous image in the current working directory"));
    actPrev->setStatusTip(tr("Loads previous image in the current working directory"));
    actPrev->setIcon(iconPrev);
    actPrev->setShortcut(QKeySequence::Back);

    //akce Next
    QIcon iconNext = QIcon::fromTheme("go-next", QIcon(":/icons/next.png"));
    actNext = new QAction(tr("&Next"), this);
    actNext->setToolTip(tr("Loads next image in the current working directory"));
    actNext->setStatusTip(tr("Loads next image in the current working directory"));
    actNext->setIcon(iconNext);
    actNext->setShortcut(QKeySequence::Forward);


    mnuNavigation = new QMenu(tr("Navi&gation"), this);
    mnuNavigation->addAction(actPrev);
    mnuNavigation->addAction(actNext);

    toolBar = this->addToolBar(tr("Main tool bar"));
    toolBar->addAction(actOpen);
    toolBar->addAction(actQuit);
    toolBar->addSeparator();
    toolBar->addAction(actZoomIn);
    toolBar->addAction(actZoomOut);
    toolBar->addAction(actZoomFit);
    toolBar->addSeparator();
    toolBar->addAction(actPrev);
    toolBar->addAction(actNext);

    this->menuBar()->addMenu(mnuFile);
    this->menuBar()->addMenu(mnuZoom);
    this->menuBar()->addMenu(mnuNavigation);
    connect(actQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(actOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(actZoomIn, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(actZoom1, SIGNAL(triggered()), this, SLOT(zoom1()));
    connect(actZoomOut, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(actZoomFit, SIGNAL(triggered()), this, SLOT(fitToWindow()));
    connect(actPrev, SIGNAL(triggered()), this, SLOT(prev()));
    connect(actNext, SIGNAL(triggered()), this, SLOT(next()));
    toggleZoomActions(false);
    actZoomFit->setEnabled(false);
    this->statusBar()->showMessage(tr("Application started"), 3000);
    QSettings settings(tr("FJFI"), tr("ImageViewer"));
    workDir = settings.value("general/workDir", QDir::homePath()).toString();
}

void Viewer::closeEvent(QCloseEvent *){
    QSettings settings(tr("FJFI"), tr("ImageViewer"));
    settings.setValue("general/workDir", workDir);
}

void Viewer::open(quint16 index){
    QString fileName = workDir + QDir::separator() + images[index];
    if(!fileName.isEmpty()){
        QImage image(fileName);
        if(image.isNull()){
            QMessageBox::warning(this, tr("Error"),
                                 tr("Failed to load selected image"));
            return;
        }
        lblImage->setPixmap(QPixmap::fromImage(image));
        lblImage->adjustSize();
        toggleZoomActions(true);
        actZoomFit->setEnabled(true);
        statusBar()->showMessage(tr("Image %1 was loaded").arg(fileName),
                                 3000);
        zoom1();
    }
}

void Viewer::open(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select image"),
                                                    workDir,
                                                    tr("Images (*.png *.xpm *.jpg *.jpeg);;All files (*)"));
    if(fileName.isEmpty()){
        return;
    }
    images.clear();
    QFileInfo info(fileName);
    QDir dir = info.path();
    workDir = dir.canonicalPath();
    fileName = info.fileName();
    qDebug() << workDir;
    QStringList filters;
    filters << "*.jpg" << "*.gif" << "*.png" << "*.jpeg" << "*.xpm";
    images = dir.entryList(filters);
    currIndex = images.indexOf(fileName);
    open(currIndex);
}

void Viewer::fitToWindow(){
    bool fitted = actZoomFit->isChecked();
    scrollArea->setWidgetResizable(fitted);
    if(!fitted){
        lblImage->adjustSize();
        zoom1();
    }
    toggleZoomActions(!fitted);
}

void Viewer::toggleZoomActions(bool enable){
    actZoomIn->setEnabled(enable);
    actZoom1->setEnabled(enable);
    actZoomOut->setEnabled(enable);
    actPrev->setEnabled(enable);
    actNext->setEnabled(enable);
}

void Viewer::zoom1(){
    zoomFactor = 1.0;
    zoom(1.0);
}

void Viewer::zoom(double factor){
    zoomFactor = zoomFactor*factor;
    lblImage->resize(lblImage->pixmap()->size()*zoomFactor);
    actZoomIn->setEnabled(zoomFactor < 3.0);
    actZoomOut->setEnabled(zoomFactor > 0.2);
}

void Viewer::zoomIn(){
    zoom(1.25);
}

void Viewer::zoomOut(){
    zoom(0.8);
}

void Viewer::next(){
    if(currIndex == images.count() - 1){
        currIndex = 0;
    } else{
        currIndex++;
    }
    open(currIndex);
}

void Viewer::prev(){
    if(currIndex == 0){
        currIndex = images.count() - 1;
    } else{
        currIndex--;
    }
    open(currIndex);
}
