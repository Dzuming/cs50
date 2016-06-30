//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    double velocity = drand48() + 1.2;
    
    double horizontal = drand48() / 1.2;
    // keep playing until game over
    waitForClick();
    while (lives > 0 && bricks > 0)
    {
    
        GEvent event = getNextEvent(MOUSE_EVENT);
         
          
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                
                double x = getX(event) - getWidth(paddle) / 2;
                double y = getY(paddle);
                if (x >= 0 && (x + getWidth(paddle) <= WIDTH))
                {
                    setLocation(paddle, x,y);
             }
              
            }
           
        }
        
         
        move(ball, horizontal, velocity);
        if (getX(ball) <= 0 || (getX(ball) >= WIDTH - 15))
        {
            horizontal = -horizontal;
         }
         else if (getY(ball) >= HEIGHT )
        {
            setLocation(ball, WIDTH / 2, HEIGHT - 200);
            lives -= 1;
            waitForClick();
            }
            else if (getY(ball) <= 0 )
            
        {
                     
            velocity = -velocity;
                                                      
                                                                  }
             
        GObject object = detectCollision(window, ball);
        if (object != NULL)
        {
            
            if (strcmp(getType(object), "GRect") == 0  )
            {
                velocity = -velocity;
   
}
            if (object != paddle && object != label )
            {
                bricks -= 1 ;
                points += 1;
                updateScoreboard (window, label, points);
                removeGWindow (window, object);
             } 

    }
        pause(5);
}
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
  
    
    GRect Bricks [COLS - 1][ROWS - 1];  
    int x = 20;
    int y = 40;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (j == 0)
            {
                x = 2;
                Bricks[i][j] = newGRect(x, y, 38.9, 10);
    }
    else
            {
                Bricks[i][j] = newGRect(x, y, 38.9, 10);
    }
            add(window, Bricks[i][j]);
            setFilled(Bricks[i][j], true);
            if (i == 0)
            {
                setColor(Bricks[i][j], "ff0059");
    }
            if (i == 1)
            {
                setColor(Bricks[i][j], "ff900a");
    }
            if (i == 2)
            {
                setColor(Bricks[i][j], "fff68f");
    }
            if (i == 3)
            {
                setColor(Bricks[i][j], "00ff00");
    }
            if (i == 4)
            {
                setColor(Bricks[i][j], "00ffff");
    }
            x += 40;
    
    }
        y += 12;
    }
    
     
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval Ball  = newGOval(WIDTH / 2, HEIGHT - 200, 15, 15);
    add(window, Ball);
    setFilled(Ball, true);
    setColor(Ball, "000000");
    return Ball;
    
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    
    GRect Paddle  = newGRect(WIDTH / 2, HEIGHT - 20, 40, 10);
    add(window, Paddle);
    setFilled(Paddle, true);
    setColor(Paddle, "000000");
    return Paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel Scoreboard = newGLabel("0"); 
   
    
    setLocation(Scoreboard, WIDTH / 2, HEIGHT / 2);
    add(window, Scoreboard);
    setFilled(Scoreboard, true);
    setColor(Scoreboard, "FFF000");
    setFont(Scoreboard, "Calibri-40");
    return Scoreboard;
    
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
