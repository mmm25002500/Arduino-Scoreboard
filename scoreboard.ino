const byte button[]={13,12,11,10,9};
const byte seg_L[]={22,24,26,28,30,32,34,36,23,25,27,29,31,33,35,37};
const byte seg_R[]={38,40,42,44,46,48,50,52,39,41,43,45,47,49,51,53};
const bool winner[12][16]={
            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0}, //Power ON sign
            {1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0}, //sign "Pt"
            };
                         
const bool score[101][16]={
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //blank
            {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0}, //0
            {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0}, //1
            {0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,0}, //2
            {0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0}, //3
            {0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0}, //4
            {0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0}, //5
            {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0}, //6
            {0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0}, //7
            {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0}, //8
            {0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0}, //9
            {0,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0}, //10
            {0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0}, //11
            {0,1,1,0,0,0,0,0,1,1,0,1,1,0,1,0}, //12
            {0,1,1,0,0,0,0,0,1,1,1,1,0,0,1,0}, //13
            {0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0}, //14
            {0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,0}, //15
            {0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0}, //16
            {0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0}, //17
            {0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0}, //18
            {0,1,1,0,0,0,0,0,1,1,1,0,0,1,1,0}, //19
            {1,1,0,1,1,0,1,0,1,1,1,1,1,1,0,0}, //20
            {1,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0}, //21
            {1,1,0,1,1,0,1,0,1,1,0,1,1,0,1,0}, //22
            {1,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0}, //23
            {1,1,0,1,1,0,1,0,0,1,1,0,0,1,1,0}, //24
            {1,1,0,1,1,0,1,0,1,0,1,1,0,1,1,0}, //25
            {1,1,0,1,1,0,1,0,0,0,1,1,1,1,1,0}, //26
            {1,1,0,1,1,0,1,0,1,1,1,0,0,0,0,0}, //27
            {1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0}, //28
            {1,1,0,1,1,0,1,0,1,1,1,0,0,1,1,0}, //29
            {1,1,1,1,0,0,1,0,1,1,1,1,1,1,0,0}, //30
            {1,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0}, //31
            {1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,0}, //32
            {1,1,1,1,0,0,1,0,1,1,1,1,0,0,1,0}, //33
            {1,1,1,1,0,0,1,0,0,1,1,0,0,1,1,0}, //34
            {1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,0}, //35
            {1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,0}, //36
            {1,1,1,1,0,0,1,0,1,1,1,0,0,0,0,0}, //37
            {1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0}, //38
            {1,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0}, //39
            {0,1,1,0,0,1,1,0,1,1,1,1,1,1,0,0}, //40
            {0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0}, //41
            {0,1,1,0,0,1,1,0,1,1,0,1,1,0,1,0}, //42
            {0,1,1,0,0,1,1,0,1,1,1,1,0,0,1,0}, //43
            {0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0}, //44
            {0,1,1,0,0,1,1,0,1,0,1,1,0,1,1,0}, //45
            {0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,0}, //46
            {0,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0}, //47
            {0,1,1,0,0,1,1,0,1,1,1,1,1,1,1,0}, //48
            {0,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0}, //49
            {1,0,1,1,0,1,1,0,1,1,1,1,1,1,0,0}, //50
            {1,0,1,1,0,1,1,0,0,1,1,0,0,0,0,0}, //51
            {1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0}, //52
            {1,0,1,1,0,1,1,0,1,1,1,1,0,0,1,0}, //53
            {1,0,1,1,0,1,1,0,0,1,1,0,0,1,1,0}, //54
            {1,0,1,1,0,1,1,0,1,0,1,1,0,1,1,0}, //55
            {1,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0}, //56
            {1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0}, //57
            {1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0}, //58
            {1,0,1,1,0,1,1,0,1,1,1,0,0,1,1,0}, //59
            {0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0}, //60
            {0,0,1,1,1,1,1,0,0,1,1,0,0,0,0,0}, //61
            {0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0}, //62
            {0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,0}, //63
            {0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,0}, //64
            {0,0,1,1,1,1,1,0,1,0,1,1,0,1,1,0}, //65
            {0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0}, //66
            {0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0}, //67
            {0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0}, //68
            {0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0}, //69
            {1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0}, //70
            {1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0}, //71
            {1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,0}, //72
            {1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,0}, //73
            {1,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0}, //74
            {1,1,1,0,0,0,0,0,1,0,1,1,0,1,1,0}, //75
            {1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0}, //76
            {1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0}, //77
            {1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0}, //78
            {1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,0}, //79
            {1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0}, //80
            {1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0}, //81
            {1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0}, //82
            {1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,0}, //83
            {1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0}, //84
            {1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0}, //85
            {1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0}, //86
            {1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0}, //87
            {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0}, //88
            {1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,0}, //89
            {1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,0}, //90
            {1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0}, //91
            {1,1,1,0,0,1,1,0,1,1,0,1,1,0,1,0}, //92
            {1,1,1,0,0,1,1,0,1,1,1,1,0,0,1,0}, //93
            {1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0}, //94
            {1,1,1,0,0,1,1,0,1,0,1,1,0,1,1,0}, //95
            {1,1,1,0,0,1,1,0,0,0,1,1,1,1,1,0}, //96
            {1,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0}, //97
            {1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,0}, //98
            {1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0}, //99
            };
