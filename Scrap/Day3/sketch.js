var total_time=0;
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
var s = 0;
var frameCount=0;
var simulation_speed=30;

function setup() {
  createCanvas(400, 300);
  frameRate(simulation_speed);
}

function draw() {
  background(220);
  textSize(12);
  energy=energy-0.1
  draw_agent(x,y,0);
  move()
  fill(255,255,255);
  ellipse(r,y,10,10);
  eat_food()
  text('average time '+ Math.floor(avg_time * 100) / 100 +' ms',50,50);
  text('last cycle time '+ Math.floor(cycle_time * 100) / 100  + ' ms', 50,250);
	text('ENERGY '+ Math.floor(energy),50,30);
  text('Death Count '+death_count,50,70);
  text('Total Time '+total_time,50,90);
  keyPressed();
  text('frame count '+frameCount, 50,105);
  text('simulation speed '+simulation_speed, 50,120);
}

function eat_food(){
  if (x==r){
    energy=energy+10
		r=int(random(20,380));
  	count_cycletime()
  }
kill_agent()
}

function reset(){
	r =int(random(20,380));
	x=int(random(400));
}

function kill_agent(){
	if (energy<0){
  	reset();
    energy=100;
    death_count=death_count+1;
  }
}


function draw_agent(x, y,theta){
  var beta=radius*cos(2*PI/9);
  var gama=radius*sin(2*PI/9);

	if (direction==0){
	triangle(x+radius,y,x-beta,y-gama,x-beta,y+gama);
	}
	else if (direction==1) {
	triangle(x-radius,y,x-beta+2*beta,y-gama,x-beta+2*beta,y+gama);
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

function move(){
	  if (x==0+radius) {
    flip_agent();
  } else if (x>400-radius) {
    flip_agent();
  }

  if (x<=400 && direction==0) {
    x=x+1;
  } else if (x>0 && direction==1) {
  	x=x-1;
  }
}


function count_cycletime(){
  var time= frameCount
  cycle_time=time-time2
  total_time=total_time+cycle_time
  avg_time=total_time/count
  time2=time
  count=count+1
}

function keyPressed(){
    if (keyCode == UP_ARROW){
        simulation_speed += 20;
    }
    else if(keyCode == DOWN_ARROW){
        simulation_speed -= 20;
    }
    // Update frame rate to the updated simulation speed
    frameRate(simulation_speed);
}
