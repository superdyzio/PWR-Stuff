#!/usr/bin/python
import time 
import RPi.GPIO as GPIO

GPIO.cleanup()
GPIO.setmode(GPIO.BCM)

GPIO.setup(17,GPIO.OUT)
GPIO.setup(27,GPIO.OUT)
GPIO.setup(22,GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(24,GPIO.OUT)
GPIO.setup(25,GPIO.OUT)
GPIO.setup(5,GPIO.OUT)	# dioda prawego skrajnego czujnika
GPIO.setup(6,GPIO.OUT)	# dioda prawego srodkowego czujnika
GPIO.setup(13,GPIO.OUT)	# dioda centralnego czujnika
GPIO.setup(19,GPIO.OUT)	# dioda lewego srodkowego czujnika
GPIO.setup(26,GPIO.OUT)	# dioda lewego skrajnego czujnika
GPIO.setup(7,GPIO.IN)	
GPIO.setup(12,GPIO.IN)
GPIO.setup(16,GPIO.IN)
GPIO.setup(20,GPIO.IN)
GPIO.setup(21,GPIO.IN)

GPIO.output(27,GPIO.LOW)	# kierunek obrotu jednego silnika
GPIO.output(22,GPIO.HIGH)	
GPIO.output(23,GPIO.HIGH)	# kierunek obrotu drugiego silnika
GPIO.output(24,GPIO.LOW)
GPIO.output(5,GPIO.HIGH)
GPIO.output(6,GPIO.HIGH)
GPIO.output(13,GPIO.HIGH)
GPIO.output(19,GPIO.HIGH)
GPIO.output(26,GPIO.HIGH)
a = GPIO.PWM(25,50)
b = GPIO.PWM(17,50)
a.start(0)	# silnik lewy
b.start(0)	# silnik prawy

while True:
	ilosc = 0		# ilosc czujnikow w stanie wysokim
	if GPIO.input(7):	# lewy skrajny czujnik
		GPIO.output(26,GPIO.LOW)
		a.ChangeDutyCycle(30)
		b.ChangeDutyCycle(10)
		ilosc += 1
	else:
		GPIO.output(26,GPIO.HIGH)
	if GPIO.input(21):	# prawy skrajny czujnik
		GPIO.output(5,GPIO.LOW)
		a.ChangeDutyCycle(10)
		b.ChangeDutyCycle(30)
		ilosc += 1
	else:
		GPIO.output(5,GPIO.HIGH)
	if GPIO.input(12):	# lewy srodkowy czujnik
		GPIO.output(19,GPIO.LOW)
		a.ChangeDutyCycle(32)
		b.ChangeDutyCycle(20)
		ilosc += 1
	else:
		GPIO.output(19,GPIO.HIGH)
	if GPIO.input(20):	# prawy srodkowy czujnik
		GPIO.output(6,GPIO.LOW)
		a.ChangeDutyCycle(27)
		b.ChangeDutyCycle(30)
		ilosc += 1
	else:
		GPIO.output(6,GPIO.HIGH)
	if GPIO.input(16):	# centralny czujnik
		GPIO.output(13,GPIO.LOW)
		a.ChangeDutyCycle(45)
		b.ChangeDutyCycle(40)
		ilosc += 1
	else:
		GPIO.output(13,GPIO.HIGH)
	if ilosc == 0 or ilosc > 2:
		a.ChangeDutyCycle(0)
		b.ChangeDutyCycle(0)
	time.sleep(0.01)
GPIO.cleanup()
