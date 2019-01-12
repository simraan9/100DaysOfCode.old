var total_time=0;
var avg_time=0;
var cycle_time=0;
var count=0;
var x=200;
var y=150;
var direction=0;
var time2=0;

var energy=100;
function setup() {
  createCanvas(400, 300);
  r = int(random(400));
  }

function draw() {
  //translate(width/2,height/2);
  background(220);
  textSize(12);
  timer()
  energy=energy-0.1
  count=count+1
  agent(x,y,0);
  move()
  fill(255,255,255);
  ellipse(r,y,10,10);
  eat()
  text('average time '+ avg_time/1000 +'  s',50,50);
  text('current cycle time '+ cycle_time/1000 + '  s', 50,250);
	text('ENERGY '+energy,50,30);

}

function eat(){
  if (x==r){
    energy=energy+10
		r=int(random(400));
  	cycle()
  }
}

function die(){

}
function agent(x, y,theta){
  var r = 20;
  if (direction==1){
		theta=theta+PI;
  }
  var p1x= x+(r*(cos(theta)));
  var p1y=y+(r*(sin(theta)));
  var p2x=x+(r*(cos(theta+2*(PI/3)+(PI/8))));
  var p2y=y+(r*(sin(theta+2*(PI/3)+(PI/8))));
  var p3x=x+(r*(cos(theta+(-4)*(PI/6)-(PI/8))));
  var p3y=y+(r*(sin(theta+(-4)*(PI/6)-(PI/8))));
  fill(0,0,255);
 	triangle(p1x,p1y,p2x,p2y,p3x,p3y);
  }

function flip(){
	if (direction==0){
  	direction=1
  }
  else	if (direction==1){
  	direction=0
  }
}

function move(){
	  if (x==0) {
    flip();
  } else if (x>400) {
    flip();
  }

  if (x<=400 && direction==0) {
    x=x+1;
  } else if (x>0 && direction==1) {
  	x=x-1;
  }
}

function timer(){
  var s = 0;
  s = millis();
	return s;
}

function cycle(){
  var time=timer()
  cycle_time=time-time2
  total_time=total_time+cycle_time
  avg_time=total_time/count
  time2=time
}
