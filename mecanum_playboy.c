string top_left = port4;
string bottom_left = port5;
string top_right = port2;
string bottom_right = port3;

int limit_range(int value_2_limit, int minimum_value)
{
	if(abs(value_2_limit) < minimum_value)
	{
		return 0;
	} else {
		return value_2_limit;
	}
}

void power_motors(int x, int y, int z, int t)
{
	motor[top_right] = x;
	motor[bottom_right] = y;
	motor[bottom_left] = z;
	motor[top_left] = t;
}

task move_with_buttons() {
	while (true)
	{
		if(vexRT(Btn7U) == true)
		{
			power_motors (127, 127, 127, 127);
		}
		else if(vexRT(Btn7R) == true)
		{
			power_motors (-127, 127, -127, 127);
		}
		else if(vexRT(Btn7L) == true)
		{
			power_motors (127, -127, 127, -127);
		}
		else if(vexRT(Btn7D) == true)
		{
			power_motors (-127, -127, -127, -127);
		}
		else
		{
			power_motors (0, 0, 0, 0);
		}


	}
}
task play_sounds() {
	while(true)
	{
		if(vexRT(Btn8R) == true)
		{
			playSound(soundBeepBeep);
			wait1Msec(1000);
			clearSounds();
		}
	}
}

task move_with_joystick {
	while(true)
	{
		int min_val = 10;
		int side_power = vexRT(Ch2)
		if(side_power > min_val){
			power_motors(-1 * side_power, -1 * side_power, side_power, side_power);
		} else {
			int top_right_power = limit_range(vexRT(Ch3), min_val) - limit_range(vexRT(Ch4) , min_val);
			int bottom_right_power = limit_range(vexRT(Ch3), min_val)+ limit_range(vexRT(Ch4), min_val);
			int bottom_left_power = limit_range(vexRT(Ch3), min_val)-limit_range(vexRT(Ch4), min_val);
			int top_left_power = limit_range(vexRT(Ch3), min_val)+limit_range(vexRT(Ch4), min_val);

			power_motors(top_right_power, bottom_right_power, bottom_left_power, top_right_power);
		}
	}
}






task main()
{
	bMotorFlippedMode[top_right] = true;
	bMotorFlippedMode[bottom_right] = true;

	//startTask(move_with_buttons);
	startTask(play_sounds);
	startTask(move_with_joystick);
	while(true) {
		int x = 7;
	}

}
