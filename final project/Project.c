
#include "simpletools.h"                      // Include simple tools
#include "servo.h"
#include "fdserial.h"
#include "wavplayer.h"
#include "servodiffdrive.h"
#include "ping.h"                             // Include ping header

#define PIN_SOUND       26                    // pin for the speaker, default=26
#define PIN_XBEE_RX      0
#define PIN_XBEE_TX      1
#define PIN_SERVO_LEFT  14
#define PIN_SERVO_RIGHT 15
#define PIN_SERVO_MID   19

volatile int ch;
volatile int XeeChange=0;
volatile int cmDist=0;
volatile int turn=0;
volatile unsigned int lockR;                      // Lock ID 
int DO = 22, CLK = 23, DI = 24, CS = 25;          // SD I/O pins
int * cog_ptr[8];
const char *WAVfile[] = {"1jagger.wav","somebody.wav","callme.wav","rolling.wav","origin.wav"};
volatile fdserial *xbee;

void XBee();
void music(int ch);
void robot();
void PING();
char char2lowercase(char c);

int start = 0;                                    // whether the music starts to play
int song = 1;                                    // switch songs from 1 to 3
char song_cnt = '1';                              // which song is playing right now
int irsensor;
int walk = 0;

int main(void) {
  xbee = fdserial_open(PIN_XBEE_RX, PIN_XBEE_TX, 0, 9600);
  sd_mount(DO, CLK, DI, CS);                      // Mount SD card
  drive_pins(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);    // Set the Left and Right servos
  print("=================================\n");
  print("       Final Project \n");
  print("=================================\n\n");

  print("***Music Part***\n");
  print("[Play]     Start music\n");
  print("[Pause]    Stop music\n");
  print("[Next]     Next song\n");
  print("[Previous] Previous song\n\n");

  print("***line tracing-part***\n");
  print("[Run]      Start line-tracing robot\n");
  print("[Stop]     Stop the robot\n");

  print("=================================\n\n");

  print("[1] Move like jagger\n");
  print("[2] Somebody that I used to know\n");
  print("[3] Call me maybe\n");
  print("[4] Rolling in the deep\n");
  print("[5] Origin\n");
  

  
  cog_ptr[1] = cog_run(&XBee,32);
  
  while(1)
  {      
    if(XeeChange)
    {
      ch = char2lowercase(ch);
      switch ((char) ch)
      {
        case '1':               
          print("[Play]\n");
          start = 1;
          if (walk == 0) {            
            servo_stop();
            servo_speed(14,30);
            servo_speed(15,30);
            pause(500);
          }          
          music(ch);
          break;
        case 'x':
          print("[Pause]\n");
          wav_stop();                                      // Stop playing
          break;
        case 'r':
          print("[Run]\n");
          walk = 1;
          cog_ptr[6] = cog_run(&robot,64);                 // Ask a cog to run the function robot()
          break; 
        case 'n':
          print("[Next]\n");
          if (start == 1){
            song++;
            if (song > 5) {
              song = 1;
              song_cnt = '1';
            }            
            if (song == 2) {
              song_cnt = '2';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,-30);
                servo_speed(15,-30);
                pause(500);
              }
            }                
            if (song == 3)  {
              song_cnt = '3';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,60);
                servo_speed(15,60);
                pause(500);
              }
            } 
            if (song == 4)  {
              song_cnt = '4';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,-60);
                servo_speed(15,-60);
                pause(500);
              }
            }   
            if (song == 5)  {
              song_cnt = '5';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,0);
                servo_speed(15,0);
                pause(500);
              }
            }   
            music(song_cnt);
          }          
          break;
        case 'p':
          print("[Previous]\n");
          if (start == 1){
            song--;
            if (song == 0) {
              song = 5;
              song_cnt = '5';
            }            
            if (song == 1) {
              song_cnt = '1';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,30);
                servo_speed(15,30);
                pause(500);
              }
            } 
            if (song == 2) {
              song_cnt = '2';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,-30);
                servo_speed(15,-30);
                pause(500);
              }
            } 
            if (song == 3) {
              song_cnt = '3';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,60);
                servo_speed(15,60);
                pause(500);
              }
            }
            if (song == 4) {
              song_cnt = '4';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,-60);
                servo_speed(15,-60);
                pause(500);
              }
            }
            if (song == 5) {
              song_cnt = '5';
              if (walk == 0) {
                servo_stop();
                servo_speed(14,0);
                servo_speed(15,0);
                pause(500);
              }
            }
            music(song_cnt);
          }          
          break;          
        case 's':
          print("[Stop]\n");
          walk = 0;
          servo_stop();
          cog_end(cog_ptr[7]);
          cog_end(cog_ptr[6]);
          break;
        default:
           print("%c", (char) ch);
      }     
      XeeChange = 0;
    }   
    pause(1);
  }    
  return 0;
}

void XBee(){
   putchar(CLS);
   fdserial_rxFlush(xbee);
   while(1){
     ch = fdserial_rxChar(xbee);
     XeeChange = 1;
     fdserial_txChar(xbee, ch);
     fdserial_txFlush(xbee);
   }
}  

void music(int ch){
  wav_stop();
  wav_play(WAVfile[ch-(int)'1']);                 // Pass the wavfile name to wav player (cost 2 core)
  wav_volume(8);                                  // Adjust volume
}  

void robot(){
  lockR = locknew();                              // Check out a lock
  servo_angle(PIN_SERVO_MID, 900);                // Turn the standard servo to 90 degrees
  servo_stop();                                   // Close those Cogs which control the servo 
  cog_ptr[7] = cog_run(&PING,16);                 // Ask a cog to run the function PING()
  while(1){
    pause(10);
    /**********IRsensor****************/
    irsensor = input(2);
    pause(100);
    /**********************************/
    while(lockset(lockR));                        // Set the lock
      if (cmDist < 15)
      {
        servo_speed(14,0);
        servo_speed(15,0);
        high(26);
        high(27);
        pause(100);
        low(26);
        low(27);
        pause(100);
      }        
      else if ((cmDist >= 15)&&(irsensor == 1))    // go
      {
        servo_speed(14,-60);
        servo_speed(15,30);         
        high(26);
        low(27);
        pause(100);
        servo_speed(14,-30);
        servo_speed(15,30);
        pause(50);
      }
      else if ((cmDist >= 11)&&(irsensor == 0))
      {
        servo_speed(14,50);
        servo_speed(15,-50);
        pause(700);
        servo_speed(14,0);
        servo_speed(15,100);
        pause(700);
        servo_speed(14,-30);
        servo_speed(15,30);
        low(26);
        high(27);
        pause(100);
      }                               
      cog_ptr[7] = cog_run(&PING,16);    
      lockclr(lockR);
  }    
}  

void PING(){                // Use Ping))) to measure distance
  while(lockset(lockR));    // Set the lock 
    cmDist = ping_cm(8);    // get the distance
    lockclr(lockR);         // Clear the lock
    cog_end(cog_ptr[7]);    // close itself
}  

char char2lowercase(char c) {
	return ('A'<=c && c<='Z') ? c+32 : c;
}