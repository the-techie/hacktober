#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import subprocess
import xlrd as xl
import os
import sys
import time

if (os.path.exists(sys.argv[1])):
    filePath = os.path.basename(sys.argv[1])
else:
    print("No such file exists")
    exit(0)

if(filePath):
    outputFile = open("APItest.txt", "a")
    print("------------------------Executing---------------------------")
    wb = xl.open_workbook(filePath)
    sheet = wb.sheet_by_index(0)

    for i in range(len(sheet[0])):
        print("===========================================================================================================================================================")
        outputFile.write(
            "===========================================================================================================================================================\n")
        if(sheet.cell(0, i).value):
            print("Please wait hitting server..!!!")
            time.sleep(2)
            print("----------------------------------------------------------------------REQUEST------------------------------------------------------------------------------")
            print(sheet.cell(0, i).value)
            outputFile.write("\nREQUEST:\n" + sheet.cell(0, i).value + "\n")
            res = subprocess.check_output(
                sheet.cell_value(0, i) + "| json_pp", shell=True)
            print("----------------------------------------------------------------------RESPONSE------------------------------------------------------------------------------")
            res = res.decode()
            print(res)
            outputFile.write("\n\nRESPONSE:\n" + res + "\n")

    outputFile.close()
