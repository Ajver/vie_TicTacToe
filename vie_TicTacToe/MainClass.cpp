#include "MainClass.h"

#include <vie/Graphics.h>

#include <iostream>

MainClass::MainClass()
{
	runEngine("Tic Tac Toe", 600, 400);
}


MainClass::~MainClass()
{
}

void MainClass::update(float et)
{
}

void MainClass::render(vie::Graphics* g)
{
	g->setBackgroundColor(vie::Color(30, 30, 30));
}