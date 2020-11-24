import serial
import serial.tools.list_ports
import time

"""
This program reads a string of sensor data and GPS data
from an arduino in format: 
        " ----, -----, ----, ---- : _____ ______ _______"
    Where "------," means data separated by commas or CSVs
    and "______ *space*" means data separated by commas.

" ----, -----, ----, ---- : _____ ______ _______"
      |                                                
      |
      |
"CSVs : GPS Coords"  sent in formatted way.
CSVs are sensor values from strain, vibration, gyros, etc.


This is part of my work in the UPRM MoonBuggy - Telemetry dpt. 
as of Feb 20. 2020. More will be uploaded in the future.


Buggy is a class separate from this script, which is not included 
for privacy. 
"""

def parser(Data_String):

    data_types = Data_string.split(':')
    Data_String = data_types[0]
    GPS_string = data_types[1]

    Data_List = Data_String.split(',')
    GPS_List = GPS_parser(GPS_string)
    
    for i in range(len(Data_List)):
        Data_List[i] = Data_List[i].strip()

    return Data_List, GPS_List

def GPS_parser(GPS_String):
    GPS_info_list = GPS_String.split(' ')
    for i in range(len(GPS_info_list)):
        GPS_info_list = GPS_info_list[i].strip()
    return GPS_info_list

def setup():
      arduino = serial.Serial('COM5',9600)
      decoded_data = None
      while True:
          data = int(arduino.readline())
          data = arduino.readline()
          if data:
              decoded_data = data.decode("utf-8")
              cleaned_data, gps_data = parser(decoded_data)
              obj = Buggy(cleaned_data, gps_data)
              
              #csv_reader sends obj instance to a CSV log for storage
              csv_reader(obj)
              #send_json sends obj instance to JSON formatter 
              send_json(obj)
 
if "__main__" == __name__:
    setup()

"""
Made by: Felix M. Perez Quinones
"""