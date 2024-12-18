#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>


cv::Mat preproc(cv::Mat& img);

std::vector<cv::Point> getCont(const cv::Mat& imgPreproc);

std::vector<cv::Point> reorderCont(const std::vector<cv::Point> cont);

cv::Mat getWarp(const cv::Mat img, const std::vector<cv::Point> docCont, float w, float h);

void drawPoints(const cv::Mat img, const std::vector<cv::Point> cont, const cv::Scalar color);

// warp

// video

// git

// toggleBar