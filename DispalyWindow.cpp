#include "DisplayWindow.h"


WindowDisp::WindowDisp(int width, int height) : w_width(width), w_height(height), pixels(new Uint8[width * height * 4])
{

}

bool WindowDisp::write(Texture * texture)
{
//    RenderWindow window;
//    window.create(VideoMode(1200, 600), "Test" );
//
//    Event event;
//
//    Sprite sprite;
//
//    Texture texture;
//    texture.create(1200, 600);
//    while(1)
//    {
//        window.clear(Color::White);
//        window.pollEvent(event);
        texture->update(pixels);
//
//        sprite.setTexture(texture);
//        window.draw(sprite);
//        window.display();

//        if(event.type == Event::Closed)
//        {
//            window.close();
//            break;
//        }
//    }

    return true;

}


void WindowDisp::setPixel(int x, int y,int d_length, uint8_t red, uint8_t green, uint8_t blue)
{
    // i - kolejny wiersz
        for(int i=y; i<d_length+y; i++)
        {
            pixels[x*4 + i*WINDOW_SIZE_X*4]     = red; // R
            pixels[x*4 + i*WINDOW_SIZE_X*4 + 1] = green; // G
            pixels[x*4 + i*WINDOW_SIZE_X*4 + 2] = blue; // B
            pixels[x*4 + i*WINDOW_SIZE_X*4 + 3] = 255; // A
        }

}


// Clear Pixel:



