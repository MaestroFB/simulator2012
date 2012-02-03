#ifndef BOARD_H
#define BOARD_H

#include <QPainter>

#define PAINTER_SCALE           0.2

#define MAIN_RECT_WIDTH         3000
#define MAIN_RECT_HEIGHT        2000

#define START_RECT_WIDTH        500
#define START_RECT_HEIGHT       500

#define TOP_ISLAND_YELLOW_D     800
#define TOP_ISLAND_GREEN_D      600

#define CENTR_ISLAND_YELLOW_D   600
#define CENTR_ISLAND_GREEN_D    400
#define CENTR_ISLAND_DIST       800
#define CENTR_ISLAND_PALM_D     150

#define TOTEM_WIDTH             250
#define TOTEM_HEIGHT            250

#define DECK_SIZE_UP            400
#define DECK_SIZE_DOWN          325

#define BEDROOM_WIDTH           340
#define BEDROOM_HEIGHT          610

#define BOTTLE_WIDTH            200
#define BOTTLE_HEIGHT           50
#define BOTTLE_DIST1            640
#define BOTTLE_DIST2            477

void Board_Show(QPaintDevice* paintDevice);

#endif // BOARD_H
