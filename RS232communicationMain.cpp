#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "RS232communication.h"
#include "/home/xytable/src/XYTable/MotorControl.h" 


using namespace std;

int main(){

    char output[80];

    unsigned char Address, Status;
    int Value;

    int Motor_handle;
    bool verbosity=true;



    //Motor_handle = OpenRS232_dev("/dev/ttyS4", 9600); // Baudrate=9600 is defined in RS232communication.hpp, this parameter has no effect
    Motor_handle = OpenRS232(5, 9600);

    cout << Motor_handle << endl;
    if (Motor_handle >= 0){
      bool connected = true;
      SendCmd(Motor_handle, 1, TMCL_GAP, 0, 0, 0); // just try to speak with motor, used GAP to not change the position
      sleep(1);
      Address = 0; Status = 0; Value = 0;


      //if (GetResult(Motor_handle[a], &Address, &Status, &Value)==TMCL_RESULT_OK) break;
      GetResult(Motor_handle, &Address, &Status, &Value);
        if (verbosity) cout << "errno = " << errno << ":\t" << strerror(errno) << endl;
          if (errno != 0 ){
            connected = false;
            if (verbosity) cout << "com device did not respond" << endl;
          }
        else{
          cout << Motor_handle  << " ok" << endl;
        }
    }










	  //int comhandle = OpenRS232(4, 9600);

    int comhandle = open ("/dev/ttyS4", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);

    //write (comhandle, "hallo", 5);
    //sleep (2);
    //read (comhandle, output, 5);

    cout << comhandle << endl;

    close(comhandle);
    return 0;
}
