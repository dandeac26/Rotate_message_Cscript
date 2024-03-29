#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFSIZE 100
#define max_upper 90
#define max_lower 122
#define min_upper 65
#define min_lower 97

int check_num(char *num){
    unsigned int r = 0;
    int p = 1;
    for(int i = strlen(num)-1; i >= 0;i--){
        if(isdigit(num[i])==0){
            printf("Error: non digit characters\n");
            return -1;
        } 
        
        r =((unsigned int)num[i] - '0')*p + r;
        p=p*10;
    }
    return r;
}

bool notValid(char *arr){
    if(strcmp(arr, "-b")==0 || strcmp(arr, "-f")==0 || 
       strcmp(arr, "--backward")==0 || 
       strcmp(arr, "--forward")==0)
        return false;
    return true;
}

int main(int argc, char **argv){
    if(argc >= 2 && strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
        printf("\n      -- ROT encoder/decoder -- \n\n    Program expects two arguments:\n      *direction: {forward,backward} or {-f, -b}\n      *number to rotate by\n\n    Example for rotating forward by 10: ./rotate -f 10\n\n    Program expects a string to be entered - no spaces as of this implementention are allowed\n");
        return 0;
    }
    if(argc < 3 || notValid(argv[1])){
        printf("\nProgram expects two arguments:\n    *direction: {forward,backward} or {-f, -b}\n    *number to rotate by\n    (message)\n\nUse --help for more info.\n\n");
        return 1;
    }

    char *buf = (char*) malloc(BUFSIZE);
    unsigned int ROT = check_num(argv[2]);
    
    if(ROT == -1){
        printf("invalid rotation value, expected unsigned int\n");
        return 2;
    }
    
    if(ROT < 1 || ROT > 25){
        printf("Invalid ROT value\n-has to be between 1-25\n");
        return 2;
    }

    /// handling direction of rotation
    char dir[10];
    if(strcmp(argv[1], "--forward") == 0 || strcmp(argv[1], "-f") == 0)
        strcpy(dir,"forward");
    else if(strcmp(argv[1], "--backward") == 0 || strcmp(argv[1], "-b") == 0){
        strcpy(dir,"backward");
        ROT = 26 - ROT; // use the complement 
    }

    printf("\n------ Rot-%d %s ------\n", ROT, dir);
    
    if(argv[3]){
        strcpy(buf,argv[3]);
    }else{
        printf("Enter message: "); 
        scanf("%s", buf);
    }

    int decimal_value = -1;
    printf("\nresult: ");
    for(int i = 0; i<strlen(buf); i++){
        if(!isalpha(buf[i])){
            printf("%c", buf[i]);
            continue;
        }
            
        decimal_value = (int)buf[i];

        if(isupper(buf[i]) && (decimal_value + ROT > max_upper))
            printf("%c", (char)(min_upper + ROT-1 - max_upper + decimal_value));
        
        else if(islower(buf[i]) &&(decimal_value + ROT > max_lower))
            printf("%c", (char)(min_lower + ROT-1 - max_lower + decimal_value));
        
        else
            printf("%c", (char)(decimal_value + ROT));
        
    }
    printf("\n\n<<Completed Successfully>>\n");
    return 0;
}

