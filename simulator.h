#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "board.h"
#include "robot.h"

#include <QtGui/QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QPainter>
#include <QBrush>
#include <QPoint>
#include <QPaintDevice>
#include <QTextEdit>
#include <QLabel>
#include <QTimer>

#define TIMER_INTERVAL  50

#define DELTA_LENGTH    10
#define DELTA_ANGLE     5

class ImageBox : public QWidget
{
    Q_OBJECT

public:
    ImageBox();
    ~ImageBox();

    Robot robot;
    QTimer* pTimer;
    double dl;
    double da;
    void paintEvent(QPaintEvent *);
};

class Simulator : public QDialog
{
    Q_OBJECT

public:
    Simulator(QWidget* parent = 0);
    ~Simulator();

private:
    QTextEdit* pTextBox;
    QGridLayout* pLayout;
    QPushButton* pButtonClose;
    QLabel* pLabel;
    int textWordCounter;
    ImageBox* pImg;

public slots:
    void pTextBoxEnter();
};

#endif // SIMULATOR_H
