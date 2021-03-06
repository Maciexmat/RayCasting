#include <iostream>
#include <math.h>
#include "RayCast.h"

using namespace std;


// Mapa:
int Map[MAP_SIZE][MAP_SIZE]={{1,1,1,0,0,0,0},
                             {1,1,0,0,0,0,0},
                             {1,0,0,1,0,1,1},
                             {1,0,0,0,0,1,1},
                             {1,0,0,0,0,0,0},
                             {1,1,0,1,0,0,0},
                             {1,1,1,1,1,1,1}}; // Kazde pole ma 10 jednostek x i 10 jednostek y

bool check_sector(int x, int y)
{
    if( x >= 0 && x <= MAP_SIZE-1 && y >= 0 && y <= MAP_SIZE-1 )
    {
        bool set_p = false;

        set_p = Map[MAP_SIZE-1-y][x];
        if(set_p)
        {
            //cout << "[" << 4-y << "]" << "["<< x << "]" << ". ";
            return true;
        }
        else
            return false;
    }
    else
    {
        return true;   // Poza mapa
    }

}

void Set_Vertical(Point *X, int xShift, float move_X, float moveY)
{
    X->d = (X->x+(10*xShift))/(cos(X->alfa));                       // dla 90st mam tu dzielenie przez 0
            // dla 90st mam tu dzielenie przez 0
            //cout << "X->d " << X->d << endl;
            //cout << "cos(X->alfa) " << cos(X->alfa) << endl;
    if(X->d > 0)
    {
        X->h = X->d*sin(X->alfa);
        X->wx = (X->x+(10*xShift))/10 + move_X + 1;                             // obliczenie wsp X (liczba calkowita). Patrzymy w prawo wiec + 1
        X->wy = (X->y+X->h)/10 + moveY;                                 // obliczenie wsp Y
    }

   else
   {
       X->d = fabs(X->d);
       X->h = X->d*sin(X->alfa);
       X->wx = (X->x-(10*xShift))/10 + move_X - 1;                               // obliczenie wsp X (liczba calkowita). Patrzymy w lewo wiec od -1
       X->wy = (X->y+X->h)/10 + moveY;                                 // obliczenie wsp Y

   }

}

void Set_Horizontal(Point *X, int yShift, float move_X, float moveY)
{
    X->d = (X->y+(10*yShift))/(sin(X->alfa));
    if(X->d > 0)                      // obliczenie odleglosci do punktu na osi Y
    {
        X->n = X->d*cos(X->alfa);

        X->wx = (X->x+X->n)/10 + move_X;                                     // obliczenie wsp X
        X->wy = (X->y+(10*yShift))/10 + moveY + 1;                                 // obliczenie wsp Y (liczba calkowita.  Patrzymy w prawo wiec + 1, gdy alfa > 90st to - 1 bo patrzymy w lewo i nalezy cofnac sie do lewej krawedzi.
    }
    else
    {
        X->d = fabs(X->d);
        X->n = X->d*cos(X->alfa);

        X->wx = (X->x+X->n)/10 + move_X;                                     // obliczenie wsp X
        X->wy = (X->y-(10*yShift))/10 + moveY - 1;
    }

}

void Show_basic_map(int size_x, int size_y)
{
    for(int i=0;i<size_y;i++)
    {
        for(int j=0;j<size_x;j++)
            cout << "|" << Map[i][j];
            cout << "|" << endl;
    }

}


float Find_Height_Vertical(Point& A, float shift_Y, float moveX, float moveY)
{
	Set_Vertical (&A, shift_Y, moveX, moveY);

	if((check_sector(A.wx, A.wy) || A.wx <= 0 || A.wx > MAP_SIZE-1) && A.wy < MAP_SIZE && A.wy >=0)
	{
		return shift_Y;		// Daje pozwolenie na rysowanie verticalnej w tym sektorze.
	}
	else
	{
		shift_Y++;
		if(shift_Y >MAP_SIZE-1){
            return shift_Y;       // Daje pozwolenie na rysowanie verticalnej w tym sektorze bo to koniec mapy.
		};

		return Find_Height_Vertical(A, shift_Y, moveX, moveY );
	}


}


float Find_Height_Horizontal(Point& B, float shift_X, float moveX, float moveY)
{
	Set_Horizontal(&B, shift_X, moveX, moveY);

	if((check_sector(B.wx, B.wy) || B.wy <= 0 || B.wy > MAP_SIZE-1) && B.wx < MAP_SIZE && B.wx >=0)
	{
		return shift_X;		// Daje pozwolenie na rysowanie verticalnej w tym sektorze.
	}
	else
	{
		shift_X++;
		if(shift_X > MAP_SIZE-1){
            return shift_X;       // Daje pozwolenie na rysowanie verticalnej w tym sektorze bo to koniec mapy.
		};

		return Find_Height_Horizontal(B, shift_X, moveX, moveY );
	}

}

















