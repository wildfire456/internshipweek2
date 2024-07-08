#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

 Sprite menu, helpmenu, highmenu;


  Font opensans;
  Text display;
  string prompt = " Arrow keys : Move \n           C        : change color \n           R        : Recentre \n           S        : Change Shape \n           X        : Exit";
  
  
 
int main()
{    
     bool colorchange =0;
     bool shapechange =1;
     int shape = 2;
     int color = 1;
     float speed = 0.7;
     opensans.loadFromFile("open-sans/OpenSans-Regular.ttf");
     display.setFont(opensans);
      sf::RenderWindow window(sf::VideoMode(900, 700), "Window");
      window.clear(sf::Color::Black);
       display.setString(prompt);
         float x = 360, y = 270;


         

       CircleShape circle(80);
       circle.setPosition(x,y);
       circle.setFillColor(sf::Color::Yellow);

        ConvexShape triangle(3);
        triangle.setScale(1.75,2.7);
        triangle.setPoint(0, sf::Vector2f(100.f, 100.f));
        triangle.setPoint(1, sf::Vector2f(200.f, 100.f));
        triangle.setPoint(2, sf::Vector2f(150.f, 50.f));
        triangle.setPosition(x-200, y-150);
        
        

        RectangleShape square(sf::Vector2f(135.f, 135.f));
        square.setPosition(x-35, y+50);
      

    while (window.isOpen())
    {   


        //color change            
        if (color==1)
        {
        circle.setFillColor(sf::Color::Yellow);
        triangle.setFillColor(sf::Color::Yellow);
        square.setFillColor(sf::Color::Yellow);
        
        }

        else if (color==2)
        {
        circle.setFillColor(sf::Color::Red);
        triangle.setFillColor(sf::Color::Red);
        square.setFillColor(sf::Color::Red);
        
        }

        else if (color==3)
        {
        circle.setFillColor(sf::Color::Blue);
        triangle.setFillColor(sf::Color::Blue);
        square.setFillColor(sf::Color::Blue);
        
        }

          else if (color==4)
        {
        circle.setFillColor(sf::Color::Green);
        triangle.setFillColor(sf::Color::Green);
        square.setFillColor(sf::Color::Green);
        
        }

            else if (color==5)
        {
        circle.setFillColor(sf::Color::Magenta);
        triangle.setFillColor(sf::Color::Magenta);
        square.setFillColor(sf::Color::Magenta);
        
        }

                else if (color==6)
        {
        circle.setFillColor(sf::Color::White);
        triangle.setFillColor(sf::Color::White);
        square.setFillColor(sf::Color::White);

        
        }

       
          
       





        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        
        }


          // key presses////////////////////////////
            if (Keyboard::isKeyPressed(Keyboard::X))
             {
                window.close();
                return 0;
             }
             
             

             //movement
             else if (Keyboard::isKeyPressed(Keyboard::Up))
             {
               y-=speed;
             }

             else if (Keyboard::isKeyPressed(Keyboard::Down))
             {
               y+=speed;
             }

              else if (Keyboard::isKeyPressed(Keyboard::Left))
             {
               x-=speed;
             }

              else if (Keyboard::isKeyPressed(Keyboard::Right))
             {
               x+=speed;
             }

             if (Keyboard::isKeyPressed(Keyboard::C) && colorchange==0)
             {
               color++;

               if(color==7)
               color=1;
               colorchange =1;

             }

             if(!Keyboard::isKeyPressed(Keyboard::C))
             colorchange=0;



              if (Keyboard::isKeyPressed(Keyboard::S) && shapechange ==0)
             {
               shape++;

               if(shape==4)
               shape=1;
               shapechange =1;

             }

               if(!Keyboard::isKeyPressed(Keyboard::S))
              shapechange=0;


           //recentre  
             if(Keyboard::isKeyPressed(Keyboard::R))
             {
              x = 360;
              y = 270;
             }
           
    
        window.clear(sf::Color::Black); 
        display.setPosition(20,560);
        display.setFillColor(Color::Cyan); 
         display.setCharacterSize(18); 

        

        circle.setPosition(x+16,y-3);
        triangle.setPosition(x-168, y-130);
        square.setPosition(x+28, y+5);
        

        if (shape==1)
         {
            window.draw(circle);
         }

           else if (shape==2)
         {
            window.draw(square);
         }

           else if (shape==3)
         {
            window.draw(triangle);
         }
        
        window.draw(display);

        window.display();
    }

    return 0;
}
