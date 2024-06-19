#include "inference.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main( )
{


    std::string model_path = "/home/cj/chaintwork/pcl/code_c++/yolov10cpp-main/yolov10s.onnx";
    std::string image_path = "/home/cj/chaintwork/pcl/code_c++/yolov10cpp-main/IMG_4057.JPG";

    try
    {
        InferenceEngine engine(model_path);


        cv::Mat image = cv::imread(image_path);
        int orig_width = image.cols;
        int orig_height = image.rows;
        std::vector<float> input_tensor_values = engine.preprocessImage(image );

        std::vector<float> results = engine.runInference(input_tensor_values);

        float confidence_threshold = 0.5;


        std::vector<Detection> detections = engine.filterDetections(results, confidence_threshold, engine.input_shape[2], engine.input_shape[3], orig_width, orig_height);

        cv::Mat output = engine.draw_labels(image, detections);

        cv::imwrite("result.jpg", output);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
