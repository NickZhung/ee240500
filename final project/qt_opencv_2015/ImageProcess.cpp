#include "ImageProcess.h"
#include "ui_subwindow.h"
#include <QLabel>
#include <QDebug>
#include "math.h"

ImageProcess::ImageProcess(QObject *parent) : QThread(parent) {
    subWidget = new QWidget();
    ui.setupUi(subWidget);

    method = 0;

    subWidget->show();
}

ImageProcess::~ImageProcess() {
    delete this;
}

void ImageProcess::run() {

    qDebug() << "New thread started successfully!!";

}

void ImageProcess::processImage(cv::Mat &image) {
    cv::Mat process;
    vector<vector<Point> > squares;

    // Determine how to process the image by mode
    switch(method) {
        case 0: process = image;
                break;
        case 1: process = edgeDetection(image);
                break;
        case 2: process = findCircles(image);
                break;
        case 3: findSquares(image, squares);
                drawSquares(image, squares);
                process = image;
                break;
        case 4: process = findLines(image);
                break;
        default:process = image;
                break;
    }

    // Display processed image to another widget.
    QPixmap pix = QPixmap::fromImage(imageConvert(process));
    ui.displayLabel->setPixmap(pix);

    // Free the memory to avoid overflow.
    image.release();
}
/*
cv::Mat ImageProcess::Gesture(cv::Mat &image){
    cv::Mat edge;

    cv::rectangle(image,(300,300),(100,100),(0,255,0),0);
    cv::cvtColor(image, edge, CV_BGR2GRAY );
    //cv::blur(edge,edge,cv::Size(9,9));
    double thresh1 = cv::threshold(cv::blur(edge,edge,cv::Size(9,9)), 127, 255,
                                   THRESH_BINARY_INV+THRESH_OTSU);
    cv::imshow('Thresholded', thresh1);

    Mat contours = cv::findContours(thresh1.copy(),cv::RETR_TREE);
    int hierarchy = cv::CHAIN_APPROX_NONE;
    double max_area = -1;
    int ci;
    int cnt;
    for (int i = 0;i < contours.size; i++){
        cnt = contours[i];
        double area = cv::contourArea(cnt);
        if (area > max_area) {
            max_area = area;
            ci = i;
        }
    }
    cnt = contours[ci];
    Rect x = cv::boundingRect(cnt);
    Rect y = cv::boundingRect(cnt);
    Rect w = cv::boundingRect(cnt);
    Rect h = cv::boundingRect(cnt);
    cv::rectangle(image,(x,y),(x+w,y+h),(0,0,255),0);
    cv::convexHull(cnt);

}
*/
cv::Mat ImageProcess::edgeDetection(cv::Mat &image) {
    cv::Mat edge;
    int lowThreshold = 10;
    int ratio = 3;
    int kernel_size = 3;

    // Convert it to gray
    cv::cvtColor(image, edge, CV_BGR2GRAY);

    // Run the edge detector on grayscale
    cv::blur(edge, edge, cv::Size(9,9));
    cv::Canny(edge, edge, lowThreshold, lowThreshold*ratio, kernel_size);

    return edge;
}

void ImageProcess::findSquares(cv::Mat &image, vector<vector<Point> > &squares) {
    squares.clear();

    Mat pyr, timg, gray0(image.size(), CV_8U), gray;
    int thresh = 50, N = 11;

    // down-scale and upscale the image to filter out the noise
    pyrDown(image, pyr, Size(image.cols/2, image.rows/2));
    pyrUp(pyr, timg, image.size());
    vector<vector<Point> > contours;

    // find squares in every color plane of the image
    for( int c = 0; c < 3; c++ )
    {
        int ch[] = {c, 0};
        cv::mixChannels(&timg, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for( int l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                cv::Canny(gray0, gray, 0, thresh, 5);
                // dilate canny output to remove potential
                // holes between edge segments
                cv::dilate(gray, gray, Mat(), Point(-1,-1));
            }
            else
            {
                // apply threshold if l!=0:
                // tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l+1)*255/N;
            }

            // find contours and store them all as a list
            cv::findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

            vector<Point> approx;

            // test each contour
            for( size_t i = 0; i < contours.size(); i++ )
            {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                cv::approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if( approx.size() == 4 &&
                    fabs(contourArea(Mat(approx))) > 1000 &&
                    cv::isContourConvex(Mat(approx)) )
                {
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        // find the maximum cosine of the angle between joint edges
                        double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if( maxCosine < 0.3 )
                        squares.push_back(approx);
                }
            }
        }
    }
}

void ImageProcess::drawSquares(cv::Mat &image, vector<vector<Point> > &squares) {
    // the function draws all the squares in the image
    for( size_t i = 0; i < squares.size(); i++ ) {
        const Point* p = &squares[i][0];
        int n = (int)squares[i].size();

        polylines(image, &p, &n, 1, true, Scalar(0,255,0), 3, CV_AA);
    }
}

cv::Mat ImageProcess::findCircles(cv::Mat &image) {
    cv::Mat circle;
    vector<Vec3f> circles;

    // Convert it to gray
    cvtColor(image, circle, CV_BGR2GRAY);

    // Reduce the noise so we avoid false circle detection
    GaussianBlur(circle, circle, Size(9, 9), 2, 2);

    // Apply the Hough Transform to find the circles
    HoughCircles(circle, circles, CV_HOUGH_GRADIENT, 1, circle.rows/16, 150, 30, 0, 0);

    // Draw the circles detected
    for(size_t i = 0; i < circles.size(); i++ ) {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        // circle center
        cv::circle(image, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
        // circle outline
        cv::circle(image, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
    }

    return image;
}

cv::Mat ImageProcess::findLines(cv::Mat &image) {
    cv::Mat line;
    vector<Vec4i> lines;

    // Convert it to gray
    cvtColor(image, line, CV_BGR2GRAY);

    // Detect the edges of the image by using a Canny detector
    Canny(line, line, 50, 200, 3);

    // Apply the Hough Transform to find the line segments
    HoughLinesP(line, lines, 1, CV_PI/180, 50, 50, 10);

    // Draw the line segments detected
    for(size_t i = 0; i < lines.size(); i++) {
      Vec4i l = lines[i];

      cv::line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
    }

    return image;
}

// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2
double ImageProcess::angle(Point pt1, Point pt2, Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

// The following slots are used to set image processing mode.
void ImageProcess::changeToNormal() {
    method = 0;
}

void ImageProcess::changeToEdgeDetection() {
    method = 1;
}

void ImageProcess::changeToCircleDetection() {
    method = 2;
}

void ImageProcess::changeToSquareDetection() {
    method = 3;
}

void ImageProcess::changeToLineDetection() {
    method = 4;
}

QImage ImageProcess::imageConvert(cv::Mat &matImage) {
    QImage::Format format;

    // If we use edge detection, we will use gray scale to display image.
    switch(method) {
        case 1: format = QImage::Format_Indexed8;
                break;
        default:format = QImage::Format_RGB888;
                break;
    }

    // Convert processed openCV frame to Qt's image format in order to display.
    QImage qImage(
        (uchar*)matImage.data,
        matImage.cols,
        matImage.rows,
        matImage.step,
        format
        );

    return qImage.rgbSwapped().mirrored(true, false);
}
