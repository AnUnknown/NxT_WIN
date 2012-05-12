#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include "nxt.h"
#include "test.h"
using namespace std;

//set up the NXT
Connection *connection = new Bluetooth();
Sensor *sensor1 = new Touch(IN_1, connection);
Sensor *sensor2 = new Touch(IN_3, connection);
Sensor *sensorSon = new Sonar(IN_2, connection, METRIC);
Motor *motorA = new Motor(OUT_A, connection);
Motor *motorC = new Motor(OUT_C, connection);
Motor *motorB = new Motor(OUT_B, connection);
int main()
{
  try{
    cout << "Try to connect to the NXT" << endl;
    connection->connect(4);
    cout << "Connected" << endl;
    cout << "Read the touch sensor - hit any key to end" << endl;
        motorA->stop();
        motorA->reset_rotation();
        motorB->stop();
        motorB->reset_rotation();
        motorC->stop();
        motorC->reset_rotation();
        motorB->get_rotation();
        long maxRightSA = 0;
        long maxLeftSA = 0;
        long middle = 0;
       /* cout << "calibrer middle" << endl;
        system("PAUSE");
        middle = motorB->get_rotation();
        motorB->off(true);

        cout << "calibrer maxRightSA" << endl;
        system("PAUSE");
        maxRightSA = motorB->get_rotation();
        motorB->off(true);

        cout << "calibrer maxLeftSA" << endl;
        system("PAUSE");
        maxLeftSA = motorB->get_rotation();
        motorB->off(true);

        cout << "maxLeftSA : " << maxLeftSA << endl;
        motorB->move_to(40,maxLeftSA,6);
        Sleep(2);
        cout << "maxRightSA : " << maxRightSA << endl;
        motorB->move_to(40,maxRightSA,6);
        Sleep(2);
        cout << "middle : " << middle << endl;
        motorB->move_to(40,middle,6);
        Sleep(2);*/
        bool blocked = false;
       while(!_kbhit())
             {
                 bool isOnWall = (sensorSon->read()<=40);
                 if((sensor1->read()==0&&sensor2->read()==0)&&!isOnWall&&!blocked)
                 {

                    forward( motorA, motorC );
                    //  cout << sensorSon->print() << endl; //returns a string can be used on all sensor types
                    cout << sensorSon->read() << endl;
                 }else{
                    stop( motorA, motorC );
                    cout << sensorSon->read() << endl;
                    if(isOnWall){
                        cout << "reculer" << endl;
                        blocked = true;
                        backward( motorA, motorC, 2);
                        stop(motorA, motorC);
                        cout << sensorSon->read() << endl;
                        return 1;
                    }
                 }


   //   sensor1->read() == 1
      //cout << sensor1->print() << endl;
            }

  }

  catch (Nxt_exception& e){
    //some error occurred - print it out
    cout << e.what() << endl;
    cout << "error code: " << e.error_code() << endl;
    cout << "error type: " << e.error_type() << endl;
    cout << e.who() << endl;
    connection->disconnect();
  }
    motorC->off(false);
    motorA->off(false);
    motorB->off(false);
    connection->disconnect();

  return 0;
}
