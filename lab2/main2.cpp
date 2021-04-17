#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
#include<string>


using namespace std;
//----------------------------------------------
int gpio_export(unsigned int gpio){
  int fd,len;
  char buf[64];

  fd = open("/sys/class/gpio/export",O_WRONLY);
  if(fd<0)
  {
    perror("gpio/export");
    return fd;
  }
  len = snprintf(buf,sizeof(buf),"%d",gpio);
  write(fd,buf,len);
  close(fd);

  return 0;
}
//----------------------------------------------
int gpio_unexport(unsigned int gpio){
  int fd,len;
  char buf[64];

  fd = open("/sys/class/gpio/unexport",O_WRONLY);
  if(fd<0)
  {
    perror("gpio/export");
    return fd;
  }
  len = snprintf(buf,sizeof(buf),"%d",gpio);
  write(fd,buf,len);
  close(fd);

  return 0;
}
//----------------------------------------------
int gpio_set_dir(unsigned int gpio,string dirStatus){
  int fd;
  char buf[64];
  snprintf(buf,sizeof(buf),"/sys/class/gpio/gpio%d/direction",gpio);

  fd = open(buf,O_WRONLY);
  if(fd<0)
  {
    perror("gpio/direction");
    return fd;
  }
  if(dirStatus == "out"){
    write(fd,"out",4);
  }
  else
  {
    write(fd,"in",3);
  }
  close(fd);
  return 0;
}
//----------------------------------------------
int set_value(int gpio,int value)
{
  int fd;
  char buf[64];

  snprintf(buf,sizeof(buf),"/sys/class/gpio/gpio%d/value",gpio);

  fd = open(buf,O_WRONLY);
  if(fd<0)
  {
    perror("gpio/set-value");
    return fd;
  }
  if(value==0){
    write(fd,"0",2);
  }
  else
  {
    write(fd,"1",2);
  }
  close(fd);
  return 0;
}
void led(int pin,string status){
  gpio_export(pin);
  gpio_set_dir(pin,"out");
  if(status=="on"){
    set_value(pin,1);
  }else{
    set_value(pin,0);
    gpio_unexport(pin);
  }
}
//----------------------------------------------
int writefile(string gpio){
  int fd,len;
  char buf[64];

  fd = open("./output.txt",O_WRONLY);
  if(fd<0)
  {
    perror("gpio/export");
    return fd;
  }
  len = snprintf(buf,sizeof(buf),"%s",gpio);
  write(fd,buf,len);
  close(fd);

  return 0;
}
//----------------------------------------------
int main(int argc,char *argv[])
{
  string a = argv[1];
  string status = argv[2];
  if(a=="LED1"){
    writefile("LED1 "+status);
  }
  else if(a=="LED2"){
    writefile("LED2 "+status);
  }
  else if(a=="LED3"){
    writefile("LED3 "+status);
  }
  else if(a=="LED4"){
    writefile("LED4 "+status);
  }
  else{
    writefile("shing "+status);
  }
  
  
  
  
  /*
  switch(led) {
    case "LED1":
      led(396);
      break;
    case "LED2":
      led(397);
      break;
    case "LED3":
      led(429);
      break;
    case "LED4":
      led(398);
      break;
    case "Mode_Shine":
      int team1[2]={396,397};
      int team2[2]={429,398};

      gpio_export(team1[0]);
      gpio_export(team1[1]);
      gpio_export(team2[0]);
      gpio_export(team2[1]);

      gpio_set_dir(team1[0],"out");
      gpio_set_dir(team1[1],"out");
      gpio_set_dir(team2[0],"out");
      gpio_set_dir(team2[1],"out");

      for(int i=0;i<atoi(status.c_str());i++){
        set_value(team1[0],1);
        set_value(team1[1],1);
        set_value(team2[0],0);
        set_value(team2[1],0);
        usleep(300000);
        set_value(team1[0],0);
        set_value(team1[1],0);
        set_value(team2[0],1);
        set_value(team2[1],1);
        usleep(300000);
      }
      break;
  }*/
}

