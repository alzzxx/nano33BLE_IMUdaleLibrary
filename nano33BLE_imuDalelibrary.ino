

/*****************************************************************************/
/*INCLUDES                                                                   */
/*****************************************************************************/
#include <Nano33BLEAccelerometer.h>
#include <Nano33BLEGyroscope.h>
#include <Nano33BLEMagnetic.h>

/*****************************************************************************/
/*MACROS                                                                     */
/*****************************************************************************/

/*****************************************************************************/
/*GLOBAL Data                                                                */
/*****************************************************************************/
/* 
 * Objects which we will store data in each time we read
 * the each sensor. 
 */
//Nano33BLEMagneticData magneticData;
Nano33BLEGyroscopeData gyroscopeData;
Nano33BLEAccelerometerData accelerometerData;

/*****************************************************************************/
/*SETUP (Initialisation)                                                          */
/*****************************************************************************/
void setup()
{
    /* Serial setup for UART debugging */
    Serial.begin(115200);
    /* 
     * Initialises the all the sensor, and starts the periodic reading 
     * of the sensor using a Mbed OS thread. The data is placed in a 
     * circular buffer and can be read whenever.
     */
    // Magnetic.begin();
    Gyroscope.begin();
    Accelerometer.begin();
    delay(500);
}

/*****************************************************************************/
/*LOOP (runtime super loop)                                                          */
/*****************************************************************************/
void loop()
{
    /*
     * This gets all the data from each sensor. Note that each sensor gets data
     * at different frequencies. Seeing as this super loop runs every 50mS, not
     * all the sensors will have new data. If a sensor does not have new data, 
     * the old data will just be printed out again. This is a little sloppy, but
     * allows the data to be printed in a coherrent way inside serial plotter.
     */
    //Magnetic.pop(magneticData);
    Gyroscope.pop(gyroscopeData);
    Accelerometer.pop(accelerometerData);

    Serial.print("Accelerometer: ");
    Serial.print(accelerometerData.x);
    Serial.print('\t');
    Serial.print(accelerometerData.y);
    Serial.print('\t');
    Serial.println(accelerometerData.z);

    Serial.print("Gyroscope: ");
    Serial.print(gyroscopeData.x);
    Serial.print('\t');
    Serial.print(gyroscopeData.y);
    Serial.print('\t');
    Serial.println(gyroscopeData.z);
    /*
    Serial.print("Magnetometer: ");
    Serial.print(magneticData.x);
    Serial.print('\t');
    Serial.print(magneticData.y);
    Serial.print('\t');
    Serial.println(magneticData.z);
    */

    delay(50);
}