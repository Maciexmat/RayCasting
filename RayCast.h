/*
 * RayCast.h
 *
 *  Created on: 14 sty 2020
 *      Author: Maciek
 */

#ifndef RAYCAST_H_
#define RAYCAST_H_

#include "Bitmap.h"

#define Pi 3.141592

#define START 210        // 50
#define STOP 410        // 448
#define ANGLE_div 500   // 500 to jest Pi -> 180st
#define WALL_SIZE 2000  // wysokosc sciany dzielona przez odleglosc
#define MAP_SIZE 7      // Mapa 5x5

int const WIDTH = 1200;
int const HEIGHT = 600;



// Point on the border of sectors:
class Point
{
public:
	Point(float a, float b) : x(a), y(b){};

    float x;
    float y;
    float alfa = 0;
    float d = 0;
    float h = 0;    // wysokosc trojkata
    float n = 0;    // podstawa trojkata (odleglosc do najblizszej pionowej)
    uint16_t wx = 0;
    uint16_t wy = 0;

};


//Functions:
bool check_sector(int x, int y);
void Set_Vertical(Point *X, int xShift, int move_X, int moveY);                         // ustawienie pionowej ...
void Set_Horizontal(Point *X, int yShift, int move_X, int moveY);                       // ustawienie poziomej ...
void Show_basic_map(int size_x, int size_y);
float Find_Height_Vertical(Point& A, float shift_Y, int moveX, int moveY);
float Find_Height_Horizontal(Point& B, float shift_X, int moveX, int moveY);







#endif /* RAYCAST_H_ */
