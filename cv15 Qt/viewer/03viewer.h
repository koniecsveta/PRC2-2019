#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include <QDir>

class QLabel;
class QScrollArea;
class QAction;
class QMenu;
class QToolBar;
class QCloseEvent;


class Viewer : public QMainWindow
{
    Q_OBJECT
    QLabel *lblImage;
    QScrollArea *scrollArea;
    QAction *actQuit;
    QAction *actOpen;
    QAction *actZoomIn;
    QAction *actZoom1;
    QAction *actZoomOut;
    QAction *actZoomFit;
    QAction *actNext;
    QAction *actPrev;
    QMenu *mnuFile;
    QMenu *mnuZoom;
    QMenu *mnuNavigation;
    QToolBar *toolBar;
    QString workDir;
    QList<QString> images;
    quint16 currIndex;
    void zoom(double factor);
    void toggleZoomActions(bool enable);
    double zoomFactor;
    void open(quint16 index);
    void loadImages(QDir &dir);
    void closeEvent(QCloseEvent *event);
public:
    explicit Viewer(QWidget *parent = nullptr);
signals:
public slots:
    void open();
    void zoomIn();
    void zoomOut();
    void zoom1();
    void fitToWindow();
    void next();
    void prev();
};

#endif // VIEWER_H
