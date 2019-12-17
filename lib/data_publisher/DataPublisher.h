#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "../controller/Controller.h"
#include "../detector/Detector.h"
#include "robot_line_follower/msg/process_data.hpp"
#include <opencv2/opencv.hpp>

using namespace std::chrono_literals;

#ifndef DATA_PUBLISHER_H
#define DATA_PUBLISHER_H

class DataPublisher : public rclcpp::Node
{
  public:
    DataPublisher();
    std::map <std::string, double> get_params();
    void set_controller(std::shared_ptr<Controller> controller);
    void set_detector(std::shared_ptr<Detector> detector);

  private:
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
    rclcpp::Publisher<robot_line_follower::msg::ProcessData>::SharedPtr data_publisher_;
    std::vector<std::string> parameters_;
    std::shared_ptr<rclcpp::SyncParametersClient> parameters_client_;
    std::shared_ptr<Controller> controller_;
    std::shared_ptr<Detector> detector_;
};

#endif
