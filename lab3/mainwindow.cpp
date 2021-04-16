#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
using namespace std;
QTimer *timer = new QTimer(NULL);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->PLed_1->setHidden(true);
    ui->PLed_2->setHidden(true);
    ui->PLed_3->setHidden(true);
    ui->PLed_4->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;

}
int gpio_export(unsigned int gpio){
  int fd,len;
  char buf[64];
  fd = open("/sys/class/gpio/export",O_WRONLY);
  if(fd<0){
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
int times=0;

void MainWindow::on_LED_Shining_clicked()
{
    if(ui->LED1->isChecked()){
        ui->PLed_1->setHidden(false);
        led(396,"on");
    }else{
        ui->PLed_1->setHidden(true);
        led(396,"off");
    }

    if(ui->LED2->isChecked()){
        ui->PLed_2->setHidden(false);
        led(397,"on");
    }else{
        ui->PLed_2->setHidden(true);
        led(397,"off");
    }

    if(ui->LED3->isChecked()){
        ui->PLed_3->setHidden(false);
        led(429,"on");
    }else{
        ui->PLed_3->setHidden(true);
        led(429,"off");
    }

    if(ui->LED4->isChecked()){
        ui->PLed_4->setHidden(false);
        led(398,"on");
    }else{
        ui->PLed_4->setHidden(true);
        led(398,"off");
    }
}


void MainWindow::on_LED_Switching_clicked()
{
    timer = new QTimer(NULL);
    connect(timer,SIGNAL(timeout()),this,SLOT(switching()));
    timer->start((6-((ui->horizontalSlider->value()))/20)*100);
}
void MainWindow::switching()
{
    times++;
    QCheckBox* checkboxes[] = {ui->LED1, ui->LED2, ui->LED3, ui->LED4};
    QLabel* leds[] = {ui->PLed_1, ui->PLed_2, ui->PLed_3, ui->PLed_4};
    int gpio[4] = {396,397,429,398};
    if(!(checkboxes[0]->checkState() || checkboxes[1]->checkState() || checkboxes[2]->checkState() || checkboxes[3]->checkState()) || (checkboxes[2]->checkState() && checkboxes[3]->checkState())){
        for(int i=0;i<2;i++){
            leds[i]->setHidden(false);
            led(gpio[i],"on");
            checkboxes[i]->setChecked(true);
            leds[i+2]->setHidden(true);
            led(gpio[i+2],"off");
            checkboxes[i+2]->setChecked(false);
        }
    }
    else{
        for(int i=0;i<2;i++){
            leds[i]->setHidden(true);
            led(gpio[i],"off");
            checkboxes[i]->setChecked(false);
            leds[i+2]->setHidden(false);
            led(gpio[i+2],"on");
            checkboxes[i+2]->setChecked(true);
        }
    }
    if(times>=ui->times->text().toInt())
    {
        times = 0;
        timer->stop();
    }

}
void MainWindow::keyPressEvent(QKeyEvent *k){
    if(k->key()==43){
        ui->horizontalSlider->setValue(ui->horizontalSlider->value()+1);

    }else if(k->key()==45){
        ui->horizontalSlider->setValue(ui->horizontalSlider->value()-1);
    }
    ui->progressBar->setValue(ui->horizontalSlider->value());
}


void MainWindow::on_LED_Switching_off_clicked()
{
    timer->stop();
    QCheckBox* checkboxes[] = {ui->LED1, ui->LED2, ui->LED3, ui->LED4};
    QLabel* leds[] = {ui->PLed_1, ui->PLed_2, ui->PLed_3, ui->PLed_4};
    int gpio[4] = {396,397,429,398};
    for(int i=0;i<4;i++){
        leds[i]->setHidden(true);
        led(gpio[i],"off");
        checkboxes[i]->setChecked(false);

    }

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->progressBar->setValue(position);
}
