/*
 * =====================================================================================
 *
 *       Filename:  gstHandler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 24 December 2010 03:42:47  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  shashank singh, 
 *        Company: awaz.me 
 *
 *      pipeline = gst_pipeline_new ("my_pipeline");
 * =====================================================================================
 */

#include "gstHandler.h"
#include <QDebug>

/*  
static gboolean bus_call (GstBus     *bus,   GstMessage *msg,   gpointer    data)
{
GMainLoop *loop = data;

switch (GST_MESSAGE_TYPE (msg)) 
{
case GST_MESSAGE_EOS:
    g_print ("End-of-stream\n");
    g_main_loop_quit (loop);
break;
case GST_MESSAGE_ERROR: 
{
    gchar *debug = NULL;
    GError *err = NULL;
    gst_message_parse_error (msg, &err, &debug);
    qDebug("Error: %s\n", err->message);
    g_error_free (err);
    if (debug) {
                      g_print ("Debug deails: %s\n", debug);
                      g_free (debug);
                   }
                   g_main_loop_quit (loop);
                   break;
                 }
                 default:
                   break;
              }
              return TRUE;
  }
*/


gstHandler::gstHandler(int argc,char ** argv)
{
/*  initialization */
gst_init (&argc,&argv);
loop = g_main_loop_new (NULL, FALSE);
}

gstHandler::~gstHandler()
{
gst_object_unref (pipeline);
//free(loop);
}

int gstHandler::constructPipeline()
{
GstStateChangeReturn ret;
pipeline = gst_pipeline_new ("my_pipeline");
src=gst_element_factory_make ("v4l2src", NULL);
//sink=gst_element_factory_make ("xvimagesink", NULL);
sink=gst_element_factory_make ("appsink", NULL);

gst_bin_add (GST_BIN (pipeline), src);
gst_bin_add (GST_BIN (pipeline), sink);
gst_element_link (src, sink);

ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);

if (ret == GST_STATE_CHANGE_FAILURE) 
{
GstMessage *msg;
qDebug ("Failed to start up pipeline!\n");
}

g_main_loop_run (loop);
return ret;
}

GstBuffer* gstHandler::gstbufferExtractBufferFromSink()
{
/* 
  while (!gst_app_sink_is_eos (GST_APP_SINK (sink))) {
    GstBuffer *buf;

    buf = gst_app_sink_pull_buffer (GST_APP_SINK (sink));
    qDebug ("retrieved buffer %p\n", buf);
    gst_buffer_unref (buf);
  }
  gst_element_set_state (pipeline, GST_STATE_NULL);
*/
}

  
QImage* gstHandler::qimageExtractBufferFromSink()
{
/* 
  while (!gst_app_sink_is_eos (GST_APP_SINK (sink))) {
    GstBuffer *buf;

    buf = gst_app_sink_pull_buffer (GST_APP_SINK (sink));
    qDebug ("retrieved buffer %p\n", buf);
    gst_buffer_unref (buf);
  }
  gst_element_set_state (pipeline, GST_STATE_NULL);
*/
}
