/*
    The Autonomous Agent of Future
    Authors: Apoorva & Simran
    © 2018 Apoorva&Simran. All Rights Resered.
*/

class Food{
  constructor(){
    //this.x position of food
    this.r=0;
    this.y=150;
  }

  display(){
    ellipse(this.r,this.y,10,10);
  }

  //respawns the food
  reset(){
    this.r = int(random(20,380))
  }

  die(){
		if (this.energy<0){
  		reset();
  	}
}

class Agent {

  constructor(){
    // position and shape
    this.x=0;
    this.y=150;
    this.direction=0;
    this.radius=30;

    //energy
    this.energy=0;

    //
    this.flag=0; // only for now
    this.max_speed=10

    //get food location
    this.look_for = 0;
  }

  setFood(food){
      this.look_for = food
  }

  display(){
  	var beta=this.radius*cos(2*PI/9);
  	var gamma=this.radius*sin(2*PI/9);

		if (this.direction==0){
			triangle(this.x+this.radius,this.y,this.x-beta,this.y-gamma,this.x-beta,this.y+gamma);
		}
		else if (this.direction==1) {
			triangle(this.x-this.radius,this.y,this.x-beta+2*beta,this.y-gamma,this.x-beta+2*beta,this.y+gamma);
		}
	}

  move(){
	  if (this.x<=0+this.radius) {
    	flip();
  	}
    else if (this.x>=400-this.radius) {
    	flip();
  	}

  	if (this.x<=400 && this.direction==0) {
    	if(this.energy/100<=this.max_speed)
    		this.x=this.x+(this.energy/100);
    	else
      	this.x=this.x+this.max_speed
  	}
    else if (this.x>0 && this.direction==1) {
    	if(this.energy/100<=this.max_speed)
    		this.x=this.x-(this.energy/100);
  		else
      	this.x=this.x-this.max_speed
 		}
    this.energy=this.energy-1
	}

  flip(){
		if (this.direction==0){
  		this.direction=1
 		}
  	else	if (this.direction==1){
  		this.direction=0
 		}
	}

  //change name to see(). This function checks if the food is within 50px and returns the place value in this.flag.Change name to place_value
  see(){
		if ((check_jumps(this.x,this.x+50,)!=0) && this.direction ==1){//checks for 50px awareness in +ve direction
   		if ((check_jumps(this.x,(this.x+(this.energy/100)))!=0) && this.direction ==1) //checks for speed awareness +ve direction
    		if(this.energy<=900){
  				eat_food()
    		}
   		else
      	move()
  	}
  	else if ((check_jumps(this.x-50,this.x)!=0)&& this.direction ==0){ //checks for 50px awareness in -ve direction
  		if ((check_jumps(this.x-(this.energy/100),this.x)!=0)&& this.direction ==0) //checks for speed awareness -ve direction
  	 		if(this.energy<=900){
  					eat_food()
     		}
   		else
     		move()
		}
  	else
   		move()
		return this.flag;
	}

  //checks if the food is between two points
  check_jumps(m, n){
    var r = this.look_for;
  	if(this.direction==1){
    	for(var i=m; i<n+1; i++)
     		if(i>=r-1 && i<=r+1)
        	this.flag=i
  	}

  	else if (this.direction==0){
    	for(var i=n; i>m-1; i--)
      	if(i>=r-1 && i<=r+1)
        	this.flag=i
  	}
  	return this.flag;
	}

  //If the returned place_value is at the same position as the food, it consumes it and respawns food
  eat_food(){
    r = this.look_for;
  	if(this.x>=r-(this.energy/100) && this.x<=r+(this.energy/100)){
    	count_cycletime()
    	this.energy=this.energy+50
			r=int(random(50,350));
			this.flag=0;
  	}
  //else
    //move()
  //return p
	}

  //dies the agent of the this.energy<900
  die(){
		if (this.energy<0){
  		reset();
  	}
  this.flag=0;
	}

  //respawns the agent
  reset(){
		this.x = parseInt(random(400))
  	this.energy=1000;
  	death_count=death_count+1;
	}
}

var t
var dummy;
var meal;
var death_count=-1;

function setup() {
  createCanvas(400, 300);
  frameRate(this.simulation_speed);
  dummy= new Agent;
  meal= new Food;
  dummy.setFood(meal.r);
  t= new time;
}

function draw() {
  background(220);
  textSize(12);
  dummy.display();
  if(dummy.see()>=0){
  	dummy.move()
  }
  fill(255,255,255);
  meal.display()
  dummy.die()
  meal.die()
  //text('average time '+ Math.floor(this.avg_time * 100) / 100 +' ms',50,50);
  //text('last cycle time '+ Math.floor(this.cycle_time * 100) / 100  + ' ms', 50,250);
  //text('Total Time '+this.total_time,50,90);
	text('this.energy '+ Math.floor(this.energy),50,30);
  text('Death this.count_cycle '+death_count,50,70);
  keyPressed();
  //text('frame this.count_cycle '+this.frame_counts, 50,105);
  text('simulation speed ' + this.simulation_speed, 50,110);
  text('this.x: '+this.x+ '    this.x+this.energy: '+(this.x+(this.energy/100)) + '    this.r: '+ this.r, 50, 200);
  //text(check_flag(), 50, 50)
  text(check_jumps(), 50, 100)
  text(check_jumps(this.x,(this.x+this.energy/100)), 50, 250)
  text(eat_food(this.flag), 50, 260)
}

class Time{
  constructor(){
    this.count_cycle=0;
    this.cycle_time=0;
    this.total_time=0;
    this.avg_time=0;
    this.time2=0;
    var frameCounts=0;
    this.simulation_speed=15;
  }

