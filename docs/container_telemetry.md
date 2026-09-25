name,type,unit,resolution,requirement
ID,char[],N/A,N/A,Team Number + C for container
MISSION_TIME,float,seconds,.001,Time since powerup
PACKET_COUNT,int,packets,N/A,Number of packets
COMMAND_COUNT,int,commands,N/A,Numebr of commands recieved
MODE,char,F/S,N/A,F=Flight S=Simulation
ALTITUDE,float,meters,.1,altitude in meters
PRESSURE,double,Pascals,1,Air Pressure
TEMPERATURE,float,Celcus,.1,Temperature
BATTERY_VOLTAGE,float,volts,.1,Battery input voltage
BATTERY_CURRENT,int,milliamps,1,Battery input current
MECH_STATE,int,0/1,N/A,Hex Value Bit 0=Deployment 1=PocketQube release
STATE,enum,LAUNCH_PAD/ASCENT/APOGEE/PQ_RELEASE,N/A,Flight operation state
CMD_ECHO,char[],N/A,1,Last recieved command no commas.