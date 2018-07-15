#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainview.h"
#include <QString>

class QLabel;
class QRubberBand;
class QGraphicsScene;
class QGraphicsPixmapItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    QString file_name=NULL;
public slots:
    void openPixmap();
    void changeSetting();
    void onImageSizeChanged(const QSize &);
    void onZoomFactorChanged(double);
    void onToggleFullScreen(bool);
    void leaveFullScreen();
    void onResizeImage();
    void nextImage();
    void previousImage();
private slots:



private:
    Ui::MainWindow *ui;
    QSize pieceSize;

    QString lastSaveDir;
    QString lastOpenDir;
    QSize lastSize;

    GraphicsView *view;

    QLabel *imageSizeLabel;
    QLabel *zoomFactorLabel;

    QString filename;
    QSize imageSize;
    bool isModified;

    QVector<QString> fileList;
    int currentFileIndex;

};

#endif // MAINWINDOW_H
