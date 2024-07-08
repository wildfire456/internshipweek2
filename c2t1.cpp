#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

 Sprite menu, helpmenu, highmenu;


  Font opensans;
  Text display;
  string prompt = " Press x to exit \n Press C to change background color";
  
  
 
int main()
{     
    int color =1;
    bool colorchange=0;
     opensans.loadFromFile("open-sans/OpenSans-Regular.ttf");
     display.setFont(opensans);
      sf::RenderWindow window(sf::VideoMode(700, 700), "Window");
      window.clear(sf::Color::Blue);
       display.setString(prompt);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        
        }
            if (Keyboard::isKeyPressed(Keyboard::X))
            {
          window.close();
          return 0;
            }
          if (Keyboard::isKeyPressed(Keyboard::C) && colorchange==0)
          {
            color++;

            if (color == 8)
            color =1;
            colorchange=1;
          }

          if (!Keyboard::isKeyPressed(Keyboard::C))
           {
            colorchange=0;
           }
     
        if (color==1)
        window.clear(sf::Color::Blue); 

        else if (color==2)
        window.clear(sf::Color::Black); 

        else if (color==3)
        window.clear(sf::Color::Red); 

        else if (color==4)
        window.clear(sf::Color::Yellow); 
       
        else if (color==5)
        window.clear(sf::Color::Magenta);

        else if (color==6)
        window.clear(sf::Color::Cyan); 

        else if (color==7)
        window.clear(sf::Color::Green); 


        
     
        display.setPosition(160,350);
         display.setCharacterSize(24); 
        window.draw(display);
        window.display();
    }

    return 0;
}
