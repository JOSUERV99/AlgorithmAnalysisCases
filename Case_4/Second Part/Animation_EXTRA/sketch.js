let radius, angle, divisions, scale, myColor;
let myPoints, myOtherPoints, w, h, offset, step;
let circles, pointSize, xmov1, ymov1, xmov2, ymov2;
let movementRange;

function setup() {
  w = 650;
  h = 500;
  radius = 20;
  pointSize = 6;
  angle = myColor = 0;
  step = 25;
  circles = 6;
  divisions = 16;
  scale_ = (2 * PI) / divisions;
  xmov1 = ymov1 = xmov2 = ymov2 = 0;
  movementRange = 20;
  
  myColor = ['blue', 'yellow'];

  createCanvas(w, h);
  // create points
  myPoints = getPoints(divisions, scale_);
  myOtherPoints = getPoints(divisions, scale_);
  
}

function draw() {
  background(0);
  
   translate(w/2, h/2);
  for (let offset = 0; offset < circles*step; offset+=step)
    for (let i=0; i<myPoints.length; i++)
      myPoints[i].show(myColor[0], offset, angle, xmov1, ymov1);
  
  translate(-radius/4, -radius/4);
  for (let offset = 0; offset < circles*step; offset+=step)
    for (let i=0; i<myOtherPoints.length; i++)
      myOtherPoints[i].show(myColor[1], offset, angle, xmov2, ymov2);
  
  xmov1 =  abs( cos(angle) )*radius;
  ymov1 =  sin(   angle    )*radius;
  xmov2 = -abs( cos(angle) )*radius;
  ymov2 = -sin(   angle    )*radius;
  
  angle += 0.1;
}

function getPoints(n, scale) {
  let points = [];
  for(let i=0; i<n*scale; i+=scale)
    points.push(new MyPoint(cos(i), sin(i)));
  return points;
}

function MyPoint(x, y) {
  this.x = x;
  this.y = y;
  this.show = function(color, offset, angle, xmov, ymov) {
    stroke(0);
    fill(color)
    rect( (this.x)*(radius + offset)+xmov, 
         (this.y)*(radius + offset)+ymov, 
         pointSize, pointSize);
    
    // rect( (this.x)*( cos(angle)/cos(angle) )*(radius + offset), 
    //      (this.y)*( sin(angle)/sin(angle) )*(radius + offset), 
    //      pointSize, pointSize);
  }
}