name,type,unit,resolution,requirement
ID,char[],N/A,N/A,Team Number + P for PocketQube
MISSION_TIME,float,seconds,N/A,Time since power up
GNSS_TIME,char[],GNSS format,N/A,GNSS time in provided format
PACKET_COUNT,int,packets,N/A,Number of telemetry packets
COMMAND_COUNT,int,commands,N/A,Number of commands received
CMD_ECHO,char[],N/A,N/A,Last command received parameters not needed
MODE,char,F/S,N/A,F=Flight S=Simulation
ALTITUDE,float,meters,.1,Altitude derived from air pressure sensor
PRESSURE,double,Pascals,1,Air pressure
TEMPERATURE,float,Celsius,.1,Temperature
VOLTAGE,float,volts,.1,Battery voltage
CURRENT,int,milliamps,1,Battery current
ROT_RATE,float[3],degrees/sec,.1,X Y Z rate gyro values
ACCEL,float[3],m/s^2,.001,X Y Z acceleration values
MAG,float[3],milliGauss,1,Calibrated X Y Z magnetometer values
GNSS_LATITUDE,double,degrees,GNSS provided,GNSS latitude
GNSS_LONGITUDE,double,degrees,GNSS provided,GNSS longitude
GNSS_ALT,double,meters,GNSS provided,GNSS altitude
GNSS_SATS,int,satellites,N/A,Number of satellites used
SOLAR_1,float,volts,.01,Solar panel 1 voltage
SOLAR_2,float,volts,.01,Solar panel 2 voltage
MECH_STATE,int,0/1,N/A,Hex value Bit 0=Solar panel 1 Bit 1=Solar panel 2 Bit 2=Boom Bit 3=Camera recording
IMAGE_STABILIZATION,float[],N/A,N/A,Control loop stabilization data
SCIENCE_EXP,float[],N/A,N/A,Science experiment data