#include <SDL.h>

//Basic class for a player with a rectangular collider
class Player {

public:
    //variables forx, y, width and height
    float x;
    float y;
    float w;
    float h;

    int leftPressed;
    int rightPressed;
    int jumpPressed;

    bool isGrounded;

    //Method to check collisions with other rectangle objects
    bool checkCollision(SDL_Rect b)
    {
        float leftA, leftB;
        float rightA, rightB;
        float topA, topB;
        float bottomA, bottomB;

        //left,right,top and bottom for this object
        leftA = x;
        rightA = x + w;
        topA = y;
        bottomA = y + h;
        
        //left,right,top and bottom for collided rectangle
        leftB = b.x;
        rightB = b.x + b.w;
        topB = b.y;
        bottomB = b.y + b.h;

        //If any of the sides from A are outside of B
        if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
        {
            return false;
        }
        
        //If none of the sides from A are outside B
        return true;
    }

    //Method to resolve collisions with other rectangle object
    void resolveCollision(SDL_Rect b)
    {
        float rightB;
        float midAx, midAy, midBx, midBy;
        float bottomB;

        //center coords of player object
        midAx = (x + w) / 2;
        midAy = (y + h) / 2;

        //center coords of b as well as right and bottom sides
        rightB = b.x + b.w;
        midBx = (b.x + b.w) / 2;
        midBy = (b.y + b.h) / 2;
        bottomB = b.y + b.h;

        //calculates the distance between center of collided rects
        float xdiff = midAx - midBx;
        float ydiff = midAy - midBy;

        if (xdiff * xdiff < ydiff * ydiff) //obtain positive values
        {
            //collision on top
            if (ydiff > 0) 
            {
                y = bottomB;
            }
            else //collision on bottom
            {
                y = b.y - h;
            }
        }
        else
        {
            //collision right side
            if (xdiff > 0)
            {
                x = rightB;
            }
            else //collision left side
            {
                x = b.x - w;
            }
        }
    }
};
