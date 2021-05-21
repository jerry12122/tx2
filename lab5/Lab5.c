#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;
void setGPIO(unsigned int gpio,string status)
{
    int io;
    io = open("/dev/demo",O_WRONLY);
    if(io<0){
        perror("gpio error")
        return;
    }
    char buf[10] = {0};
    if(status == "on"){
        strcpy(buf,(to_string(gpio) + "1").c_str());
    }
    else
    {
        strcopy(buf,(to_string(gpio) + "0").c_str())
    }
    cout << buf << endl;
    write(io,buf,5);
    close(io);
    return;
}
void getGPIO(unsigned int gpio)
{
    int io;
    io = open("/dev/demo",O_WRONLY);
    if(io<0){
        perror("gpio error")
        return;
    }
    char buf[10] = {0};
    if(status == "on"){
        strcpy(buf,(to_string(gpio) + "1").c_str());
    }
    else
    {
        strcopy(buf,(to_string(gpio) + "0").c_str())
    }
    cout << buf << endl;
    write(io,buf,5);
    close(io);
    return;
}
int main(int argc,char *argv[])
{
    string a = argv[1];
    string status = argv[2];
    if(a=="LED1"){
        if(status == "on" || status == "off")
        {
            setGPIO(396,status);
        }
        else
        {
            getGPIO(396);
        }
    }
    else if(a=="LED2"){
        if(status == "on" || status == "off")
        {
            setGPIO(397,status);
        }
        else
        {
            getGPIO(397);
        }
    }
    else if(a=="LED3"){
        if(status == "on" || status == "off")
        {
            setGPIO(429,status);
        }
        else
        {
            getGPIO(429);
        }
    }
    else if(a=="LED4"){
        if(status == "on" || status == "off")
        {
            setGPIO(398,status);
        }
        else
        {
            getGPIO(398);
        }
    }
}