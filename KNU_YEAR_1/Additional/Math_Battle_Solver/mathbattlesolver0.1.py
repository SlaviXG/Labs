from bs4 import BeautifulSoup
from tkinter import Tk
import pyautogui
import time

def correctness (x, y, op, res) :

    if(op == "+") :
        if(x + y == res) :
            return 1
        else :
            return 0
    if (op == "-"):
        if (x - y == res):
            return 1
        else:
            return 0
    if (op == "×") :
        if (x * y == res):
            return 1
        else:
            return 0
    if (op == "/"):
        if (x // y == res):
            return 1
        else:
            return 0



user_time = int(input())

time.sleep(2.5)

start_time = time.time()

while(time.time() - start_time < user_time) :

    print(pyautogui.position())

    pyautogui.click(button = 'right')
    pyautogui.move(20,-20)
    pyautogui.click()
    time.sleep(0.2)
    pyautogui.moveTo(1230, 200)
    time.sleep(0.2)
    pyautogui.click(button='right')
    time.sleep(0.2)
    pyautogui.move(80, 185)
    pyautogui.click()
    pyautogui.move(250, 0)
    pyautogui.click()
    pyautogui.moveTo(1900, 150)
    pyautogui.click()
    text = Tk().clipboard_get()

    soup = BeautifulSoup(text, 'lxml')

    items = soup.find('div', {'class' : 'task_wrap'})

    x = int(items.find('span', {'id' : 'task_x'}).text)
    y = int(items.find('span', {'id': 'task_y'}).text)
    op = items.find('span', {'id': 'task_op'}).text
    res = int(items.find('span', {'id': 'task_res'}).text)

    print (x,y,op,res)

    if(correctness(x, y, op, res)) :
        pyautogui.moveTo(852, 815)
        pyautogui.click()
    else :
        pyautogui.moveTo(1065, 815)
        pyautogui.click()

