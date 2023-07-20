#include <PS2X_lib.h>  

#define PS2_DAT        13      
#define PS2_CMD        12  
#define PS2_SEL        11  
#define PS2_CLK        10  
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false
// HAI BANH TRUOC  

#define INA1          6       // yellow
#define INB1          5       //white
//DC 1
#define IN11          31      // cam 
#define IN21          33      // do 
//DC 2
#define IN31          35      // nau
#define IN41          37      // den
//HAI BANH SAU
#define INA2          9       // den
#define INB2          8       // green
//DC3
#define IN12          39      // trang
#define IN22          41      // xam
//DC4
#define IN32          43      // tim
#define IN42          45      // blue

PS2X ps2x; // create PS2 Controller Class

int a;
int error = 0;
byte type = 0;
byte vibrate = 0;
//////////    BIEN GHI GIA TRI CUA CAC NUT XOAY    ///////////////////
int valRx;
int valRy;
int valLx;
int valLy;
///////////////////////////////////////////////
void stopRobot()
{
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, LOW);
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, LOW);

    digitalWrite (IN12, LOW);
    digitalWrite (IN22, LOW);
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, LOW);
  }
  //////////////////////////////////
void forWard(int i)       //di thang
{
    digitalWrite (IN11, HIGH);
    digitalWrite (IN21, LOW);
    digitalWrite (IN31, HIGH);
    digitalWrite (IN41, LOW);

    digitalWrite (IN12, HIGH);
    digitalWrite (IN22, LOW);
    digitalWrite (IN32, HIGH);
    digitalWrite (IN42, LOW);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
    delay(100);
  }
  ///////////////////////////////
void backWard(int i)      //di lui
{
    //DC1
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, HIGH);
    //DC2
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, HIGH);
    //DC3
    digitalWrite (IN12, LOW);
    digitalWrite (IN22, HIGH);
    //DC4
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, HIGH);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
    delay(100);
}
////////////////////////////////////////
void ngangRight(int i)   //di ngang ben phai
{
    //DC1
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, HIGH);
    //DC2
    digitalWrite (IN31, HIGH);
    digitalWrite (IN41, LOW);
    //DC3
    digitalWrite (IN12, LOW);
    digitalWrite (IN22, HIGH);
    //DC4
    digitalWrite (IN32, HIGH);
    digitalWrite (IN42, LOW);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
    delay(100);
  }
////  ////////////////////////////////
void ngangLeft(int i)    //di ngang ben trai
{
    digitalWrite (IN11, HIGH);
    digitalWrite (IN21, LOW);
    //DC2
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, HIGH);
    //DC3
    digitalWrite (IN12, HIGH);
    digitalWrite (IN22, LOW);
    //DC4
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, HIGH);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
    delay(100);
  }
//  ////////////////////////////////////
void rotageLeft()        //xoay quanh truc trai
{
    //DC1
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, HIGH);
    //DC2
    digitalWrite (IN31, HIGH);
    digitalWrite (IN41, LOW);
    //DC3
    digitalWrite (IN12, HIGH);
    digitalWrite (IN22, LOW);
    //DC4
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, HIGH);
    analogWrite (INA1, 120);
    analogWrite (INB1, 120);
    analogWrite (INA2, 120);
    analogWrite (INB2, 120);
  }
  //////////////////////////////////
void rotageRight ()         //xoay quang truc phai
{
    //DC1
    digitalWrite (IN11, HIGH);
    digitalWrite (IN21, LOW);
    //DC2
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, HIGH);
    //DC3
    digitalWrite (IN12, LOW);
    digitalWrite (IN22, HIGH);
    //DC4
    digitalWrite (IN32, HIGH);
    digitalWrite (IN42, LOW);
    analogWrite (INA1, 100);
    analogWrite (INB1, 100);
    analogWrite (INA2, 100);
    analogWrite (INB2, 100);
  }
//  //////////////////////////////////
void cheotrenphai(int i)      // 
{
    //DC1
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, LOW);
    //DC2
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, HIGH);
    //DC3
    digitalWrite (IN12, LOW);
    digitalWrite (IN22, LOW);
    //DC4
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, HIGH);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
  }
//  ///////////////////////////////
void cheotrentrai(int i)      // D
{
    //DC1
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, HIGH);
    //DC2
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, LOW);
    //DC3
    digitalWrite (IN12, LOW);
    digitalWrite (IN22, HIGH);
    //DC4
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, LOW);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
  }
  ////////////////////////////////////
void cheoduoiphai(int i)      // DDDDDDD
{
  //DC1
    digitalWrite (IN11, HIGH);
    digitalWrite (IN21, LOW);
    //DC2
    digitalWrite (IN31, LOW);
    digitalWrite (IN41, LOW);
    //DC3
    digitalWrite (IN12, HIGH);
    digitalWrite (IN22, LOW);
    //DC4
    digitalWrite (IN32, LOW);
    digitalWrite (IN42, LOW);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
  }
  ////////////////////////////////
