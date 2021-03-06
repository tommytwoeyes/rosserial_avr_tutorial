#ifndef _ROS_create_node_RoombaSensorState_h
#define _ROS_create_node_RoombaSensorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace create_node
{

  class RoombaSensorState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t bumps_wheeldrops;
      bool wall;
      bool cliff_left;
      bool cliff_front_left;
      bool cliff_front_right;
      bool cliff_right;
      bool virtual_wall;
      uint8_t motor_overcurrents;
      uint8_t dirt_detector_left;
      uint8_t dirt_detector_right;
      uint8_t remote_opcode;
      uint8_t buttons;
      int16_t distance;
      int16_t angle;
      uint8_t charging_state;
      uint16_t voltage;
      int16_t current;
      int8_t temperature;
      uint16_t charge;
      uint16_t capacity;
      enum { CHARGING_NOT_CHARGING =  0 };
      enum { CHARGING_CHARGING_RECOVERY =  1 };
      enum { CHARGING_CHARGING =  2 };
      enum { CHARGING_TRICKLE_CHARGING =  3 };
      enum { CHARGING_WAITING =  4 };
      enum { CHARGING_CHARGING_ERROR =  5 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->bumps_wheeldrops >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bumps_wheeldrops);
      union {
        bool real;
        uint8_t base;
      } u_wall;
      u_wall.real = this->wall;
      *(outbuffer + offset + 0) = (u_wall.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wall);
      union {
        bool real;
        uint8_t base;
      } u_cliff_left;
      u_cliff_left.real = this->cliff_left;
      *(outbuffer + offset + 0) = (u_cliff_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff_left);
      union {
        bool real;
        uint8_t base;
      } u_cliff_front_left;
      u_cliff_front_left.real = this->cliff_front_left;
      *(outbuffer + offset + 0) = (u_cliff_front_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff_front_left);
      union {
        bool real;
        uint8_t base;
      } u_cliff_front_right;
      u_cliff_front_right.real = this->cliff_front_right;
      *(outbuffer + offset + 0) = (u_cliff_front_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff_front_right);
      union {
        bool real;
        uint8_t base;
      } u_cliff_right;
      u_cliff_right.real = this->cliff_right;
      *(outbuffer + offset + 0) = (u_cliff_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff_right);
      union {
        bool real;
        uint8_t base;
      } u_virtual_wall;
      u_virtual_wall.real = this->virtual_wall;
      *(outbuffer + offset + 0) = (u_virtual_wall.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->virtual_wall);
      *(outbuffer + offset + 0) = (this->motor_overcurrents >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_overcurrents);
      *(outbuffer + offset + 0) = (this->dirt_detector_left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dirt_detector_left);
      *(outbuffer + offset + 0) = (this->dirt_detector_right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dirt_detector_right);
      *(outbuffer + offset + 0) = (this->remote_opcode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->remote_opcode);
      *(outbuffer + offset + 0) = (this->buttons >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons);
      union {
        int16_t real;
        uint16_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        int16_t real;
        uint16_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angle);
      *(outbuffer + offset + 0) = (this->charging_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charging_state);
      *(outbuffer + offset + 0) = (this->voltage >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current);
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature);
      *(outbuffer + offset + 0) = (this->charge >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charge >> (8 * 1)) & 0xFF;
      offset += sizeof(this->charge);
      *(outbuffer + offset + 0) = (this->capacity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->capacity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->capacity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->bumps_wheeldrops =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bumps_wheeldrops);
      union {
        bool real;
        uint8_t base;
      } u_wall;
      u_wall.base = 0;
      u_wall.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wall = u_wall.real;
      offset += sizeof(this->wall);
      union {
        bool real;
        uint8_t base;
      } u_cliff_left;
      u_cliff_left.base = 0;
      u_cliff_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff_left = u_cliff_left.real;
      offset += sizeof(this->cliff_left);
      union {
        bool real;
        uint8_t base;
      } u_cliff_front_left;
      u_cliff_front_left.base = 0;
      u_cliff_front_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff_front_left = u_cliff_front_left.real;
      offset += sizeof(this->cliff_front_left);
      union {
        bool real;
        uint8_t base;
      } u_cliff_front_right;
      u_cliff_front_right.base = 0;
      u_cliff_front_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff_front_right = u_cliff_front_right.real;
      offset += sizeof(this->cliff_front_right);
      union {
        bool real;
        uint8_t base;
      } u_cliff_right;
      u_cliff_right.base = 0;
      u_cliff_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff_right = u_cliff_right.real;
      offset += sizeof(this->cliff_right);
      union {
        bool real;
        uint8_t base;
      } u_virtual_wall;
      u_virtual_wall.base = 0;
      u_virtual_wall.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->virtual_wall = u_virtual_wall.real;
      offset += sizeof(this->virtual_wall);
      this->motor_overcurrents =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_overcurrents);
      this->dirt_detector_left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dirt_detector_left);
      this->dirt_detector_right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dirt_detector_right);
      this->remote_opcode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->remote_opcode);
      this->buttons =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->buttons);
      union {
        int16_t real;
        uint16_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        int16_t real;
        uint16_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      this->charging_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charging_state);
      this->voltage =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      this->charge =  ((uint16_t) (*(inbuffer + offset)));
      this->charge |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->charge);
      this->capacity =  ((uint16_t) (*(inbuffer + offset)));
      this->capacity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->capacity);
     return offset;
    }

    const char * getType(){ return "create_node/RoombaSensorState"; };
    const char * getMD5(){ return "9e8632c0937537603a670e96e85cd991"; };

  };

}
#endif