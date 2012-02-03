#include "robot.h"

Robot::Robot()
{
    setSize(350,250);
    setLocation(QPoint(250,250));
    setScale(0.2);
    angle = 0;
}

void Robot::setPaintDevice(QPaintDevice *_paintDevice)
{
    paintDevice = _paintDevice;
}

void Robot::setSize(int _width,int _height)
{
    width = _width;
    height = _height;
}

void Robot::setLocation(QPoint _location)
{
    location = _location;
}

void Robot::setScale(float _scale)
{
    scale = _scale;
}

void Robot::setBusy(bool _busy)
{
    busy = _busy;
}

bool Robot::isBusy()
{
    return busy;
}

void Robot::show()
{
    painter.begin(paintDevice);
    painter.scale(scale,scale);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush(Qt::black, Qt::Dense2Pattern));
    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine));

    QPoint robotPoints[5];
    robotPoints[0] = QPoint(location.x() - height * cos(angle * 3.14 / 180.0) / 2 + width * sin(angle * 3.14 / 180.0) / 2,location.y() + height * sin(angle * 3.14 / 180.0) / 2 + width * cos(angle * 3.14 / 180.0) / 2);
    robotPoints[1] = QPoint(location.x() + height * cos(angle * 3.14 / 180.0) / 2 + width * sin(angle * 3.14 / 180.0) / 2,location.y() - height * sin(angle * 3.14 / 180.0) / 2 + width * cos(angle * 3.14 / 180.0) / 2);
    robotPoints[2] = location;
    robotPoints[3] = QPoint(location.x() + height * cos(angle * 3.14 / 180.0) / 2 - width * sin(angle * 3.14 / 180.0) / 2,location.y() - height * sin(angle * 3.14 / 180.0) / 2 - width * cos(angle * 3.14 / 180.0) / 2);
    robotPoints[4] = QPoint(location.x() - height * cos(angle * 3.14 / 180.0) / 2 - width * sin(angle * 3.14 / 180.0) / 2,location.y() + height * sin(angle * 3.14 / 180.0) / 2 - width * cos(angle * 3.14 / 180.0) / 2);
    painter.drawPolygon(robotPoints,5);

    painter.end();
}

void Robot::move(double value)
{
    ActionStruct tempAction;

    tempAction.flag = 1;
    tempAction.value = value;

    actionStack.push_back(tempAction);
}

void Robot::rotate(double value)
{
    ActionStruct tempAction;

    tempAction.flag = 2;
    tempAction.value = value;

    actionStack.push_back(tempAction);
}

void Robot::realMove(double value)
{
    location.setX(location.x() + value * cos(angle * 3.14 / 180.0));
    location.setY(location.y() - value * sin(angle * 3.14 / 180.0));
}

void Robot::realRotate(double value)
{
    angle += value;
}
