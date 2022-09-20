from bs4 import BeautifulSoup
from selenium import webdriver
import pyautogui
import time

import config

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

driver = webdriver.Chrome()
driver.get(config.URL)
driver.find_element_by_class_name("icon_play").click()
time.sleep(0.1)

while(pyautogui.position().x > 10 and pyautogui.position().y > 10) :
    text = driver.page_source

    soup = BeautifulSoup(text, 'lxml')

    items = soup.find('div', {'class' : 'task_wrap'})

    x = int(items.find('span', {'id' : 'task_x'}).text)
    y = int(items.find('span', {'id': 'task_y'}).text)
    op = items.find('span', {'id': 'task_op'}).text
    res = int(items.find('span', {'id': 'task_res'}).text)

    time.sleep(0.1)

    if(correctness(x, y, op, res)) :
        driver.find_element_by_class_name("button_correct").click()
    else :
        driver.find_element_by_class_name("button_wrong").click()

exit()
