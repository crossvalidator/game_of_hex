
/*
x = xinit + 1.5*(v-u)*s
y = yinit + (a/2)*(u+v-2)*s
*/

/******************************************************************************
drawHexagon(int u, int v, float size )

Inputs: 
	Arguments:	
		1. u,v
		2. size 
	Global Variables:size
Outputs:
	output: draws a hexagon with array coordinates u,v 
    Return Value: none 
    Reference Arguments: none 

Assumptions: n<=8
/***********************************************************************/

void drawHexagon(int u, int v, float size ){
float x, y;
x = xinit + 1.5*(v-u)*size;
y = yinit + (a/2)*(u+v-2)*size;
Position Hexagon[6];
	Hexagon[0]=Position(x-1*size,y);
	Hexagon[1]=Position(x-0.5*size,y-(a/2)*size);
	Hexagon[2]=Position(x+0.5*size,y-(a/2)*size);
	Hexagon[3]=Position(x+1*size,y);
	Hexagon[4]=Position(x+0.5*size,y+(a/2)*size);
	Hexagon[5]=Position(x-0.5*size,y+(a/2)*size);

if      ((Who %2)== 0) w.RenderPolygon(Hexagon,6,Blue,true);
else if ((Who %2)== 1) w.RenderPolygon(Hexagon,6,Red ,true);
else                   w.RenderPolygon(Hexagon,6,Yellow,true); 
return ;
}
/******************************************************************************
findClickedHex()

Inputs: 
	Arguments: none	
	Global Variables: size,XY,u,v,a
Outputs:
	output: stores in u,v; the arry-coords corresponding to the hexagon clicked
	        if no valid hexagon was clicked then it returns failure
	        
    Return Value: returns 1 if the clicked hexagon was valid (success); else returns 0
    
    Reference Arguments:

Assumptions: n<=8
/*************************************************************************************/

int findClickedHex(){
float x, y, xZero, yZero, r;
xZero = XY.GetXDistance();
yZero = XY.GetYDistance();
for (int i=1; i<=n; i++){
	for (int j=1; j<=n; j++){
		x = xinit + 1.5*(j-i)*size;
		y = yinit + (a/2)*(i+j-2)*size;
		r= sqrt((x-xZero)*(x-xZero)+(y-yZero)*(y-yZero));
		if (r < ((a/2)*size)){
		u = i; v = j;
		return 1;
		}
		else continue;
	}
}
return 0;
}
/******************************************************************************
eventClick()

Inputs: 
	Arguments: none	
		 
	Global Variables: u,v,size,Who,Comp,Player,HexGrid
Outputs:
	output: draws the hexagon at (u,v) if the position was valid
    Return Value: 1 if hexagon is drawn(success) else returns 0
    Reference Arguments: none

Assumptions: n<=8
/************************************************************************************/

int eventClick(){
if ((findClickedHex()==1)){
	if ((HexGrid[u][v]==4)){
		drawHexagon(u, v, size);
		HexGrid[u][v]=(Who % 2);
		Comp[u][v]=Player[u][v]=HexGrid[u][v];
		return 1;
	}
}
else	{
//	cout<<"position already played"<<endl;
	return 0;
	}
}
/******************************************************************************
click(const Position& p)

Inputs: 
	Arguments: 	
		1. Position of the click 
	Global Variables: player, win, Who, HexGrid, w
Outputs:
	output: In "2 Player" game it plays at the clicked hex if valid and changes player no.
	        In "1 Player" game it plays at the clicked hex if valid and makes computer play
    Return Value: returns 1,0 if the game resulted in a win for either of the players
                  returns 2 if the click was on help
    Reference Arguments: none

Assumptions: n<=8
/*************************************************************************************/
int click(const Position& p){
float xo,yo;
xo = p.GetXDistance();
yo = p.GetYDistance();

if (xo>1 && xo<3){
	if(yo>2 && yo<3){
		help.Open();
		help.RenderText (Position(1,1),Position(15,3),"1.The game of hex consists of a hexagonal grid of given size.",Black,White);
  help.RenderText (Position(1,3),Position(15,5),"2.You have to form a continuous bridge of hexagons of your colour",Red,White);
 help.RenderText (Position(1,4),Position(15,7),"from one side of the grid to the other.",Red,White);
		return 2;
	}
}

int event;

if (player==2){			//player 2 code begins
XY = p;

if (win != 1) event=eventClick(); 
else return 0;
	
if((Who%2)==0){		//for the first played
	if (event==1){
		++Who;
	}
	if(terminate1(HexGrid)==0){
		cout<<"PLAYER 1 WINS"<<endl;
		w.RenderText( Position(5,yinit+a*(n-1)*size+1),Position(10, yinit+(a)*(n-1)*size+2),"PLAYER 1 WINS", Blue,White);
		win = 1;
		}
	}

else{
	if (event==1){	//2nd played
		++Who;	
	}
	if(terminate2(HexGrid)==0){
		cout<<"PLAYER 2 WINS"<<endl;
		w.RenderText( Position(5,yinit+a*(n-1)*size+1),Position(10, yinit+(a)*(n-1)*size+2),"PLAYER 2 WINS", Red,White);
		win = 1;
	}
}
displaygrid(HexGrid);
cout<<endl;
}			//player 2 ends

if (player==1){
XY = p;
if (win != 1) event=eventClick(); 
else return 0;
										
	if (event==1){
		++Who;
	
	}		
	if(terminate2(HexGrid)==0){
		cout<<"PLAYER WINS"<<endl;
		w.RenderText( Position(5,yinit+a*(n-1)*size+1), Position(10, yinit+(a)*(n-1)*size+2),"PLAYER WINS", Red,White);
		win = 1;
		return 1;
	}
if (event==1) compPlays();
	displaygrid(HexGrid);
	cout<<endl;
}

return 1;
}
/******************************************************************************
optClick(const Position& p)

Inputs: 
	Arguments: 	
		1.Positon of the click 
	Global Variables: player, Who, opt
Outputs:
	output: accepts initial settings from the user and draws the Grid accordingly
    Return Value: 0
    Reference Arguments: none

Assumptions: n<=8
/************************************************************************************/

