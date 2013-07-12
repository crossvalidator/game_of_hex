/******************** GLOBAL VARIABLES**************************************/

const float a=sqrt(3);
SimpleWindow w("Hexagonal Grid", 15.0, 15.0, Position(1.0, 2.0));
SimpleWindow opt("Options", 15.0, 15.0, Position(1.0, 2.0));
SimpleWindow help("Help", 15.0, 15.0, Position(1.0, 2.0));
int Who(-1);
float xinit=7.5;
float yinit=3;
float size = .5;
int n(0);
Position XY;
int u(1),v(1) ;
int HexGrid[10][10], Player[10][10], Comp[10][10];
int glb(0);
int win(0),virtualWin(0);
int player(0);
int level(1);

/***************************** FUNCTIONS ****************************************/

void drawHexagon(int u, int v, float size );
int findClickedHex();
int eventClick();
int click(const Position& p);
void drawGrid();
void displaygrid(int M[][10]);
void flag(int E[][10],int u,int v,int &count,int U[],int V[],int g);
void findreachables(int a,int b,int E[][10]);
void copyarray(int From[][10],int To[][10]);
int terminate1(int tantalum[][10]);
int terminate2(int tantalum[][10]);
void play();
void compPlays();
void getUV();
void stopwinmove();
void winmove();
void virtualWinMoveComp();
int PVC(int i1, int j1, int i2, int j2);
int reallyPVC();
int PVW(int i1, int j1, int i2, int j2);
int reallyPVW();
void createVirtualPath_player();
void createVirtualPath_comp();
void reallyCreateVirtualPath(int i1, int j1, int i2, int j2);
int findBridgeHex(int i, int j);
void makeBridge();
int optClick(const Position& p);
void askOptions();
void virtualWinMovePlayer();
void checkVirtualWin();
/***********************************************************************************/