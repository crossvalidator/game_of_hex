#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"rect.h"
#include"ezwin.h"
#include <cassert>
#include"randint.h"
#include "FunctionPrototypes.h"
#include "GraphicFunctions.h"
#include "NonGraphicFunctions.h"
#include "AI.h"


int ApiMain(){
srand((unsigned int) time(0));

cout<<"\n Please enter the order of grid which you want(1~8): \n";
cin>>n;
cout<<"Enter the difficulty level at which you want to play(1/2/3):\n";
cin>>level;

w.Open();
w.RenderText( Position(1.0,2.0), Position(3.0,3.0), "HELP", Red, Yellow);

opt.Open();
askOptions();

opt.SetMouseClickCallback(optClick);
w.SetMouseClickCallback(click);

return 0;
}
