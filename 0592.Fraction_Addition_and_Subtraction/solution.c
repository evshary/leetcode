#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FRACTION {
    int signed_s;
    int numerator;
    int denominator;
};

struct FRACTION *getFraction(char* expr, struct FRACTION *frac) {
    static char *ptr;
    /* '+'/'-':0->1,   '/':1->2,   next'+'/'-':return */
    int state = 0;
    int num_state = 0;
    if (expr != NULL)
        ptr = expr;
    frac->signed_s = 1;
    frac->numerator = 0;
    frac->denominator = 0;
    while(*ptr != '\0') {
        switch(*ptr) {
        case '+':
            if (state != 0) return frac;
            state = 1;
            break;
        case '-':
            if (state != 0) return frac;
            state = 1;
            frac->signed_s = -1;
            break;
        case '/':
            state = 2;
            num_state = 0;
            break;
        default:
            if (state == 2) {
                if (num_state)
                    frac->denominator *= 10;
                num_state++;
                frac->denominator += *ptr - '0';
            } else {
                if (num_state)
                    frac->numerator *= 10;
                num_state++;
                frac->numerator += *ptr - '0';
            }
        }
        ptr++;
    }
    if (state == 2)
        return frac;
    return NULL;
}

int gcd(int i, int j) {
    int k;
    while(j != 0) {
        k = i % j;
        i = j;
        j = k;
    }
    return i;
}

struct FRACTION addFraction(struct FRACTION frac1, struct FRACTION frac2) {
    struct FRACTION frac;
    int gcd_num;
    frac.numerator = frac1.numerator * frac1.signed_s * frac2.denominator + 
                      frac2.numerator * frac2.signed_s * frac1.denominator;
    frac.denominator = frac1.denominator * frac2.denominator;
    if (frac.numerator > 0)
        frac.signed_s = 1;
    else if (frac.numerator < 0) {
        frac.signed_s = -1;
        frac.numerator *= -1;
    }else if (frac.numerator == 0) {
        frac.signed_s = 1;
        frac.denominator = 1;
    }
    gcd_num = gcd(frac.numerator, frac.denominator);
    frac.numerator /= gcd_num;
    frac.denominator /= gcd_num;
    
    return frac;
}

char * frac2String(struct FRACTION frac) {
    char num[10];
    char *str = malloc(20);
    memset(str, 0, 20);
    int i = 0;
    if (frac.signed_s < 0)
        str[i++] = '-';
    sprintf(num, "%d", frac.numerator);
    strcpy(&str[i], num);
    i += strlen(num);
    str[i++] = '/';
    sprintf(num, "%d", frac.denominator);
    strcpy(&str[i], num);
    i += strlen(num);
    return str;
}

char* fractionAddition(char* expression) {
    struct FRACTION frac1, frac2;
    getFraction(expression, &frac1);
    while(getFraction(NULL, &frac2) != NULL) {
        //printf("frac1 %d/%d\n", frac1.numerator * frac1.signed_s, frac1.denominator);
        //printf("frac2 %d/%d\n", frac2.numerator * frac2.signed_s, frac2.denominator);
        frac1 = addFraction(frac1, frac2);
        //printf("frac %d/%d\n", frac1.numerator * frac1.signed_s, frac1.denominator);
    }
    return frac2String(frac1);
}

int main()
{
    printf("result=%s\n", fractionAddition("-1/2+1/2"));
    printf("result=%s\n", fractionAddition("-1/2+1/2+1/3"));
    printf("result=%s\n", fractionAddition("1/3-1/2"));
    printf("result=%s\n", fractionAddition("5/3+1/3"));
    printf("result=%s\n", fractionAddition("1/8+3/1-1/3+2/1-1/1+4/5+9/10+1/9-9/7-6/7"));
    return 0;
}