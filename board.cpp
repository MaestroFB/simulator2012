#include "board.h"

void Board_Show(QPaintDevice *paintDevice)
{
    QPainter painter;

    painter.begin(paintDevice);
    painter.scale(PAINTER_SCALE,PAINTER_SCALE);
    painter.setRenderHint(QPainter::Antialiasing);

    //Main rectangle
    painter.setBrush(QBrush(QColor::fromRgb(0,204,255), Qt::SolidPattern));
    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine));
    painter.drawRect(0,0,MAIN_RECT_WIDTH,MAIN_RECT_HEIGHT);

    //Start violet rectangle
    painter.setBrush(QBrush(QColor::fromRgb(128,0,255), Qt::SolidPattern));
    painter.drawRect(0,0,START_RECT_WIDTH,START_RECT_HEIGHT);

    //Start red rectangle
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawRect(MAIN_RECT_WIDTH - START_RECT_WIDTH,0,START_RECT_WIDTH,START_RECT_HEIGHT);

    //Top island
    painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 - TOP_ISLAND_YELLOW_D / 2,- TOP_ISLAND_YELLOW_D / 2,TOP_ISLAND_YELLOW_D,TOP_ISLAND_YELLOW_D);
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 - TOP_ISLAND_GREEN_D / 2,- TOP_ISLAND_GREEN_D / 2,TOP_ISLAND_GREEN_D,TOP_ISLAND_GREEN_D);

    //Centr island (yellow)
    painter.setPen(QPen(Qt::black, 0, Qt::NoPen));
    painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 - CENTR_ISLAND_DIST / 2 - CENTR_ISLAND_YELLOW_D / 2,MAIN_RECT_HEIGHT / 2 - CENTR_ISLAND_YELLOW_D / 2,CENTR_ISLAND_YELLOW_D,CENTR_ISLAND_YELLOW_D);
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 + CENTR_ISLAND_DIST / 2 - CENTR_ISLAND_YELLOW_D / 2,MAIN_RECT_HEIGHT / 2 - CENTR_ISLAND_YELLOW_D / 2,CENTR_ISLAND_YELLOW_D,CENTR_ISLAND_YELLOW_D);
    painter.drawRect(MAIN_RECT_WIDTH / 2 - CENTR_ISLAND_DIST / 2,MAIN_RECT_HEIGHT / 2 - CENTR_ISLAND_YELLOW_D / 2,CENTR_ISLAND_DIST,CENTR_ISLAND_YELLOW_D);

    //Centr island (green)
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 - CENTR_ISLAND_DIST / 2 - CENTR_ISLAND_GREEN_D / 2,MAIN_RECT_HEIGHT / 2 - CENTR_ISLAND_GREEN_D / 2,CENTR_ISLAND_GREEN_D,CENTR_ISLAND_GREEN_D);
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 + CENTR_ISLAND_DIST / 2 - CENTR_ISLAND_GREEN_D / 2,MAIN_RECT_HEIGHT / 2 - CENTR_ISLAND_GREEN_D / 2,CENTR_ISLAND_GREEN_D,CENTR_ISLAND_GREEN_D);
    painter.drawEllipse(MAIN_RECT_WIDTH / 2 - CENTR_ISLAND_PALM_D / 2,MAIN_RECT_HEIGHT / 2 - CENTR_ISLAND_PALM_D / 2,CENTR_ISLAND_PALM_D,CENTR_ISLAND_PALM_D);

    //Narrow centr island
    painter.setBrush(QBrush(QColor::fromRgb(0,204,255), Qt::SolidPattern));
    painter.drawEllipse(1200,600,600,200);
    painter.drawEllipse(1200,1200,600,200);

    //Totems
    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine));
    painter.setBrush(QBrush(QColor::fromRgb(0x96,0x4B,0), Qt::SolidPattern));
    painter.drawRect(MAIN_RECT_WIDTH / 2 - CENTR_ISLAND_DIST / 2 - TOTEM_WIDTH / 2,MAIN_RECT_HEIGHT / 2 - TOTEM_HEIGHT / 2,TOTEM_WIDTH,TOTEM_HEIGHT);
    painter.drawRect(MAIN_RECT_WIDTH / 2 + CENTR_ISLAND_DIST / 2 - TOTEM_WIDTH / 2,MAIN_RECT_HEIGHT / 2 - TOTEM_HEIGHT / 2,TOTEM_WIDTH,TOTEM_HEIGHT);

    //Deck
    QPoint points1[4];
    points1[0] = QPoint(0,START_RECT_HEIGHT);
    points1[1] = QPoint(DECK_SIZE_UP,START_RECT_HEIGHT);
    points1[2] = QPoint(DECK_SIZE_DOWN,MAIN_RECT_HEIGHT);
    points1[3] = QPoint(0,MAIN_RECT_HEIGHT);
    painter.drawPolygon(points1,4);
    points1[0] = QPoint(MAIN_RECT_WIDTH,START_RECT_HEIGHT);
    points1[1] = QPoint(MAIN_RECT_WIDTH - DECK_SIZE_UP,START_RECT_HEIGHT);
    points1[2] = QPoint(MAIN_RECT_WIDTH - DECK_SIZE_DOWN,MAIN_RECT_HEIGHT);
    points1[3] = QPoint(MAIN_RECT_WIDTH,MAIN_RECT_HEIGHT);
    painter.drawPolygon(points1,4);

    //Bedroom
    painter.setBrush(QBrush(Qt::white, Qt::Dense5Pattern));
    painter.drawRect(0,MAIN_RECT_HEIGHT - BEDROOM_HEIGHT,BEDROOM_WIDTH,BEDROOM_HEIGHT);
    painter.drawRect(MAIN_RECT_WIDTH - BEDROOM_WIDTH,MAIN_RECT_HEIGHT - BEDROOM_HEIGHT,BEDROOM_WIDTH,BEDROOM_HEIGHT);

    //Blue bottle
    painter.setBrush(QBrush(QColor::fromRgb(128,0,255), Qt::SolidPattern));
    painter.drawRect(BOTTLE_DIST1 - BOTTLE_WIDTH / 2,MAIN_RECT_HEIGHT + 1,BOTTLE_WIDTH,BOTTLE_HEIGHT);
    painter.drawRect(MAIN_RECT_WIDTH - BOTTLE_DIST1 - BOTTLE_DIST2 - BOTTLE_WIDTH / 2,MAIN_RECT_HEIGHT + 1,BOTTLE_WIDTH,BOTTLE_HEIGHT);

    //Red bottle
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawRect(BOTTLE_DIST1 + BOTTLE_DIST2 - BOTTLE_WIDTH / 2,MAIN_RECT_HEIGHT + 1,BOTTLE_WIDTH,BOTTLE_HEIGHT);
    painter.drawRect(MAIN_RECT_WIDTH - BOTTLE_DIST1 - BOTTLE_WIDTH / 2,MAIN_RECT_HEIGHT + 1,BOTTLE_WIDTH,BOTTLE_HEIGHT);

    painter.end();
}
