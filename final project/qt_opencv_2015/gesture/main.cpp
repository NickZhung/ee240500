#include <iostream>

//**************************///

#include "Python.h"
#include "opencv2/opencv.hpp"
#include "math.h"

using namespace std;
using namespace cv;


int main()
{

cap = cv::VideoCapture(0)
while(cap.isOpened()):
    ret, img = cap.read()
    cv.rectangle(img,Rect(300,300),Rect(100,100),(0,255,0),0)
    crop_img = img[100:300, 100:300]
    grey = cv.cvtColor(crop_img, cv.COLOR_BGR2GRAY)
    value = (35, 35)
    blurred = cv.GaussianBlur(grey, value, 0)
    _, thresh1 = cv.threshold(blurred, 127, 255,
                               cv.THRESH_BINARY_INV+cv.THRESH_OTSU)
    cv::imshow('Thresholded', thresh1)
    contours, hierarchy = cv.findContours(thresh1.copy(),cv.RETR_TREE, \
            cv.CHAIN_APPROX_NONE)

    max_area = -1
    for i in range(len(contours)):
        cnt=contours[i]
        area = cv.contourArea(cnt)
        if(area>max_area):
            max_area=area
            ci=i
    cnt=contours[ci]
    x,y,w,h = cv.boundingRect(cnt)
    cv.rectangle(crop_img,(x,y),(x+w,y+h),(0,0,255),0)
    hull = cv.convexHull(cnt)
    drawing = np.zeros(crop_img.shape,np.uint8)
    cv.drawContours(drawing,[cnt],0,(0,255,0),0)
    cv.drawContours(drawing,[hull],0,(0,0,255),0)
    hull = cv.convexHull(cnt,returnPoints = False)
    defects = cv.convexityDefects(cnt,hull)
    count_defects = 0
    cv.drawContours(thresh1, contours, -1, (0,255,0), 3)
    for i in range(defects.shape[0]):
        s,e,f,d = defects[i,0]
        start = tuple(cnt[s][0])
        end = tuple(cnt[e][0])
        far = tuple(cnt[f][0])
        a = math.sqrt((end[0] - start[0])**2 + (end[1] - start[1])**2)
        b = math.sqrt((far[0] - start[0])**2 + (far[1] - start[1])**2)
        c = math.sqrt((end[0] - far[0])**2 + (end[1] - far[1])**2)
        angle = math.acos((b**2 + c**2 - a**2)/(2*b*c)) * 57
        if angle <= 90:
            count_defects += 1
            cv.circle(crop_img,far,1,[0,0,255],-1)
        #dist = cv.pointPolygonTest(cnt,far,True)
        cv.line(crop_img,start,end,[0,255,0],2)
        #cv.circle(crop_img,far,5,[0,0,255],-1)
    if count_defects == 1:
        cv.putText(img,"I am Vipul", (50,50), cv.FONT_HERSHEY_SIMPLEX, 2, 2)
    elif count_defects == 2:
        str = "This is a basic hand gesture recognizer"
        cv.putText(img, str, (5,50), cv.FONT_HERSHEY_SIMPLEX, 1, 2)
    elif count_defects == 3:
        cv.putText(img,"This is 4 :P", (50,50), cv.FONT_HERSHEY_SIMPLEX, 2, 2)
    elif count_defects == 4:
        cv.putText(img,"Hi!!!", (50,50), cv.FONT_HERSHEY_SIMPLEX, 2, 2)
    else:
        cv.putText(img,"Hello World!!!", (50,50),\
                    cv.FONT_HERSHEY_SIMPLEX, 2, 2)
    #cv.imshow('drawing', drawing)
    #cv.imshow('end', crop_img)
    cv.imshow('Gesture', img)
    all_img = np.hstack((drawing, crop_img))
    cv.imshow('Contours', all_img)
    k = cv.waitKey(10)
    if k == 27:
        break
}
