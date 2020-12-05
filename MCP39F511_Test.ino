#if defined(ESP32)
HardwareSerial Serial1(2);
#endif

#define TEST_COMMAND {0xA5, 0x08, 0x41, 0x00, 0x02,  0x4E, 0x20, 0x5E}

void setup() {
  Serial1.begin(115200);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello MCP39F511");
  uint8_t command[8] = TEST_COMMAND;
  uint8_t result[35];
  Serial1.write(command, 8);
  Serial1.readBytes((char*)&result,35);
  Serial.print(result[0]);
}
