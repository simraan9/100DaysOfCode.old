x=400;
y=200;
r=100;
direction=0;
p = 100
function setup() {
  createCanvas(600, 600);
	
}

function draw() {
	background(220);
	stroke(255,0,0);
	move()
	if (direction==0){
	triangle(x+r,y,x-r*cos(2*PI/9),y-r*sin(2*PI/9),x-r*cos(2*PI/9),y+r*sin(2*PI/9));
	}
	else if (direction==1) {
			triangle(x-r-r*cos(2*PI/9)-r*cos(2*PI/9),y,x-r*cos(2*PI/9),y-r*sin(2*PI/9),x-r*cos(2*PI/9),y+r*sin(2*PI/9));
	}
	ellipse (p,y,100,100);
	
  if (x==p){
		p=int(random(400));  }

function spawnFood(){

  }
}
function flip(){
	if (direction==0){
		direction=1;
	}
	else if (direction==1){
		direction=0;
	}
}
function move(){
	  if (x==0) {
    flip();
  } else if (x>600) {
    flip();
  }
  
  if (x<=600 && direction==0) {
    x=x+1;
  } else if (x>0 && direction==1) {
  	x=x-1    
  }
}
