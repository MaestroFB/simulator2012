#ifndef ROBOT_H
#define ROBOT_H

#include <QPoint>
#include <QPaintDevice>
#include <QPainter>
#include <math.h>

class Robot
{
public:
    Robot();

    void setSize(int _width,int _height);
    void setLocation(QPoint _location);
    void setScale(float _scale);
    void setPaintDevice(QPaintDevice* _paintDevice);

    void show();

    //Add to actionStack
    void move(double value);
    void rotate(double value);

    //Change location and angle
    void realMove(double value);
    void realRotate(double value);

    void setBusy(bool _busy);
    bool isBusy();

    struct ActionStruct
    {
        int flag;
        double value;
    };
    ActionStruct action_temp;

    QVector<ActionStruct> actionStack;

private:
    int width;
    int height;
    double angle;
    float scale;
    bool busy;
    QPaintDevice* paintDevice;
    QPoint location;
    QPainter painter;


};

#endif // ROBOT_H
