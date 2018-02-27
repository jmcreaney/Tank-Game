#define WIN32_LEAN_AND_MEAN

#pragma once

#include<windows.h>
#include<windowsx.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm> 
#include<vector>
#include<ctime>

#include "ai.h"
#include "resources.h"
#include "win_base.h"
#include "coord.h"
#include "tankData.h"
#include "hAFV.h"
#include "mvorder.h"
#include "atorder.h"
#include "player.h"
#include "control.h"
//#include "gun.h"
#include "ploter.h"
#include "color.h"
#include "colorStruct.h"

#ifndef GAME_H
#define GAME_H

void save();
void load();
void loadTxt();

void setup(HWND);
void paint(HDC);
void quit();

int roll(int);
void makeTank(int);
void resetOrders();
bool placeTank(std::vector<h_AFV>::iterator, int, int);
int isTank(int,int);
int resDir(coord,coord);
char gthtAngle(int);

void resolveFire(HWND);
void resolveOFire(HWND);
void resolveMove();

void x(HWND, int, std::vector<atOrder>::iterator&);

void commands(HWND, UINT, WPARAM, LPARAM);

BOOL    CALLBACK aboutProc(HWND, UINT, WPARAM, LPARAM);// About Box
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM); //winproc function
BOOL    CALLBACK startProc(HWND, UINT, WPARAM, LPARAM);// Start Menu
BOOL    CALLBACK chooseProc(HWND, UINT, WPARAM, LPARAM);// Selects Tanks
BOOL    CALLBACK chooseProc2(HWND, UINT, WPARAM, LPARAM);// Selects Tanks
BOOL    CALLBACK ordersProc(HWND, UINT, WPARAM, LPARAM);// Selects Orders
BOOL    CALLBACK resultsProc(HWND, UINT, WPARAM, LPARAM);// Displays Results
BOOL    CALLBACK resultsProc2(HWND, UINT, WPARAM, LPARAM);// Displays Overwath Results


#endif


