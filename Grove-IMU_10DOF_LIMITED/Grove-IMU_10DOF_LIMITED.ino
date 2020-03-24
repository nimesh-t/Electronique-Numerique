#include "Wire.h"
#include "I2Cdev.h"
#include "MPU9250.h"
#include "BMP280.h"

MPU9250 accelgyro;
I2Cdev   I2C_M;

uint8_t buffer_m[6];


int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t   mx, my, mz;

float heading;
float tiltheading;

float Axyz[3];
float Gxyz[3];
float Mxyz[3];


#define sample_num_mdate  5000

volatile float mx_sample[3];
volatile float my_sample[3];
volatile float mz_sample[3];

static float mx_centre = 0;
static float my_centre = 0;
static float mz_centre = 0;

volatile int mx_max = 0;
volatile int my_max = 0;
volatile int mz_max = 0;

volatile int mx_min = 0;
volatile int my_min = 0;
volatile int mz_min = 0;

float temperature;
float pressure;
float atm;
float altitude;
BMP280 bmp280;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    Wire.setClock(400000);

    Serial.begin(9600);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();
    bmp280.init();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU9250 connection successful" : "MPU9250 connection failed");

    delay(1000);
    Serial.println("     ");
}

void loop() {

    temperature = bmp280.getTemperature(); //Get the temperature, bmp180ReadUT MUST be called first
    pressure = bmp280.getPressure();//Get the temperature
    altitude = bmp280.calcAltitude(pressure); //Uncompensated caculation - in Meters
    atm = pressure / 101325;

    Serial.print("Temperature: ");
    Serial.print(temperature, 2); //display 2 decimal places
    Serial.println(" C°");

    Serial.print("Pressure: ");
    Serial.print(pressure, 0); //whole number only.
    Serial.println(" Pa");

    Serial.print("Ralated Atmosphere: ");
    Serial.println(atm, 4); //display 4 decimal places

    Serial.print("Altitude: ");
    Serial.print(altitude, 2); //display 2 decimal places
    Serial.println(" m");

    Serial.println();
    delay(2500);
}
