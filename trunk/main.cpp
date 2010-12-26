/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 24 December 2010 03:20:27  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  shashank singh, 
 *        Company:  Awaaz.me
 *
 * =====================================================================================
 */

#include <QApplication>
#include <QLabel>
#include "gstHandler.h"


int main(int argc , char ** argv) 
{
QApplication app(argc,argv);
gstHandler pipeline(argc,argv);
pipeline.constructPipeline();
QLabel label;
label.show();

return 0;
}

