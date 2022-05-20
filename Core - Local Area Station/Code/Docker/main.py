#!/usr/bin/env python
from flask import Flask, render_template, Response
import cv2
import datetime
import time
import matplotlib.pyplot as plt
import cvlib as cv
import urllib.request
import numpy as np
import argparse
from cvlib.object_detection import draw_bbox

global url
im=None

app = Flask(__name__)


def run2():
    capture = cv2.VideoCapture(url)
    while True:
        #img_resp=urllib.request.urlopen(url)
        #imgnp=np.array(bytearray(img_resp.read()),dtype=np.uint8)
        _, frame = capture.read()
        #im = cv2.imdecode(imgnp,-1)
        print(np.shape(frame))
        im = frame#cv2.imdecode(frame,-1)
        
        bbox, label, conf = cv.detect_common_objects(im)
        ct = datetime.datetime.now()
        print(ct,": ",bbox, label, conf)
        im = draw_bbox(im, bbox, label, conf)
        frame = cv2.imencode('.jpg', im)[1].tobytes()
        yield (b'--frame\r\n'b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

@app.route('/video_feed')
def video_feed():
    return Response(run2(),mimetype='multipart/x-mixed-replace; boundary=frame')

    
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "url", type=str, help="File containing data you want to evaluate upon"
    )
    args = parser.parse_args()
    #url = 'http://'+args.url
    url = 'rtsp://'+args.url+':8554/mjpeg/1'
    print(url)
    app.run(host='0.0.0.0',port=12345)#, debug=True)
