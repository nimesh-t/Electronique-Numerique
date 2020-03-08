#define ZERO     B00000000
#define ONE      B01001000
#define TWO      B00111101
#define THREE    B01101101
#define FOUR     B01001011
#define FIVE     B11100111
#define SIX      B11110111
#define SEVEN    B01001100
#define EIGHT    B11111111
#define NINE     B11101111
#define TEN      B11011111
#define ELEVEN   B11110011
#define TWELVE   B10110110
#define THIRTEEN B11111001
#define FOURTEEN B10110111
#define FIFTEEN  B10010111

int val = 0;

void setup() {
    DDRD = B11111111; // sets Arduino pins 0 to 7 as output
}

void loop() {
    switch(val){
        case 0:
            PORTD = ZERO;
            break;
        case 1:
            PORTD = ONE;
            break;
        case 2:
            PORTD = TWO;
            break;
        case 3:
            PORTD = THREE;
            break;
        case 4:
            PORTD = FOUR;
            break;
        case 5:
            PORTD = FIVE;
            break;
        case 6:
            PORTD = SIX;
            break;
        case 7:
            PORTD = SEVEN;
            break;
        case 8:
            PORTD = EIGHT;
            break;
        case 9:
            PORTD = NINE;
            break;
        case 10:
            PORTD = TEN;
            break;
        case 11:
            PORTD = ELEVEN;
            break;
        case 12:
            PORTD = TWELVE;
            break;
        case 13:
            PORTD = THIRTEEN;
            break;
        case 14:
            PORTD = FOURTEEN;
            break;
        case 15:
            PORTD = FIFTEEN;
            break;
        default:
            PORTD = ZERO;          
    }
    delay(2000);
    val++;
}
