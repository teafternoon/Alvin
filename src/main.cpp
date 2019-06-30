#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
    const char* path = "lena.jpeg";
    Mat img = imread(path);
    if (img.empty())
    {
        cout << "error";
        return -1;
    }
    imshow("原图像", img);


    //水平方向边缘提取
    Mat h_kern = (Mat_<float>(3, 3) << 1, 1, 1,
                                    0, 0, 0,
                                    -1, -1, -1);
    Mat h_mat;
    filter2D(img, h_mat, img.depth(), h_kern);
    imshow("水平方向边缘提取", h_mat);

    Mat v_kern = (Mat_<float>(3, 3) << 1, 0, -1,
                                    1, 0, -1,
                                    1, 0, -1);
    Mat v_mat;
    filter2D(img, v_mat, img.depth(), v_kern);
    imshow("线性非均值滤波2", v_mat);

    waitKey();

    return 0;
}