int optClick(const Position& p){
float x,y;
x= p.GetXDistance();
y= p.GetYDistance();
if (x>2 && x<5.5){				
	if (y>5 && y< 6){			// click is on "I play 1st"
		player=1; Who=1;
		opt.Close();
	}
	else if (y>6 && y<7){
		player=1; Who=0;		// click is on "I play 2nd"
		opt.Close();
	}
}
else if (x>9.5 && x<13){		// click is on "2 Player"
	if (y>3 && y<4){			
		player=2; Who=0;
		opt.Close();
	}
}
drawGrid();

if (player==1){
	if (Who==0){
		compPlays();
	}
}
else if (player==2) Who=0;

return 0;
}
/******************************************************************************
askOptions()

Inputs: 
	Arguments:	none
	 
	Global Variables: opt
Outputs:
	output: in the opt window, writes the necessary text
    Return Value: none
    Reference Arguments: none

Assumptions: n<=8
/*************************************************************************************/
void askOptions(){

	assert(opt.GetStatus() == WindowOpen);
	
	opt.RenderText( Position(2.5,1.0), Position(12.5,2.0), "GAME OF HEX", Red, White);
	opt.RenderText( Position(2.0,3.0), Position(6.5,4.0), "1 Player", Blue, Yellow);
	opt.RenderText( Position(8.5,3.0), Position(13.0,4.0), "2 Player", Blue, Yellow);
	opt.RenderText( Position(2.0,5.0), Position(6.5,6.0), "I play 1st", Blue, Yellow);
	opt.RenderText( Position(2.0,6.0), Position(6.5,7.0), "I play 2nd", Blue, Yellow);
	
return;
}
/******************************************************************************
drawGrid()

Inputs: 
	Arguments: none
		 
	Global Variables: Who, w, HexGrid, Comp, Player
Outputs:
	output: 
    Return Value: 
    Reference Arguments:

Assumptions: n<=8
/**********************************************************************************/
void drawGrid() {

float x1, y1, x2,y2,x3,y3,x4,y4;
x1 = xinit + 1.5*(1-1)*size;
y1 = yinit + (a/2)*(1+1-2)*size;
x2 = xinit + 1.5*(n-1)*size;
y2 = yinit + (a/2)*(1+n-2)*size;
x3 = xinit + 1.5*(n-n)*size;
y3 = yinit + (a/2)*(n+n-2)*size;
x4 = xinit + 1.5*(1-n)*size;
y4 = yinit + (a/2)*(n+1-2)*size;
Position Parallelogram[4];
	Parallelogram[0]=Position(x1-0.5*size,y1-(a/2)*size);
	Parallelogram[1]=Position(x2+0.5*size,y2+(a/2)*size);
	Parallelogram[2]=Position(x3+0.5*size,y3+(a/2)*size);
	Parallelogram[3]=Position(x4-0.5*size,y4-(a/2)*size);

w.RenderPolygon(Parallelogram,4,Red,false);

	Parallelogram[0]=Position(x1+0.5*size,y1-(a/2)*size);
	Parallelogram[1]=Position(x2+0.5*size,y2-(a/2)*size);
	Parallelogram[2]=Position(x3-0.5*size,y3+(a/2)*size);
	Parallelogram[3]=Position(x4-0.5*size,y4+(a/2)*size);

w.RenderPolygon(Parallelogram,4,Blue,false);

int f = Who;
Who = -1;
w.Open();
assert(w.GetStatus() == WindowOpen);

for(int u=1; u<=n; u++){
	for(int v=1; v<=n; v++){
		drawHexagon(u, v, size);
	}
}
Who = f;

for(int u=0; u<=9; u++){
	for(int v=0; v<=9; v++){
		HexGrid[u][v]=5;
		Comp[u][v]=0;
		Player[u][v]=1;
	}
}

for(int i=0;i<=n+1;++i) {Comp[i][0]=5; Comp[i][n+1]=5;}
for(int i=0;i<=n+1;++i) {Player[0][i]=5; Player[n+1][i]=5;}

for(int u=1; u<=n; u++){
	for(int v=1; v<=n; v++){
		HexGrid[u][v]=4;
		Comp[u][v]=4;
		Player[u][v]=4;
	}
}
return;
}
/***************************************************************************************/