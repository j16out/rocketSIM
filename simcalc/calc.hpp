#ifndef calc_INCLUDED
#define calc_INCLUDED
//g++ macro.cpp GPT.cpp mroot.cpp -Wall -o2 -o test1 `root-config --cflags --glibs` -std=c++0x -pthread



#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h> 
#include <thread>
#include <stdio.h>
#include <iterator>
#include <sys/stat.h>
#include <unistd.h>
#include "/home/jerin/rocketSIM/cpress/cpress.hpp"



using namespace std;

template <typename T> string tostr(const T& t) { 
   ostringstream os; 
   os<<t; 
   return os.str();
}

struct vec
{
 float x, y;
};

struct prock
{
vec d;
vec v;
vec Ft;
float m;
};

struct frock
{
vec fd;
vec fw;
vec ft;
vec fg;
};

struct fvec
{vector<vec> v;
 vector<vec> d;
};

void initialize(prock & rp, frock & rf, string filename);


void calc_forces(prock & rp, frock & rf, float tstep);

void calc_kinematics(prock & rp, float tstep);

void log_data(prock rp, fvec & dfinal);

void set_thrust(float temp);
void set_stmass(float temp);
void set_dragCd(float temp);
void set_Xarea(float temp);
void set_wind(float temp);
void use_thrustCurve(string filename);

float get_btime();
float mag(vec v1);


void deploy_Chute();





#endif