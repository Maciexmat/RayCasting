#include "DisplayWindow.h"
#include "RayCast.h"

WindowDisp::WindowDisp(int width, int height) : w_width(width), w_height(height), pixels(new Uint8[width * height * 4])
{

}

void WindowDisp::Draw_Background(int HEIGHT, int WIDTH)
{
	bool halfLine = 0;
    for(int y = 0; y < HEIGHT; y++)
    {
        if(y == HEIGHT/2) halfLine = 1;
            for( int x = 0; x < WIDTH; x++)
            {
                if(halfLine == 0)
                {
                    //bitmap.setPixel(x, y, 128, 128, 128);
                    setPixel(x, y, 1, 180, 180, 180);
                }
                else if(halfLine == 1)
                {
                    //bitmap.setPixel(x, y, 180, 180, 180);
                    setPixel(x, y, 1, 128, 128, 128);
                }

            }
    }
}

void WindowDisp::draw_vertical_line(int W, int H, int x, int d_length, int offColour, int offColour2, int offColour3)
{
    int h1 = H/2 - d_length/2;
    int h2 = H/2 + d_length/2;

    //for(int i = 0; i < d_length; i++)
    //{
        //bitmap.setPixel(x, h1+i, 255 - offColour, offColour2, offColour3);

    //}
    setPixel(x, h1, d_length, 255 - offColour, offColour2, offColour3);
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
            pixels[x*4 + i*WINDOW_SIZE_X*4]     = red;      // R
            pixels[x*4 + i*WINDOW_SIZE_X*4 + 1] = green;    // G
            pixels[x*4 + i*WINDOW_SIZE_X*4 + 2] = blue;     // B
            pixels[x*4 + i*WINDOW_SIZE_X*4 + 3] = 255;      // A
        }

}

void WindowDisp::movement(Event event, int *move_x, int *move_y, int *start, int *stop)
{
    Clock clock;
    Time x;

    if (event.type == Event::TextEntered)
        {
            if (event.text.unicode == 100 && *move_x < MAP_SIZE-1)
            {
                cout << "key pressed: " << static_cast<char>(event.text.unicode) << endl;
                (*move_x)++;
                x = clock.restart();
                while(x.asMilliseconds() < 200) x = clock.getElapsedTime();
            }

            if (event.text.unicode == 97 && *move_x > 0)
            {
                cout << "key pressed: " << static_cast<char>(event.text.unicode) << endl;
                (*move_x)--;
                x = clock.restart();
                while(x.asMilliseconds() < 200) x = clock.getElapsedTime();
            }

            if (event.text.unicode == 119 && *move_y < MAP_SIZE-1)
            {
                cout << "key pressed: " << static_cast<char>(event.text.unicode) << endl;
                (*move_y)++;
                x = clock.restart();
                while(x.asMilliseconds() < 200) x = clock.getElapsedTime();
            }

            if (event.text.unicode == 115 && *move_y > 0)
            {
                cout << "key pressed: " << static_cast<char>(event.text.unicode) << endl;
                (*move_y)--;
                x = clock.restart();
                while(x.asMilliseconds() < 200) x = clock.getElapsedTime();
            }

            if (event.text.unicode == 113)
            {
                cout << "key pressed: " << static_cast<char>(event.text.unicode) << endl;
                (*start)+=10;
                (*stop)+=10;
            }

            if (event.text.unicode == 101)
            {
                cout << "key pressed: " << static_cast<char>(event.text.unicode) << endl;
                (*start)-=10;
                (*stop)-=10;
            }

        }

}