  function count_cycletime(){
    var time= frameCounts;
    this.cycle_time= time-this.time2;
    this.total_time=this.total_time+this.cycle_time;
    this.avg_time=this.total_time/this.count_cycle;
    this.time2= time;
    this.count_cycle=this.count_cycle+1;
  }

function keyPressed(){
    if (keyCode == UP_ARROW){
        this.simulation_speed += 20;
    }
    else if(keyCode == DOWN_ARROW){
        this.simulation_speed -= 20;
    }
}
}
//r- food position
/*var total_time=0;
var avg_time=0;
var cycle_time=0;
var time2=0;
var count=0;
var y=150;
var direction=0;
var energy=0;
var x,r;
var radius=30;
var death_count=-1;
var frameCounts=0;
var simulation_speed=15;
var flag=0;
var max_speed=10

function setup() {
  createCanvas(400, 300);
  frameRate(simulation_speed);
}

function draw() {
  background(220);
  textSize(12);
  energy=energy-5
  draw_agent(x,y,0);
  if(optical_sensor()>=0){
  	move()
  }
  fill(255,255,255);
  ellipse(r,y,10,10);
  //text('average time '+ Math.floor(avg_time * 100) / 100 +' ms',50,50);
  //text('last cycle time '+ Math.floor(cycle_time * 100) / 100  + ' ms', 50,250);
  //text('Total Time '+total_time,50,90);
	text('ENERGY '+ Math.floor(energy),50,30);
  text('Death Count '+death_count,50,70);
  keyPressed();
  //text('frame count '+frameCounts, 50,105);
  text('simulation speed ' + simulation_speed, 50,110);
  text('x: '+x+ '    x+energy: '+(x+(energy/100)) + '    r: '+ r, 50, 200);
  //text(check_flag(), 50, 50)
  text(check_jumps(), 50, 100)
  text(check_jumps(x,(x+energy/100)), 50, 250)
  text(eat_food(flag), 50, 260)
}

function optical_sensor(){
	kill_agent()
	if ((check_jumps(x,x+50)!=0) && direction ==1){//checks for 50px awareness
   if ((check_jumps(x,(x+(energy/100)))!=0) && direction ==1) //checks for speed awareness
    if(energy<=900){
  		eat_food()
    }
   else
      move()
  }
  else if ((check_jumps(x-50,x)!=0)&& direction ==0){
  	if ((check_jumps(x-(energy/100),x)!=0)&& direction ==0)
  	 if(energy<=900){
  		eat_food()
     }
   else
      move()
	}
  else
    move()
	return flag;
}


function check_jumps(m, n){
  if(direction==1){
    for(var i=m; i<n+1; i++)
      if(i>=r-1 && i<=r+1)
        flag=i
  }

  if(direction==0){
    for(var i=n; i>m-1; i--)
      if(i>=r-1 && i<=r+1)
        flag=i
  }
  return flag;
}

function eat_food(){
  if(x>=r-1 && x<=r+1){
    count_cycletime()
    energy=energy+50
		r=int(random(50,350));
		flag=0;
  }
  //else
    //move()
  //return p
}

function kill_agent(){
	if (energy<0){
  	reset();
  }
  flag=0;
}

function reset(){
	r = int(random(20,380))
	x = parseInt(random(400))
  energy=1000;
  death_count=death_count+1;
}


function draw_agent(x, y,theta){
  var beta=radius*cos(2*PI/9);
  var gamma=radius*sin(2*PI/9);

	if (direction==0){
	triangle(x+radius,y,x-beta,y-gamma,x-beta,y+gamma);
	}
	else if (direction==1) {
	triangle(x-radius,y,x-beta+2*beta,y-gamma,x-beta+2*beta,y+gamma);
	}
}

function move(){
	  if (x<=0+radius) {
    flip_agent();
  } else if (x>=400-radius) {
    flip_agent();
  }

  if (x<=400 && direction==0) {
    if(energy/100<=max_speed)
    	x=x+(energy/100);
    else
      x=x+max_speed
  } else if (x>0 && direction==1) {
    if(energy/100<=max_speed)
    	x=x-(energy/100);
    else
      x=x-max_speed
  }
}

function flip_agent(){
	if (direction==0){
  	direction=1
  }
  else	if (direction==1){
  	direction=0
  }
}

function count_cycletime(){
  var time= frameCounts;
  cycle_time= time-time2;
  total_time=total_time+cycle_time;
  avg_time=total_time/count;
  time2= time;
  count=count+1;
}

function keyPressed(){
    if (keyCode == UP_ARROW){
        simulation_speed += 20;
    }
    else if(keyCode == DOWN_ARROW){
        simulation_speed -= 20;
    }
}*/
