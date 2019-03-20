#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        //specify rotation transformation Quaternion(pitch, roll, yaw, 1)
        //specify translation btVector3(x,y,z)
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.2)),
        // time stamp, parent node, child node
        ros::Time::now(),"base_link", "base_laser"));
    r.sleep();
  }
}