void cheoduoitrai(int i)      //
{
    //DC1
    digitalWrite (IN11, LOW);
    digitalWrite (IN21, LOW);
    //DC2
    digitalWrite (IN31, HIGH);
    //DC3
    digitalWrite (IN12, LOW);
    digitalWrite (IN22, LOW);
    //DC4
    digitalWrite (IN32, HIGH);
    digitalWrite (IN42, LOW);
    analogWrite (INA1, i);
    analogWrite (INB1, i);
    analogWrite (INA2, i);
    analogWrite (INB2, i);
  }
///////////////////////////  
void goCross ()
{
  ps2x.read_gamepad(false, vibrate);
  delay (20);
  if (ps2x.Button (PSB_PAD_UP) )
      {
        a = 1;
        Serial.println("CHEO TREN TRAI");
        ps2x.read_gamepad(false, vibrate);
        delay (20);
      }
      
      else if (ps2x.Button (PSB_PAD_RIGHT))
      {
        a = 2;
        Serial.println("cheo tren phai");
        ps2x.read_gamepad(false, vibrate);
        delay (20);
        }
        
        else if (ps2x.Button (PSB_PAD_LEFT))
        {
          a = 3;                    
          Serial.println ("cheo duoi trai");
          ps2x.read_gamepad(false, vibrate);
          delay(20);
        }
        
        else if (ps2x.Button (PSB_PAD_DOWN))
        {
          a = 4;        
          Serial.println ("cheo duoi phai");
          ps2x.read_gamepad(false, vibrate);
          delay (20);
        }
// nut nhan ben phai
        
        else if (ps2x.Button (PSB_TRIANGLE))
        {
          a = 5;                    
          Serial.println ("cheo tren trai cham");
          ps2x.read_gamepad(false, vibrate);
          delay (20);
          }
          
          else if (ps2x.Button (PSB_CIRCLE))
          {
            a = 6;
            delay (20);
            Serial.println("cheo tren phai cham");
            ps2x.read_gamepad(false, vibrate);
            delay (20);
            }
            
            else if (ps2x.Button (PSB_SQUARE))
            {
              a = 7;                          
              Serial.println("cheo duoi phai");
              ps2x.read_gamepad(false, vibrate);
              delay (20); 
              }
              
              else if (ps2x.Button (PSB_CROSS))
              {
                a = 8;                
                Serial.println("cheo duoi trai");
                ps2x.read_gamepad(false, vibrate);
                delay (20);              
              }              
          else if (ps2x.Button (PSB_L1))
              {
                a = 9;               
                Serial.println ("xoay trai");
                ps2x.read_gamepad(false, vibrate);
                delay (20);               
              }else if (ps2x.Button (PSB_R1))
              {
                a = 10;                
                Serial.println ("xoay phai");
              }
              
              else a = 0;              
              
}
void setup()
{
  // khai bao cac chan cua cau dk 2 banh truoc
  pinMode (IN11, OUTPUT);
  pinMode (IN21, OUTPUT);
  pinMode (IN31, OUTPUT);
  pinMode (IN41, OUTPUT);
  pinMode (INA1, OUTPUT);
  pinMode (INB1, OUTPUT);
  // khai bao cac chan cua cau dk 2 banh sau
  pinMode (IN12, OUTPUT);
  pinMode (IN22, OUTPUT);
  pinMode (IN32, OUTPUT);
  pinMode (IN42, OUTPUT);
  pinMode (INA2, OUTPUT);
  pinMode (INB2, OUTPUT);
///////////////////////////
  Serial.begin(57600);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  if (error == 0) {
    Serial.print("Đã tìm thấy bộ điều khiển ");
    Serial.print("pressures = ");
    if (pressures)
      Serial.println("true ");
    else
      Serial.println("false");
      Serial.print("rumble = ");
    if (rumble)
      Serial.println("true)");
    else
      Serial.println("false");
    Serial.println("Hãy thử tất cả các nút;");
    Serial.println("giữ L1 hoặc R1 sẽ in ra các giá trị analog.");
  }
  else if (error == 1)
    Serial.println("Không kết nối đc, thử lại...");

  else if (error == 2)
    Serial.println("Bộ điều khiển tìm thấy nhưng không chấp nhận lệnh");

  else if (error == 3)
    Serial.println("Bộ điều khiển từ chối để vào chế độ Pressures ");
  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.print("Tay điều khiển không phù hợp ");
      break;
    case 1:
      Serial.print("Đã tìm thấy DualShock ");
      break;
    case 2:
      Serial.print("Đã tìm thấy GuitarHero ");
      break;
    case 3:
      Serial.print("Không dây của Sony DualShock điều khiển tìm thấy ");
      break;
  }
}
void loop() {
  valRx = 0;
  valRy = 0;
  valLx = 0;
  valLy = 0;
  if(error == 1)
    return;  
  if(type == 2)
  {
    ps2x.read_gamepad();          //read controller 
  }
  else {
set:
    ps2x.read_gamepad ();
    valRx =  ps2x.Analog(PSS_RX);
    valRy =  ps2x.Analog(PSS_RY);
    valLx =  ps2x.Analog(PSS_LX);
    valLy =  ps2x.Analog(PSS_LY);     
/////////////////////////  NUT JOYSTICK PHAI  ///////////////////
// di lui cham
    if (valRy < 127)
    {
      int change = map(valRy, 127, 0, 0, 255);
      Serial.print("tien RY  ");
      Serial.println(change);
      if(change > 155 && change <= 255)
      {
        int i = 100;
        backWard(i);
        change = 0;
        }
      if(change < 155 && change >= 0)
      {
        stopRobot();
        goto set;
      }
      ps2x.read_gamepad();
      valRy = ps2x.Analog(PSS_RY);
      if (valRy >= 127) goto set;
      delay(300);
    }
// Di tien cham
    if (valRy > 127)
    {
      int change = map(valRy, 127, 255, 0, 255);
      Serial.print("lui RY ");
      Serial.println(change);
      if(change > 155 && change <= 255)
      {
        int i = 100;
        forWard(i);
        change = 0;       
        }
      if (change < 155 && change >= 0)
      {
        stopRobot();
        goto set;
      }
      ps2x.read_gamepad();
      valRy = ps2x.Analog(PSS_RY);
      if (valRy <= 127)  goto set;
      delay(300);
    }
// di ngang phai
      if (valRx > 128)
      {
        int change = map (valRx, 127, 255, 0, 255);
        Serial.print(" phai Rx   ");
        Serial.println(change);
        if(change > 155 && change <= 255)
        {
          int i = 80;
          ngangRight(i);
          change = 0;
        }
        if (change < 155 && change >= 0)
        {
          stopRobot();
          goto set;
        }
        ps2x.read_gamepad ();
        valRx = ps2x.Analog (PSS_RX);
        if (valRx <= 128)  goto set;
        delay (300);
      }
//// Di ngang trai
      if (valRx < 128)
      {
        int change = map (valRx, 127, 0, 0, 255);
        Serial.print (" trai Rx  ");
        Serial.println(change);
        if (change > 155 && change <= 255)
        {
          int i = 80;
          ngangLeft(i);
          change = 0;
          }
        if (change < 155 && change >= 0)
        {
          stopRobot();
          goto set;  
        }
        ps2x. read_gamepad();
        valRx = ps2x. Analog(PSS_RX);
        if (valRx >= 128) goto set;
        delay (300);
        }
//////////////////////////  Nut joystick bên trai   ////////////////
// Di lui
        if (valLy < 127)
    {
      int change = map(valLy, 127, 0, 0, 255);
      Serial.print("tien LY  ");
      Serial.println(change);
      if(change > 155 && change <= 255)
      {
        int i = 200;
        backWard(i);
        change = 0;
        }
      if(change < 155 && change >= 0)
      {
        stopRobot();
        goto set;
      }
      ps2x.read_gamepad();
      valLy = ps2x.Analog(PSS_LY);
      if (valLy >= 127) goto set;
      delay(300);
    }
// Di tien cham
    if (valLy > 127)
    {
      int change = map(valLy, 127, 255, 0, 255);
      Serial.print(" lui LY ");
      Serial.println(change);
      if(change > 155 && change <= 255)
      {
        int i = 200;
        forWard(i);
        change = 0;       
        }
      if (change < 155 && change >= 0)
      {
        stopRobot();
        goto set;
      }
      ps2x.read_gamepad();
      valLy = ps2x.Analog(PSS_LY);
      if (valRy <= 127)  goto set;
      delay(300);
    }
// di ngang phai
      if (valLx > 128)
      {
        int change = map (valLx, 127, 255, 0, 255);
        Serial.print(" phai Lx   ");
        Serial.println(change);
        if(change > 155 && change <= 255)
        {
          int i = 120;
          ngangRight(i);
          change = 0;
        }
        if (change < 155 && change >= 0)
        {
          stopRobot();
          goto set;
        }
        ps2x.read_gamepad ();
        valLx = ps2x.Analog (PSS_LX);
        if (valLx <= 128)  goto set;
        delay (300);
      }
//// Di ngang trai
      if (valLx < 128)
      {
        int change = map (valLx, 127, 0, 0, 255);
        Serial.print (" trai Lx  ");
        Serial.println(change);
        if (change > 155 && change <= 255)
        {
          int i = 120;
          ngangLeft(i);
          change = 0;
          }
        if (change < 155 && change >= 0)
        {
          stopRobot();
          goto set;  
        }
        ps2x. read_gamepad();
        valLx = ps2x. Analog(PSS_LX);
        if (valLx >= 128) goto set;
        delay (300);
        }
        goCross ();
        if (a == 1) cheotrentrai(100);
        if (a == 2) cheotrenphai(100);
        if (a == 3) cheoduoitrai(100);
        if (a == 4) cheoduoiphai(100);
        if (a == 5) cheotrentrai(70);
        if (a == 6) cheotrenphai(70);
        if (a == 7) cheoduoiphai(70);
        if (a == 8) cheoduoitrai(70);
        if (a == 9) rotageLeft();
        if (a == 10) rotageRight();
        if (a == 0) 
        {
          stopRobot();
          goto set;
          }
    delay(100);
}
}
