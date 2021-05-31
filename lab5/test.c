#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
#include<string>
#include<map>

using namespace std;
void setGPIO(unsigned int gpio,string status)
{
    int io;
    io = open("/dev/demo",O_WRONLY);
    if(io<0){
        perror("gpio error");
        return;
    }
    char buf[10] = {0};
    if(status == "on")
    {
        strcpy(buf,(to_string(gpio)+"1").c_str());
    }
    else
    {
        strcpy(buf,(to_string(gpio)+"0").c_str());
    }
    write(io,buf,5);
    close(io);
    return;
}
void readGPIO(unsigned int gpio)
{
    int io;
    io = open("/dev/demo",O_RDONLY);
    if(io<0){
        perror("gpio error");
        return;
    }
    char buf[10] = {0};
    strcpy(buf,(to_string(gpio)).c_str());
    read(io,buf,4);
    cout << buf[0] << endl;
    close(io);
    return;
}
int main(int argc,char *argv[])
{
    
    if(argc==3)
    {
        string a = argv[1];
        string status = argv[2];
        if(a=="LED1"){
            setGPIO(396,status);
        }
        else if(a=="LED2"){
            setGPIO(397,status);
        }
        else if(a=="LED3"){
            setGPIO(429,status);
        }
        else if(a=="LED4"){
            setGPIO(398,status);
        }
    }
    else
    {
        
        string a = argv[1];
        cout << a << " Status: ";
        if(a=="LED1"){
            readGPIO(396);
        }
        else if(a=="LED2"){
            readGPIO(397);
        }
        else if(a=="LED3"){
            readGPIO(429);
        }
        else if(a=="LED4"){
            readGPIO(398);
        }
    }

    return 0;
}