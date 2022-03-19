#include rosros.h
#include std_msgsInt8.h
#include std_msgsBool.h boolean_data
#include std_msgsString.h
#include sensor_msgsRange.h
#include geometry_msgsTwist.h

std_msgsBool flag_AEB;

geometry_msgsTwist cmd_vel_msg;

void UltraSonarCallback(const sensor_msgsRangeConstPtr& msg)
{
	ROS_INFO(Sonar Seq [%d], msg-header.seq);
	ROS_INFO(Sonar Range [%f], msg-range);
	if(msg-range =1.0)
	{
		ROS_INFO(AEB_Activation!!);
		flag_AEB.data =true;
	}
	else
	{
		flag_AEB.data = false;
	}
}
void CarControlCallback(const geometry_msgsTwist& msg)
{
	ROS_INFO(cmd_vel  linear_x [%f], msg.linear.x);
	cmd_vel_msg=msg;
	ROS_INFO(cmd_vel  linear_x[%f], cmd_vel_msg.linear.x);
	
}

void UltraSonarCallback2(const sensor_msgsRangeConstPtr& msg)
{
	ROS_INFO(Sonar2 seq [%d], msg-header.seq);
	ROS_INFO(Sonar2 Range [%f], msg-range);
}


int main(int argc, char argv)
{
	int count = 0;
	
	rosinit(argc, argv, aeb_controller);
	
	rosNodeHandle n;
	
	
	
	rosSubscriber sub = n.subscribe(range, 1000, UltraSonarCallback);
	rosSubscriber sonar_sub = n.subscribe(RangeSonar1, 1000, UltraSonarCallback2);
	
	rosSubscriber cmd_vel_sub = n.subscribe(cmd_vel, 10, &CarControlCallback);
	
	rosPublisher pub_aeb_activation_flag=n.advertisestd_msgsBool(aeb_activation_flag,1);
	rosPublisher pub_cmd_vel=n.advertisegeometry_msgsTwist(ackermann_steering_controllercmd_vel, 10);
	
	rosRate loop_rate(10); 10
	
	while(rosok())
	{
		if((count%2)==0)
		{
			pub_aeb_activation_flag.publish(flag_AEB);
		}
		
		if(flag_AEB.data == true)
		{
			cmd_vel_msg.linear.x=0;
			pub_cmd_vel.publish(cmd_vel_msg);
		}
		
		else
		{
			pub_cmd_vel.publish(cmd_vel_msg);
		}
		
		loop_rate.sleep();
		rosspinOnce();
		++count;
	}
	return 0;
}