#define deuceled  21
int victoryscore = 0;
int Addpoints_L = LOW;
int Addpoints_R = LOW;
int deduction_L = LOW;
int deduction_R = LOW;
int buttonState_L = LOW;
int buttonState_R = LOW;
int buttonState_Lde = LOW;
int buttonState_Rde = LOW;
int lastButtonState_L = LOW;
int lastButtonState_R = LOW;
int lastButtonState_Lde = LOW;
int lastButtonState_Rde = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void(* resetFunc) (void) = 0; //Declare the reset function

void setup() {
  for(int i=0;i<5;i++)
    pinMode(button[i],INPUT);
  for(int i=0;i<16;i++){
    pinMode(seg_L[i],OUTPUT);
    pinMode(seg_R[i],OUTPUT);
    digitalWrite(seg_L[i],score[0][i]);
    digitalWrite(seg_R[i],winner[10][i]);
  }
  pinMode(deuceled,OUTPUT);
}

void loop(){
  
  if(digitalRead(button[3])==0)
  {
    int add=1;
    while(add<101){
      for(int j=0;j<16;j++){
        digitalWrite(seg_R[j],score[add][j]);
        digitalWrite(seg_L[j],winner[11][j]);
      }
        

        int reading_R = digitalRead(button[3]);
        if (reading_R != lastButtonState_R) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if (reading_R != buttonState_R) {
            buttonState_R = reading_R;
            if (buttonState_R == LOW) {
              Addpoints_R = !Addpoints_R;
            }
          }
        }
        lastButtonState_R = reading_R;



        int reading_Rde = digitalRead(button[4]);
        if (reading_Rde != lastButtonState_Rde) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if (reading_Rde != buttonState_Rde) {
            buttonState_Rde = reading_Rde;
            if (buttonState_Rde == LOW) {
              deduction_R = !deduction_R;
            }
          }
        }

        lastButtonState_Rde = reading_Rde;
    
        if(Addpoints_R==0){
          Addpoints_R = !Addpoints_R;
          add++;
          if(add>100)
           add=100;
        }

        if(deduction_R==0){
          deduction_R = !deduction_R;
          add--;
          if(add<1)
            add=1;        
        }
          
        if(digitalRead(button[2])==0){ //check victoryscore
          victoryscore = add;
          break;
        }
    }

    
    int i=0;
    int x=1;
    while(i<101){
      while(x<101){
        for(int j=0;j<16;j++){
          digitalWrite(seg_L[j],score[i][j]);
          digitalWrite(seg_R[j],score[x][j]);
        }

        if(victoryscore>2 and i==x and (victoryscore-1==i and x)){ //deuce
          victoryscore++;
          digitalWrite(deuceled,1);
        }

/*---------------------------seg_L Addpoint----------------------------------*/

        int reading_L = digitalRead(button[0]); //seg_L Addpoint
        if (reading_L != lastButtonState_L) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if (reading_L != buttonState_L) {
            buttonState_L = reading_L;
            if (buttonState_L == LOW) {
              Addpoints_L = !Addpoints_L;
            }
          }
        }
        lastButtonState_L = reading_L;

/*---------------------------seg_L Deduction---------------------------------*/

        int reading_Lde = digitalRead(button[1]);  //seg_L Deduction
        if (reading_Lde != lastButtonState_Lde) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if (reading_Lde != buttonState_Lde) {
            buttonState_Lde = reading_Lde;
            if (buttonState_Lde == LOW) {
              deduction_L = !deduction_L;
            }
          }
        }

        lastButtonState_Lde = reading_Lde;

/*---------------------------seg_R Addpoint----------------------------------*/

        int reading_R = digitalRead(button[3]); //seg_R Addpoint
        if (reading_R != lastButtonState_R) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if (reading_R != buttonState_R) {
            buttonState_R = reading_R;
            if (buttonState_R == LOW) {
              Addpoints_R = !Addpoints_R;
            }
          }
        }
        
        lastButtonState_R = reading_R;

/*---------------------------seg_R Deduction---------------------------------*/

        int reading_Rde = digitalRead(button[4]);  //seg_R Deduction
        if (reading_Rde != lastButtonState_Rde) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if (reading_Rde != buttonState_Rde) {
            buttonState_Rde = reading_Rde;
            if (buttonState_Rde == LOW) {
              deduction_R = !deduction_R;
            }
          }
        }

        lastButtonState_Rde = reading_Rde;

/*----------------------------------End--------------------------------------*/
    
        if(Addpoints_L==0){
          Addpoints_L = !Addpoints_L;
          i++;
          if(i==victoryscore){
           for(int win=0;win<10;win++){                   //Flash [DP1] five times on winner's seg
             for(int seg=0;seg<16;seg++){
               digitalWrite(seg_R[seg],winner[1][seg]);
               digitalWrite(seg_L[seg],winner[win][seg]);
               digitalWrite(deuceled,0);
             }
             delay(500);
             if(win==9)
               resetFunc();
           }
          }
        }

        if(deduction_L==0){
          deduction_L = !deduction_L;
          i--;
          if(i<1)
            i=1;
        }

        if(Addpoints_R==0){
          Addpoints_R = !Addpoints_R;
          x++;
          if(x==victoryscore){
           for(int win=0;win<10;win++){
             for(int seg=0;seg<16;seg++){
               digitalWrite(seg_L[seg],winner[1][seg]);
               digitalWrite(seg_R[seg],winner[win][seg]);
               digitalWrite(deuceled,0);
             }
             delay(500);
             if(win==9)
               resetFunc();
           }
          }
        }

        if(deduction_R==0){
          deduction_R = !deduction_R;
          x--;
          if(x<1)
            x=1;      
        }
      }
    }
  }
}
