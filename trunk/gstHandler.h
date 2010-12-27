/*
 * =====================================================================================
 *
 *       Filename:  gstHandler.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 24 December 2010 03:42:53  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shashank singh:w
 *        Company:  Awaaz.me
 *
 * =====================================================================================
 */

#ifndef GSTHANDLER_H
#define GSTHANDLER_H
#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <QObject>
#include <QDebug>
#include <QImage>
#include <QCoreApplication>

class gstHandler  : public QObject
{
Q_OBJECT

private:
GMainLoop *loop;
GstElement *pipeline;
GstElement *src;
GstElement *sink;

public slots:

public:
  
gstHandler(int,char**);
~gstHandler();

int constructPipeline();
GstBuffer *gstbufferExtractBufferFromSink();
QImage *qimageExtractBufferFromSink();//overloaded function  
//gboolean process_qt_event (gpointer *data);
};

#endif


