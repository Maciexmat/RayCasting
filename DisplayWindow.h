#ifndef DISPLAYWINDOW_H_INCLUDED
#define DISPLAYWINDOW_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define WINDOW_SIZE_X 600
#define WINDOW_SIZE_Y 600

using namespace sf;

class WindowDisp
{
    private:
        int w_width{0};
        int w_height{0};
        Uint8 * pixels = nullptr;

    public:
        WindowDisp(int width, int height);
        void setPixel(int x, int y, int d_length, uint8_t red, uint8_t green, uint8_t blue);
        bool write(Texture * texture);
        void Draw_Background(int HEIGHT, int WIDTH);
        void draw_vertical_line(int W, int H, int x, int d_length, int offColour, int offColour2, int offColour3);
        void movement(Event event, int *move_x, int *move_y, int *start, int *stop);


};


#endif // DISPLAYWINDOW_H_INCLUDED
