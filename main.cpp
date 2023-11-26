// SDL_Basic_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "screen.h"
#include <math.h>
#include <stdlib.h>
#include "Swarm.h"


using namespace std;
using namespace sahito;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    screen screen;
    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }
  
    
    Swarm swarm;

    while (true) {
        //update particles
        //draw particles
        //check for messages/events

        //Draw Particles
        int elapsed = SDL_GetTicks();
        
        swarm.update(elapsed);

        unsigned char green = (1 + sin(elapsed * 0.001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;

        const Particle* const pParticles = swarm.getParticles();
        for (int i=0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * screen::SCREEN_WIDTH / 2 + screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
            
        }


       
        
        

        screen.boxBlur();
        //Draw the screen
        screen.update();
        if (screen.processEvents() == false) {
            break;
        }

        
    }
    
    screen.close();
    
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
