#include "simulator.h"

Simulator::Simulator(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle("Simulator");
    textWordCounter = 0;

    //pImg
    pImg = new ImageBox();
    pImg->setFixedSize(601,421);

    //pButtonClose
    pButtonClose = new QPushButton("Close");
    pButtonClose->setFixedSize(100,30);
    connect(pButtonClose,SIGNAL(clicked()),this,SLOT(close()));

    //pLabel
    pLabel = new QLabel("Ready...");

    //pTextBox
    pTextBox = new QTextEdit();
    pTextBox->setFixedSize(100,400);
    connect(pTextBox,SIGNAL(textChanged()),this,SLOT(pTextBoxEnter()));

    //pLayout
    pLayout = new QGridLayout();
    pLayout->addWidget(pImg,0,0);
    pLayout->addWidget(pTextBox,0,1);
    pLayout->addWidget(pLabel,1,0);
    pLayout->addWidget(pButtonClose,1,1);
    this->setLayout(pLayout);
}


Simulator::~Simulator()
{
    delete pButtonClose;
    delete pLayout;
    delete pImg;
    delete pTextBox;
    delete pLabel;
}

void Simulator::pTextBoxEnter()
{
    if(pTextBox->document()->toPlainText().endsWith('\n'))
    {
        QString textTemp;

        textTemp = pTextBox->document()->toPlainText().mid(textWordCounter);
        textWordCounter += textTemp.length();

        if(textTemp.startsWith("mov"))
        {
            pImg->robot.move(textTemp.mid(textTemp.indexOf(' '),textTemp.length() - textTemp.indexOf(' ') - 1).toDouble());
        }

        if(textTemp.startsWith("rot"))
        {
            pImg->robot.rotate(textTemp.mid(textTemp.indexOf(' '),textTemp.length() - textTemp.indexOf(' ') - 1).toDouble());
        }

        if(!textTemp.startsWith("rot") && !textTemp.startsWith("mov"))
        {
            pLabel->setText("Please enter: MOV XXX or ROT XXX");
        }

        //pLabel->setText(QString::number(pImg->robot.actionStack[pImg->robot.actionStack.count() - 1].value));
    }
}



ImageBox::ImageBox()
{
    //Delta
    dl = DELTA_LENGTH;
    da = DELTA_ANGLE;

    //robot
    robot.setPaintDevice(this);

    //pTimer
    pTimer = new QTimer(this);
    pTimer->setInterval(TIMER_INTERVAL);
    connect(pTimer,SIGNAL(timeout()),SLOT(repaint()));
    pTimer->start();
}

ImageBox::~ImageBox()
{
    delete pTimer;
}


void ImageBox::paintEvent(QPaintEvent *)
{
    Board_Show(this);
    bool flag_remove = 0;

    if(!robot.actionStack.isEmpty())
    {
        //Move
        if(robot.actionStack[0].flag == 1)
        {
            if(robot.actionStack[0].value > 0)
            {
                robot.actionStack[0].value -= dl;
                robot.realMove(dl);

                if(robot.actionStack[0].value < dl)
                    flag_remove = 1;
            }

            if(robot.actionStack[0].value < 0)
            {
                robot.actionStack[0].value += dl;
                robot.realMove(-dl);

                if(robot.actionStack[0].value > -dl)
                    flag_remove = 1;
            }
        }

        //Rotate
        if(robot.actionStack[0].flag == 2)
        {
            if(robot.actionStack[0].value > 0)
            {
                robot.actionStack[0].value -= da;
                robot.realRotate(da);

                if(robot.actionStack[0].value < da)
                    flag_remove = 1;
            }

            if(robot.actionStack[0].value < 0)
            {
                robot.actionStack[0].value += da;
                robot.realRotate(-da);

                if(robot.actionStack[0].value > -da)
                    flag_remove = 1;
            }
        }
    }

    if(flag_remove)
    {
        robot.actionStack.pop_front();
        flag_remove = 0;
    }
    robot.show();
}
