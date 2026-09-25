format,vehicle,argument type,argument range,argument,echo string,result on wrong state
SIM,Container + PocketQube,char,F or S,MODE,SIM MODE,Reject command and do not change mode
SIMP,Container + PocketQube,float,Valid simulated pressure range,PRESSURE,SIMP PRESSURE,Reject command if not in simulation mode
CAL,Container,N/A,N/A,N/A,CAL,Reject command if calibration is not allowed in current state
ARM,Container,N/A,N/A,N/A,ARM,Reject command if not in allowed prelaunch state
MEC_CONTAINER_RELEASE,Container,int,0 or 1,STATE,MEC_CONTAINER_RELEASE STATE,Reject command and do not activate mechanism
MEC_SOLAR_1,PocketQube,int,0 or 1,STATE,MEC_SOLAR_1 STATE,Reject command and do not change mechanism state
MEC_SOLAR_2,PocketQube,int,0 or 1,STATE,MEC_SOLAR_2 STATE,Reject command and do not change mechanism state
MEC_BOOM,PocketQube,int,0 or 1,STATE,MEC_BOOM STATE,Reject command and do not change mechanism state
MEC_DEROTATION,PocketQube,int,0 or 1,STATE,MEC_DEROTATION STATE,Reject command and do not change mechanism state
MEC_CAMERA_RECORD,PocketQube,int,0 or 1,STATE,MEC_CAMERA_RECORD STATE,Reject command and do not change recording state
MEC_CAMERA_ROTATE,PocketQube,float,Team-defined valid angle range,ANGLE,MEC_CAMERA_ROTATE ANGLE,Reject command and do not rotate camera