#include <iostream>
#include "Bitmap.h"
#include "RayCast.h"

using namespace std;

int const WIDTH = 1200;
int const HEIGHT = 600;
int pom = 0;


Bitmap bitmap(WIDTH, HEIGHT);

void Draw_Background(int HEIGHT, int WIDTH)
{
	bool pom = 0;
    for(int y = 0; y < HEIGHT; y++)
    {
        if(y == HEIGHT/2) pom = 1;
            for( int x = 0; x < WIDTH; x++)
            {
                if(pom == 0)
                  bitmap.setPixel(x, y, 128, 128, 128);
                else if(pom == 1)
                  bitmap.setPixel(x, y, 180, 180, 180);
            }
    }
}


void draw_lines(int W, int H, int d_length, int p_numberOfLines, int n_shiftUp, int offx, int offy, int offColour)
{
    int h1 = H/2 - d_length/2 + n_shiftUp;  // dolny punkt konca linii
    int h2 = H/2 + d_length/2 + n_shiftUp;  // górny punkt konca linii

    for(int y = 0; y < H; y++)
    {
            for( int x = 0; x < W; x++)
            {
                if(x == p_numberOfLines+offx && y > (h1+offy) && y < (h2+offy))
                    bitmap.setPixel(x, y, 255 - offColour, 0, 0);
            }
    }
}

void draw_vertical_line(int W, int H, int x, int d_length, int offColour, int offColour2, int offColour3)
{
    int h1 = H/2 - d_length/2;
    int h2 = H/2 + d_length/2;

    for(int i = 0; i < d_length; i++)
    {
        bitmap.setPixel(x, h1+i, 255 - offColour, offColour2, offColour3);
    }
}


int main()
{

    Draw_Background(HEIGHT, WIDTH);
    Show_basic_map(5, 5);

    Point A(5,5,Pi/3);
    Point B(5,5,Pi/3);

    int draw_H = 0;
    int draw_V = 0;
    float rotationAngle = 0;
    int step;

    do
    {

        cout << " podaj krok o ile w prawo "<< endl;
        cin >> step;

        step;

     for(int i = START; i <= STOP; i++)
     {

          rotationAngle = i*Pi/ANGLE_div;
          if(rotationAngle != STOP/2*Pi/STOP)
          {
                A.alfa = rotationAngle;                  // max < PI/2 -> 90st
                B.alfa = rotationAngle;                  // max < PI/2 -> 90st
          }

                draw_V = Find_Height_Vertical(A, 0,MOVE_X,MOVE_Y) + 1;
                draw_H = Find_Height_Horizontal(B,0,MOVE_X,MOVE_Y) + 1;

                pom = draw_V - 1;
                //if(draw_V)
                    //cout << decrement[pom] <<  " ";


                if(WALL_SIZE/A.d > 600)
                {
                    draw_vertical_line(WIDTH, HEIGHT, 1197-3*(i-START), 600, 100,0,0);
                }
                else if(A.d < B.d && draw_V != 0)
                {
                    //if(i != 414)
                    draw_vertical_line(WIDTH, HEIGHT, 1197-3*(i-START), WALL_SIZE/A.d, 0,0,0);
                    draw_V = 0;
                    cout << A.wy << "-" << A.wx <<  "V ";
                }
                else if(A.d > B.d && draw_H != 0)
                {
                    draw_vertical_line(WIDTH, HEIGHT, 1197-3*(i-START), WALL_SIZE/B.d, 255,0,0);
                    draw_H = 0;
                    cout << B.wy << "-" << B.wx <<  "H ";
                }
                else
                {
                    cout << "Blad porownania odleglosci " << endl;
                }


     }


         bitmap.write("test.bmp");
        cout << "Finished." << endl;

        }while( 0);


    return 0;
}
