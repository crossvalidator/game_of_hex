
/********************************************************************************
flag(int E[][10],int u,int v,int &count,int U[],int V[],int g)

Inputs: 
	Arguments:	
		1. u,v : coords of cell which you want to flag.
		2. E: flags are marked in E
		3: count: keeps count of number of reachables (flaged cells)
		4: U, V: arrays which store coords of flagged cells
		5: g: value of HexGrid[u][v]
	Global Variables: none
Outputs:
	output: marks all cells of E surrounding uv & having value g with 9. (9 represents 				reachable cell)
    Return Value: none
    Reference Arguments: count, U, V, E

Assumptions: nonecheckvirtualwin exited

*******************************************************************************/

void flag(int E[][10],int u,int v,int &count,int U[],int V[],int g){
	if( ((g==1 && E[u-1][v-1]==7)||(g==1 && E[u-1][v-1]==1)) || ((g==0 && E[u-1][v-1]==6)||(g==0 && E[u-1][v-1]==0)) ) 
		{ E[u-1][v-1]=9; U[count]=u-1; V[count]=v-1; count++; }
	if( ((g==1 && E[u+1][v+1]==7)||(g==1 && E[u+1][v+1]==1)) || ((g==0 && E[u+1][v+1]==6)||(g==0 && E[u+1][v+1]==0)) ) 
		{ E[u+1][v+1]=9; U[count]=u+1; V[count]=v+1; count++; }
	if( ((g==1 && E[u-1][v]  ==7)||(g==1 && E[u-1][v]  ==1)) || ((g==0 && E[u-1][v]  ==6)||(g==0 && E[u-1][v]==0)) )   
		{ E[u-1][v]  =9; U[count]=u-1; V[count]=v  ; count++; } 
	if( ((g==1 && E[u+1][v]  ==7)||(g==1 && E[u+1][v]  ==1)) || ((g==0 && E[u+1][v]  ==6)||(g==0 && E[u+1][v]==0)) ) 
		{ E[u+1][v]  =9; U[count]=u+1; V[count]=v  ; count++; }
	if( ((g==1 && E[u][v-1]  ==7)||(g==1 && E[u][v-1]  ==1)) || ((g==0 && E[u][v-1]  ==6)||(g==0 && E[u][v-1]==0)) ) 
		{ E[u][v-1]  =9; U[count]=u  ; V[count]=v-1; count++; }
	if( ((g==1 && E[u][v+1]  ==7)||(g==1 && E[u][v+1]  ==1)) || ((g==0 && E[u][v+1]  ==6)||(g==0 && E[u][v+1]==0)) ) 
		{ E[u][v+1]  =9; U[count]=u  ; V[count]=v+1; count++; }
}

/******************************************************************************
findreachables(int a,int b,int E[][10])

Inputs: 
	Arguments:	
		1. a,b : base coords of cell about which reachables are desired
		2. E: array on which all operations are performed 
	Global Variables: - none
Outputs:
	output:	marks a path of 9s from 1 row to another, containg a,b
    Return Value: none
    Reference Arguments: E

Assumptions: none

/********************************************************************************/

void findreachables(int a,int b,int E[][10]){
int count=1;		
int g=E[a][b];
int U[50],V[50];
U[0]=a;V[0]=b;
E[a][b]=9;
int runner=0;
while((runner!=count)){
	flag(E, U[runner], V[runner], count, U, V, g);
	runner++;
}	
}	


/******************************************************************************
copyarray(int From[][10],int To[][10])

Inputs: 
	Arguments:	
		1. from array
		2. to array
	Global Variables: none 
Outputs:cout<<"\n hi ha ha";
	output: copies array from into array to
    Return Value: none
    Reference Arguments: From, To

Assumptions: none

/*******************************************************************************/

void copyarray(int From[][10],int To[][10]){
	for(int u=0;u<=n+1;u++){
		for(int v=0;v<=n+1;v++){
			To[u][v]=From[u][v];
		}		
	}
}
		
/******************************************************************************
terminate1(int tantalum[][])

Inputs: 
	Arguments:	
		1. tantalum[][]
	Global Variables: u, v 
Outputs:
	output: finds if a bridge exists for the player1 on grid tantalum
    Return Value: 0 if bridge exists (success), 1 if not.
    Reference Arguments: tantalum

Assumptions: none

/*******************************************************************************/

int terminate1(int tantalum[][10]){

int B[10][10];
copyarray(tantalum,B);
if(B[u][v]==0|| B[u][v]==6){
		findreachables(u, v, B);
	
	for(int h=1;h<=n;h++){
		
		for(int k=1;k<=n;k++){
			if((B[1][h]==9)&&(B[n][k]==9))	return 0;
		}	
	}
}
return 1;
}

/******************************************************************************
terminate2(int tantalum[][])

Inputs: 
	Arguments:	
		1. tantalum[][]
	Global Variables: u, v 
Outputs:
	output: finds if a bridge exists for the player2 on grid tantalum
    Return Value: 0 if bridge exists (success), 1 if not.
    Reference Arguments: tantalum

Assumptions: none

errors: giving segmentation fault if the cout statement is removed

/*****************************************************************************/

int terminate2(int tantalum[][10]){

cout<<'\0';
int B[10][10];
copyarray(tantalum,B);

if(B[u][v]==1||B[u][v]==7){
	findreachables(u, v, B);
	for(int h=1;h<=n;h++){
		for(int k=1;k<=n;k++){
			if((B[h][1]==9)&&(B[k][n]==9)) 
			{
			 return 0;
		    }
	}
}
}
return 1;
}

/******************************************************************************
displaygrid(M[][])
Inputs: 
	Arguments:	
		1. M[][]
	Global Variables:
Outputs:
	output: displays the grid M[][]
    Return Value: none
    Reference Arguments: M[][]

Assumptions: n<=8

/******************************************************************************/
void displaygrid(int M[][10]){
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if (M[u][v]==4) cout<<"-"<<" ";
			else if (M[u][v]==0) cout<<"x"<<" ";
			else if (M[u][v]==1) cout<<"o"<<" ";
			else cout<< M[u][v] << " ";
		}
	cout<<"\n";
	}
}

/*************************************************************************
compPlays()
Inputs: 
	Arguments:none	
		
	Global Variables:u,v,size,Who,HexGrid[][],Comp[][],Player[][]
Outputs:
	output: marks the calculated hexagon
    Return Value: none
    Reference Arguments:

Assumptions: n<=8
/*****************************************************************************/

void compPlays(){
getUV();
drawHexagon(u,v,size);
HexGrid[u][v]=0;
Comp[u][v]=0;
Player[u][v]=0;
createVirtualPath_comp();
checkVirtualWin();
++Who;

if(terminate1(HexGrid)==0){
	cout<<"I WIN"<<endl;
	w.RenderText( Position(5,yinit+a*(n-1)*size+1), Position(10, yinit+(a)*(n-1)*size+2), "I WIN", Blue, White);
	win = 1;
}
}

/***************************************************************************/
