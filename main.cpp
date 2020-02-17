#include <iostream>
#include "Bitmap.h"
#include "RayCast.h"
#include "DisplayWindow.h"

using namespace std;

WindowDisp winDisp(WINDOW_SIZE_X, WINDOW_SIZE_Y);
//Bitmap bitmap(WIDTH, HEIGHT);


int main()
{
    RenderWindow window;
    window.create(VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "RayCasting Project" );

    Event event;

    Sprite sprite;

    Texture texture;
    texture.create(WINDOW_SIZE_X, WINDOW_SIZE_Y);

    Show_basic_map(5, 5);

    Point A(5,5);
    Point B(5,5);

    int draw_H = 0;
    int draw_V = 0;
    float rotationAngle = 0;
    int step;

    int start = 10;
    int stop = 210;
    int move_x = 2;
    int move_y = 2;

    while(1)
    {
        //start+=4;
        //stop+=4;
        winDisp.movement(event, &move_x, &move_y, &start, &stop);

         winDisp.Draw_Background(HEIGHT, WIDTH);

         for(int i = start; i <= stop; i++)
         {

            window.pollEvent(event);

            rotationAngle = i*Pi/ANGLE_div;
            if(rotationAngle != 1/2*Pi)
            {
                A.alfa = rotationAngle;                  // max < PI/2 -> 90st
                B.alfa = rotationAngle;                  // max < PI/2 -> 90st
            }

            draw_V = Find_Height_Vertical(A, 0,move_x,move_y) + 1;
            draw_H = Find_Height_Horizontal(B,0,move_x,move_y) + 1;


            if(WALL_SIZE/A.d > WINDOW_SIZE_Y)
            {
                winDisp.draw_vertical_line(WIDTH, HEIGHT, 597-3*(i-start), WINDOW_SIZE_Y, 100,0,0);
            }
            else if(A.d < B.d && draw_V != 0)
            {
                winDisp.draw_vertical_line(WIDTH, HEIGHT, 597-3*(i-start), WALL_SIZE/A.d, 0,0,0);
                draw_V = 0;
            }
            else if(A.d > B.d && draw_H != 0)
            {
                winDisp.draw_vertical_line(WIDTH, HEIGHT, 597-3*(i-start), WALL_SIZE/B.d, 255,0,0);
                draw_H = 0;
            }
            else
            {
                cout << "Blad porownania odleglosci " << endl;
            }


         }

        winDisp.write(&texture);
        window.clear(Color::White);
        sprite.setTexture(texture);
        window.draw(sprite);
        window.display();

        if(event.type == Event::Closed)
        {
            window.close();
            break;
        }
    }


        // bitmap.write("test.bmp");
        cout << "Finished." << endl;

    return 0;
}
