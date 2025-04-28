#include "ComplexPlane.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
//Partnered With Anna :3

using namespace sf;
using namespace std; 

int main()
{
    unsigned int screenWidth = VideoMode::getDesktopMode().width / 2;
    unsigned int screenHeight = VideoMode::getDesktopMode().height / 2;

    //Anna did rest of this :3
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Complex plane!"); //RenderWindows is required to have string
    ComplexPlane plane(screenWidth, screenHeight);

    Font newFont;
    newFont.loadFromFile("/home/ubuntu/Desktop/cisp400/fonts/Roboto/static/Roboto-Black.ttf"); //put a new path

    Text newText("MANDELBROT", newFont, 50);
    newText.setFillColor(Color::White);
    newText.setStyle(Text::Bold);

    Event event;
    while (window.pollEvent(event)){
        if (event.type == Event::Closed){
            window.close();
        }
        if (event.type == Event::MouseButtonPressed){
            if (event.mouseButton.button == Mouse::Left){
                //Left click will zoomIn and call setCenter on the ComplexPlane object
                // with the(x, y) pixel location of the mouse click
                cout << "the left button was pressed" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;

                plane.zoomIn(); 
                plane.setCenter(event.mouseButton.x, event.mouseButton.y);
            }
            else if (event.mouseButton.button == Mouse::Right) {
            //Right click will zoomOut and call setCenter on the ComplexPlane 
            //object with the (x,y) pixel location of the mouse click
                cout << "the right button was pressed" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;

                plane.zoomOut();
                plane.setCenter(event.mouseButton.x, event.mouseButton.y);
            }   
        }
        else if (event.type == Event::MouseMoved) { 
            //Call setMouseLocation on the ComplexPlane object to store the (x,y) pixel location of the mouse click
            //This will be used later to display the mouse coordinates as it moves
            plane.setMouseLocation(event.mouseMoved.x, event.mouseMoved.y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
    }
    /*
    Update Scene segment
        Call updateRender on the ComplexPlane object
        Call loadText on the ComplexPlane object
    */
    plane.updateRender();
    plane.loadText(newText); //mb no parameters?

    /*
        Draw Scene segment
        Clear the RenderWindow object
        draw the ComplexPlane object
        draw the Text object
        Display the RenderWindow object
    */
    window.clear();
    window.draw(plane);
    window.draw(newText);
    window.display();

    return 0;
}
