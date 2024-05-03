from PIL import Image, ImageGrab
import pytesseract
import pyautogui
import time

pytesseract.pytesseract.tesseract_cmd = 'M:\\Programs\\Tesseract ORC\\tesseract.exe'

def res_text (txt_old) :
    txt = ""
    for s in txt_old :
        if(s == "\n") :
            break
        txt+=s
    return txt

def correctness (txt1, txt2) :

    op_pos = -1
    for i in range(len(txt1)) :
        try :
            el = txt1[i]
            tmp = int(el)
        except :
            op_pos = i

    x = txt1 [ : i]
    y = txt1 [i+1 : ]

    op = txt1[op_pos]

    res = int(txt2[1:])

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
    if (op == "×" or op == "x" or op == "X" or op == "*") :
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

    im1 = ImageGrab.grab().crop((730, 305, 1175, 410))
    im1.save("scr1.png")
    im2 = ImageGrab.grab().crop((800, 410, 1075, 525))
    im2.save("scr2.png")

    text1 = pytesseract.image_to_string(Image.open("scr1.png"), config = r"--oem 3 --psm 13")
    text2 = pytesseract.image_to_string(Image.open("scr2.png"), config = r"--oem 3 --psm 8")

    print(text1, text2)

    text1_new = res_text(text1)
    text2_new = res_text(text2)


    time.sleep(0.2)

    if(correctness(text1_new,text2_new)) :
        pyautogui.moveTo(852, 815, 0.3)
        pyautogui.click()
    else :
        pyautogui.moveTo(1065, 815, 0.3)
        pyautogui.click()
