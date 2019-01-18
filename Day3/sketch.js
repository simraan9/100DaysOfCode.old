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
var frameCounts=0;
var simulation_speed=15;
var flag=0;

function setup() {
  createCanvas(400, 300);
  frameRate(simulation_speed);
}

function draw() {
  background(220);
  textSize(12);
  energy=energy-1
  draw_agent(x,y,0);
  if(check_flag()>=0){
  	move()
  }
  fill(255,255,255);
  ellipse(r,y,10,10);
  text('average time '+ Math.floor(avg_time * 100) / 100 +' ms',50,50);
  text('last cycle time '+ Math.floor(cycle_time * 100) / 100  + ' ms', 50,250);
  text('Total Time '+total_time,50,90);
	text('ENERGY '+ Math.floor(energy),50,30);
  text('Death Count '+death_count,50,70);
  keyPressed();
  text('frame count '+frameCounts, 50,105);
  text(simulation_speed, 50,120);
  //text('x: '+x+ '    x+energy: '+(x+(energy/100)) + '    r: '+ r, 50, 200);
  //text(check_flag(), 50, 50)
  //text(check_jumps(), 50, 100)
  //text(check_jumps(x,(x+energy/100)), 50, 250)
}

function check_flag(){
  kill_agent()
  if ((check_jumps(x,(x+(energy/100)))!=0) && direction ==1){
    flag=1
  	eat_food()
  }

  else if ((check_jumps((x-(energy/100)),x)!=0)&& direction ==0){
    flag=1
  	eat_food()
  }
  else
    move()
  return flag;
}

function check_jumps(m, n){
  if(direction==1){
    for(var i=m; i<n+1; i++)
      if(i>r-1 && i<r+1)
        flag=i
  }

  if(direction==0){
    for(var i=n; i>m-1; i--)
      if(i>r-1 && i<r+1)
        flag=i
  }
  return m,n, flag;
}

function eat_food(){
  //if (p>r-1 && p<r+1){
    energy=energy+100
		r=int(random(20,380));
  	count_cycletime()
 // }
flag=0;
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
    x=x+(energy/100);
  } else if (x>0 && direction==1) {
  	x=x-(energy/100);
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
  cycle_time=time-time2;
  total_time=total_time+cycle_time;
  avg_time=total_time/count;
  time2=time;
  count=count+1;
}

function keyPressed(){
    if (keyCode == UP_ARROW){
        simulation_speed += 20;
    }
    else if(keyCode == DOWN_ARROW){
        simulation_speed -= 20;
    }
}
