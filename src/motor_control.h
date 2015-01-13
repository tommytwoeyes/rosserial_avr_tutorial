#include <inttypes.h>
#include "ros.h"
#include "std_msgs/String.h"

#ifndef _MONSTER_MOTO_SHIELD_AVR_DRIVER_H_
#define _MONSTER_MOTO_SHIELD_AVR_DRIVER_H_

namespace WildThumperRobot
{
	class DC_Motor {
		public:
			void initialize(void);
			void go(uint8_t direction, uint8_t speed);
		private:
			uint8_t pin_inputA;
			uint8_t pin_inputB;
			uint8_t pin_pwm;
	};
}

#endif
