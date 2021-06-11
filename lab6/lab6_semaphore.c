#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<iostream>
#define LED1 396
#define LED2 397
#define LED3 429
#define LED4 398

using namespace std;
string status = "";
int times;

sem_t semaphore;
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
void led(int pin,int status){
  gpio_export(pin);
  gpio_set_dir(pin,"out");
  if(status==1){
    set_value(pin,1);
  }else{
    set_value(pin,0);
    gpio_unexport(pin);
  }
}
//----------------------------------------------

void* led1_thread(void* arg){
    //string = (char *)input;
    
    sem_wait(&semaphore);
    for(int i=0;i<times;i++){
      led(LED1,status[0]-'0');
      usleep(500000);
      led(LED1,1-(status[0]-'0'));
      usleep(500000);
    }

    pthread_exit(NULL);
}
void* led2_thread(void* arg){
    //string = (char *)input;
    
    sem_wait(&semaphore);
    for(int i=0;i<times;i++){
      led(LED2,status[1]-'0');
      usleep(500000);
      led(LED2,1-(status[1]-'0'));
      usleep(500000);
    }

    pthread_exit(NULL);
}
void* led3_thread(void* arg){
    //string = (char *)input;
    
    sem_wait(&semaphore);
    for(int i=0;i<times;i++){
      led(LED3,status[2]-'0');
      usleep(500000);
      led(LED3,1-(status[2]-'0'));
      usleep(500000);
    }

    pthread_exit(NULL);
}
void* led4_thread(void* arg){
    //string = (char *)input;
    
    sem_wait(&semaphore);
    for(int i=0;i<times;i++){
      led(LED4,status[3]-'0');
      usleep(500000);
      led(LED4,1-(status[3]-'0'));
      usleep(500000);
    }

    pthread_exit(NULL);
}
int main(int argc,char * argv[]){
    status = argv[1];
    times =atoi(argv[2]);
    cout <<  status << endl << times << endl;
     
    sem_init(&semaphore,0,0);

    pthread_t led1,led2,led3,led4;
    pthread_create(&led1,NULL,led1_thread,NULL);
    pthread_create(&led2,NULL,led2_thread,NULL);
    pthread_create(&led3,NULL,led3_thread,NULL);
    pthread_create(&led4,NULL,led4_thread,NULL);
    for(int i=0;i<times*4;i++)
    {
      sem_post(&semaphore);
    }
    pthread_join(led1,NULL);
    pthread_join(led2,NULL);
    pthread_join(led3,NULL);
    pthread_join(led4,NULL);





    return 0;

}