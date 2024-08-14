#include <iostream>
#include <string>
#include <time.h>
using namespace std;

    string pmam;

void pmamChange(){
    if(pmam=="pm")
        pmam="am";
    else
        pmam="pm";
}

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);

int main(){
    int hr, min;
    char choice;
    bool inputAccepted = true;
    int outputs[6][2]={0};
    string pmamA[6]={" "};
    bool changeTime = false;

    cout << "Hello, I am your sleep helper. Please enter the letter of one of the options that you would like to find out:" << endl << "A- When do I Sleep?" << endl << "B- I'm Going To Sleep Now" << endl << "C- I'm Planning on Going to Sleep At ___" << endl << endl;

    do{
        cin >> choice;

        //if they want to give a time to wake up, and look at when to sleep:
        if(choice == 'a' || choice == 'A'){
            inputAccepted = true;
            
            

            cout << endl << "What Time Do you Want to Wake up?" << endl << "Please Enter the Hour Now (12-hour Format):" << endl;
            cin >> hr;

            cout << endl << endl << "Please enter the minutes now (0-59):" << endl;
            cin >> min;

            cout << endl << endl << "Is this time PM or AM? (pm/am)" << endl;
            cin >> pmam;
            cout << endl << endl;
            if(pmam == "pm" || pmam == "PM" || pmam == "Pm"){
                pmam="pm";
            }
            else if(pmam == "am" || pmam == "AM" || pmam == "Am"){
                pmam="am";
            }

            //time for a person to sleep
            min-=15;

            //makes sure that minutes and hours are not (-)
            if(min<0){
                hr--;
                min+=60;
            }
            if(hr<1){
                hr+=12;
            }
            int hrtemp = hr;
            //calculating the sleeping times (-1:30 everytime)
            for(int i = 0; i < 6 ; i++){
                
                hr--; hrtemp--;
                
                min-=30;
            
                if(min<0){
                    hr--; hrtemp--;
                    min+=60;
                }
                if(hr<1){
                    hr+=12;
                }
                if(hrtemp<0){
                    pmamChange();
                    hrtemp+=12;
                }
                

                pmamA[i]=pmam;
                outputs[i][0]=hr;
                outputs[i][1]=min;
            }

            //prints the sleep times
            cout << "To wake up at this time, make sure to sleep at one of these times:" << endl;
            for(int i = 5 ; i >= 0 ; i--){
                cout << outputs[i][0] << ":";
                
                //if minutes are less than 0, it adds a filler zero (like in 4:04)
                if(outputs[i][1] < 10){
                    cout << "0";
                }

                cout << outputs[i][1] << " " << pmamA[i];

                if(i>0){
                    cout << ", ";
                }
            }
            cout << endl << endl << "A good full sleep requires 5-6 'cycles'" << endl << endl;
        }

        //if they want to go to sleep now, and know when to wake up
        else if(choice == 'b' || choice == 'B'){
            inputAccepted = true;
            hr=aTime->tm_hour;
            min=aTime->tm_min;

            //convert to 12-Hour
            if(hr > 12){
                hr-=12;
                pmam = "pm";
            }

            cout << "It is now " << hr << ":";
            if(min<10){
                cout << "0";
            }
            cout << min << " is that correct? (Y/N)" << endl;
            string confirm;
            cin >> confirm;

            if(confirm == "no" || confirm == "No" || confirm == "NO" || confirm == "n" || confirm == "N"){
                cout << endl << "Oh! We are sorry, what is the time now?" << endl << "Please Enter the Hour Now (1-12):" << endl;
                cin >> hr;

                cout << endl << endl << "Please enter the minutes now (0-59):" << endl;
                cin >> min;

                cout << endl << endl << "Is this time PM or AM? (pm/am)" << endl;
                cin >> pmam;
                cout << endl << endl;
                if(pmam == "pm" || pmam == "PM" || pmam == "Pm"){
                    pmam="pm";
                }
                else if(pmam == "am" || pmam == "AM" || pmam == "Am"){
                    pmam="am";
                }
            }

            //time for the person to sleep
            min+=15;

            //makes sure that min!>59, and hr!>12;
            if(min>59){
                hr++;
                min -= 60;
            }
            if(hr>12){
                hr -= 12;
                pmam = "pm";
            }

            int hrtemp = hr;
            //calculating the sleeping times (+1:30 everytime)
            for(int i = 0; i < 6 ; i++){
                hr++; hrtemp++;
                min+=30;
            
                if(min>59){
                    hr++; hrtemp++;
                    min-=60;
                }
                if(hr>12){
                    hr-=12;
                }
                if(hrtemp>11){
                    pmamChange();
                    hrtemp-=12;
                }

                pmamA[i]=pmam;
                outputs[i][0]=hr;
                outputs[i][1]=min;
            }

            //prints the sleeping times
            cout << endl << "If you want to go to sleep now, it is best to wake up at one of these times: " << endl;
            for(int i = 0; i < 6; i++){
                cout << outputs[i][0] << ":";
                
                //if mintes are less than 0, it adds a filler zero (like in 4:04)
                if(outputs[i][1] < 10){
                    cout << "0";
                }

                cout << outputs[i][1] << " " << pmamA[i];

                if(i < 5){
                    cout << ", ";
                }
            } 
            cout << endl << endl << "A good full sleep requires 5-6 'cycles'" << endl << endl;
        }
        else if(choice == 'c' || choice == 'C'){
            inputAccepted = true;
            
            cout << endl << "What time are you planning on sleeping?" << endl << "Please Enter the Hour Now (1-12):" << endl;
            cin >> hr;
            cout << endl << endl << "Please enter the minutes now (0-59):" << endl;
            cin >> min;

            cout << endl << endl << "Is this time PM or AM? (pm/am)" << endl;
            cin >> pmam;
            cout << endl << endl;
            if(pmam == "pm" || pmam == "PM" || pmam == "Pm"){
                pmam="pm";
            }
            else if(pmam == "am" || pmam == "AM" || pmam == "Am"){
                pmam="am";
            }
            //time for the person to sleep
            min+=15;

            //makes sure that min!>59, and hr!>12;
            if(min>59){
                hr++;
                min -= 60;
            }
            if(hr>12){
                hr -= 12;
                pmam = "pm";
            }

            int hrtemp = hr;
            //calculating the sleeping times (+1:30 everytime)
            for(int i = 0; i < 6 ; i++){
                hr++; hrtemp++;
                min+=30;
            
                if(min>59){
                    hr++; hrtemp++;
                    min-=60;
                }
                if(hr>12){
                    hr-=12;
                }
                if(hrtemp>11){
                    pmamChange();
                    hrtemp+=12;
                }

                pmamA[i]=pmam;
                outputs[i][0]=hr;
                outputs[i][1]=min;
            }

            //prints the sleeping times
            cout << "To sleep at this time, you will need to wake up at one of the following: " << endl;
            for(int i = 0; i < 6; i++){
                cout << outputs[i][0] << ":";
                
                //if mintes are less than 0, it adds a filler zero (like in 4:04)
                if(outputs[i][1] < 10){
                    cout << "0";
                }

                cout << outputs[i][1] << " " << pmamA[i];

                if(i < 5){
                    cout << ", ";
                }
            }
            cout << endl << endl << "A good full sleep requires 5-6 'cycles'" << endl << endl;
        }
        else{
            inputAccepted = false;
            cout << endl << "Please enter a valid option (Letter)" << endl;
        }
    }while(!inputAccepted);

    return 0;
}