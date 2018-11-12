import serial
import autopy
import keyboard

#Global Variables
ser = 0

#Function to Initialize the Serial Port
def init_serial():
    global ser          #Must be declared in Each Function
    ser = serial.Serial()
    ser.baudrate = 9600
    #ser.port = COMNUM - 1   #COM Port Name Start from 0
    ser.port = '/dev/ttyACM0' #If Using Linux

    #Specify the TimeOut in seconds, so that SerialPort
    #Doesn't hangs
    ser.timeout = 10
    ser.open()          #Opens SerialPort

    # print port open or closed
    if ser.isOpen():
        print('Open: ' + ser.portstr)
#Function Ends Here

def valid(char):
        return char != '\n' and char != '\r' and char != "" 

def stringToIntList(list):
        intList = []
        string = ""
        for i in list:
                if valid(i):
                        if i == "," and string != "":
                                try:
                                        intList.append(int(string))
                                except:
                                        print("Error, string: ", string)
                                string = ""
                        else:
                                string += i
        return intList

#Call the Serial Initilization Function, Main Program Starts from here
init_serial()

while 1:    
        bytes = ser.readline()  #Read from Serial Port
        print('You received: ' + bytes)     #Print What is Read from Port
        stringList = list(bytes)
        intList = stringToIntList(stringList)
        print(intList)
        if (len(intList) == 6):
                if intList[0] < 1000 and intList[1] < 1000:
                        autopy.mouse.smooth_move(intList[0], intList[1])
                if (intList[2] == 0):
                        keyboard.press_and_release('q')

    