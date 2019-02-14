//
//  simulation.h
//  mySketch
//
//  Created by Apoorva on 25/01/19.
//

#ifndef simulation_h
#define simulation_h


#endif /* simulation_h */
class Time {
public:
    int count_cycle;
    int cycle_time;
    int total_time;
    int avg_time;
    int time2;
    int frameCounts;
    int simulation_speed;
    Time(){
        count_cycle=0;
        cycle_time=0;
        total_time=0;
        avg_time=0;
        time2=0;
        frameCounts=0;
        simulation_speed=15;
    }
    void count_cycletime();
    void keyPressed();
};

class Agent {
public:
    int x;
    int y;
    int direction;
    int radius;
    //energy
    int energy;
    int flag; // only for now
    int max_speed;
    //get food location
    Food look_for;
    Time timer;
    Food change_f;
    Agent(){
        /*
         purpose: initialize all the variables inside the object of Agent
         input: None
         output: Agent object
         */
        // position and shape
        x=0;
        y=150;
        direction=0;
        radius=30;
        
        //energy
        energy=0;
        
        //
        flag=0; // only for now
        max_speed=10;
        
        //get food location
        //look_for = 0;
        //timer = 0;
        //change_f = 0;
        
    }
    
    class Food{
    public:
        int r;
        int y;
        Food(){
            //this.x position of food
            r=50;
            y=150;
        }
        void display();
        void reset(); //respawns the food
    };
    
    void setFood(Food food);
    void setTimer(Time timer);
    void reSpawn(Food doof);
    void display();
    void move();
    void flip();
    
    //change name to see(). This function checks if the food is within 50px and returns the place value in this.flag.Change name to place_value
    int see();
    
    //checks if the food is between two points
    int check_jumps(int m, int n);
    
    //If the returned place_value is at the same position as the food, it consumes it and respawns food
    void eat_food();
    
    //dies the agent of the this.energy<900
    void die();
    
    //respawns the agent
    void reset();
};
