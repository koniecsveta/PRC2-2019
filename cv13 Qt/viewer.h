#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include <QDir>
#include <QLabel>
#include <QScrollArea>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QCloseEvent>


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
