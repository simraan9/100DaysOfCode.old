/*
    The Autonomous Agent of Future
    Authors: Apoorva & Simran
    © 2018 Apoorva&Simran. All Rights Resered.
*/
class Obstacle{
	constructor(){
    this.pos=int(random(0,400));
    this.y=150;

  }

  display(){
  rect(this.pos,this.y-5,10,10);
  }

  respawn(){
  this.pos=int(random(0,400));
  }

  wait(){
  var wait=int(random(0,500));
    for (var i=0; i<=wait;i++)
    	console.log("i")
  //this.respawn();
}


}
class Food{
  constructor(){
    //this.x position of food
    this.r=50;
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
  		this.reset();
  	}
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
    this.timer = 0;
    this.change_f = 0;
  }

  setFood(food){
    this.look_for = food
  }

  setTimer(timer){
    this.timer = timer
  }

  reSpawn(doof){
  	this.change_f=doof;
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
    	this.flip();
  	}
    else if (this.x>=400-this.radius) {
    	this.flip();
  	}

  	if (this.x<=400 && this.direction==0) {
    	if(this.energy/100<=this.max_speed){
    		this.x=this.x+(this.energy/100);
      }
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
		if ((this.check_jumps(this.x,this.x+50)!=0) && this.direction ==1){//checks for 50px awareness in +ve direction
   		if ((this.check_jumps(this.x,(this.x+(this.energy/100)))!=0) && this.direction ==1) //checks for speed awareness +ve direction
    		if(this.energy<=900){
  				this.eat_food()
    		}
   		else
      	this.move()
  	}
  	else if ((this.check_jumps(this.x-50,this.x)!=0)&& this.direction ==0){ //checks for 50px awareness in -ve direction
  		if ((this.check_jumps(this.x-(this.energy/100),this.x)!=0)&& this.direction ==0) //checks for speed awareness -ve direction
  	 		if(this.energy<=900){
  					this.eat_food()
     		}
   		else
     		this.move()
		}
  	else
   		this.move()
		return this.flag;
	}

  //olfactory, This function checks if the food is within 30px ahead and 15 px behind his nose and flips direction to get there quicker.
  olfactory(){
		if ((this.check_jumps(this.x,this.x+30)!=0) && this.direction ==1){//checks for 30px awareness in +ve direction
   		if ((this.check_jumps(this.x,(this.x+(this.energy/100)))!=0) && this.direction ==1) //checks for speed awareness +ve direction
    		if(this.energy<=900){
  				this.eat_food()
    		}
   		else
      	this.move()
  	}
  	else if ((this.check_jumps(this.x-30,this.x)!=0)&& this.direction ==0){ //checks for 30px awareness in -ve direction
  		if ((this.check_jumps(this.x-(this.energy/100),this.x)!=0)&& this.direction ==0) //checks for speed awareness -ve direction
  	 		if(this.energy<=900){
  					this.eat_food()
     		}

    if ((this.check_jumps(this.x-15+this.radius,this.x+this.radius)!=0) && this.direction ==1){//checks for 30px awareness in +ve direction
   		if ((this.check_jumps(this.x,(this.x+(this.energy/100)))!=0) && this.direction ==1) //checks for speed awareness +ve direction
    		if(this.energy<=900){
  				this.eat_food()
    		}
   		else
      	this.move()
  	}
  	else if ((this.check_jumps(this.x+this.radius,this.x-15+this.radius)!=0)&& this.direction ==0){ //checks for 50px awareness in -ve direction
  		if ((this.check_jumps(this.x-(this.energy/100),this.x)!=0)&& this.direction ==0) //checks for speed awareness -ve direction
  	 		if(this.energy<=900){
  					this.eat_food()
     		}
   		else
     		this.move()
		}
  	else
   		this.move()
		return this.flag;
	}
  }


  //checks if the food is between two points
  check_jumps(m, n){
    var r = this.look_for.r;
  	if(this.direction==1){
    	for(var i=m; i<n+1; i++)
     		if(i>=r-1 && i<=r+1)
        	this.flag=i
  	}

  	else if (this.direction==0){
    	for(var j=n; j>m-1; j--)
      	if(j>=r-1 && j<=r+1)
        	this.flag=j
  	}
  	return this.flag;
	}

  //If the returned place_value is at the same position as the food, it consumes it and respawns food
  eat_food(){
    var r = this.look_for.r;
  	if(this.x>=r-(this.energy/100) && this.x<=r+(this.energy/100)){
    	var timer=this.timer.count_cycletime()
    	this.energy=this.energy+10
			this.change_f.reset()
			this.flag=0;
  	}
  //else
    //move()
  //return p
	}

  //dies the agent of the this.energy<900
  die(){
		if (this.energy<0){
  		this.reset();
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
var barrier;

function setup() {
  createCanvas(400, 300);
  frameRate(this.simulation_speed);
  dummy= new Agent();
  meal= new Food();
  barrier= new Obstacle();
  dummy.setFood(meal);
  t= new Time();
  dummy.setTimer(t)
  dummy.reSpawn(meal)
}

function draw() {
  background(220);
  textSize(12);

  //color response to energy
  if (dummy.energy>800){
    fill(0,0,255);
  }
  if (dummy.energy<800 && dummy.energy>500){
    fill(50,50,255);}
//  if (dummy.energy<500 && dummy.energy>300){
  //  fill(15,200,20);}
  //if (dummy.energy<300 && dummy.energy>100){
    //fill(255,250,0);}


else if (dummy.energy<500 && dummy.energy>0){
  fill(0,0,0);
}

  dummy.display();
  if(dummy.see()>=0 && dummy.olfactory()>=0){
  //  int b=random(255);
  	dummy.move()
  }

  fill(255,255,255);
  meal.display();
  fill(55,150,55);
  barrier.display();
 	barrier.wait();
  dummy.die()
  meal.die()
  //text('average time '+ Math.floor(this.avg_time * 100) / 100 +' ms',50,50);
  //text('last cycle time '+ Math.floor(this.cycle_time * 100) / 100  + ' ms', 50,250);
  //text('Total Time '+this.total_time,50,90);
	text('Energy '+ Math.floor(dummy.energy),50,30);
  text('Death count '+death_count,50,70);
  t.keyPressed();
  //text('frame this.count_cycle '+this.frame_counts, 50,105);
  //text('simulation speed ' + this.simulation_speed, 50,110);
  //text('this.x: '+this.x+ '    this.x+this.energy: '+(this.x+(this.energy/100)) + '    this.r: '+ this.r, 50, 200);
  //text(check_flag(), 50, 50)
  //text(dummy.check_jumps(), 50, 100)
  //text(dummy.check_jumps(this.x,(this.x+this.energy/100)), 50, 250)
  //text(dummy.eat_food(this.flag), 50, 260)
}

class Time{
  constructor(){
    this.count_cycle=0;
    this.cycle_time=0;
    this.total_time=0;
    this.avg_time=0;
    this.time2=0;
    this.frameCounts=0;
    this.simulation_speed=15;
  }


  count_cycletime(){
    var time= this.frameCounts;
    this.cycle_time= time-this.time2;
    this.total_time=this.total_time+this.cycle_time;
    this.avg_time=this.total_time/this.count_cycle;
    this.time2= time;
    this.count_cycle=this.count_cycle+1;
  }

	keyPressed(){
    if (keyCode == UP_ARROW){
        this.simulation_speed += 20;
    }
    else if(keyCode == DOWN_ARROW){
        this.simulation_speed -= 20;
    }
	}
}
