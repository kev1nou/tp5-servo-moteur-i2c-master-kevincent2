#include <mbed.h>

#define ADDRESSE_I2C_PAR_DEFAUT 0x23

static BufferedSerial serial_port(USBTX, USBRX);

I2C i2c(p28, p27);

int main() {

  serial_port.set_baud(9600);
  const int addr8bit = ADDRESSE_I2C_PAR_DEFAUT << 1;

  char cmd[1];
  char message[10];

  while(1) {
    printf("test\r\n");
    cmd[0] = 126; // Démarrer le moteur
    i2c.write(addr8bit, cmd, 1);

    cmd[0] = 45; // Envoyer le moteur à la position 45°
    i2c.write(addr8bit, cmd, 1);

    ThisThread::sleep_for(500ms);

    //i2c.read(addr8bit, message, sizeof(message));
    //printf("Message reçu: %s\r\n", message);

    //ThisThread::sleep_for(1000ms);
  }
}