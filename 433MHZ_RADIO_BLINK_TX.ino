long pblePkt = 0x55;
byte addrPkt = 0x00;
byte chkPkt;

void setup() 
{
  Serial.begin(2400);
}

void loop() 
{
  sendMsgOverRadio(0xFF);
  delay(1000);
  sendMsgOverRadio(0x00);
  delay(1000);
}

void sendMsgOverRadio(byte msgByte)
{
  for (int n = 0; n < 5; n++)
  {
    Serial.write(pblePkt);
    Serial.write(addrPkt);
    Serial.write(msgByte);
    chkPkt = addrPkt + msgByte;
    Serial.write(chkPkt);
  }
}
