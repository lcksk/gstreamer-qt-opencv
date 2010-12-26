gst-launch v4l2src num-buffers=1 ! jpegenc ! filesink location=capture1.jpeg
gst-launch v4l2src ! xvimagesink
gst-launch v4l2src ! appsink name="sink"
